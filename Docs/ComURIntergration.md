# Universal Robots  Integration

## 1. Overview
The computational protocol allows external systems (like Grasshopper) to read and write variables on a UR robot controller in real time.

The **Grasshopper_Machine-Bridge** uses MML and Robot Plugin for:
- Monitoring robot states (TCP pose, digital IO, joint velocities)
- Sending high-level commands (e.g., set DO, speed scaling, program start/stop)
- Synchronizing ambient feedback (e.g., LEDs or sound when motion states change)

---

## 2. Setup

### Requirements
- UR robot (UR3–UR10e)
- Proper URCaps installed.
- Robot connected to same LAN as host PC
- Known IP address (e.g., `192.168.30.66`)

### Steps
1. On the UR pendant, ensure **Remote Control** is permitted.  
2. Open Grasshopper and load the script.  
3. Enter:
   - `Robot IP` → `192.168.x.x`
   - `Port` → `30004`
4. Start trigger button; verify live feedback (TCP pose, program state).

---

## 3. Data Rate Notes
| Frequency | Latency | Use Case |
|------------|----------|----------|
| 10 Hz | ~100 ms | Human-perceptible feedback loops |
| 50 Hz | ~30 ms | Visual intention mapping (LEDs, AR cues) |
| 125 Hz | ~8 ms | Low-level control (avoid for UDP or Firefly) |


