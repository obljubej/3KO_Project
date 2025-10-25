DCM Requirements

1. General Description
   The Device Controller-Monitor (DCM) is a desktop application designed to interface with a pacemaker simulation system. For Deliverable 1, the DCM frontend should provide user account management, parameter setup, display, and rigorous input validation. Communication with hardware is not required at this stage.

2. User Management
   Support up to 10 local users.

Provide a registration and login screen.

Store user data locally.

Prevent duplicate usernames.

3. Core Functional Requirements
   3.1. Window and Screen Management
   Implement a welcome screen for authentication.

After login, display the DCM main screen for programming and monitoring.

3.2. Pacemaker Mode Display
Present all implemented pacemaker modes (AOO, VOO, AAI, VVI).

Modes should be selectable through the GUI.

3.3. Parameter Management
Display and allow editing of the following programmable parameters:

Lower Rate Limit (LRL)

Upper Rate Limit (URL)

Atrial Amplitude

Atrial Pulse Width

Ventricular Amplitude

Ventricular Pulse Width

VRP (Ventricular Refractory Period)

ARP (Atrial Refractory Period)

All parameters must be validated—only accept values within specification limits.

Changes should be saved to disk per user profile.

3.4. Data Storage
Use persistent local files to save all profiles, settings, and parameters.

Program structure must accommodate future storage of electrogram (egram) data.

3.5. User Interface
Parameters must be adjustable via form fields or dropdowns.

Current values must always be visible.

The interface should highlight validation errors in real time.

4. Documentation and Code Structure
   All public functions, data structures, and classes must be commented.

Use clear, descriptive variable and file naming.

Provide internal documentation for module interaction and GUI logic.

5. Constraints
   No communication with the pacemaker hardware in Deliverable 1.

Follow project security guidelines for handling user data.
