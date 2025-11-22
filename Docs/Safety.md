# Safety Guidelines and Lab SOPs

## 1. General Principles
Work involving robots and electronic systems requires vigilance, situational awareness, and proper supervision.  
Even collaborative robots (e.g., UR10e) can cause harm if misconfigured or improperly wired.

---

## 2. Safety Hierarchy
1. **Simulate First** — Test logic in *URSim* or *RoboDK* before physical execution.  
2. **Tethered Mode** — Validate serial or UDP connection with robot motors off.  
3. **Reduced-Speed Mode** — Activate movement only within 250 mm/s limit.  
4. **Full Operation** — Proceed only when observers and PPE are in place.

---

## 3. Electrical Safety
- Never power high-current LED strips directly from the board’s 5 V line.  
- Use **external supplies with common ground** and **inline fuses**.  
- Keep all cables strain-relieved and insulated.  
- Disconnect power before modifying circuits.  

---

## 4. Robot Safety
- Always enable the **Emergency Stop (E-Stop)**.  
- Define **workspace boundaries** via UR teach pendant.  
- Avoid dynamic reprogramming during motion.  
- Ensure **TCP orientation stability** before tracking targets.

---

## 5. Fire, Burn, and Shock Hazards
| Risk | Prevention |
|-------|-------------|
| Short circuit | Use insulated jumpers, breadboards, or PCB shields |
| Overcurrent heating | Add inline fuses; keep LED brightness ≤ 60% |
| ESP32 overheating | Provide airflow; use sleep modes when idle |

---

## 6. Laboratory PPE
- Safety glasses  
- Non-conductive gloves  
- Closed shoes  
- Anti-static wrist strap when handling components  

---

## 7. Supervision and Documentation
- All experiments must be supervised by a **qualified instructor or technician**.  
- Maintain an experiment log (date, operator, configuration, result).  
- Photograph wiring before powering up.  

---

## 8. Disclaimer
The maintainers of **Grasshopper_Machine-Bridge** are not liable for injuries, property damage, or data loss arising from improper use of the resources.  
Follow institutional and national robotics safety standards (e.g., ISO 10218-1, ISO 15066).
