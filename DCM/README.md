# Custom Pacemaker Device Controller-Monitor Application

A comprehensive pacemaker simulation system built with custom tkinter styling, featuring modern UI design, user authentication, parameter management, and device communication capabilities.

## Features

### 🎨 **Custom Styling**

- Modern color scheme with professional appearance
- Custom fonts and consistent styling throughout
- Responsive layout with proper grid management
- Theme-aware components

### 👤 **User Management**

- Support for up to 10 local users
- Secure authentication system
- User profile management with persistent storage
- Registration and login with validation

### ⚡ **Pacemaker Modes**

- **AOO**: Asynchronous Atrial Pacing
- **VOO**: Asynchronous Ventricular Pacing
- **AAI**: Atrial Pacing with Atrial Sensing
- **VVI**: Ventricular Pacing with Ventricular Sensing
- **AOOR**: Rate-Adaptive Asynchronous Atrial Pacing
- **AAIR**: Rate-Adaptive Atrial Pacing with Sensing
- **VOOR**: Rate-Adaptive Asynchronous Ventricular Pacing
- **VVIR**: Rate-Adaptive Ventricular Pacing with Sensing

### 🔧 **Parameter Management**

- Real-time parameter validation
- Interactive sliders with entry field synchronization
- Mode-specific parameter sets
- Range validation and step size enforcement
- Persistent parameter storage per user

### 📊 **EGRAM Visualization**

- Real-time signal visualization using matplotlib
- Atrial and ventricular signal simulation
- Interactive plotting with proper scaling
- Professional medical-grade appearance

### 🔌 **Device Communication**

- Serial communication simulation
- Structured data packet creation
- Mode-specific parameter encoding
- Send/Receive data functionality

### ⚙️ **Settings & Configuration**

- Language selection (English, French, Spanish, German, Chinese, Japanese)
- Theme selection (Light, Dark, System)
- UI scaling options (80% - 120%)
- Device information display

## Project Structure

```
pulse-point-dcm/
├── src/
│   └── main.py              # Main application with all functionality
├── data/
│   └── users.json           # User data storage
├── run.py                   # Main entry point script
├── requirements.txt          # Dependencies
├── README.md                # Documentation
└── pyproject.toml          # Project configuration
```

## Installation

### Prerequisites

```bash
pip install tkinter pillow matplotlib numpy pyserial
```

### Running the Application

```bash
# Run the main application
python run.py

# Or run directly from src
python src/main.py
```

## Usage

### 1. **Authentication**

- Register a new user with personal information
- Login with username and password
- User data is stored locally in JSON format

### 2. **Mode Selection**

- Choose from 8 different pacemaker modes
- Each mode has specific parameter sets
- Parameters automatically update based on selected mode

### 3. **Parameter Adjustment**

- Use sliders for intuitive parameter control
- Direct input via text fields
- Real-time validation with error messages
- Automatic synchronization between controls

### 4. **Data Management**

- Save parameters to user profile
- Load previously saved configurations
- Export/import parameter sets

### 5. **Device Communication**

- Send parameter data to simulated device
- Receive status information
- Structured binary data packet format

### 6. **Visualization**

- View EGRAM data in separate window
- Real-time signal plotting
- Professional medical visualization

## Architecture

### **CustomPacemakerApp**

Main application class managing window lifecycle and screen transitions.

### **UserManager**

Handles user authentication, registration, and data persistence.

### **PacemakerParameters**

Manages pacemaker parameters with validation and mode-specific configurations.

### **CustomStyle**

Centralized styling configuration with colors, fonts, and themes.

### **Screen Classes**

- `LoginScreen`: Authentication interface
- `MainScreen`: Primary application interface
- `SettingsWindow`: Application preferences
- `AboutWindow`: Device information display

## Parameter Specifications

### **Rate Parameters**

- Lower Rate Limit: 30-175 ppm (5 ppm steps)
- Upper Rate Limit: 50-175 ppm (5 ppm steps)
- Maximum Sensor Rate: 50-175 ppm (5 ppm steps)

### **Amplitude Parameters**

- Atrial/Ventricular Amplitude: 0.1-5.0 V (0.1 V steps)

### **Pulse Width Parameters**

- Atrial/Ventricular Pulse Width: 0.1-1.9 ms (0.1 ms steps)

### **Sensitivity Parameters**

- Atrial/Ventricular Sensitivity: 0.0-5.0 mV (0.1 mV steps)

### **Refractory Periods**

- ARP (Atrial Refractory Period): 150-500 ms (10 ms steps)
- VRP (Ventricular Refractory Period): 150-500 ms (10 ms steps)
- PVARP (Post-Ventricular Atrial Refractory Period): 150-500 ms (10 ms steps)

### **Rate Response Parameters**

- Activity Threshold: 0-6 (1 step)
- Reaction Time: 10-50 s (10 s steps)
- Response Factor: 1-16 (1 step)
- Recovery Time: 2-16 min (2 min steps)

## Data Format

### **Communication Protocol**

```
Header: 0x16 0x55
Chamber: 1 (Atrial) / 2 (Ventricular)
Sensing: 0 (Off) / 1 (On)
Rate Adaptive: 0 (Off) / 1 (On)
Parameters: Mode-specific parameter values
```

### **User Data Storage**

```json
{
  "username": {
    "username": "string",
    "password": "string",
    "first_name": "string",
    "last_name": "string",
    "age": "string",
    "profile_data": {
      "pacemaker_parameters": {
        "mode": "string",
        "parameters": {...}
      }
    }
  }
}
```

## Customization

### **Styling**

Modify `CustomStyle` class to change:

- Color scheme
- Font families and sizes
- Component styling
- Theme configurations

### **Parameters**

Add new parameters in `PacemakerParameters.MODE_PARAMETERS`:

```python
"Parameter_Name": {
    "min": minimum_value,
    "max": maximum_value,
    "step": step_size,
    "unit": "unit_string",
    "default": default_value
}
```

### **Modes**

Add new pacemaker modes in `PacemakerMode` enum and corresponding parameter sets.

## Error Handling

- Comprehensive input validation
- User-friendly error messages
- Graceful handling of missing files
- Exception handling for serial communication
- Validation for parameter ranges and types

## Future Enhancements

- Real serial device integration
- Advanced EGRAM analysis
- Parameter trending and history
- Multi-language support implementation
- Database integration for user management
- Advanced visualization features
- Export/import functionality
- Parameter templates and presets

## License

This project is developed for educational and research purposes in medical device simulation.

## Contributing

1. Follow the existing code structure and styling
2. Add comprehensive error handling
3. Include parameter validation
4. Maintain consistent UI/UX design
5. Add appropriate documentation

---

**Note**: This application is for educational and simulation purposes only. It should not be used for actual medical device control without proper certification and validation.
