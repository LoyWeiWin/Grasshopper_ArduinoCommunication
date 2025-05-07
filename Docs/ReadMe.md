# Grasshopper_ArduinoCommunication

**Grasshopper_ArduinoCommunication** enables dynamic serial communication between Grasshopper (a visual programming environment within Rhino) and Arduino microcontrollers.

## Features
- **Board Compatibility**: Tested with Arduino UNO and Mega boards.
- **Responsive Serial Communication**: Supports dynamic data exchange between Grasshopper and Arduino using the Firefly plugin.
- **Modular and Open**: Designed for prototyping, educational use, and HCI research.

## Compatibility Notes

- **Grasshopper**: Native to Rhino 6/7; limited support in Rhino 8 due to .NET runtime changes.
- **Firefly Plugin**: Requires `.NET Framework`. Use `SetDotNetRuntime` in Rhino 8 to switch from `.NET Core`.
- **Arduino IDE**: Compatible with Arduino IDE 2.3.6 and earlier.

## Requirements

- **Grasshopper** (included in Rhino 6/7)
- **Firefly Plugin** ([Download](https://www.food4rhino.com/en/app/firefly))
- **Arduino IDE** ([Download](https://www.arduino.cc/en/software))
- **Arduino Boards**: UNO, Mega

## Getting Started

Introductory tutorials:

- [Introduction to Firefly for Grasshopper](https://www.youtube.com/watch?v=a1fwyfkEHAg)
- [Interactive Design with Firefly](https://www.youtube.com/watch?v=4cGnw35fzzM)
- [Arduino Guide](https://www.arduino.cc/en/Guide/)

## Repository Structure

- `Project/`: Grasshopper scripts, Arduino sketches (need to upload to the microcontrollers prior interfacing with grasshopper), Wiring schematics, Diagrammatic sketches, Usage
- `Assets/`: Images, thumbnails, and videos
- `Docs/`: Additional local documentation

## Limitations

- Rhino 8 support is limited; ensure correct .NET runtime is set
- Only one COM port/device supported at a time

## Contributing

We welcome contributions to improve this repository. Please refer to the [Contributing Guidelines](https://github.com/LoyWeiWin/Grasshopper_ArduinoCommunication/wiki/05_Contributing-Guidelines) in the Wiki.

## Code of Conduct

This project follows the Contributor Covenant Code of Conduct. Please read the [Code of Conduct](https://github.com/LoyWeiWin/Grasshopper_ArduinoCommunication/blob/main/CODE_OF_CONDUCT.md) before contributing.

## Safety Disclaimer

If you are unfamiliar with Arduino or electronics, seek supervision from a qualified advisor or instructor before working with physical components. While many Arduino applications operate at low voltage, some functions—such as driving motors, actuators, or high-current loads—require additional power sources or external circuitry, which may introduce electrical hazards if mishandled.

Improper wiring or grounding can lead to equipment damage, fire hazards, or personal injury. Always follow best practices in electronics, and if your setup involves voltages above 12V, high current, or external power supplies, ensure you have formal electrical training and wear proper PPE (Personal Protective Equipment) such as insulated gloves, safety glasses, and antistatic protection.

To mitigate risks, you are strongly encouraged to simulate your workflow using virtual tools like TinkerCAD Circuits before attempting physical deployment.

The contributors and maintainers of this repository are not responsible for any physical damage, injury, or environmental harm resulting from improper or unsafe use of the provided resources.

## Author

Developed by Loy Wei Win  
PhD Researcher in Human-Robot Interaction and Parametric Design Systems

If used in academic work, please cite:

> Loy W. Win, *Grasshopper_ArduinoCommunication*, GitHub (2025).
