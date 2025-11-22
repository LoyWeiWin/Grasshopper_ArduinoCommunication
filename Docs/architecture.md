# Grasshopper_Machine-Bridge — System Architecture

## 1. Overview
The **Grasshopper_Machine-Bridge** acts as a distributed communication framework between:
- **Grasshopper (Rhino)** — the computational design interface;
- **Universal Robots (UR)** — via the **Real-Time Data Exchange (RTDE)** protocol;
- **Arduino / ESP32 boards** — providing sensor inputs and ambient actuation outputs.

The system enables **bidirectional interaction** between humans and non-anthropomorphic robots, allowing environmental conditions (e.g., light, proximity, audio) to influence robot behavior while exposing robotic intentions through ambient media (LEDs, sound, motion).

---

## 2. Data Flow

```
[Sensor / Environment]
        ↓
 [Arduino / ESP32]
   (Serial or UDP)
        ↓
 [Grasshopper]
        ↓
 [UR RTDE Interface]
        ↓
 [Robot Controller → Physical Robot]
        ↑
 [Feedback Stream (TCP States, Tool Data, DO/DI)]
        ↑
 [Visualization Nodes: LEDs / Buzzers / GUI]
```

---

## 3. State Diagram

```
┌─────────────┐      sensor event     ┌───────────────┐
│ Idle / Wait │ ───────────────────▶ │ Data Acquired │
└─────────────┘                      └───────────────┘
       ▲                                     │
       │                                     ▼
       │                             ┌────────────────┐
       │     RTDE command / motion   │  Action Commit  │
       └──────────────────────────── │ (LED / Robot)   │
                                     └────────────────┘
                                              │
                                     feedback │ state
                                              ▼
                                     ┌────────────────┐
                                     │ Feedback Synch │
                                     └────────────────┘
```

---

## 4. Core Modules

| Module | Function | Location |
|--------|-----------|----------|
| **Transport Layer** | Serial and UDP packet handling | `/Project/_shared/arduino/` |
| **Grasshopper Cluster Layer** | Visual nodes for data parsing and actuation | `/Project/_shared/gh/` |
| **UR RTDE Client** | Handles robot data exchange | `/Project/_shared/ur/` |
| **Demo Layer** | Concrete implementations (Lux Trigger, Proximity Brake, etc.) | `/Project/demos/` |

---

## 5. Failure Modes and Mitigation

| Failure Mode | Cause | Mitigation |
|---------------|--------|-------------|
| **Dropped UDP packets** | Weak Wi-Fi or unacknowledged datagrams | Include redundancy & value smoothing in GH scripts |
| **Serial buffer overflow** | Excessive polling rate | Limit Baud to 115200, throttle updates at ~10–50 Hz |
| **UR RTDE sync loss** | RTDE disconnect > 1 s | Implement heartbeat checker + auto-reconnect |
| **Sensor noise / false trigger** | Environmental interference | Apply moving average or hysteresis threshold |
| **Hardware freeze** | Power fluctuation or cable strain | Use isolated 5 V supply + strain relief + watchdog timer |

---

## 6. Extensibility
- Modular structure allows integration of **new sensors** or **network protocols**.
- Grasshopper clusters act as reusable middleware nodes.
- ESP32’s Wi-Fi stack supports distributed sensing and robot state broadcasting.
