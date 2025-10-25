"""Pacemaker Parameters Module for DCM Application

This module defines the pacemaker parameters, validation rules,
and parameter management functionality as specified in the requirements.
"""

from dataclasses import dataclass
from enum import Enum
from typing import Any, Dict, List, Tuple


class PacemakerMode(Enum):
    """Enumeration of supported pacemaker modes."""

    AOO = "AOO"
    VOO = "VOO"
    AAI = "AAI"
    VVI = "VVI"


@dataclass
class ParameterLimits:
    """Data class defining parameter limits for validation."""

    min_value: float
    max_value: float
    step: float = 1.0
    unit: str = ""


class PacemakerParameters:
    """Manages pacemaker parameters with validation according to specifications.
    All parameters are validated against their defined limits.
    """

    # Parameter limits as specified in requirements
    PARAMETER_LIMITS = {
        "lower_rate_limit": ParameterLimits(30, 175, 5, "ppm"),
        "upper_rate_limit": ParameterLimits(50, 175, 5, "ppm"),
        "atrial_amplitude": ParameterLimits(0.1, 5.0, 0.1, "V"),
        "atrial_pulse_width": ParameterLimits(0.1, 1.9, 0.1, "ms"),
        "ventricular_amplitude": ParameterLimits(0.1, 5.0, 0.1, "V"),
        "ventricular_pulse_width": ParameterLimits(0.1, 1.9, 0.1, "ms"),
        "vrp": ParameterLimits(150, 500, 10, "ms"),  # Ventricular Refractory Period
        "arp": ParameterLimits(150, 500, 10, "ms"),  # Atrial Refractory Period
    }

    def __init__(self):
        """Initialize pacemaker parameters with default values."""
        self.mode = PacemakerMode.AOO
        self.parameters = {
            "lower_rate_limit": 60.0,
            "upper_rate_limit": 120.0,
            "atrial_amplitude": 3.5,
            "atrial_pulse_width": 0.4,
            "ventricular_amplitude": 3.5,
            "ventricular_pulse_width": 0.4,
            "vrp": 320,
            "arp": 250,
        }
        self._validation_errors = {}

    def set_parameter(self, param_name: str, value: float) -> Tuple[bool, str]:
        """Set a parameter value with validation.

        Args:
            param_name: Name of the parameter to set
            value: Value to set

        Returns:
            Tuple of (success, error_message)
        """
        if param_name not in self.PARAMETER_LIMITS:
            return False, f"Unknown parameter: {param_name}"

        limits = self.PARAMETER_LIMITS[param_name]

        # Validate value is within limits
        if value < limits.min_value or value > limits.max_value:
            return False, f"Value must be between {limits.min_value} and {limits.max_value} {limits.unit}"

        # Validate step size
        if (value - limits.min_value) % limits.step != 0:
            return False, f"Value must be in increments of {limits.step} {limits.unit}"

        # Additional validation for specific parameters
        if param_name == "upper_rate_limit" and value <= self.parameters["lower_rate_limit"]:
            return False, "Upper rate limit must be greater than lower rate limit"

        if param_name == "lower_rate_limit" and value >= self.parameters["upper_rate_limit"]:
            return False, "Lower rate limit must be less than upper rate limit"

        # Set the parameter
        self.parameters[param_name] = value
        self._validation_errors.pop(param_name, None)

        return True, ""

    def get_parameter(self, param_name: str) -> float:
        """Get a parameter value.

        Args:
            param_name: Name of the parameter to get

        Returns:
            Parameter value
        """
        return self.parameters.get(param_name, 0.0)

    def get_all_parameters(self) -> Dict[str, float]:
        """Get all parameter values."""
        return self.parameters.copy()

    def set_mode(self, mode: PacemakerMode) -> None:
        """Set the pacemaker mode.

        Args:
            mode: The pacemaker mode to set
        """
        self.mode = mode

    def get_mode(self) -> PacemakerMode:
        """Get the current pacemaker mode."""
        return self.mode

    def get_available_modes(self) -> List[PacemakerMode]:
        """Get list of available pacemaker modes."""
        return list(PacemakerMode)

    def validate_all_parameters(self) -> Dict[str, str]:
        """Validate all parameters and return any errors.

        Returns:
            Dictionary of parameter names to error messages
        """
        errors = {}

        for param_name, value in self.parameters.items():
            success, error_msg = self.set_parameter(param_name, value)
            if not success:
                errors[param_name] = error_msg

        return errors

    def get_parameter_info(self, param_name: str) -> Dict[str, Any]:
        """Get information about a parameter including limits and current value.

        Args:
            param_name: Name of the parameter

        Returns:
            Dictionary with parameter information
        """
        if param_name not in self.PARAMETER_LIMITS:
            return {}

        limits = self.PARAMETER_LIMITS[param_name]
        return {
            "name": param_name,
            "current_value": self.parameters.get(param_name, 0.0),
            "min_value": limits.min_value,
            "max_value": limits.max_value,
            "step": limits.step,
            "unit": limits.unit,
            "error": self._validation_errors.get(param_name, ""),
        }

    def get_all_parameter_info(self) -> Dict[str, Dict[str, Any]]:
        """Get information for all parameters."""
        return {param_name: self.get_parameter_info(param_name) for param_name in self.PARAMETER_LIMITS.keys()}

    def reset_to_defaults(self) -> None:
        """Reset all parameters to their default values."""
        self.parameters = {
            "lower_rate_limit": 60.0,
            "upper_rate_limit": 120.0,
            "atrial_amplitude": 3.5,
            "atrial_pulse_width": 0.4,
            "ventricular_amplitude": 3.5,
            "ventricular_pulse_width": 0.4,
            "vrp": 320,
            "arp": 250,
        }
        self._validation_errors = {}

    def to_dict(self) -> Dict[str, Any]:
        """Convert parameters to dictionary for storage."""
        return {"mode": self.mode.value, "parameters": self.parameters.copy()}

    def from_dict(self, data: Dict[str, Any]) -> None:
        """Load parameters from dictionary.

        Args:
            data: Dictionary containing parameter data
        """
        if "mode" in data:
            try:
                self.mode = PacemakerMode(data["mode"])
            except ValueError:
                self.mode = PacemakerMode.AOO

        if "parameters" in data:
            for param_name, value in data["parameters"].items():
                if param_name in self.parameters:
                    self.parameters[param_name] = float(value)
