# Troubleshooting Guide

## Common Issues and Solutions

### 1. Grasshopper Cannot Communicate with Arduino
- **Problem:** No data received from Arduino.
- **Solution:**
  1. Verify the correct serial port is set in the Grasshopper script.
  2. Check if another application is using the serial port.
  3. Ensure the Arduino sketch is uploaded and running.

### 2. Serial Port Not Detected
- **Problem:** The serial port does not appear in the dropdown.
- **Solution:**
  - Reconnect the Arduino.
  - Restart Rhino and Grasshopper.
  - Check the serial port in your system's device manager.

### 3. Grasshopper Freezes During Execution
- **Problem:** Script execution causes Grasshopper to freeze.
- **Solution:**
  - Reduce data polling frequency in the Arduino sketch.
  - Test the script with fewer components.

