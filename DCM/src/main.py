"""Main Application for Device Controller-Monitor (DCM).

This is the main entry point for the DCM application that provides
pacemaker simulation system interface as specified in the requirements.
"""

import os
import sys
import tkinter as tk
from tkinter import ttk

# Add src directory to path for imports
sys.path.append(os.path.dirname(os.path.abspath(__file__)))

from gui.auth_screen import AuthScreen
from gui.main_screen import MainScreen
from user_management import UserManager


class DCMApplication:
    """Main application class for the Device Controller-Monitor (DCM).

    Manages the application lifecycle and screen transitions.
    """

    def __init__(self):
        """Initialize the DCM application."""
        self.root = tk.Tk()
        self.user_manager = UserManager()
        self.auth_screen = None
        self.main_screen = None
        self._setup_application()

    def _setup_application(self) -> None:
        """Set up the application window and initial state."""
        # Configure main window
        self.root.title("Device Controller-Monitor (DCM)")
        self.root.geometry("800x600")
        self.root.minsize(600, 400)

        # Configure style
        style = ttk.Style()
        style.theme_use("clam")

        # Configure grid weights for responsive layout
        self.root.columnconfigure(0, weight=1)
        self.root.rowconfigure(0, weight=1)

        # Start with authentication screen
        self._show_auth_screen()

    def _show_auth_screen(self) -> None:
        """Show the authentication screen."""
        if self.main_screen:
            self.main_screen.hide()

        self.auth_screen = AuthScreen(self.root, self.user_manager, self._on_login_success)
        self.auth_screen.show()

    def _show_main_screen(self) -> None:
        """Show the main application screen."""
        if self.auth_screen:
            self.auth_screen.hide()

        self.main_screen = MainScreen(self.root, self.user_manager, self._on_logout)
        self.main_screen.show()

    def _on_login_success(self) -> None:
        """Handle successful login."""
        self._show_main_screen()

    def _on_logout(self) -> None:
        """Handle user logout."""
        self._show_auth_screen()

    def run(self) -> None:
        """Run the application."""
        try:
            self.root.mainloop()
        except KeyboardInterrupt:
            print("Application interrupted by user")
        except Exception as e:
            print(f"Application error: {e}")
            raise


def main():
    """Main entry point for the DCM application."""
    print("Starting Device Controller-Monitor (DCM)...")

    try:
        app = DCMApplication()
        app.run()
    except Exception as e:
        print(f"Failed to start application: {e}")
        sys.exit(1)

    print("DCM application closed.")


if __name__ == "__main__":
    main()
