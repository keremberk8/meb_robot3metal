<div align="center">

# 🤖 MEB Robot 3 — Metal

**Third robot configuration • metal motors • 7 cm wheels**

![C++](https://img.shields.io/badge/C%2B%2B-Arduino-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)
![Robotics](https://img.shields.io/badge/Robotics-Embedded-111827?style=for-the-badge)
![Status](https://img.shields.io/badge/Status-Development-f59e0b?style=for-the-badge)

</div>

---

## 🧭 Overview

Firmware and experiments for the **third MEB robot configuration**, using metal motors and 7 cm wheels. This repository is kept separate because the mechanical setup changes the robot's motion characteristics and therefore the control code.

## ⚙️ Hardware Context

| Component | Configuration |
|---|---|
| Robot version | MEB Robot 3 |
| Motor setup | Metal motors |
| Wheel size | 7 cm |
| Controller | Arduino-based |
| Firmware | C/C++ |

## 🧠 Control Model

```text
Sensor Input
     ↓
State / Decision Logic
     ↓
Motor Commands
     ↓
Mechanical Response
     ↓
Calibration & Iteration
```

The firmware should be tuned against the actual motor polarity, wheel geometry and chassis behavior before competition use.

## 🛠️ Stack

**C/C++ · Arduino IDE · Embedded Systems · Motor Control · Robotics**

## 🚀 Getting Started

1. Open the matching `.ino` sketch.
2. Select the correct Arduino board and port.
3. Check every pin assignment against the current wiring.
4. Upload and verify left/right motor direction.
5. Calibrate movement before autonomous logic.

## 🚧 Status

**Robot development configuration**

Part of the broader MEB robotics development history maintained across the SWAXFORCE and personal repositories.
