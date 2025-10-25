"""User Management Module for DCM Application

This module handles user registration, authentication, and local storage
for up to 10 users as required by the DCM specifications.
"""

import json
import os
from dataclasses import dataclass
from typing import Dict, Optional, Tuple


@dataclass
class User:
    """Data class representing a user in the system."""

    username: str
    password: str  # In a real application, this would be hashed
    profile_data: Dict = None

    def __post_init__(self):
        """Initialize the User class."""
        if self.profile_data is None:
            self.profile_data = {}


class UserManager:
    """Manages user accounts and authentication for the DCM application.
    Supports up to 10 local users with persistent storage.
    """

    MAX_USERS = 10
    DATA_FILE = "users.json"

    def __init__(self, data_dir: str = "data"):
        """Initialize the UserManager.

        Args:
            data_dir: Directory to store user data files
        """
        self.data_dir = data_dir
        self.users: Dict[str, User] = {}
        self.current_user: Optional[User] = None
        self._ensure_data_directory()
        self._load_users()

    def _ensure_data_directory(self) -> None:
        """Create data directory if it doesn't exist."""
        if not os.path.exists(self.data_dir):
            os.makedirs(self.data_dir)

    def _load_users(self) -> None:
        """Load users from persistent storage."""
        file_path = os.path.join(self.data_dir, self.DATA_FILE)
        if os.path.exists(file_path):
            try:
                with open(file_path, "r") as f:
                    data = json.load(f)
                    for username, user_data in data.items():
                        self.users[username] = User(
                            username=user_data["username"],
                            password=user_data["password"],
                            profile_data=user_data.get("profile_data", {}),
                        )
            except (json.JSONDecodeError, KeyError) as e:
                print(f"Error loading users: {e}")
                self.users = {}

    def _save_users(self) -> None:
        """Save users to persistent storage."""
        file_path = os.path.join(self.data_dir, self.DATA_FILE)
        try:
            data = {}
            for username, user in self.users.items():
                data[username] = {
                    "username": user.username,
                    "password": user.password,
                    "profile_data": user.profile_data,
                }

            with open(file_path, "w") as f:
                json.dump(data, f, indent=2)
        except Exception as e:
            print(f"Error saving users: {e}")

    def register_user(self, username: str, password: str) -> Tuple[bool, str]:
        """Register a new user.

        Args:
            username: Username for the new user
            password: Password for the new user

        Returns:
            Tuple of (success, message)
        """
        # Check if we've reached the maximum number of users
        if len(self.users) >= self.MAX_USERS:
            return False, f"Maximum number of users ({self.MAX_USERS}) reached"

        # Check if username already exists
        if username in self.users:
            return False, "Username already exists"

        # Validate username and password
        if not username or not password:
            return False, "Username and password cannot be empty"

        if len(username) < 3:
            return False, "Username must be at least 3 characters long"

        if len(password) < 4:
            return False, "Password must be at least 4 characters long"

        # Create new user
        new_user = User(username=username, password=password)
        self.users[username] = new_user
        self._save_users()

        return True, "User registered successfully"

    def login_user(self, username: str, password: str) -> Tuple[bool, str]:
        """Authenticate a user.

        Args:
            username: Username to authenticate
            password: Password to verify

        Returns:
            Tuple of (success, message)
        """
        if username not in self.users:
            return False, "User not found"

        user = self.users[username]
        if user.password != password:
            return False, "Invalid password"

        self.current_user = user
        return True, "Login successful"

    def logout_user(self) -> None:
        """Logout the current user."""
        self.current_user = None

    def get_current_user(self) -> Optional[User]:
        """Get the currently logged in user."""
        return self.current_user

    def is_logged_in(self) -> bool:
        """Check if a user is currently logged in."""
        return self.current_user is not None

    def get_user_count(self) -> int:
        """Get the current number of registered users."""
        return len(self.users)

    def can_register_more_users(self) -> bool:
        """Check if more users can be registered."""
        return len(self.users) < self.MAX_USERS
