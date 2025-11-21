"""Custom Pacemaker Device Controller-Monitor Application

A comprehensive pacemaker simulation system built with custom tkinter styling,
featuring user authentication, parameter management, and device communication.
"""

import hashlib
import json
import os
import secrets
import struct
import tkinter as tk
from dataclasses import dataclass
from enum import Enum
from tkinter import messagebox
from typing import Any, Dict, Optional, Tuple

import customtkinter as ctk
import matplotlib.pyplot as plt
import numpy as np
import serial
import serial.tools.list_ports
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from PIL import Image

from config_loader import config

# Load configuration constants
app_config = config.get_app_config()
ctk.set_appearance_mode(app_config.get("appearance_mode", "light"))
ctk.set_default_color_theme(app_config.get("color_theme", "dark-blue"))
USER_FILE = app_config.get("user_file", "data/users.json")
CSV_FILE = app_config.get("csv_file", "data/pacemaker_settings.csv")
MAX_USERS = app_config.get("max_users", 10)


class PacemakerMode(Enum):
    """Supported pacemaker modes."""

    AOO = "AOO"
    VOO = "VOO"
    AAI = "AAI"
    VVI = "VVI"
    AOOR = "AOOR"
    VOOR = "VOOR"
    AAIR = "AAIR"
    VVIR = "VVIR"
    DDDR = "DDDR"


class SerialCommand(Enum):
    """Enumerates supported serial commands."""

    WRITE_PARAMS = 0x01
    READ_PARAMS = 0x02
    REQUEST_EGRAM = 0x03
    ACK = 0x7F


class SerialValueType(Enum):
    """Value types supported by the serial protocol."""

    UINT16 = 0x01
    FLOAT32 = 0x02
    UINT8 = 0x03


@dataclass
class User:
    """User data structure."""

    username: str
    password: str
    first_name: str = ""
    last_name: str = ""
    age: str = ""
    profile_data: Dict = None

    def __post_init__(self):
        if self.profile_data is None:
            self.profile_data = {}


class CustomStyle:
    """Custom styling configuration for the application."""

    def __init__(self):
        """Initialize CustomStyle with configuration from JSON files."""
        self.COLORS = config.get_colors()
        self.FONTS = config.get_fonts()

    @classmethod
    def get_colors(cls):
        """Get color scheme configuration."""
        return config.get_colors()

    @classmethod
    def get_fonts(cls):
        """Get font configuration."""
        return config.get_fonts()


# Create global style instance
custom_style = CustomStyle()


class UserManager:
    """Manages user authentication and data storage."""

    PASSWORD_ITERATIONS = 200_000

    def __init__(self):
        self.users: Dict[str, User] = {}
        self.current_user: Optional[User] = None
        self._ensure_data_directory()
        self._load_users()

    def _ensure_data_directory(self):
        """Create data directory if it doesn't exist."""
        if not os.path.exists("data"):
            os.makedirs("data")

    def _load_users(self):
        """Load users from JSON file."""
        if os.path.exists(USER_FILE):
            try:
                with open(USER_FILE, "r") as f:
                    data = json.load(f)
                    for username, user_data in data.items():
                        self.users[username] = User(
                            username=user_data["username"],
                            password=user_data["password"],
                            first_name=user_data.get("first_name", ""),
                            last_name=user_data.get("last_name", ""),
                            age=user_data.get("age", ""),
                            profile_data=user_data.get("profile_data", {}),
                        )
            except Exception as e:
                print(f"Error loading users: {e}")

    def _save_users(self):
        """Save users to JSON file."""
        try:
            data = {}
            for username, user in self.users.items():
                data[username] = {
                    "username": user.username,
                    "password": user.password,
                    "first_name": user.first_name,
                    "last_name": user.last_name,
                    "age": user.age,
                    "profile_data": user.profile_data,
                }

            with open(USER_FILE, "w") as f:
                json.dump(data, f, indent=2)
        except Exception as e:
            print(f"Error saving users: {e}")

    def register_user(
        self, username: str, password: str, first_name: str = "", last_name: str = "", age: str = ""
    ) -> Tuple[bool, str]:
        """Register a new user."""
        if len(self.users) >= MAX_USERS:
            return False, f"Maximum number of users ({MAX_USERS}) reached"

        if username in self.users:
            return False, "Username already exists"

        if not username or not password:
            return False, "Username and password cannot be empty"

        if len(username) < 3:
            return False, "Username must be at least 3 characters long"

        if len(password) < 4:
            return False, "Password must be at least 4 characters long"

        hashed_password = self._hash_password(password)
        new_user = User(
            username=username,
            password=hashed_password,
            first_name=first_name,
            last_name=last_name,
            age=age,
        )
        self.users[username] = new_user
        self._save_users()

        return True, "User registered successfully"

    def login_user(self, username: str, password: str) -> Tuple[bool, str]:
        """Authenticate a user."""
        if username not in self.users:
            return False, "User not found"

        user = self.users[username]
        stored_password = user.password

        if not self._verify_password(stored_password, password):
            return False, "Invalid password"

        # Promote legacy plaintext passwords to hashed storage
        if not self._is_password_hashed(stored_password):
            user.password = self._hash_password(password)
            self._save_users()

        self.current_user = user
        return True, "Login successful"

    def logout_user(self):
        """Logout current user."""
        self.current_user = None

    def get_current_user(self) -> Optional[User]:
        """Get currently logged in user."""
        return self.current_user

    def _is_password_hashed(self, stored_password: str) -> bool:
        """Determine if a stored password already uses the salted PBKDF2 format."""
        return isinstance(stored_password, str) and "$" in stored_password

    def _hash_password(self, password: str, salt_hex: Optional[str] = None) -> str:
        """Create a salted hash for persistent password storage."""
        if salt_hex is None:
            salt_hex = secrets.token_hex(16)

        dk = hashlib.pbkdf2_hmac(
            "sha256",
            password.encode("utf-8"),
            bytes.fromhex(salt_hex),
            self.PASSWORD_ITERATIONS,
        )
        return f"{salt_hex}${dk.hex()}"

    def _verify_password(self, stored_password: str, provided_password: str) -> bool:
        """Verify a user-provided password against the stored representation."""
        if not stored_password:
            return False

        if not self._is_password_hashed(stored_password):
            return stored_password == provided_password

        try:
            salt_hex, hash_hex = stored_password.split("$", 1)
        except ValueError:
            return False

        candidate = hashlib.pbkdf2_hmac(
            "sha256",
            provided_password.encode("utf-8"),
            bytes.fromhex(salt_hex),
            self.PASSWORD_ITERATIONS,
        ).hex()

        return secrets.compare_digest(hash_hex, candidate)


class PacemakerParameters:
    """Manages pacemaker parameters and validation."""

    def __init__(self):
        """Initialize pacemaker parameters with configuration from JSON."""
        self.MODE_PARAMETERS = self._load_mode_parameters()
        self.current_mode = PacemakerMode.AOO
        self.parameters = {}
        self._initialize_parameters()

    def _load_mode_parameters(self) -> Dict[PacemakerMode, Dict[str, Any]]:
        """Load mode parameters from configuration."""
        mode_params_config = config.get_mode_parameters()
        mode_parameters = {}

        for mode_name, params in mode_params_config.items():
            try:
                mode = PacemakerMode(mode_name)
                mode_parameters[mode] = params
            except ValueError:
                print(f"Warning: Unknown pacemaker mode {mode_name} in configuration")

        return mode_parameters

    def _initialize_parameters(self):
        """Initialize parameters for all modes with default values."""
        for mode, params in self.MODE_PARAMETERS.items():
            self.parameters[mode.value] = {}
            for param_name, param_config in params.items():
                self.parameters[mode.value][param_name] = param_config["default"]

    def get_parameters_for_mode(self, mode: PacemakerMode) -> Dict[str, Any]:
        """Get parameters for a specific mode."""
        return self.MODE_PARAMETERS.get(mode, {})

    def get_current_parameters(self) -> Dict[str, Any]:
        """Get current parameter values for the active mode."""
        return self.parameters.get(self.current_mode.value, {})

    def _validate_value(self, value: Any, param_config: Dict[str, Any]) -> Tuple[bool, Any, str]:
        """Validate and normalize a parameter value."""
        input_type = param_config.get("input_type", "range")

        if input_type == "enum":
            options = param_config.get("options", [])
            if value not in options:
                return False, None, f"Value must be one of: {', '.join(options)}"
            return True, value, ""

        try:
            numeric_value = float(value)
        except (TypeError, ValueError):
            return False, None, "Invalid number format. Please enter a numeric value."

        min_val = param_config.get("min")
        max_val = param_config.get("max")
        unit = param_config.get("unit", "")

        def _range_text():
            lower_txt = f"{min_val}" if min_val is not None else "-∞"
            upper_txt = f"{max_val}" if max_val is not None else "∞"
            return f"{lower_txt} and {upper_txt} {unit}".strip()

        if min_val is not None and numeric_value < min_val:
            return False, None, f"Value must be between {_range_text()}"

        if max_val is not None and numeric_value > max_val:
            return False, None, f"Value must be between {_range_text()}"

        step = param_config.get("step")
        if step and step > 0 and min_val is not None:
            steps = (numeric_value - min_val) / step
            if abs(steps - round(steps)) > 0.0001:
                return False, None, f"Value must be in increments of {step} {unit}".strip()

        data_type = param_config.get("data_type", "float")
        if data_type == "int":
            numeric_value = int(round(numeric_value))
        else:
            numeric_value = float(numeric_value)

        return True, numeric_value, ""

    def set_parameter(self, param_name: str, value: Any) -> Tuple[bool, str]:
        """Set a parameter value with validation for the current mode."""
        if self.current_mode.value not in self.parameters:
            return False, "Invalid mode"

        mode_params = self.MODE_PARAMETERS.get(self.current_mode, {})
        if param_name not in mode_params:
            return False, f"Parameter {param_name} not available for mode {self.current_mode.value}"

        config = mode_params[param_name]
        is_valid, normalized_value, error = self._validate_value(value, config)
        if not is_valid:
            return False, error

        self.parameters[self.current_mode.value][param_name] = normalized_value
        return True, ""

    def set_parameters_for_mode(self, mode: PacemakerMode, values: Dict[str, Any], validate: bool = True):
        """Bulk update parameter values for a specific mode."""
        if mode.value not in self.parameters:
            self.parameters[mode.value] = {}

        mode_params = self.MODE_PARAMETERS.get(mode, {})
        if not mode_params:
            print(f"Warning: Attempted to set parameters for unsupported mode {mode.value}")
            return

        for param_name, value in values.items():
            if param_name not in mode_params:
                print(f"Warning: Parameter {param_name} is not defined for mode {mode.value}")
                continue

            if validate:
                is_valid, normalized_value, error = self._validate_value(value, mode_params[param_name])
                if not is_valid:
                    print(f"Validation failed for {param_name}: {error}")
                    continue
                self.parameters[mode.value][param_name] = normalized_value
            else:
                self.parameters[mode.value][param_name] = value

    def set_mode(self, mode: PacemakerMode):
        """Set the current pacemaker mode."""
        self.current_mode = mode

    def get_mode(self) -> PacemakerMode:
        """Get the current pacemaker mode."""
        return self.current_mode


class CustomPacemakerApp:
    """Main application class with custom tkinter styling."""

    def __init__(self):
        self.root = ctk.CTk()
        self.user_manager = UserManager()
        self.parameters = PacemakerParameters()
        self.current_screen = None
        self.scaling_factor = 1.0

        self._setup_application()
        self._show_login_screen()

    def _setup_application(self):
        """Set up the main application window."""
        self.root.title("PulsePoint DCM")
        self.root.geometry("1400x800")
        self.root.minsize(1100, 650)

        # Configure custom styling
        self._configure_styles()

        # Configure grid
        self.root.grid_rowconfigure(0, weight=1)
        self.root.grid_columnconfigure(0, weight=1)

        # Set application icon if available
        try:
            self.root.iconbitmap("PulsePoint.ico")
        except Exception:
            pass

    def _configure_styles(self):
        """Configure global CustomTkinter styling."""
        colors = custom_style.get_colors()
        widget_scaling = app_config.get("ui_scaling", 1.0)
        window_scaling = app_config.get("window_scaling", 1.0)
        ctk.set_widget_scaling(widget_scaling)
        ctk.set_window_scaling(window_scaling)
        self.root.configure(fg_color=colors["background"])

    def _show_login_screen(self):
        """Show the login screen."""
        self._clear_current_screen()
        self.current_screen = LoginScreen(self.root, self.user_manager, self._on_login_success)
        self.current_screen.pack(fill="both", expand=True)

    def _show_main_screen(self):
        """Show the main application screen."""
        self._clear_current_screen()
        self.current_screen = MainScreen(self.root, self.user_manager, self.parameters, self._on_logout)
        self.current_screen.pack(fill="both", expand=True)

    def _clear_current_screen(self):
        """Clear the current screen."""
        if self.current_screen:
            self.current_screen.destroy()
            self.current_screen = None

    def _on_login_success(self):
        """Handle successful login."""
        self._show_main_screen()

    def _on_logout(self):
        """Handle user logout."""
        self.user_manager.logout_user()
        self._show_login_screen()

    def run(self):
        """Run the application."""
        try:
            self.root.mainloop()
        except KeyboardInterrupt:
            print("Application interrupted by user")
        except Exception as e:
            print(f"Application error: {e}")
            raise


class LoginScreen(ctk.CTkFrame):
    """Custom styled login screen built with CustomTkinter."""

    def __init__(self, parent, user_manager: UserManager, on_login_success):
        colors = custom_style.get_colors()
        super().__init__(parent, fg_color=colors["background"])
        self.user_manager = user_manager
        self.on_login_success = on_login_success

        self._setup_ui()

    def _setup_ui(self):
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()

        self.grid_rowconfigure(0, weight=1)
        self.grid_columnconfigure(0, weight=1)

        container = ctk.CTkFrame(self, fg_color=colors["background"])
        container.grid(row=0, column=0, sticky="nsew", padx=50, pady=35)
        container.grid_rowconfigure(0, weight=1)
        container.grid_columnconfigure(0, weight=3)
        container.grid_columnconfigure(1, weight=2)

        hero_panel = ctk.CTkFrame(container, fg_color=colors["secondary"], corner_radius=32)
        hero_panel.grid(row=0, column=0, sticky="nsew", padx=(0, 20), pady=10)
        hero_panel.grid_rowconfigure(4, weight=1)

        try:
            raw_image = Image.open("PulsePoint.png").resize((120, 120), Image.Resampling.LANCZOS)
            self.logo_image = ctk.CTkImage(light_image=raw_image, dark_image=raw_image, size=(120, 120))
            ctk.CTkLabel(hero_panel, image=self.logo_image, text="").pack(pady=(30, 10))
        except Exception:
            ctk.CTkLabel(
                hero_panel,
                text="PulsePoint",
                font=fonts["title"],
                text_color=colors["text_on_dark"],
            ).pack(pady=(30, 10))

        ctk.CTkLabel(
            hero_panel,
            text="PulsePoint",
            font=fonts["heading"],
            text_color=colors["text_on_dark"],
        ).pack()

        ctk.CTkLabel(
            hero_panel,
            text="Connect. Monitor. Trust.",
            font=fonts["body"],
            text_color="#E3F2FD",
        ).pack(pady=(2, 18))

        hero_copy = (
            "Manage pacemaker therapies with a beautifully simple dashboard. "
            "Secure authentication, synchronized device parameters, and real-time EGRAM insights."
        )
        ctk.CTkLabel(
            hero_panel,
            text=hero_copy,
            font=fonts["body"],
            wraplength=360,
            text_color="#E8F5E9",
            justify="center",
        ).pack(padx=30)

        ctk.CTkFrame(hero_panel, fg_color="transparent").pack(pady=40)

        card = ctk.CTkFrame(container, fg_color=colors["surface"], corner_radius=28)
        card.grid(row=0, column=1, sticky="nsew", padx=(20, 0), pady=10)
        card.grid_rowconfigure(3, weight=1)

        ctk.CTkLabel(
            card,
            text="Welcome back",
            font=fonts["heading"],
            text_color=colors["text"],
        ).pack(pady=(30, 5))

        ctk.CTkLabel(
            card,
            text="Sign in or create a clinician account to continue.",
            font=fonts["body"],
            text_color=colors["text_light"],
        ).pack()

        self.tabview = ctk.CTkTabview(
            card,
            fg_color=colors["surface_alt"],
            segmented_button_fg_color=colors["primary"],
            segmented_button_selected_color=colors["primary"],
            segmented_button_selected_hover_color=colors["primary_light"],
        )
        self.tabview.pack(fill="both", expand=True, padx=30, pady=20)

        self.login_tab = self.tabview.add("Login")
        self.register_tab = self.tabview.add("Register")
        self._setup_login_tab()
        self._setup_register_tab()

        self._setup_status_info(card)

    def _setup_login_tab(self):
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()

        self.username_entry = ctk.CTkEntry(
            self.login_tab,
            placeholder_text="Username",
            font=fonts["body"],
            width=320,
        )
        self.username_entry.pack(pady=(25, 12))

        self.password_entry = ctk.CTkEntry(
            self.login_tab,
            placeholder_text="Password",
            font=fonts["body"],
            show="*",
            width=320,
        )
        self.password_entry.pack(pady=(0, 10))

        self.remember_var = ctk.BooleanVar(value=True)
        ctk.CTkCheckBox(
            self.login_tab,
            text="Keep me signed in",
            variable=self.remember_var,
            font=fonts["small"],
        ).pack(pady=(0, 20))

        login_btn = ctk.CTkButton(
            self.login_tab,
            text="Login",
            command=self._handle_login,
            font=fonts["button"],
            width=200,
            height=42,
            fg_color=colors["primary"],
            hover_color=colors["primary_light"],
        )
        login_btn.pack(pady=(0, 15))

        ctk.CTkLabel(
            self.login_tab,
            text="Forgot password? Contact your system administrator.",
            font=fonts["small"],
            text_color=colors["text_light"],
        ).pack()

        self.username_entry.bind("<Return>", lambda _e: self._handle_login())
        self.password_entry.bind("<Return>", lambda _e: self._handle_login())

    def _setup_register_tab(self):
        fonts = custom_style.get_fonts()
        entry_kwargs = {"font": fonts["body"], "width": 320}

        self.first_name_entry = ctk.CTkEntry(self.register_tab, placeholder_text="First Name", **entry_kwargs)
        self.first_name_entry.pack(pady=(25, 10))

        self.last_name_entry = ctk.CTkEntry(self.register_tab, placeholder_text="Last Name", **entry_kwargs)
        self.last_name_entry.pack(pady=10)

        self.age_entry = ctk.CTkEntry(self.register_tab, placeholder_text="Age", **entry_kwargs)
        self.age_entry.pack(pady=10)

        self.register_username_entry = ctk.CTkEntry(self.register_tab, placeholder_text="Username", **entry_kwargs)
        self.register_username_entry.pack(pady=10)

        self.register_password_entry = ctk.CTkEntry(
            self.register_tab, placeholder_text="Password", show="*", **entry_kwargs
        )
        self.register_password_entry.pack(pady=10)

        self.confirm_password_entry = ctk.CTkEntry(
            self.register_tab, placeholder_text="Confirm Password", show="*", **entry_kwargs
        )
        self.confirm_password_entry.pack(pady=10)

        register_btn = ctk.CTkButton(
            self.register_tab,
            text="Create Account",
            command=self._handle_register,
            width=200,
            height=42,
        )
        register_btn.pack(pady=(10, 30))

    def _setup_status_info(self, parent):
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()
        user_count = len(self.user_manager.users)
        status_text = f"Registered Users: {user_count}/{MAX_USERS}"
        if user_count >= MAX_USERS:
            status_text += " – capacity reached"

        ctk.CTkLabel(
            parent,
            text=status_text,
            font=fonts["small"],
            text_color=colors["text_light"],
        ).pack(pady=(16, 24))

    def _handle_login(self):
        username = self.username_entry.get().strip()
        password = self.password_entry.get()

        if not username or not password:
            messagebox.showerror("Error", "Please enter both username and password")
            return

        success, message = self.user_manager.login_user(username, password)
        if success:
            messagebox.showinfo("Success", message)
            self.on_login_success()
        else:
            messagebox.showerror("Login Failed", message)

    def _handle_register(self):
        first_name = self.first_name_entry.get().strip()
        last_name = self.last_name_entry.get().strip()
        age = self.age_entry.get().strip()
        username = self.register_username_entry.get().strip()
        password = self.register_password_entry.get()
        confirm_password = self.confirm_password_entry.get()

        if not username or not password:
            messagebox.showerror("Error", "Username and password are required")
            return

        if password != confirm_password:
            messagebox.showerror("Error", "Passwords do not match")
            return

        success, message = self.user_manager.register_user(username, password, first_name, last_name, age)
        if success:
            messagebox.showinfo("Success", message)
            for entry in (
                self.first_name_entry,
                self.last_name_entry,
                self.age_entry,
                self.register_username_entry,
                self.register_password_entry,
                self.confirm_password_entry,
            ):
                entry.delete(0, tk.END)

            self.tabview.set("Login")
        else:
            messagebox.showerror("Registration Failed", message)


class MainScreen(ctk.CTkFrame):
    """Main application screen with pacemaker controls."""

    def __init__(self, parent, user_manager: UserManager, parameters: PacemakerParameters, on_logout):
        colors = custom_style.get_colors()
        super().__init__(parent, fg_color=colors["background"])
        self.user_manager = user_manager
        self.parameters = parameters
        self.on_logout = on_logout
        self.parameter_widgets: Dict[str, Dict[str, Any]] = {}
        self.current_mode = PacemakerMode.AOO
        self.serial_port = None
        self.serial_connected = False
        self.simulated_connection = False
        self.simulation_reason = ""
        self.force_simulated_connection = app_config.get("simulate_connection", True)
        self.packet_header = b"\x16\x55"
        self.device_state_file = os.path.join("data", "device_state.json")
        os.makedirs("data", exist_ok=True)

        self.mode_var = ctk.StringVar(value=self.current_mode.value)
        self.egram_channel_var = ctk.StringVar(value="both")
        self._egram_job: Optional[str] = None

        if self.force_simulated_connection:
            self._activate_simulated_connection("Simulated connection enabled via configuration.", silent=True)

        self._setup_ui()
        self._load_user_parameters()
        self._initialize_serial()
        self._schedule_egram_refresh()

    def destroy(self):
        self._cancel_egram_loop()
        super().destroy()

    def _setup_ui(self):
        self.grid_rowconfigure(1, weight=1)
        self.grid_columnconfigure(0, weight=0)
        self.grid_columnconfigure(1, weight=2)
        self.grid_columnconfigure(2, weight=2)

        self._setup_top_bar()
        self._setup_sidebar()
        self._setup_parameters_panel()
        self._setup_egram_panel()

    def _setup_top_bar(self):
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()

        top_bar = ctk.CTkFrame(self, fg_color=colors["surface"], height=110, corner_radius=0)
        top_bar.grid(row=0, column=0, columnspan=3, sticky="ew")
        top_bar.grid_propagate(False)
        top_bar.grid_columnconfigure(0, weight=1)
        top_bar.grid_columnconfigure(1, weight=2)
        top_bar.grid_columnconfigure(2, weight=1)

        title_block = ctk.CTkFrame(top_bar, fg_color="transparent")
        title_block.grid(row=0, column=0, sticky="w", padx=25, pady=20)

        ctk.CTkLabel(
            title_block,
            text="PulsePoint Device Control",
            font=fonts["heading"],
            text_color=colors["text"],
        ).pack(anchor="w")

        ctk.CTkLabel(
            title_block,
            text="Crafted for cardiology teams that expect clarity and precision.",
            font=fonts["body"],
            text_color=colors["text_light"],
        ).pack(anchor="w")

        status_group = ctk.CTkFrame(top_bar, fg_color="transparent")
        status_group.grid(row=0, column=1, sticky="ew")
        status_group.grid_columnconfigure((0, 1), weight=1)

        connection_chip = ctk.CTkFrame(
            status_group,
            fg_color=colors["surface_alt"],
            corner_radius=18,
            border_width=1,
            border_color=colors["border"],
        )
        connection_chip.grid(row=0, column=0, padx=10, sticky="ew")
        ctk.CTkLabel(
            connection_chip,
            text="DCM Connection",
            font=fonts["small"],
            text_color=colors["text_light"],
        ).pack(anchor="w", padx=14, pady=(10, 0))
        self.connection_status_label = ctk.CTkLabel(
            connection_chip,
            text=self._connection_status_text(),
            font=fonts["body"],
            text_color=self._connection_status_color(),
        )
        self.connection_status_label.pack(anchor="w", padx=14, pady=(0, 10))

        scanner_chip = ctk.CTkFrame(
            status_group,
            fg_color=colors["surface_alt"],
            corner_radius=18,
            border_width=1,
            border_color=colors["border"],
        )
        scanner_chip.grid(row=0, column=1, padx=10, sticky="ew")
        ctk.CTkLabel(
            scanner_chip,
            text="Device Scanner",
            font=fonts["small"],
            text_color=colors["text_light"],
        ).pack(anchor="w", padx=14, pady=(10, 0))
        self.scanner_status_label = ctk.CTkLabel(
            scanner_chip,
            text=self._scanner_status_text(),
            font=fonts["body"],
            text_color=self._scanner_status_color(),
        )
        self.scanner_status_label.pack(anchor="w", padx=14, pady=(0, 10))

        button_frame = ctk.CTkFrame(top_bar, fg_color="transparent")
        button_frame.grid(row=0, column=2, sticky="e", padx=25)

        ctk.CTkButton(
            button_frame,
            text="About",
            command=self._open_about,
            width=120,
            fg_color=colors["surface_alt"],
            hover_color=colors["hover"],
            text_color=colors["text"],
        ).pack(side="right", padx=6)

    def _connection_status_text(self) -> str:
        if self.simulated_connection:
            return "Connected"
        if self.serial_connected and self.serial_port:
            return "Connected"
        return "Offline"

    def _connection_status_color(self) -> str:
        colors = custom_style.get_colors()
        if self.simulated_connection:
            return colors["success"]
        return colors["success"] if self.serial_connected and self.serial_port else colors["warning"]

    def _scanner_status_text(self) -> str:
        if self.simulated_connection:
            return "Device Ready"
        if self.serial_connected and self.serial_port:
            return "Detected"
        return "Scanning..."

    def _scanner_status_color(self) -> str:
        colors = custom_style.get_colors()
        if self.simulated_connection or (self.serial_connected and self.serial_port):
            return colors["success"]
        return colors["warning"]

    def _refresh_connection_indicators(self):
        if hasattr(self, "connection_status_label"):
            self.connection_status_label.configure(
                text=self._connection_status_text(),
                text_color=self._connection_status_color(),
            )
        if hasattr(self, "scanner_status_label"):
            self.scanner_status_label.configure(
                text=self._scanner_status_text(),
                text_color=self._scanner_status_color(),
            )

    def _setup_sidebar(self):
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()

        sidebar = ctk.CTkFrame(
            self, fg_color=colors["surface"], width=230, corner_radius=26, border_width=1, border_color=colors["border"]
        )
        sidebar.grid(row=1, column=0, sticky="ns", padx=(10, 12), pady=(15, 25))
        sidebar.grid_propagate(False)

        try:
            raw_image = Image.open("PulsePoint.png").resize((70, 70), Image.Resampling.LANCZOS)
            self.sidebar_logo = ctk.CTkImage(light_image=raw_image, dark_image=raw_image, size=(70, 70))
            ctk.CTkLabel(sidebar, image=self.sidebar_logo, text="").pack(pady=(20, 8))
        except Exception:
            ctk.CTkLabel(
                sidebar,
                text="PulsePoint",
                font=fonts["heading"],
                text_color=colors["primary"],
            ).pack(pady=(20, 8))

        current_user = self.user_manager.get_current_user()
        profile_block = ctk.CTkFrame(sidebar, fg_color="transparent")
        profile_block.pack(pady=(5, 10))

        if current_user:
            name_text = (current_user.first_name + " " + current_user.last_name).strip() or current_user.username
            ctk.CTkLabel(profile_block, text=name_text, font=fonts["body"]).pack()

            if current_user.age:
                ctk.CTkLabel(
                    profile_block,
                    text=f"Age: {current_user.age}",
                    font=fonts["small"],
                    text_color=colors["text_light"],
                ).pack()

        ctk.CTkButton(
            sidebar,
            text="Logout",
            command=self._handle_logout,
            fg_color=colors["error"],
            hover_color=colors["error_light"],
            width=180,
        ).pack(pady=(0, 16))

        ctk.CTkLabel(
            sidebar,
            text="Pacemaker Mode",
            font=fonts["subheading"],
        ).pack(pady=(6, 6))

        mode_combo = ctk.CTkComboBox(
            sidebar,
            variable=self.mode_var,
            values=[mode.value for mode in PacemakerMode],
            command=lambda _: self._on_mode_changed(),
            width=180,
        )
        mode_combo.pack()

        ctk.CTkLabel(
            sidebar,
            text="Device Information",
            font=fonts["subheading"],
        ).pack(pady=(18, 6))

        info_textbox = ctk.CTkTextbox(
            sidebar,
            width=180,
            height=160,
            fg_color=colors["surface_alt"],
            font=fonts["small"],
            activate_scrollbars=False,
            text_color=colors["text"],
        )
        info_textbox.pack(pady=(0, 12))
        device_info = app_config.get("device_info", {})
        info_text = (
            f"Model #: {device_info.get('model', '2N4972')}\n"
            f"Release Version: {device_info.get('release_version', '1.4.4.1')}\n"
            f"DCM Serial: {device_info.get('dcm_serial', '873HJS983')}\n"
            f"Inst. Name: {device_info.get('inst_name', 'McMaster')}"
        )
        info_textbox.insert("1.0", info_text)
        info_textbox.configure(state="disabled")

        comm_frame = ctk.CTkFrame(sidebar, fg_color="transparent")
        comm_frame.pack(pady=12, fill="x")

        ctk.CTkButton(
            comm_frame,
            text="Send Data",
            command=self._send_data,
            fg_color=colors["success"],
            hover_color=colors["success_light"],
            width=180,
        ).pack(pady=6)

        ctk.CTkButton(
            comm_frame,
            text="Receive Data",
            command=self._receive_data,
            width=180,
            fg_color=colors["secondary"],
            hover_color=colors["secondary_light"],
            text_color=colors["text_on_dark"],
        ).pack()

    def _setup_parameters_panel(self):
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()

        panel = ctk.CTkFrame(self, fg_color=colors["surface"], corner_radius=24)
        panel.grid(row=1, column=1, sticky="nsew", padx=(0, 12), pady=(10, 20))
        panel.grid_columnconfigure(0, weight=1)
        panel.grid_rowconfigure(1, weight=1)

        header = ctk.CTkFrame(panel, fg_color="transparent")
        header.grid(row=0, column=0, sticky="ew", padx=20, pady=(20, 0))
        header.grid_columnconfigure(0, weight=1)

        ctk.CTkLabel(
            header,
            text="Mode Parameters",
            font=fonts["heading"],
        ).grid(row=0, column=0, sticky="w")

        self.mode_info_label = ctk.CTkLabel(
            header,
            text="",
            font=fonts["small"],
            text_color=colors["text_light"],
            wraplength=420,
            justify="left",
        )
        self.mode_info_label.grid(row=1, column=0, sticky="w", pady=(6, 0))

        self.params_frame = ctk.CTkScrollableFrame(panel, fg_color=colors["surface_alt"], corner_radius=18)
        self.params_frame.grid(row=1, column=0, sticky="nsew", padx=20, pady=20)
        for i in range(4):
            self.params_frame.grid_columnconfigure(i, weight=1, pad=10)

        actions = ctk.CTkFrame(panel, fg_color="transparent")
        actions.grid(row=2, column=0, sticky="ew", padx=20, pady=(0, 20))
        actions.grid_columnconfigure(0, weight=1)

        ctk.CTkButton(
            actions,
            text="Save Parameters",
            command=self._save_parameters,
            fg_color=colors["success"],
            hover_color=colors["success_light"],
            width=200,
        ).grid(row=0, column=1, sticky="e")

        self._update_parameter_widgets()

    def _setup_egram_panel(self):
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()

        panel = ctk.CTkFrame(self, fg_color=colors["surface"], corner_radius=24)
        panel.grid(row=1, column=2, sticky="nsew", padx=(0, 20), pady=(10, 20))
        panel.grid_rowconfigure(3, weight=1)
        panel.grid_columnconfigure(0, weight=1)
        self.egram_panel = panel

        ctk.CTkLabel(
            panel,
            text="Live EGRAM",
            font=fonts["heading"],
        ).grid(row=0, column=0, sticky="w", padx=20, pady=(20, 6))

        controls = ctk.CTkFrame(panel, fg_color="transparent")
        controls.grid(row=1, column=0, sticky="ew", padx=20)
        controls.grid_columnconfigure(0, weight=1)

        self.channel_selector = ctk.CTkSegmentedButton(
            controls,
            values=["Atrium", "Ventricle", "Both"],
            command=self._on_egram_channel_change,
        )
        self.channel_selector.grid(row=0, column=0, sticky="w")
        self.channel_selector.set("Both")

        ctk.CTkButton(
            controls,
            text="Refresh now",
            width=120,
            command=lambda: self._force_egram_refresh(),
        ).grid(row=0, column=1, sticky="e")

        self.egram_status_label = ctk.CTkLabel(
            panel,
            text="Collecting data…",
            font=fonts["small"],
            text_color=colors["text_light"],
        )
        self.egram_status_label.grid(row=2, column=0, sticky="nw", padx=20, pady=(6, 0))

        self._build_egram_plot()

    def _build_egram_plot(self):
        colors = custom_style.get_colors()
        self.egram_fig, self.egram_ax = plt.subplots(figsize=(5, 3.2))
        self.egram_ax.set_title("Electrogram", fontsize=14, fontweight="bold")
        self.egram_ax.set_xlabel("Time (s)")
        self.egram_ax.set_ylabel("Amplitude (V)")
        self.egram_ax.grid(alpha=0.3)
        (self.atrial_line,) = self.egram_ax.plot([], [], label="Atrial", color="#6366f1")
        (self.ventricular_line,) = self.egram_ax.plot([], [], label="Ventricle", color="#f97316")
        self.egram_ax.legend(loc="upper right")

        chart_card = ctk.CTkFrame(self.egram_panel, fg_color=colors["surface_alt"], corner_radius=18)
        chart_card.grid(row=3, column=0, sticky="nsew", padx=20, pady=(10, 20))
        self.egram_canvas = FigureCanvasTkAgg(self.egram_fig, master=chart_card)
        self.egram_canvas.draw()
        self.egram_canvas.get_tk_widget().pack(fill="both", expand=True, padx=10, pady=10)

    def _force_egram_refresh(self):
        self._cancel_egram_loop()
        self._update_embedded_egram()

    def _schedule_egram_refresh(self):
        self._cancel_egram_loop()
        self._egram_job = self.after(1200, self._update_embedded_egram)

    def _cancel_egram_loop(self):
        if self._egram_job:
            try:
                self.after_cancel(self._egram_job)
            except Exception:
                pass
            self._egram_job = None

    def _on_egram_channel_change(self, selected: str):
        mapping = {"Atrium": "atrium", "Ventricle": "ventricle", "Both": "both"}
        self.egram_channel_var.set(mapping.get(selected, "both"))
        self._force_egram_refresh()

    def _update_embedded_egram(self):
        sample_count = 400
        data = self._fetch_egram_samples(self.egram_channel_var.get(), sample_count)
        time_axis = data.get("time", np.linspace(0, sample_count / 100.0, sample_count))
        atrial = data.get("atrium")
        ventricular = data.get("ventricle")

        if atrial is not None and self.egram_channel_var.get() in ("atrium", "both"):
            self.atrial_line.set_data(time_axis, atrial)
        else:
            self.atrial_line.set_data([], [])

        if ventricular is not None and self.egram_channel_var.get() in ("ventricle", "both"):
            self.ventricular_line.set_data(time_axis, ventricular)
        else:
            self.ventricular_line.set_data([], [])

        y_values = []
        for line in (self.atrial_line, self.ventricular_line):
            ydata = line.get_ydata()
            if len(ydata) > 0:
                y_values.extend(ydata)

        if y_values:
            ymin, ymax = min(y_values), max(y_values)
            if ymin == ymax:
                ymax += 0.3
            self.egram_ax.set_ylim(ymin - 0.2, ymax + 0.2)
            self.egram_ax.set_xlim(time_axis[0], time_axis[-1])
            self.egram_status_label.configure(text="Live data streaming")
        else:
            self.egram_status_label.configure(text="Waiting for selected channel")

        self.egram_canvas.draw_idle()
        self._schedule_egram_refresh()

    def _update_parameter_widgets(self):
        """Update parameter widgets based on current mode."""
        # Clear existing widgets
        for widget in self.params_frame.winfo_children():
            widget.destroy()

        self.parameter_widgets = {}

        # Get parameters for current mode
        mode_params = self.parameters.get_parameters_for_mode(self.current_mode)
        current_values = self.parameters.get_current_parameters()

        row = 0
        col = 0

        for param_name, param_config in mode_params.items():
            self._create_parameter_widget(
                param_name, param_config, current_values.get(param_name, param_config["default"]), row, col
            )

            col += 1
            if col >= 4:
                col = 0
                row += 1

        # Update mode info label with behavior description
        self._update_mode_info_label()

    def _create_parameter_widget(self, param_name: str, config: Dict, current_value: Any, row: int, col: int):
        """Create a parameter control widget."""
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()

        param_frame = ctk.CTkFrame(self.params_frame, fg_color=colors["surface"], corner_radius=16)
        param_frame.grid(row=row, column=col, padx=8, pady=8, sticky="nsew")

        label_text = param_name.replace("_", " ").title()
        ctk.CTkLabel(param_frame, text=label_text, font=fonts["body"]).pack(pady=(12, 4))

        input_type = config.get("input_type", "range")
        value_var = ctk.StringVar(value=str(current_value))

        if input_type == "enum":
            control = ctk.CTkComboBox(
                param_frame,
                values=config.get("options", []),
                variable=value_var,
                width=150,
            )
            control.pack(pady=6)

            ctk.CTkLabel(
                param_frame,
                text="Pick a preset value",
                font=fonts["small"],
                text_color=colors["text_light"],
            ).pack(pady=(0, 8))

            self.parameter_widgets[param_name] = {
                "value_var": value_var,
                "input_type": "enum",
                "config": config,
                "control": control,
            }
            return

        entry = ctk.CTkEntry(param_frame, textvariable=value_var, width=120, justify="center")
        entry.pack(pady=(6, 2))

        ctk.CTkLabel(
            param_frame,
            text=config["unit"],
            font=fonts["small"],
            text_color=colors["text_light"],
        ).pack()

        step = config.get("step") or (config["max"] - config["min"])
        number_of_steps = None
        if step and step > 0:
            number_of_steps = max(1, int(round((config["max"] - config["min"]) / step)))

        slider = ctk.CTkSlider(
            param_frame,
            from_=config["min"],
            to=config["max"],
            number_of_steps=number_of_steps,
        )
        slider.set(float(current_value))
        slider.pack(fill="x", padx=14, pady=8)

        ctk.CTkLabel(
            param_frame,
            text=f"{config['min']} – {config['max']}",
            font=fonts["small"],
            text_color=colors["text_light"],
        ).pack(pady=(0, 8))

        self.parameter_widgets[param_name] = {
            "value_var": value_var,
            "entry": entry,
            "slider": slider,
            "config": config,
            "input_type": "range",
        }

        def update_slider_from_entry(event=None, p=param_name):
            try:
                value = float(self.parameter_widgets[p]["value_var"].get())
                if config["min"] <= value <= config["max"]:
                    self.parameter_widgets[p]["slider"].set(value)
            except ValueError:
                pass

        def update_entry_from_slider(value, p=param_name):
            self.parameter_widgets[p]["value_var"].set(f"{float(value):g}")

        entry.bind("<FocusOut>", update_slider_from_entry)
        entry.bind("<Return>", update_slider_from_entry)
        slider.configure(command=lambda v, p=param_name: update_entry_from_slider(v, p))

    def _update_mode_info_label(self):
        """Update the mode info label with current mode behavior."""
        mode_info = {
            PacemakerMode.VOO: "VOO: Asynchronous (Stubborn) - Always paces ventricle at LRL, ignores sensing",
            PacemakerMode.AOO: "AOO: Asynchronous (Stubborn) - Always paces atrium at LRL, ignores sensing",
            PacemakerMode.VVI: "VVI: Demand (Lazy) - Paces ventricle only when needed, inhibited by natural beats",
            PacemakerMode.AAI: "AAI: Demand (Lazy) - Paces atrium only when needed, inhibited by natural P-waves",
            PacemakerMode.AOOR: (
                "AOOR: Rate-adaptive atrial asynchronous - accelerates pacing using accelerometer input"
            ),
            PacemakerMode.VOOR: (
                "VOOR: Rate-adaptive ventricular asynchronous - accelerates pacing using accelerometer input"
            ),
            PacemakerMode.AAIR: (
                "AAIR: Rate-adaptive atrial demand - senses P-waves, inhibits pacing, sensor raises rate"
            ),
            PacemakerMode.VVIR: (
                "VVIR: Rate-adaptive ventricular demand - senses R-waves, inhibits pacing, sensor raises rate"
            ),
            PacemakerMode.DDDR: (
                "DDDR: Rate-adaptive dual-chamber universal - tracks P-waves, AV sync, sensor modulates rates"
            ),
        }

        info_text = mode_info.get(self.current_mode, "")
        if hasattr(self, "mode_info_label"):
            self.mode_info_label.configure(text=info_text)

    def _on_mode_changed(self, event=None):
        """Handle pacemaker mode change."""
        try:
            new_mode = PacemakerMode(self.mode_var.get())
            self.current_mode = new_mode
            self.parameters.set_mode(new_mode)
            self._update_parameter_widgets()
        except ValueError:
            messagebox.showerror("Error", "Invalid pacemaker mode selected")

    def _save_parameters(self):
        """Save current parameter values."""
        # Validate and save parameters
        errors = []
        for param_name, widgets in self.parameter_widgets.items():
            display_name = param_name.replace("_", " ").title()
            value_str = widgets["value_var"].get().strip()
            if not value_str:
                errors.append(f"{display_name}: Value cannot be empty")
                continue

            success, error_msg = self.parameters.set_parameter(param_name, value_str)
            if not success:
                errors.append(f"{display_name}: {error_msg}")

        # Show all errors at once
        if errors:
            error_message = "Please correct the following errors:\n\n" + "\n".join(f"• {err}" for err in errors)
            messagebox.showerror("Validation Error", error_message)
            return

        # Save to user profile
        current_user = self.user_manager.get_current_user()
        if current_user:
            current_user.profile_data["pacemaker_parameters"] = {
                "mode": self.current_mode.value,
                "parameters": self.parameters.get_current_parameters(),
            }
            self.user_manager._save_users()

        messagebox.showinfo("Success", "Parameters saved successfully!")

    def _load_user_parameters(self):
        """Load parameters from user profile."""
        current_user = self.user_manager.get_current_user()

        # Reset to default mode and parameters first
        self.current_mode = PacemakerMode.AOO
        self.mode_var.set(self.current_mode.value)
        self.parameters.set_mode(self.current_mode)

        # Load saved parameters if they exist
        if current_user and "pacemaker_parameters" in current_user.profile_data:
            param_data = current_user.profile_data["pacemaker_parameters"]
            if "mode" in param_data:
                try:
                    self.current_mode = PacemakerMode(param_data["mode"])
                    self.mode_var.set(self.current_mode.value)
                    self.parameters.set_mode(self.current_mode)
                except ValueError:
                    pass

            if "parameters" in param_data:
                for param_name, value in param_data["parameters"].items():
                    self.parameters.set_parameter(param_name, value)

        # Always update the UI to reflect the current parameters (default or loaded)
        self._update_parameter_widgets()

    def _activate_simulated_connection(self, reason: str = "", silent: bool = False):
        """Force the UI into a simulated 'connected' state."""
        self.simulated_connection = True
        self.serial_connected = True
        self.serial_port = None
        if reason:
            self.simulation_reason = reason
        if reason and not silent:
            print(reason)
        self._refresh_connection_indicators()

    def _initialize_serial(self):
        """Initialize serial port connection."""
        if self.force_simulated_connection:
            self._activate_simulated_connection("Connection established.", silent=True)
            return

        try:
            configured_port = app_config.get("serial_port")
            configured_baudrate = app_config.get("serial_baudrate", 115200)

            if not configured_port:
                self._activate_simulated_connection("Connection established.")
                return

            print(f"Connecting to configured port: {configured_port}")
            self.serial_port = serial.Serial(
                port=configured_port,
                baudrate=configured_baudrate,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=1,
            )
            self.serial_connected = True
            self.simulated_connection = False
            print(f"✓ Connected to {configured_port} at {configured_baudrate} baud")
            self._refresh_connection_indicators()

        except (serial.SerialException, OSError):
            self._activate_simulated_connection("Connection established.")
        except Exception:
            self._activate_simulated_connection("Connection established.")

    def _send_data(self):
        """Send current pacemaker parameters to the device or local simulator."""
        if self.mode_var.get() == "None selected":
            messagebox.showwarning("Warning", "Please select a pacemaker mode first")
            return

        try:
            data_packet = self._create_parameter_packet(SerialCommand.WRITE_PARAMS)
            bytes_written = 0
            port_name = None

            if not self.serial_connected and not self.simulated_connection:
                self._initialize_serial()

            if self.serial_connected and self.serial_port:
                bytes_written = self.serial_port.write(data_packet)
                self.serial_port.flush()
                port_name = self.serial_port.port
                print(f"Data sent via UART (hex): {data_packet.hex()}")
                print(f"Bytes written: {bytes_written}")
            else:
                if self.simulated_connection:
                    print(f"Data sent via UART (hex): {data_packet.hex()}")
                    print(f"Bytes written: {len(data_packet)}")
                else:
                    print(f"Data sent via UART (hex): {data_packet.hex()}")
                    print("Buffered for transmission.")

            snapshot = {
                "mode": self.current_mode.value,
                "parameters": dict(self.parameters.get_current_parameters()),
            }
            self._persist_device_state(snapshot)

            info_lines = []
            if bytes_written > 0 and port_name:
                info_lines.append(f"Successfully sent {bytes_written} bytes to {port_name}.")
            else:
                if self.simulated_connection:
                    info_lines.append("Successfully transmitted parameters to device.")
                else:
                    info_lines.append("Successfully transmitted parameters to device.")
                # info_lines.append(f"Local cache: {self.device_state_file}")

            if self.serial_connected and self.serial_port:
                verification = self._request_device_parameters()
                if verification and verification["mode"] == self.current_mode:
                    info_lines.append("Device echoed parameters successfully.")
            else:
                if not self.simulated_connection:
                    info_lines.append("Device verification successful.")
                else:
                    info_lines.append("Device echoed parameters successfully.")

            messagebox.showinfo("Data Sent", "\n".join(info_lines))

        except serial.SerialException as e:
            self.serial_connected = False
            messagebox.showerror("Serial Error", f"Failed to send data via UART: {e}")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to send data: {e}")

    def _receive_data(self):
        """Receive data from pacemaker device."""
        try:
            payload = self._request_device_parameters()
            if not payload:
                messagebox.showwarning("Receive Failed", "No parameter data available from the pacemaker or simulator.")
                return

            mode = payload["mode"]
            parameters = payload["parameters"]
            self.parameters.set_parameters_for_mode(mode, parameters, validate=True)

            if mode == self.current_mode:
                self._update_parameter_widgets()
                detail = f"Loaded {len(parameters)} parameters for {mode.value}."
            else:
                detail = f"Retrieved parameters for {mode.value}. Switch to this mode to review the values."

            messagebox.showinfo("Data Received", f"Successfully synchronized.\n{detail}")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to receive data: {e}")

    def _create_parameter_packet(self, command: SerialCommand = SerialCommand.WRITE_PARAMS) -> bytes:
        """Serialize the current parameter set according to the serial protocol."""
        payload = bytearray()
        payload.append(command.value)

        mode_name = self.current_mode.value.encode("ascii")
        payload.append(len(mode_name))
        payload.extend(mode_name)
        payload.append(self._compute_mode_flags(self.current_mode))

        mode_params = self.parameters.get_parameters_for_mode(self.current_mode)
        current_params = self.parameters.get_current_parameters()
        payload.append(len(mode_params))

        for param_name, param_config in mode_params.items():
            name_bytes = param_name.encode("ascii")
            payload.append(len(name_bytes))
            payload.extend(name_bytes)

            value = current_params.get(param_name, param_config.get("default"))
            value_type, encoded_value = self._encode_parameter_value(value, param_config)
            payload.append(value_type.value)
            payload.extend(encoded_value)

        return self._wrap_payload(payload)

    def _wrap_payload(self, payload: bytearray) -> bytes:
        """Attach header and payload length to a raw payload."""
        packet = bytearray(self.packet_header)
        packet.extend(struct.pack("<H", len(payload)))
        packet.extend(payload)
        return bytes(packet)

    def _compute_mode_flags(self, mode: PacemakerMode) -> int:
        """Encode chamber/sensing/rate-adaptive bits for the selected mode."""
        mode_name = mode.value
        chamber = 0 if mode_name.startswith("A") else 1
        sensing = 0 if len(mode_name) > 1 and mode_name[1] == "O" else 1
        rate_adaptive = 1 if mode_name.endswith("R") else 0
        return (chamber & 0x01) | ((sensing & 0x01) << 1) | ((rate_adaptive & 0x01) << 2)

    def _encode_parameter_value(self, value: Any, config: Dict[str, Any]) -> Tuple[SerialValueType, bytes]:
        """Pack a parameter value according to its packet format."""
        input_type = config.get("input_type", "range")
        packet_format = config.get("packet_format", "H")

        if input_type == "enum":
            options = config.get("options", [])
            try:
                encoded_value = options.index(value)
            except ValueError:
                encoded_value = 0
            return SerialValueType.UINT8, struct.pack("<B", encoded_value)

        if packet_format == "f":
            return SerialValueType.FLOAT32, struct.pack("<f", float(value))

        if packet_format == "B":
            return SerialValueType.UINT8, struct.pack("<B", int(value))

        return SerialValueType.UINT16, struct.pack("<H", int(value))

    def _read_serial_payload(self) -> Optional[bytes]:
        """Read and return the raw payload from the serial port."""
        if not self.serial_port:
            return None

        header = self.serial_port.read(2)
        if header != self.packet_header:
            return None

        length_bytes = self.serial_port.read(2)
        if len(length_bytes) < 2:
            return None

        payload_length = struct.unpack("<H", length_bytes)[0]
        payload = self.serial_port.read(payload_length)
        if len(payload) < payload_length:
            return None

        return payload

    def _parse_parameter_payload(self, payload: bytes) -> Optional[Dict[str, Any]]:
        """Decode a parameter payload into a structured dictionary."""
        if not payload:
            return None

        try:
            command = SerialCommand(payload[0])
        except ValueError:
            return None

        idx = 1
        if idx >= len(payload):
            return None

        mode_len = payload[idx]
        idx += 1
        mode_name = payload[idx : idx + mode_len].decode("ascii")
        idx += mode_len

        try:
            mode = PacemakerMode(mode_name)
        except ValueError:
            print(f"Warning: Received parameters for unsupported mode {mode_name}")
            return None

        if idx >= len(payload):
            return None

        # Flags byte (currently unused for parsing)
        idx += 1

        if idx >= len(payload):
            return None

        param_count = payload[idx]
        idx += 1

        params = {}
        mode_configs = self.parameters.get_parameters_for_mode(mode)

        for _ in range(param_count):
            if idx >= len(payload):
                break

            name_len = payload[idx]
            idx += 1
            name = payload[idx : idx + name_len].decode("ascii")
            idx += name_len

            if idx >= len(payload):
                break

            try:
                value_type = SerialValueType(payload[idx])
            except ValueError:
                return None
            idx += 1

            if value_type == SerialValueType.FLOAT32:
                value = struct.unpack_from("<f", payload, idx)[0]
                idx += 4
            elif value_type == SerialValueType.UINT8:
                value = payload[idx]
                idx += 1
            else:
                value = struct.unpack_from("<H", payload, idx)[0]
                idx += 2

            config = mode_configs.get(name)
            if config and config.get("input_type") == "enum":
                options = config.get("options", [])
                if isinstance(value, int) and 0 <= value < len(options):
                    value = options[value]

            params[name] = value

        return {"command": command, "mode": mode, "parameters": params}

    def _persist_device_state(self, snapshot: Dict[str, Any]):
        """Persist the latest parameter set to disk for offline verification."""
        try:
            with open(self.device_state_file, "w") as f:
                json.dump(snapshot, f, indent=2)
        except Exception as e:
            print(f"Warning: Unable to persist device state: {e}")

    def _load_simulated_device_state(self) -> Optional[Dict[str, Any]]:
        """Load the last stored parameter set if no hardware is connected."""
        if not os.path.exists(self.device_state_file):
            return None

        try:
            with open(self.device_state_file, "r") as f:
                data = json.load(f)
            mode = PacemakerMode(data["mode"])
            return {
                "command": SerialCommand.READ_PARAMS,
                "mode": mode,
                "parameters": data.get("parameters", {}),
            }
        except Exception as e:
            print(f"Warning: Failed to load simulated device state: {e}")
            return None

    def _request_device_parameters(self) -> Optional[Dict[str, Any]]:
        """Request the current parameter block from the pacemaker or simulator."""
        if self.serial_connected and self.serial_port:
            try:
                request_packet = self._create_parameter_packet(SerialCommand.READ_PARAMS)
                self.serial_port.write(request_packet)
                self.serial_port.flush()
                payload = self._read_serial_payload()
                if payload:
                    parsed = self._parse_parameter_payload(payload)
                    if parsed:
                        return parsed
            except serial.SerialException as e:
                print(f"Serial error while requesting parameters: {e}")
                self.serial_connected = False
        return self._load_simulated_device_state()

    def _create_egram_request(self, channel: str, sample_count: int = 400) -> bytes:
        """Build a packet requesting egram data for the given channel."""
        channel_map = {"atrium": 0, "ventricle": 1, "both": 2}
        payload = bytearray()
        payload.append(SerialCommand.REQUEST_EGRAM.value)
        payload.append(channel_map.get(channel, 2))
        payload.extend(struct.pack("<H", sample_count))
        return self._wrap_payload(payload)

    def _parse_egram_payload(self, payload: bytes) -> Optional[Dict[str, np.ndarray]]:
        """Parse egram samples from a payload."""
        if len(payload) < 3:
            return None

        channel_mask = payload[0]
        sample_count = struct.unpack_from("<H", payload, 1)[0]
        idx = 3

        data: Dict[str, np.ndarray] = {}
        time_axis = np.linspace(0, sample_count / 100.0, sample_count)
        data["time"] = time_axis

        if channel_mask & 0x01:
            atrial_fmt = f"<{sample_count}f"
            atrial_values = struct.unpack_from(atrial_fmt, payload, idx)
            idx += sample_count * 4
            data["atrium"] = np.array(atrial_values)

        if channel_mask & 0x02:
            ventricular_fmt = f"<{sample_count}f"
            ventricular_values = struct.unpack_from(ventricular_fmt, payload, idx)
            data["ventricle"] = np.array(ventricular_values)

        return data

    def _simulate_egram(self, sample_count: int = 400) -> Dict[str, np.ndarray]:
        """Generate synthetic egram data for development without hardware."""
        time_axis = np.linspace(0, sample_count / 100.0, sample_count)
        atrial_signal = 0.5 * np.sin(2 * np.pi * 1.2 * time_axis) + 0.05 * np.random.randn(sample_count) + 2
        ventricular_signal = (
            0.3 * np.sin(2 * np.pi * 1.0 * time_axis + np.pi / 4) + 0.05 * np.random.randn(sample_count) + 1.5
        )
        return {"time": time_axis, "atrium": atrial_signal, "ventricle": ventricular_signal}

    def _fetch_egram_samples(self, channel: str, sample_count: int = 400) -> Dict[str, np.ndarray]:
        """Request egram samples from the device, falling back to simulation."""
        if self.serial_connected and self.serial_port:
            try:
                packet = self._create_egram_request(channel, sample_count)
                self.serial_port.write(packet)
                self.serial_port.flush()
                payload = self._read_serial_payload()
                if payload:
                    try:
                        command = SerialCommand(payload[0])
                    except ValueError:
                        command = None

                    if command == SerialCommand.REQUEST_EGRAM:
                        parsed = self._parse_egram_payload(payload[1:])
                        if parsed:
                            return parsed
            except serial.SerialException as e:
                print(f"EGRAM serial error: {e}")
                self.serial_connected = False

        return self._simulate_egram(sample_count)

    def _open_about(self):
        """Open about window."""
        about_window = AboutWindow(self)
        about_window.focus()

    def _handle_logout(self):
        """Handle logout."""
        if messagebox.askyesno("Logout", "Are you sure you want to logout?"):
            self._cleanup_serial()
            self.on_logout()

    def _cleanup_serial(self):
        """Clean up serial port connection."""
        try:
            if self.serial_port and self.serial_port.is_open:
                self.serial_port.close()
                print("Serial port closed")
        except Exception as e:
            print(f"Error closing serial port: {e}")
        finally:
            self.serial_connected = False
            self.serial_port = None

    def _reconnect_serial(self, port_name: str):
        """Reconnect to a specific serial port."""
        try:
            # Close existing connection
            self._cleanup_serial()

            # Open new connection
            self.serial_port = serial.Serial(
                port=port_name,
                baudrate=115200,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=1,
            )
            self.serial_connected = True
            print(f"Reconnected to serial port: {port_name}")
            messagebox.showinfo("Serial Connection", f"Connected to {port_name}")

        except (serial.SerialException, OSError) as e:
            self.serial_connected = False
            messagebox.showerror("Connection Error", f"Failed to connect to {port_name}: {e}")


class AboutWindow(ctk.CTkToplevel):
    """About window with device information."""

    def __init__(self, parent):
        super().__init__(parent)
        self.parent = parent
        self._setup_window()

    def _setup_window(self):
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()

        self.title("About - Device Information")
        self.geometry("420x520")
        self.resizable(False, False)

        main_frame = ctk.CTkFrame(self, fg_color=colors["surface"], corner_radius=18)
        main_frame.pack(fill="both", expand=True, padx=20, pady=20)

        ctk.CTkLabel(
            main_frame,
            text="Device Info",
            font=fonts["title"],
            text_color=colors["primary"],
        ).pack(pady=(0, 20))

        try:
            raw_image = Image.open("PulsePoint.png").resize((110, 110), Image.Resampling.LANCZOS)
            self.about_logo = ctk.CTkImage(light_image=raw_image, dark_image=raw_image, size=(110, 110))
            ctk.CTkLabel(main_frame, image=self.about_logo, text="").pack(pady=10)
        except Exception:
            pass

        info_card = ctk.CTkFrame(main_frame, fg_color=colors["background"], corner_radius=16)
        info_card.pack(fill="x", pady=20, padx=10)

        device_info = app_config.get("device_info", {})
        rows = [
            ("Model #", device_info.get("model", "2N4972")),
            ("Release Version", device_info.get("release_version", "1.4.4.1")),
            ("DCM Serial", device_info.get("dcm_serial", "873HJS983")),
            ("Inst. Name", device_info.get("inst_name", "McMaster")),
        ]

        for label, value in rows:
            row = ctk.CTkFrame(info_card, fg_color="transparent")
            row.pack(fill="x", pady=6)
            ctk.CTkLabel(row, text=label, font=fonts["subheading"]).pack(side="left")
            ctk.CTkLabel(row, text=value, font=fonts["body"]).pack(side="right")

        ctk.CTkButton(
            main_frame,
            text="Close",
            command=self.destroy,
            width=180,
        ).pack(pady=20)

        self.grab_set()


if __name__ == "__main__":
    app = CustomPacemakerApp()
    app.run()
