#!/usr/bin/env python3
"""HeartForge-AI Device Controller Monitor

Main entry point for the pacemaker simulation application.
"""

import os
import sys

# Add the src directory to the path
sys.path.insert(0, os.path.join(os.path.dirname(__file__), "src"))

if __name__ == "__main__":
    try:
        from main import CustomPacemakerApp

        print("PulsePoint DCM")
        print("=" * 50)
        print("Starting pacemaker simulation application...")
        print()

        # Run the application
        app = CustomPacemakerApp()
        app.run()

    except ImportError as e:
        print(f"Error importing application: {e}")
        print("Make sure all required dependencies are installed:")
        print("pip install pillow matplotlib numpy")
        sys.exit(1)
    except Exception as e:
        print(f"Error running application: {e}")
        sys.exit(1)
