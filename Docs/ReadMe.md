# Grasshopper_Machine-Bridge  
*(formerly **Grasshopper_ArduinoCommunication**)*

**Grasshopper_Machine-Bridge** is a modular, bidirectional communication framework connecting **Grasshopper** (Rhino), **Universal Robots (UR RTDE)**, and **Arduino/ESP32** microcontrollers.  

It allows ambient sensing (light, proximity, buttons, audio cues) and robotic feedback (LEDs, buzzers, motion visualization) to work in tandem—enabling **legible, expressive, and context-aware non-anthropomorphic robots**.

---

## Key Features
- **Bidirectional Communication:** Real-time data exchange between Grasshopper, UR robots, and Arduino/ESP32.  
- **Multi-Protocol Support:** Serial (USB) and UDP/Wi-Fi for flexible setups.  
- **UR Integration:** Direct connection to UR and Dashboard Server for robot state feedback and motion control.  
- **Ambient Interaction:** Translate environmental changes into robotic responses, and vice versa.  
- **Extensible Demo Library:** Each demo showcases a unique sensing/actuation workflow—ready to fork, extend, or remix.  

---

## 🖥Compatibility

| Component | Notes |
|------------|-------|
| **Grasshopper** | Rhino 6, 7, 8 (*ensure correct .NET runtime in Rhino 8*) |
| **Arduino IDE / ESP32** | Works with UNO, Mega, and ESP32 boards (Wi-Fi capable) |
| **Firefly / UDP Plugins** | For serial or network communication within Grasshopper |

---

##  Requirements
- **Rhino + Grasshopper**  
- **Arduino IDE 2.x** or ESP32 core ([Installation Guide](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html))  
- **Firefly Plugin** ([Download](https://www.food4rhino.com/en/app/firefly))  
- **Optional:** Stable Wi-Fi connection for UDP communication  

---

## Getting Started

### 1 – Explore a Demo
Each demo lives in `/Project/demos/<demo-name>/` and includes:
- `serial/` and `udp/` variants (for Arduino and ESP32)
- `.ino` and `.gh` files
- wiring diagrams and media assets
- a local `README.md` (human guide)
- a `manifest.yaml` (machine-readable metadata)

Example:
```
/Project/demos/lux-trigger/
  /serial/
    LuxTrigger_Serial.gh
    LuxTrigger_Serial.ino
    wiring-LDR.pdf
    README.md
  /udp/
    LuxTrigger_UDP.gh
    LuxTrigger_UDP.ino
    wiring-LDR-ESP32.pdf
    README.md
  manifest.yaml
```

### 2 – Upload Firmware  
Upload the relevant `.ino` from the chosen variant folder.  
Use **Serial** for Arduino (USB) or **UDP** for ESP32 (Wi-Fi).

### 3 – Run Grasshopper Script  
Open the corresponding `.gh` file.  
Set COM port (Serial) or IP address (UDP).  
Start streaming data bidirectionally.

---

## Tutorials & References
- [Firefly for Grasshopper (Video)](https://www.youtube.com/watch?v=a1fwyfkEHAg)  
- [Interactive Design with Firefly](https://www.youtube.com/watch?v=4cGnw35fzzM)  
- [Arduino Getting Started Guide](https://www.arduino.cc/en/Guide/)  
- [ESP32 UDP Example](https://randomnerdtutorials.com/esp32-udp-client-arduino/)  

---

## Repository Structure
```
/Project/
  /_shared/             → Shared libraries & Grasshopper clusters
  /demos/               → Individual demo projects
  /templates/demo/      → Starter demo templates
/Docs/                  → Technical papers, safety, RTDE notes
/Assets/                → Images & videos
LICENSE
README.md               → Root overview
```

---

## 🧩 `manifest.yaml` vs `README.md` in Each Demo

| File | Purpose | Audience | Example Content |
|------|----------|-----------|----------------|
| **`manifest.yaml`** | Metadata for indexing, CI, and automation | Machines / scripts | name, slug, sensors, transports, board types, file paths |
| **`README.md`** | Instructions, wiring, behavior, safety notes | Humans (users / students / researchers) | setup steps, screenshots, expected output, troubleshooting |

---

## Repository Evolution
Originally developed as **Grasshopper_ArduinoCommunication**, this project focused solely on serial communication.  
It has since evolved into **Grasshopper_Machine-Bridge**, supporting **multi-protocol, bidirectional communication** between Grasshopper, UR RTDE, and Arduino/ESP32 hardware.  
The new modular structure enables dozens of stand-alone demos, each illustrating a distinct **human–robot interaction** or **intention visualization** workflow.

---

## Safety Disclaimer

If you are unfamiliar with **Arduino, ESP32, or electronics**, seek guidance from a qualified advisor before building physical prototypes.  
Although most circuits run at low voltage (5 V), driving motors, LED strips, or actuators can require external power and introduce hazards.

**Always:**
- Simulate first (e.g., *TinkerCAD Circuits*, *URSim*, *RoboDK*).  
- Keep a hardware **E-Stop** within reach.  
- Avoid live wiring on moving robots.  
- Follow institutional safety policies and wear proper PPE (gloves, glasses, ESD strap).  

The authors and maintainers assume **no liability** for damage or injury from improper use.

---

## 🧑Author
**Loy Wei Win**  
PhD Researcher, Human-Robot Interaction & Parametric Design Systems  
Queensland University of Technology (QUT)

> Loy W. Win, *Grasshopper_Machine-Bridge: A Bidirectional Interface for Robotic Legibility*, GitHub (2025)

---

## Contributing
1. Fork the repository and create a feature branch.  
2. Follow the existing naming and documentation style.  
3. Add your demo under `/Project/demos/`.  
4. Include a `manifest.yaml` and `README.md` for each variant.  
5. Submit a Pull Request with a clear description and media assets.

---

## Adding a New Demo (Quick Guide)
1. Copy `/templates/demo/serial` or `/templates/demo/udp` into `/Project/demos/<new-demo>/`.  
2. Rename files (e.g., `MyDemo_Serial.ino`, `MyDemo_Serial.gh`).  
3. Edit the demo’s `manifest.yaml`.  
4. Update the local `README.md` with setup instructions and safety notes.  
5. Test in simulation → tethered → Wi-Fi progression.  
