"""Main Screen for DCM Application

This module provides the main interface for pacemaker programming
and monitoring as specified in the DCM requirements.
"""

import tkinter as tk
from tkinter import messagebox, ttk
from typing import Any, Callable, Dict

from pacemaker_parameters import PacemakerMode, PacemakerParameters
from user_management import UserManager


class MainScreen:
    """Main screen for pacemaker programming and monitoring.
    Provides interface for mode selection and parameter management.
    """

    def __init__(self, root: tk.Tk, user_manager: UserManager, on_logout: Callable):
        """Initialize the main screen.

        Args:
            root: Main tkinter window
            user_manager: UserManager instance for user data
            on_logout: Callback function when user logs out
        """
        self.root = root
        self.user_manager = user_manager
        self.on_logout = on_logout
        self.parameters = PacemakerParameters()
        self.frame = None
        self.parameter_widgets = {}
        self._setup_ui()
        self._load_user_parameters()

    def _setup_ui(self) -> None:
        """Set up the main screen user interface."""
        # Clear existing content
        if self.frame:
            self.frame.destroy()

        self.frame = ttk.Frame(self.root, padding="20")
        self.frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

        # Configure grid weights
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        self.frame.columnconfigure(1, weight=1)

        # Header
        self._setup_header()

        # Mode selection
        self._setup_mode_selection()

        # Parameters section
        self._setup_parameters_section()

        # Action buttons
        self._setup_action_buttons()

    def _setup_header(self) -> None:
        """Set up the header section with user info and logout."""
        header_frame = ttk.Frame(self.frame)
        header_frame.grid(row=0, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=(0, 20))
        header_frame.columnconfigure(1, weight=1)

        # Welcome message
        current_user = self.user_manager.get_current_user()
        welcome_label = ttk.Label(
            header_frame,
            text=f"Welcome, {current_user.username if current_user else 'User'}",
            font=("Arial", 14, "bold"),
        )
        welcome_label.grid(row=0, column=0, sticky=tk.W)

        # Logout button
        logout_button = ttk.Button(header_frame, text="Logout", command=self._handle_logout)
        logout_button.grid(row=0, column=2, sticky=tk.E)

    def _setup_mode_selection(self) -> None:
        """Set up the pacemaker mode selection interface."""
        mode_frame = ttk.LabelFrame(self.frame, text="Pacemaker Mode", padding="10")
        mode_frame.grid(row=1, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=(0, 20))

        # Mode selection
        self.mode_var = tk.StringVar(value=self.parameters.get_mode().value)
        mode_label = ttk.Label(mode_frame, text="Select Mode:")
        mode_label.grid(row=0, column=0, sticky=tk.W, pady=(0, 10))

        mode_combobox = ttk.Combobox(
            mode_frame,
            textvariable=self.mode_var,
            values=[mode.value for mode in self.parameters.get_available_modes()],
            state="readonly",
            width=20,
        )
        mode_combobox.grid(row=1, column=0, sticky=tk.W)
        mode_combobox.bind("<<ComboboxSelected>>", self._on_mode_changed)

    def _setup_parameters_section(self) -> None:
        """Set up the parameters management interface."""
        params_frame = ttk.LabelFrame(self.frame, text="Pacemaker Parameters", padding="10")
        params_frame.grid(row=2, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=(0, 20))
        params_frame.columnconfigure(1, weight=1)

        # Get parameter information
        param_info = self.parameters.get_all_parameter_info()

        row = 0
        for param_name, info in param_info.items():
            self._create_parameter_widget(params_frame, param_name, info, row)
            row += 1

    def _create_parameter_widget(self, parent: ttk.Frame, param_name: str, info: Dict[str, Any], row: int) -> None:
        """Create a parameter input widget.

        Args:
            parent: Parent frame for the widget
            param_name: Name of the parameter
            info: Parameter information dictionary
            row: Row position in the grid
        """
        # Parameter label
        label_text = param_name.replace("_", " ").title()
        label = ttk.Label(parent, text=f"{label_text}:")
        label.grid(row=row, column=0, sticky=tk.W, pady=2)

        # Input frame
        input_frame = ttk.Frame(parent)
        input_frame.grid(row=row, column=1, sticky=(tk.W, tk.E), padx=(10, 0), pady=2)
        input_frame.columnconfigure(0, weight=1)

        # Value entry
        value_var = tk.StringVar(value=str(info["current_value"]))
        entry = ttk.Entry(input_frame, textvariable=value_var, width=15)
        entry.grid(row=0, column=0, sticky=tk.W)

        # Unit label
        unit_label = ttk.Label(input_frame, text=info["unit"])
        unit_label.grid(row=0, column=1, sticky=tk.W, padx=(5, 0))

        # Range info
        range_text = f"({info['min_value']}-{info['max_value']}, step: {info['step']})"
        range_label = ttk.Label(input_frame, text=range_text, font=("Arial", 8), foreground="gray")
        range_label.grid(row=0, column=2, sticky=tk.W, padx=(10, 0))

        # Error label
        error_label = ttk.Label(input_frame, text="", foreground="red", font=("Arial", 8))
        error_label.grid(row=1, column=0, columnspan=3, sticky=tk.W)

        # Store widgets for later access
        self.parameter_widgets[param_name] = {"value_var": value_var, "entry": entry, "error_label": error_label}

        # Bind validation
        entry.bind("<FocusOut>", lambda e, p=param_name: self._validate_parameter(p))
        entry.bind("<Return>", lambda e, p=param_name: self._validate_parameter(p))

    def _setup_action_buttons(self) -> None:
        """Set up action buttons for parameter management."""
        button_frame = ttk.Frame(self.frame)
        button_frame.grid(row=3, column=0, columnspan=2, pady=(20, 0))

        # Save parameters button
        save_button = ttk.Button(
            button_frame, text="Save Parameters", command=self._save_parameters, style="Accent.TButton"
        )
        save_button.grid(row=0, column=0, padx=(0, 10))

        # Reset to defaults button
        reset_button = ttk.Button(button_frame, text="Reset to Defaults", command=self._reset_parameters)
        reset_button.grid(row=0, column=1, padx=(0, 10))

        # Validate all button
        validate_button = ttk.Button(button_frame, text="Validate All", command=self._validate_all_parameters)
        validate_button.grid(row=0, column=2)

    def _on_mode_changed(self, event=None) -> None:
        """Handle pacemaker mode change."""
        try:
            new_mode = PacemakerMode(self.mode_var.get())
            self.parameters.set_mode(new_mode)
            self._save_parameters()  # Auto-save mode change
        except ValueError:
            messagebox.showerror("Error", "Invalid pacemaker mode selected")

    def _validate_parameter(self, param_name: str) -> None:
        """Validate a single parameter and update UI.

        Args:
            param_name: Name of the parameter to validate
        """
        if param_name not in self.parameter_widgets:
            return

        widget_info = self.parameter_widgets[param_name]
        value_var = widget_info["value_var"]
        error_label = widget_info["error_label"]

        try:
            value = float(value_var.get())
            success, error_msg = self.parameters.set_parameter(param_name, value)

            if success:
                error_label.config(text="")
                # Update entry with validated value
                value_var.set(str(self.parameters.get_parameter(param_name)))
            else:
                error_label.config(text=error_msg)

        except ValueError:
            error_label.config(text="Invalid number format")

    def _validate_all_parameters(self) -> None:
        """Validate all parameters and show results."""
        errors = self.parameters.validate_all_parameters()

        if not errors:
            messagebox.showinfo("Validation", "All parameters are valid!")
        else:
            error_text = "Parameter validation errors:\n\n"
            for param_name, error_msg in errors.items():
                error_text += f"• {param_name.replace('_', ' ').title()}: {error_msg}\n"
            messagebox.showerror("Validation Errors", error_text)

    def _save_parameters(self) -> None:
        """Save parameters to user profile."""
        # Validate all parameters first
        errors = self.parameters.validate_all_parameters()

        if errors:
            messagebox.showerror("Save Failed", "Please fix validation errors before saving")
            return

        # Save to user profile
        current_user = self.user_manager.get_current_user()
        if current_user:
            current_user.profile_data["pacemaker_parameters"] = self.parameters.to_dict()
            # Note: In a real implementation, you'd save this to persistent storage

        messagebox.showinfo("Success", "Parameters saved successfully!")

    def _reset_parameters(self) -> None:
        """Reset parameters to default values."""
        if messagebox.askyesno("Confirm Reset", "Are you sure you want to reset all parameters to default values?"):
            self.parameters.reset_to_defaults()
            self._update_parameter_display()
            messagebox.showinfo("Reset Complete", "Parameters reset to default values")

    def _update_parameter_display(self) -> None:
        """Update the parameter display with current values."""
        for param_name, widget_info in self.parameter_widgets.items():
            current_value = self.parameters.get_parameter(param_name)
            widget_info["value_var"].set(str(current_value))
            widget_info["error_label"].config(text="")

    def _load_user_parameters(self) -> None:
        """Load parameters from user profile."""
        current_user = self.user_manager.get_current_user()
        if current_user and "pacemaker_parameters" in current_user.profile_data:
            param_data = current_user.profile_data["pacemaker_parameters"]
            self.parameters.from_dict(param_data)
            self._update_parameter_display()
            self.mode_var.set(self.parameters.get_mode().value)

    def _handle_logout(self) -> None:
        """Handle logout button click."""
        if messagebox.askyesno("Logout", "Are you sure you want to logout?"):
            self.user_manager.logout_user()
            self.on_logout()

    def show(self) -> None:
        """Show the main screen."""
        self.frame.grid()

    def hide(self) -> None:
        """Hide the main screen."""
        self.frame.grid_remove()
