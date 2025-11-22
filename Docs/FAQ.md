# Frequently Asked Questions (FAQ)

### Q1: Can I use this without Universal Robots hardware?
Yes. Many demos function standalone with only Grasshopper and Arduino/ESP32.  
RTDE-related clusters simply remain inactive.

---

### Q2: Why two communication types (Serial and UDP)?
- **Serial** — reliable, low-latency tethered connection for lab prototyping.  
- **UDP** — enables distributed, untethered sensing setups (Wi-Fi).  

Use Serial for precision experiments and UDP for multi-node interaction.

---

### Q3: My UDP packets are inconsistent. What should I do?
Check:
1. Wi-Fi strength and channel interference.  
2. Packet size (< 256 bytes).  
3. Add sequence numbers and ignore out-of-order packets in Grasshopper.

---

### Q4: How do I integrate additional sensors?
1. Place your code in `/Project/_shared/arduino/`.  
2. Send normalized float values (0–1).  
3. Update the target demo’s `manifest.yaml` with the new sensor.  

---

### Q5: Why does Firefly not detect my COM port?
- Confirm board drivers are installed.  
- Match the correct Baud rate (115200).  
- Restart Rhino after connecting the board.  

---

### Q6: Can I use this on Mac or Linux?
Grasshopper is Windows-only.  
However, you can use the UDP transport cross-platform (ESP32 <-> Python).

---

### Q7: What if the robot disconnects mid-operation?
The RTDE client will pause.  
Manually reset using the **Dashboard Server** or re-run the Grasshopper patch.

---

### Q8: How do I contribute new demos?
1. Copy from `/templates/demo/`.  
2. Add `manifest.yaml` + `README.md`.  
3. Submit a Pull Request with your files, description, and safety note.

---

### Q9: Is this open-source?
Yes. Licensed under **GPL-3.0**, encouraging academic and non-commercial use.

---

### Q10: Where can I find more documentation?
See `/Docs/architecture.md`, `/Docs/transports.md`, and `/Docs/ur-rtde.md` for in-depth technical design.
