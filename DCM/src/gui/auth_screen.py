"""Authentication Screen for DCM Application.

This module provides the login and registration interface
for user authentication as required by the DCM specifications.
"""

import tkinter as tk
from tkinter import messagebox, ttk
from typing import Callable

from user_management import UserManager


class AuthScreen:
    """Authentication screen for user login and registration.

    Provides interface for up to 10 local users as specified.
    """

    def __init__(self, root: tk.Tk, user_manager: UserManager, on_login_success: Callable):
        """Initialize the authentication screen.

        Args:
            root: Main tkinter window
            user_manager: UserManager instance for authentication
            on_login_success: Callback function when login is successful
        """
        self.root = root
        self.user_manager = user_manager
        self.on_login_success = on_login_success
        self.frame = None
        self._setup_ui()

    def _setup_ui(self) -> None:
        """Set up the authentication user interface."""
        # Clear existing content
        if self.frame:
            self.frame.destroy()

        self.frame = ttk.Frame(self.root, padding="20")
        self.frame.grid(row=0, column=0, sticky=(tk.W, tk.E, tk.N, tk.S))

        # Configure grid weights
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)
        self.frame.columnconfigure(1, weight=1)

        # Title
        title_label = ttk.Label(self.frame, text="Device Controller-Monitor (DCM)", font=("Arial", 16, "bold"))
        title_label.grid(row=0, column=0, columnspan=2, pady=(0, 20))

        # Subtitle
        subtitle_label = ttk.Label(self.frame, text="Pacemaker Simulation System", font=("Arial", 12))
        subtitle_label.grid(row=1, column=0, columnspan=2, pady=(0, 30))

        # Create notebook for login/register tabs
        self.notebook = ttk.Notebook(self.frame)
        self.notebook.grid(row=2, column=0, columnspan=2, sticky=(tk.W, tk.E), pady=(0, 20))

        # Login tab
        self.login_frame = ttk.Frame(self.notebook, padding="20")
        self.notebook.add(self.login_frame, text="Login")
        self._setup_login_tab()

        # Register tab
        self.register_frame = ttk.Frame(self.notebook, padding="20")
        self.notebook.add(self.register_frame, text="Register")
        self._setup_register_tab()

        # Status information
        self._setup_status_info()

    def _setup_login_tab(self) -> None:
        """Set up the login tab interface."""
        # Username
        ttk.Label(self.login_frame, text="Username:").grid(row=0, column=0, sticky=tk.W, pady=(0, 5))
        self.login_username = tk.StringVar()
        login_username_entry = ttk.Entry(self.login_frame, textvariable=self.login_username, width=30)
        login_username_entry.grid(row=1, column=0, pady=(0, 15))

        # Password
        ttk.Label(self.login_frame, text="Password:").grid(row=2, column=0, sticky=tk.W, pady=(0, 5))
        self.login_password = tk.StringVar()
        login_password_entry = ttk.Entry(self.login_frame, textvariable=self.login_password, show="*", width=30)
        login_password_entry.grid(row=3, column=0, pady=(0, 20))

        # Login button
        login_button = ttk.Button(self.login_frame, text="Login", command=self._handle_login, style="Accent.TButton")
        login_button.grid(row=4, column=0, pady=(0, 10))

        # Bind Enter key to login
        login_username_entry.bind("<Return>", lambda e: self._handle_login())
        login_password_entry.bind("<Return>", lambda e: self._handle_login())

    def _setup_register_tab(self) -> None:
        """Set up the registration tab interface."""
        # Username
        ttk.Label(self.register_frame, text="Username:").grid(row=0, column=0, sticky=tk.W, pady=(0, 5))
        self.register_username = tk.StringVar()
        register_username_entry = ttk.Entry(self.register_frame, textvariable=self.register_username, width=30)
        register_username_entry.grid(row=1, column=0, pady=(0, 15))

        # Password
        ttk.Label(self.register_frame, text="Password:").grid(row=2, column=0, sticky=tk.W, pady=(0, 5))
        self.register_password = tk.StringVar()
        register_password_entry = ttk.Entry(
            self.register_frame, textvariable=self.register_password, show="*", width=30
        )
        register_password_entry.grid(row=3, column=0, pady=(0, 15))

        # Confirm Password
        ttk.Label(self.register_frame, text="Confirm Password:").grid(row=4, column=0, sticky=tk.W, pady=(0, 5))
        self.register_confirm_password = tk.StringVar()
        register_confirm_entry = ttk.Entry(
            self.register_frame, textvariable=self.register_confirm_password, show="*", width=30
        )
        register_confirm_entry.grid(row=5, column=0, pady=(0, 20))

        # Register button
        register_button = ttk.Button(
            self.register_frame, text="Register", command=self._handle_register, style="Accent.TButton"
        )
        register_button.grid(row=6, column=0, pady=(0, 10))

        # Bind Enter key to register
        register_username_entry.bind("<Return>", lambda e: self._handle_register())
        register_password_entry.bind("<Return>", lambda e: self._handle_register())
        register_confirm_entry.bind("<Return>", lambda e: self._handle_register())

    def _setup_status_info(self) -> None:
        """Set up status information display."""
        # User count info
        user_count = self.user_manager.get_user_count()
        max_users = self.user_manager.MAX_USERS

        status_text = f"Registered Users: {user_count}/{max_users}"
        if not self.user_manager.can_register_more_users():
            status_text += " (Maximum reached)"

        self.status_label = ttk.Label(self.frame, text=status_text, font=("Arial", 10), foreground="gray")
        self.status_label.grid(row=3, column=0, columnspan=2, pady=(10, 0))

    def _handle_login(self) -> None:
        """Handle login button click."""
        username = self.login_username.get().strip()
        password = self.login_password.get()

        if not username or not password:
            messagebox.showerror("Error", "Please enter both username and password")
            return

        success, message = self.user_manager.login_user(username, password)

        if success:
            messagebox.showinfo("Success", message)
            self.on_login_success()
        else:
            messagebox.showerror("Login Failed", message)

    def _handle_register(self) -> None:
        """Handle registration button click."""
        username = self.register_username.get().strip()
        password = self.register_password.get()
        confirm_password = self.register_confirm_password.get()

        if not username or not password or not confirm_password:
            messagebox.showerror("Error", "Please fill in all fields")
            return

        if password != confirm_password:
            messagebox.showerror("Error", "Passwords do not match")
            return

        success, message = self.user_manager.register_user(username, password)

        if success:
            messagebox.showinfo("Success", message)
            # Clear registration form
            self.register_username.set("")
            self.register_password.set("")
            self.register_confirm_password.set("")
            # Switch to login tab
            self.notebook.select(0)
            # Update status
            self._update_status()
        else:
            messagebox.showerror("Registration Failed", message)

    def _update_status(self) -> None:
        """Update the status information display."""
        user_count = self.user_manager.get_user_count()
        max_users = self.user_manager.MAX_USERS

        status_text = f"Registered Users: {user_count}/{max_users}"
        if not self.user_manager.can_register_more_users():
            status_text += " (Maximum reached)"

        self.status_label.config(text=status_text)

    def show(self) -> None:
        """Show the authentication screen."""
        self.frame.grid()

    def hide(self) -> None:
        """Hide the authentication screen."""
        self.frame.grid_remove()
