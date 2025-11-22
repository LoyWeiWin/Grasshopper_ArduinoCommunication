# Transport Layer — Serial and UDP Communication Design

## 1. Overview
Two primary communication modes are supported:
1. **Serial (USB)** — low-latency tethered connection for single-board setups.  
2. **UDP (Wi-Fi)** — wireless, multi-node, non-blocking transmission for ESP32 boards.

---

## 2. Serial Transport

| Parameter | Value |
|------------|--------|
| **Protocol** | UART via USB |
| **Baud Rate** | 115200 bps |
| **Message Format** | ASCII framed or binary packet |
| **Error Handling** | Simple CRC or checksum |
| **Recommended Frequency** | 10–50 Hz |

**Example Message (ASCII mode):**
```
<lux:0.68,prox:32.1,trigger:1>
```

**Grasshopper Firefly Integration**
- Use **“Serial Read”** and **“Serial Write”** components.
- Normalize float values between `0.0–1.0` for sensor consistency.

---

## 3. UDP (Wi-Fi) Transport

| Parameter | Value |
|------------|--------|
| **Protocol** | UDP/IP (port configurable) |
| **Typical Ports** | 8888 (RX), 9999 (TX) |
| **Reliability** | Connectionless — may drop packets |
| **Payload Format** | UTF-8 JSON or binary (≤ 256 bytes) |
| **Recommended Frequency** | ≤ 100 Hz |

**Example UDP Packet (JSON)**
```json
{
  "lux": 0.75,
  "prox": 42.3,
  "trigger": true
}
```

---

## 4. Packet Structure

| Field | Type | Description |
|--------|------|-------------|
| `id` | int | message ID for tracking |
| `type` | string | “sensor”, “command”, “heartbeat” |
| `data` | object | key-value pairs for parameters |
| `crc` | int | optional checksum |

**Binary Layout (optional for performance):**
```
| STX | LEN | TYPE | DATA... | CRC | ETX |
```

---

## 5. Quality of Service (QoS) Strategies

| Issue | Mitigation |
|--------|-------------|
| Packet loss (UDP) | Heartbeat every 1 s; re-broadcast critical states |
| Out-of-order frames | Use sequence `id` field |
| Noise spikes | Apply Kalman or EMA filters in GH |
| Buffer overflow | Throttle send rate / clear serial buffer periodically |
| Mixed transport bridging | Use GH “Transport Switch” cluster for unified parsing |

---

## 6. Future Extensions
- MQTT broker integration for multi-client cloud sync  
- TCP-based fallback layer for critical feedback loops  
- Real-time OSC compatibility for AV-based installations
