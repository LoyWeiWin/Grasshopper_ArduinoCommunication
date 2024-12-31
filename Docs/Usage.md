# Usage Guide

## Grasshopper-to-Arduino Workflow

### 1. Open Grasshopper Script
1. Open Rhino and start Grasshopper.
2. Load `GrasshopperFiles/MainControl.gh`.

### 2. Connect to Arduino
- Set the serial port in the Grasshopper script to match your Arduino connection:
  - Example: COM3 (Windows) or /dev/ttyUSB0 (Linux/Mac).

### 3. Run the Workflow
- Start the workflow in Grasshopper:
  - Use the `SensorDataProcessing` module to read sensor data.
  - Use the `ActuatorControl` module to send commands to actuators.

### 4. Visualize Data
- The `Visualization.gh` module displays real-time sensor data in Grasshopper.

## Python Integration
For advanced data logging or visualization, run `PythonScripts/SerialCommunication.py`:
```bash
python PythonScripts/SerialCommunication.py
