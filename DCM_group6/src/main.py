"""Custom Pacemaker Device Controller-Monitor Application

A comprehensive pacemaker simulation system built with custom tkinter styling,
featuring user authentication, parameter management, and device communication.
"""

import json
import os
import struct
import tkinter as tk
from dataclasses import dataclass
from enum import Enum
from tkinter import messagebox, ttk
from typing import Any, Dict, Optional, Tuple

import matplotlib.pyplot as plt
import numpy as np
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from PIL import Image, ImageTk

from config_loader import config

# Load configuration constants
app_config = config.get_app_config()
USER_FILE = app_config.get("user_file", "data/users.json")
CSV_FILE = app_config.get("csv_file", "data/pacemaker_settings.csv")
MAX_USERS = app_config.get("max_users", 10)


class PacemakerMode(Enum):
    """Supported pacemaker modes."""

    AOO = "AOO"
    VOO = "VOO"
    AAI = "AAI"
    VVI = "VVI"


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

        new_user = User(username=username, password=password, first_name=first_name, last_name=last_name, age=age)
        self.users[username] = new_user
        self._save_users()

        return True, "User registered successfully"

    def login_user(self, username: str, password: str) -> Tuple[bool, str]:
        """Authenticate a user."""
        if username not in self.users:
            return False, "User not found"

        user = self.users[username]
        if user.password != password:
            return False, "Invalid password"

        self.current_user = user
        return True, "Login successful"

    def logout_user(self):
        """Logout current user."""
        self.current_user = None

    def get_current_user(self) -> Optional[User]:
        """Get currently logged in user."""
        return self.current_user


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

    def get_current_parameters(self) -> Dict[str, float]:
        """Get current parameter values for the active mode."""
        return self.parameters.get(self.current_mode.value, {})

    def set_parameter(self, param_name: str, value: float) -> Tuple[bool, str]:
        """Set a parameter value with validation."""
        if self.current_mode.value not in self.parameters:
            return False, "Invalid mode"

        mode_params = self.MODE_PARAMETERS.get(self.current_mode, {})
        if param_name not in mode_params:
            return False, f"Parameter {param_name} not available for mode {self.current_mode.value}"

        config = mode_params[param_name]

        # Validate value
        if value < config["min"] or value > config["max"]:
            return False, f"Value must be between {config['min']} and {config['max']} {config['unit']}"

        # Validate step (with tolerance for floating point precision)
        if config["step"] > 0:
            steps = (value - config["min"]) / config["step"]
            # Allow small floating point errors
            if abs(steps - round(steps)) > 0.0001:
                return False, f"Value must be in increments of {config['step']} {config['unit']}"

        self.parameters[self.current_mode.value][param_name] = value
        return True, ""

    def set_mode(self, mode: PacemakerMode):
        """Set the current pacemaker mode."""
        self.current_mode = mode

    def get_mode(self) -> PacemakerMode:
        """Get the current pacemaker mode."""
        return self.current_mode


class CustomPacemakerApp:
    """Main application class with custom tkinter styling."""

    def __init__(self):
        self.root = tk.Tk()
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
        self.root.minsize(1000, 600)

        # Configure custom styling
        self._configure_styles()

        # Configure grid
        self.root.grid_rowconfigure(0, weight=1)
        self.root.grid_columnconfigure(0, weight=1)

        # Set application icon if available
        try:
            self.root.iconbitmap("PulsePoint.ico")
        except:
            pass

    def _configure_styles(self):
        """Configure custom tkinter styles."""
        style = ttk.Style()

        # Configure custom styles
        colors = custom_style.get_colors()
        fonts = custom_style.get_fonts()
        style.configure("Title.TLabel", font=fonts["title"], foreground=colors["primary"])

        style.configure("Heading.TLabel", font=fonts["heading"], foreground=colors["text"])

        style.configure("Body.TLabel", font=fonts["body"], foreground=colors["text"])

        style.configure(
            "Primary.TButton",
            font=fonts["button"],
            foreground=colors["text_on_dark"],
            background=colors["primary"],
        )

        style.configure(
            "Secondary.TButton",
            font=fonts["button"],
            foreground=colors["text_on_dark"],
            background=colors["secondary"],
        )

        style.configure(
            "Accent.TButton",
            font=fonts["button"],
            foreground=colors["text_on_dark"],
            background=colors["accent"],
        )

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


class LoginScreen(tk.Frame):
    """Custom styled login screen."""

    def __init__(self, parent, user_manager: UserManager, on_login_success):
        super().__init__(parent)
        self.user_manager = user_manager
        self.on_login_success = on_login_success

        self._setup_ui()

    def _setup_ui(self):
        """Set up the login screen UI."""
        # Configure grid
        self.grid_rowconfigure(0, weight=1)
        self.grid_columnconfigure(0, weight=1)

        # Main container
        main_frame = tk.Frame(self, bg=custom_style.get_colors()["background"])
        main_frame.grid(row=0, column=0, sticky="nsew", padx=20, pady=20)
        main_frame.grid_rowconfigure(0, weight=1)
        main_frame.grid_columnconfigure(0, weight=1)

        # Login form container
        login_frame = tk.Frame(main_frame, bg=custom_style.get_colors()["surface"], relief="raised", bd=2)
        login_frame.grid(row=0, column=0, padx=50, pady=50, sticky="nsew")

        # Add logo if available
        try:
            image = Image.open("PulsePoint.png")
            image = image.resize((100, 100), Image.Resampling.LANCZOS)
            logo = ImageTk.PhotoImage(image)
            logo_label = tk.Label(login_frame, image=logo, bg=custom_style.get_colors()["surface"])
            logo_label.image = logo  # Keep a reference
            logo_label.pack(pady=(40, 20))
        except:
            pass

        # Title
        title_label = tk.Label(
            login_frame,
            text="PulsePoint",
            font=custom_style.get_fonts()["title"],
            fg=custom_style.get_colors()["primary"],
            bg=custom_style.get_colors()["surface"],
        )
        title_label.pack(pady=10)

        # Create notebook for login/register
        self.notebook = ttk.Notebook(login_frame)
        self.notebook.pack(fill="x", padx=40, pady=20)

        # Login tab
        self.login_frame = tk.Frame(self.notebook, bg=custom_style.get_colors()["surface"])
        self.notebook.add(self.login_frame, text="Login")
        self._setup_login_tab()

        # Register tab
        self.register_frame = tk.Frame(self.notebook, bg=custom_style.get_colors()["surface"])
        self.notebook.add(self.register_frame, text="Register")
        self._setup_register_tab()

        # Status info
        self._setup_status_info(login_frame)

    def _setup_login_tab(self):
        """Set up the login tab."""
        # Username
        tk.Label(
            self.login_frame,
            text="Username:",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(20, 5))

        self.username_entry = tk.Entry(self.login_frame, width=30, font=custom_style.get_fonts()["body"])
        self.username_entry.pack(pady=(0, 15))

        # Password
        tk.Label(
            self.login_frame,
            text="Password:",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(0, 5))

        self.password_entry = tk.Entry(self.login_frame, width=30, show="*", font=custom_style.get_fonts()["body"])
        self.password_entry.pack(pady=(0, 20))

        # Login button
        login_btn = tk.Button(
            self.login_frame,
            text="Login",
            command=self._handle_login,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["primary"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=15,
            height=2,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["primary_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        login_btn.pack(pady=10)

        # Bind Enter key
        self.username_entry.bind("<Return>", lambda e: self._handle_login())
        self.password_entry.bind("<Return>", lambda e: self._handle_login())

    def _setup_register_tab(self):
        """Set up the registration tab."""
        # First Name
        tk.Label(
            self.register_frame,
            text="First Name:",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(20, 5))

        self.first_name_entry = tk.Entry(self.register_frame, width=30, font=custom_style.get_fonts()["body"])
        self.first_name_entry.pack(pady=(0, 10))

        # Last Name
        tk.Label(
            self.register_frame,
            text="Last Name:",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(0, 5))

        self.last_name_entry = tk.Entry(self.register_frame, width=30, font=custom_style.get_fonts()["body"])
        self.last_name_entry.pack(pady=(0, 10))

        # Age
        tk.Label(
            self.register_frame,
            text="Age:",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(0, 5))

        self.age_entry = tk.Entry(self.register_frame, width=30, font=custom_style.get_fonts()["body"])
        self.age_entry.pack(pady=(0, 10))

        # Username
        tk.Label(
            self.register_frame,
            text="Username:",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(0, 5))

        self.register_username_entry = tk.Entry(self.register_frame, width=30, font=custom_style.get_fonts()["body"])
        self.register_username_entry.pack(pady=(0, 10))

        # Password
        tk.Label(
            self.register_frame,
            text="Password:",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(0, 5))

        self.register_password_entry = tk.Entry(
            self.register_frame, width=30, show="*", font=custom_style.get_fonts()["body"]
        )
        self.register_password_entry.pack(pady=(0, 10))

        # Confirm Password
        tk.Label(
            self.register_frame,
            text="Confirm Password:",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(0, 5))

        self.confirm_password_entry = tk.Entry(
            self.register_frame, width=30, show="*", font=custom_style.get_fonts()["body"]
        )
        self.confirm_password_entry.pack(pady=(0, 20))

        # Register button
        register_btn = tk.Button(
            self.register_frame,
            text="Register",
            command=self._handle_register,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["secondary"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=15,
            height=2,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["secondary_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        register_btn.pack(pady=10)

    def _setup_status_info(self, parent):
        """Set up status information."""
        user_count = len(self.user_manager.users)
        max_users = MAX_USERS

        status_text = f"Registered Users: {user_count}/{max_users}"
        if user_count >= max_users:
            status_text += " (Maximum reached)"

        status_label = tk.Label(
            parent,
            text=status_text,
            font=custom_style.get_fonts()["small"],
            fg=custom_style.get_colors()["text_light"],
            bg=custom_style.get_colors()["surface"],
        )
        status_label.pack(pady=(0, 20))

    def _handle_login(self):
        """Handle login attempt."""
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
        """Handle registration attempt."""
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
            # Clear form
            self.first_name_entry.delete(0, tk.END)
            self.last_name_entry.delete(0, tk.END)
            self.age_entry.delete(0, tk.END)
            self.register_username_entry.delete(0, tk.END)
            self.register_password_entry.delete(0, tk.END)
            self.confirm_password_entry.delete(0, tk.END)
            # Switch to login tab
            self.notebook.select(0)
        else:
            messagebox.showerror("Registration Failed", message)


class MainScreen(tk.Frame):
    """Main application screen with pacemaker controls."""

    def __init__(self, parent, user_manager: UserManager, parameters: PacemakerParameters, on_logout):
        super().__init__(parent)
        self.user_manager = user_manager
        self.parameters = parameters
        self.on_logout = on_logout
        self.parameter_widgets = {}
        self.current_mode = PacemakerMode.AOO

        self._setup_ui()
        self._load_user_parameters()

    def _setup_ui(self):
        """Set up the main screen UI."""
        # Configure grid
        self.grid_rowconfigure(1, weight=1)
        self.grid_columnconfigure(1, weight=1)

        # Top bar
        self._setup_top_bar()

        # Sidebar
        self._setup_sidebar()

        # Main content area
        self._setup_main_content()

    def _setup_top_bar(self):
        """Set up the top status bar."""
        top_bar = tk.Frame(self, bg=custom_style.get_colors()["secondary"], height=80)
        top_bar.grid(row=0, column=0, columnspan=2, sticky="ew")
        top_bar.grid_propagate(False)

        # Connection status
        status_frame = tk.Frame(top_bar, bg=custom_style.get_colors()["secondary"])
        status_frame.pack(side="left", padx=20, pady=20)

        tk.Label(
            status_frame,
            text="DCM Connection Status: ✔",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text_on_dark"],
            bg=custom_style.get_colors()["secondary"],
        ).pack()

        tk.Label(
            status_frame,
            text="New Device Detected: ✔",
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text_on_dark"],
            bg=custom_style.get_colors()["secondary"],
        ).pack()

        # Title
        title_label = tk.Label(
            top_bar,
            text="Pacemaker Device Controller-Monitor",
            font=custom_style.get_fonts()["heading"],
            fg=custom_style.get_colors()["text_on_dark"],
            bg=custom_style.get_colors()["secondary"],
        )
        title_label.pack(side="left", padx=50, pady=20)

        # Settings and About buttons
        button_frame = tk.Frame(top_bar, bg=custom_style.get_colors()["secondary"])
        button_frame.pack(side="right", padx=20, pady=20)

        settings_btn = tk.Button(
            button_frame,
            text="Settings",
            command=self._open_settings,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["primary"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=10,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["primary_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        settings_btn.pack(side="right", padx=5)

        about_btn = tk.Button(
            button_frame,
            text="About",
            command=self._open_about,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["accent"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=10,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["accent_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        about_btn.pack(side="right", padx=5)

    def _setup_sidebar(self):
        """Set up the sidebar with user info and controls."""
        sidebar = tk.Frame(self, bg=custom_style.get_colors()["surface"], width=200)
        sidebar.grid(row=1, column=0, sticky="ns", padx=(0, 10))
        sidebar.grid_propagate(False)

        # Logo
        try:
            image = Image.open("PulsePoint.png")
            image = image.resize((50, 50), Image.Resampling.LANCZOS)
            logo = ImageTk.PhotoImage(image)
            logo_label = tk.Label(sidebar, image=logo, bg=custom_style.get_colors()["surface"])
            logo_label.image = logo
            logo_label.pack(pady=(20, 10))
        except:
            tk.Label(
                sidebar,
                text="PulsePoint",
                font=custom_style.get_fonts()["heading"],
                fg=custom_style.get_colors()["primary"],
                bg=custom_style.get_colors()["surface"],
            ).pack(pady=(20, 10))

        # User info
        current_user = self.user_manager.get_current_user()
        if current_user:
            name_text = f"Name: {current_user.first_name} {current_user.last_name}".strip()
            if name_text == "Name: ":
                name_text = f"User: {current_user.username}"

            tk.Label(
                sidebar,
                text=name_text,
                font=custom_style.get_fonts()["body"],
                fg=custom_style.get_colors()["text"],
                bg=custom_style.get_colors()["surface"],
            ).pack(pady=5)

            if current_user.age:
                tk.Label(
                    sidebar,
                    text=f"Age: {current_user.age}",
                    font=custom_style.get_fonts()["body"],
                    fg=custom_style.get_colors()["text"],
                    bg=custom_style.get_colors()["surface"],
                ).pack(pady=5)

        # Logout button
        logout_btn = tk.Button(
            sidebar,
            text="Logout",
            command=self._handle_logout,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["error"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=15,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["error_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        logout_btn.pack(pady=20)

        # Mode selection
        tk.Label(
            sidebar,
            text="Pacemaker Mode:",
            font=custom_style.get_fonts()["subheading"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(20, 5))

        self.mode_var = tk.StringVar(value="AOO")
        mode_combo = ttk.Combobox(
            sidebar,
            textvariable=self.mode_var,
            values=[mode.value for mode in PacemakerMode],
            state="readonly",
            width=15,
        )
        mode_combo.pack(pady=5)
        mode_combo.bind("<<ComboboxSelected>>", self._on_mode_changed)

        # Device info textbox
        info_frame = tk.Frame(sidebar, bg=custom_style.get_colors()["surface"])
        info_frame.pack(fill="both", expand=True, padx=10, pady=20)

        tk.Label(
            info_frame,
            text="Device Information",
            font=custom_style.get_fonts()["subheading"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack()

        device_info = app_config.get("device_info", {})
        info_text = f"""Model #: {device_info.get("model", "2N4972")}
Release Version: {device_info.get("release_version", "1.4.4.1")}
DCM Serial: {device_info.get("dcm_serial", "873HJS983")}
Inst. Name: {device_info.get("inst_name", "McMaster")}"""

        info_textbox = tk.Text(
            info_frame,
            height=8,
            width=20,
            font=custom_style.get_fonts()["small"],
            bg=custom_style.get_colors()["background"],
            fg=custom_style.get_colors()["text"],
        )
        info_textbox.pack(fill="both", expand=True, pady=5)
        info_textbox.insert("1.0", info_text)
        info_textbox.config(state="disabled")

        # Communication buttons
        comm_frame = tk.Frame(sidebar, bg=custom_style.get_colors()["surface"])
        comm_frame.pack(fill="x", padx=10, pady=10)

        send_btn = tk.Button(
            comm_frame,
            text="Send Data",
            command=self._send_data,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["success"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=15,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["success_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        send_btn.pack(pady=5)

        receive_btn = tk.Button(
            comm_frame,
            text="Receive Data",
            command=self._receive_data,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["secondary"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=15,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["secondary_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        receive_btn.pack(pady=5)

    def _setup_main_content(self):
        """Set up the main content area with parameter controls."""
        main_content = tk.Frame(self, bg=custom_style.get_colors()["background"])
        main_content.grid(row=1, column=1, sticky="nsew", padx=10, pady=10)
        main_content.grid_rowconfigure(0, weight=1)
        main_content.grid_columnconfigure(0, weight=1)

        # EGRAM button
        egram_btn = tk.Button(
            main_content,
            text="View EGRAM Data",
            command=self._show_egram_data,
            font=custom_style.get_fonts()["heading"],
            bg=custom_style.get_colors()["primary"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=20,
            height=8,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["primary_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        egram_btn.grid(row=0, column=0, padx=20, pady=20, sticky="nsew")

        # Parameters frame
        self.params_frame = tk.Frame(main_content, bg=custom_style.get_colors()["surface"], relief="raised", bd=2)
        self.params_frame.grid(row=0, column=1, padx=20, pady=20, sticky="nsew")

        # Configure parameters frame grid
        for i in range(6):
            self.params_frame.grid_rowconfigure(i, weight=1)
        for i in range(4):
            self.params_frame.grid_columnconfigure(i, weight=1)

        # Save button and info frame
        button_info_frame = tk.Frame(main_content, bg=custom_style.get_colors()["background"])
        button_info_frame.grid(row=1, column=1, padx=20, pady=10, sticky="ew")

        # Mode info label
        self.mode_info_label = tk.Label(
            button_info_frame,
            text="",
            font=custom_style.get_fonts()["small"],
            fg=custom_style.get_colors()["text_light"],
            bg=custom_style.get_colors()["background"],
            justify="left",
            anchor="w",
        )
        self.mode_info_label.pack(side="left", padx=(0, 20))

        save_btn = tk.Button(
            button_info_frame,
            text="Save Parameters",
            command=self._save_parameters,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["success"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=15,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["success_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        save_btn.pack(side="right")

        # Initialize parameter widgets
        self._update_parameter_widgets()

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

    def _create_parameter_widget(self, param_name: str, config: Dict, current_value: float, row: int, col: int):
        """Create a parameter control widget."""
        # Parameter frame
        param_frame = tk.Frame(self.params_frame, bg=custom_style.get_colors()["surface_alt"], relief="raised", bd=1)
        param_frame.grid(row=row, column=col, padx=5, pady=5, sticky="nsew")

        # Parameter label
        label_text = param_name.replace("_", " ").title()
        label = tk.Label(
            param_frame,
            text=label_text,
            font=custom_style.get_fonts()["body"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface_alt"],
        )
        label.pack(pady=5)

        # Value entry
        value_var = tk.StringVar(value=str(current_value))
        entry = tk.Entry(
            param_frame, textvariable=value_var, width=10, font=custom_style.get_fonts()["body"], justify="center"
        )
        entry.pack(pady=2)

        # Unit label
        unit_label = tk.Label(
            param_frame,
            text=config["unit"],
            font=custom_style.get_fonts()["small"],
            fg=custom_style.get_colors()["text_light"],
            bg=custom_style.get_colors()["surface_alt"],
        )
        unit_label.pack()

        # Slider
        slider = tk.Scale(
            param_frame,
            from_=config["min"],
            to=config["max"],
            resolution=config["step"],
            orient="horizontal",
            bg=custom_style.get_colors()["surface_alt"],
            fg=custom_style.get_colors()["text"],
        )
        slider.set(current_value)
        slider.pack(fill="x", padx=5, pady=5)

        # Range info
        range_text = f"({config['min']}-{config['max']})"
        range_label = tk.Label(
            param_frame,
            text=range_text,
            font=custom_style.get_fonts()["small"],
            fg=custom_style.get_colors()["text_light"],
            bg=custom_style.get_colors()["surface_alt"],
        )
        range_label.pack()

        # Store widgets
        self.parameter_widgets[param_name] = {
            "value_var": value_var,
            "entry": entry,
            "slider": slider,
            "config": config,
        }

        # Bind events
        def update_slider_from_entry(event=None, p=param_name):
            try:
                value = float(self.parameter_widgets[p]["value_var"].get())
                if config["min"] <= value <= config["max"]:
                    self.parameter_widgets[p]["slider"].set(value)
            except ValueError:
                pass

        def update_entry_from_slider(value, p=param_name):
            self.parameter_widgets[p]["value_var"].set(str(value))

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
        }

        info_text = mode_info.get(self.current_mode, "")
        if hasattr(self, "mode_info_label"):
            self.mode_info_label.config(text=info_text)

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
            try:
                value_str = widgets["value_var"].get().strip()
                if not value_str:
                    errors.append(f"{param_name.replace('_', ' ').title()}: Value cannot be empty")
                    continue

                value = float(value_str)
                success, error_msg = self.parameters.set_parameter(param_name, value)
                if not success:
                    # Format parameter name nicely
                    display_name = param_name.replace("_", " ").title()
                    errors.append(f"{display_name}: {error_msg}")
            except ValueError:
                display_name = param_name.replace("_", " ").title()
                errors.append(f"{display_name}: Invalid number format. Please enter a valid number.")

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

    def _show_egram_data(self):
        """Show EGRAM data visualization window."""
        egram_window = tk.Toplevel(self)
        egram_window.title("EGRAM Data Visualization")
        egram_window.geometry("800x600")

        # Create matplotlib figure
        fig, ax = plt.subplots(figsize=(10, 6))

        # Generate sample EGRAM data
        t = np.linspace(0, 10, 1000)
        # Simulate atrial and ventricular signals
        atrial_signal = np.sin(2 * np.pi * 1.2 * t) * 0.5 + 2
        ventricular_signal = np.sin(2 * np.pi * 1.0 * t + np.pi / 4) * 0.3 + 1.5

        ax.plot(t, atrial_signal, label="Atrial Signal", color="blue", linewidth=2)
        ax.plot(t, ventricular_signal, label="Ventricular Signal", color="red", linewidth=2)

        ax.set_title("EGRAM Data Visualization", fontsize=16, fontweight="bold")
        ax.set_xlabel("Time (s)", fontsize=12)
        ax.set_ylabel("Amplitude (V)", fontsize=12)
        ax.legend()
        ax.grid(True, alpha=0.3)

        # Embed in tkinter
        canvas = FigureCanvasTkAgg(fig, master=egram_window)
        canvas.draw()
        canvas.get_tk_widget().pack(fill="both", expand=True)

    def _send_data(self):
        """Send data to pacemaker device."""
        if self.mode_var.get() == "None selected":
            messagebox.showwarning("Warning", "Please select a pacemaker mode first")
            return

        try:
            # Create data packet
            data_packet = self._create_data_packet()

            # Simulate serial communication
            messagebox.showinfo("Data Sent", f"Sent {len(data_packet)} bytes to device")
            print(f"Data packet: {data_packet}")

        except Exception as e:
            messagebox.showerror("Error", f"Failed to send data: {e}")

    def _receive_data(self):
        """Receive data from pacemaker device."""
        try:
            # Simulate receiving data
            messagebox.showinfo("Data Received", "Successfully received data from device")
        except Exception as e:
            messagebox.showerror("Error", f"Failed to receive data: {e}")

    def _create_data_packet(self):
        """Create data packet for current parameters."""
        # Header
        packet = b"\x16\x55"

        # Mode information
        mode = self.current_mode.value
        chamber = 1 if mode[0] == "A" else 2
        sensing = 0 if mode[1] == "O" else 1
        rate_adaptive = 1 if len(mode) > 3 and mode[3] == "R" else 0

        packet += struct.pack("B", chamber)
        packet += struct.pack("B", sensing)
        packet += struct.pack("B", rate_adaptive)

        # Parameters
        current_params = self.parameters.get_current_parameters()
        for param_name, value in current_params.items():
            if "Amplitude" in param_name or "Sensitivity" in param_name:
                packet += struct.pack("f", float(value))
            else:
                packet += struct.pack("H", int(value))

        return packet

    def _open_settings(self):
        """Open settings window."""
        settings_window = SettingsWindow(self)
        settings_window.focus()

    def _open_about(self):
        """Open about window."""
        about_window = AboutWindow(self)
        about_window.focus()

    def _handle_logout(self):
        """Handle logout."""
        if messagebox.askyesno("Logout", "Are you sure you want to logout?"):
            self.on_logout()


class SettingsWindow(tk.Toplevel):
    """Settings window for application preferences."""

    def __init__(self, parent):
        super().__init__(parent)
        self.parent = parent
        self._setup_window()

    def _setup_window(self):
        """Set up the settings window."""
        self.title("Settings")
        self.geometry("400x500")
        self.resizable(False, False)

        # Main frame
        main_frame = tk.Frame(self, bg=custom_style.get_colors()["surface"], padx=20, pady=20)
        main_frame.pack(fill="both", expand=True)

        # Title
        title_label = tk.Label(
            main_frame,
            text="Settings",
            font=custom_style.get_fonts()["title"],
            fg=custom_style.get_colors()["primary"],
            bg=custom_style.get_colors()["surface"],
        )
        title_label.pack(pady=(0, 20))

        # Language selection
        tk.Label(
            main_frame,
            text="Language:",
            font=custom_style.get_fonts()["subheading"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(20, 5))

        self.language_var = tk.StringVar(value="English")
        language_combo = ttk.Combobox(
            main_frame,
            textvariable=self.language_var,
            values=["English", "French", "Spanish", "German", "Chinese", "Japanese"],
            state="readonly",
            width=20,
        )
        language_combo.pack(pady=(0, 20))

        # Theme selection
        tk.Label(
            main_frame,
            text="Theme:",
            font=custom_style.get_fonts()["subheading"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(0, 5))

        self.theme_var = tk.StringVar(value="Light")
        theme_combo = ttk.Combobox(
            main_frame, textvariable=self.theme_var, values=["Light", "Dark", "System"], state="readonly", width=20
        )
        theme_combo.pack(pady=(0, 20))

        # UI Scaling
        tk.Label(
            main_frame,
            text="UI Scaling:",
            font=custom_style.get_fonts()["subheading"],
            fg=custom_style.get_colors()["text"],
            bg=custom_style.get_colors()["surface"],
        ).pack(pady=(0, 5))

        self.scaling_var = tk.StringVar(value="100%")
        scaling_combo = ttk.Combobox(
            main_frame,
            textvariable=self.scaling_var,
            values=["80%", "90%", "100%", "110%", "120%"],
            state="readonly",
            width=20,
        )
        scaling_combo.pack(pady=(0, 20))

        # Buttons
        button_frame = tk.Frame(main_frame, bg=custom_style.get_colors()["surface"])
        button_frame.pack(fill="x", pady=20)

        cancel_btn = tk.Button(
            button_frame,
            text="Cancel",
            command=self.destroy,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["text_light"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=10,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["text_secondary"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        cancel_btn.pack(side="left", padx=10)

        save_btn = tk.Button(
            button_frame,
            text="Save",
            command=self._save_settings,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["success"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=10,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["success_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        save_btn.pack(side="right", padx=10)

        # Make window modal
        self.grab_set()

    def _save_settings(self):
        """Save settings."""
        # Apply scaling if changed
        scaling = self.scaling_var.get().replace("%", "")
        if scaling != "100":
            messagebox.showinfo("Settings", f"UI scaling set to {scaling}%")

        messagebox.showinfo("Settings", "Settings saved successfully!")
        self.destroy()


class AboutWindow(tk.Toplevel):
    """About window with device information."""

    def __init__(self, parent):
        super().__init__(parent)
        self.parent = parent
        self._setup_window()

    def _setup_window(self):
        """Set up the about window."""
        self.title("About - Device Information")
        self.geometry("400x500")
        self.resizable(False, False)

        # Main frame
        main_frame = tk.Frame(self, bg=custom_style.get_colors()["surface"], padx=20, pady=20)
        main_frame.pack(fill="both", expand=True)

        # Title
        title_label = tk.Label(
            main_frame,
            text="Device Info",
            font=custom_style.get_fonts()["title"],
            fg=custom_style.get_colors()["primary"],
            bg=custom_style.get_colors()["surface"],
        )
        title_label.pack(pady=(0, 20))

        # Logo
        try:
            image = Image.open("PulsePoint.png")
            image = image.resize((100, 100), Image.Resampling.LANCZOS)
            logo = ImageTk.PhotoImage(image)
            logo_label = tk.Label(main_frame, image=logo, bg=custom_style.get_colors()["surface"])
            logo_label.image = logo
            logo_label.pack(pady=20)
        except:
            pass

        # Device information
        info_frame = tk.Frame(main_frame, bg=custom_style.get_colors()["background"], relief="raised", bd=1)
        info_frame.pack(fill="x", padx=20, pady=20)

        device_info = app_config.get("device_info", {})
        device_info_list = [
            ("Model #:", device_info.get("model", "2N4972")),
            ("Release Version:", device_info.get("release_version", "1.4.4.1")),
            ("DCM Serial:", device_info.get("dcm_serial", "873HJS983")),
            ("Inst. Name:", device_info.get("inst_name", "McMaster")),
        ]

        for label, value in device_info_list:
            info_row = tk.Frame(info_frame, bg=custom_style.get_colors()["background"])
            info_row.pack(fill="x", padx=10, pady=10)

            tk.Label(
                info_row,
                text=label,
                font=custom_style.get_fonts()["subheading"],
                fg=custom_style.get_colors()["text"],
                bg=custom_style.get_colors()["background"],
            ).pack(side="left")

            tk.Label(
                info_row,
                text=value,
                font=custom_style.get_fonts()["body"],
                fg=custom_style.get_colors()["text"],
                bg=custom_style.get_colors()["background"],
            ).pack(side="right")

        # Close button
        close_btn = tk.Button(
            main_frame,
            text="Close",
            command=self.destroy,
            font=custom_style.get_fonts()["button"],
            bg=custom_style.get_colors()["primary"],
            fg=custom_style.get_colors()["text_on_dark"],
            width=15,
            relief="raised",
            bd=2,
            activebackground=custom_style.get_colors()["primary_light"],
            activeforeground=custom_style.get_colors()["text_on_dark"],
        )
        close_btn.pack(pady=20)

        # Make window modal
        self.grab_set()


if __name__ == "__main__":
    app = CustomPacemakerApp()
    app.run()
