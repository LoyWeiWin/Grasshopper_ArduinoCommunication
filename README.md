# Grasshopper_ArduinoCommunication Library

The **Grasshopper_ArduinoCommunication** library is designed to facilitate seamless interaction between Grasshopper and Arduino boards. This library provides users with a suite of plugins to enhance communication and create a smoother, more intuitive workflow.

## Features
- **Compatibility:** Supports Arduino UNO, NANO, and Mega boards.
- **Real-time Communication:** Enables bi-directional communication between Grasshopper and Arduino via serial communication.

## Requirements
- **Grasshopper:** Ensure you have Grasshopper installed. Note: The Firefly plugin is not supported in Rhino 8.
- **Firefly Plugin:** Install the [Firefly Grasshopper Plugin](https://www.food4rhino.com/en/app/firefly) to enable communication between Grasshopper and Arduino. Use a Rhino version compatible with Firefly (e.g., Rhino 6 or 7).
- **Arduino IDE:** Install the [Arduino IDE](https://www.arduino.cc/en/software) to upload code to your Arduino boards.
- **Arduino Boards:** Compatible with Arduino UNO, NANO, and Mega.

## Installation
1. Download the library from the repository.
2. Place the downloaded files into your Grasshopper libraries folder.
   - On Windows: `C:\Users\[YourUsername]\AppData\Roaming\Grasshopper\Libraries`
3. Restart Rhino and Grasshopper.
4. Download and install the Firefly plugin from [Food4Rhino](https://www.food4rhino.com/en/app/firefly). Ensure you are using Rhino 6 or 7, as Firefly is not supported in Rhino 8.

## Getting Started
1. Open the Arduino IDE.
2. Load or write the desired Arduino sketch.
3. Upload the sketch to your Arduino board (UNO, NANO, or Mega).
4. In Grasshopper, use the Firefly plugin components to establish communication with the Arduino board.

## Example Use Cases
- Control LEDs, servos, or motors from Grasshopper.
- Read sensor data (e.g., temperature, light) into Grasshopper for further analysis.
- Develop interactive prototypes combining Grasshopper's computational design capabilities with Arduino's hardware interface.

## Tutorials
Here are some useful video tutorials to get you started:
- [Introduction to Firefly for Grasshopper](https://www.youtube.com/watch?v=a1fwyfkEHAg)
- [Firefly and Arduino LED Control](https://www.youtube.com/watch?v=TYRZSxwqlGg)
- [Reading Sensor Data with Firefly](https://www.youtube.com/watch?v=yyuM2p2UDsE)
- [Advanced Arduino Prototyping in Grasshopper](https://www.youtube.com/watch?v=RIMbaeGnDlI)
- [Interactive Design with Firefly](https://www.youtube.com/watch?v=4cGnw35fzzM)

## Contributions
Contributions are welcome! Please feel free to submit issues or pull requests to improve the library.


