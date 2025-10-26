"""Configuration loader for the pacemaker application.

This module provides a centralized way to load and manage configuration
from JSON files, making the codebase cleaner and more maintainable.
"""

import json
import os
from typing import Any, Dict, Tuple


class ConfigLoader:
    """Loads and manages configuration from JSON files."""

    def __init__(self, config_dir: str = "config"):
        """Initialize the configuration loader.

        Args:
            config_dir: Directory containing configuration files
        """
        self.config_dir = config_dir
        self._configs = {}
        self._load_all_configs()

    def _load_all_configs(self):
        """Load all configuration files."""
        config_files = {
            "mode_parameters": "mode_parameters.json",
            "colors": "colors.json",
            "fonts": "fonts.json",
            "app_config": "app_config.json",
        }

        for config_name, filename in config_files.items():
            try:
                self._configs[config_name] = self._load_json_file(filename)
            except Exception as e:
                print(f"Warning: Could not load {filename}: {e}")
                self._configs[config_name] = {}

    def _load_json_file(self, filename: str) -> Dict[str, Any]:
        """Load a JSON configuration file.

        Args:
            filename: Name of the JSON file to load

        Returns:
            Dictionary containing the configuration data

        Raises:
            FileNotFoundError: If the configuration file doesn't exist
            json.JSONDecodeError: If the JSON file is malformed
        """
        filepath = os.path.join(self.config_dir, filename)

        if not os.path.exists(filepath):
            raise FileNotFoundError(f"Configuration file not found: {filepath}")

        with open(filepath, "r") as f:
            return json.load(f)

    def get_mode_parameters(self) -> Dict[str, Any]:
        """Get pacemaker mode parameters configuration.

        Returns:
            Dictionary containing mode parameters for all pacemaker modes
        """
        return self._configs.get("mode_parameters", {})

    def get_colors(self) -> Dict[str, str]:
        """Get color scheme configuration.

        Returns:
            Dictionary containing color definitions
        """
        return self._configs.get("colors", {})

    def get_fonts(self) -> Dict[str, Tuple[str, int, str]]:
        """Get font configuration.

        Returns:
            Dictionary containing font definitions as tuples (family, size, style)
        """
        fonts = self._configs.get("fonts", {})
        # Convert lists back to tuples for font definitions
        return {name: tuple(font) for name, font in fonts.items()}

    def get_app_config(self) -> Dict[str, Any]:
        """Get application configuration.

        Returns:
            Dictionary containing application settings
        """
        return self._configs.get("app_config", {})

    def reload_config(self, config_name: str = None):
        """Reload configuration files.

        Args:
            config_name: Specific config to reload, or None to reload all
        """
        if config_name:
            config_files = {
                "mode_parameters": "mode_parameters.json",
                "colors": "colors.json",
                "fonts": "fonts.json",
                "app_config": "app_config.json",
            }
            if config_name in config_files:
                try:
                    self._configs[config_name] = self._load_json_file(config_files[config_name])
                except Exception as e:
                    print(f"Warning: Could not reload {config_name}: {e}")
        else:
            self._load_all_configs()


# Global configuration instance
config = ConfigLoader()
