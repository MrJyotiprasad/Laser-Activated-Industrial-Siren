# Laser Based Industrial Siren System

An advanced Arduino-based industrial safety siren controller designed for laser-triggered motion/event detection with a modern OLED graphical interface, configurable siren delay timing, real-time countdown monitoring, and professional embedded UI animations.

---

# Table of Contents

- [Introduction](#introduction)
- [Features](#features)
- [Hardware Used](#hardware-used)
- [Software Used](#software-used)
- [Pin Configuration](#pin-configuration)
- [Working Principle](#working-principle)
- [OLED User Interface](#oled-user-interface)
- [Project Structure](#project-structure)
- [Clone This Repository](#clone-this-repository)
- [Applications](#applications)
- [Future Improvements](#future-improvements)
- [License](#license)
- [Developed By](#developed-by)

---

# Introduction

The **Laser Based Industrial Siren System** is an embedded industrial safety and automation project developed using Arduino and SSD1306 OLED display technology.

The system is designed to detect motion or laser interruption events and activate an industrial siren after a configurable delay period. The delay duration can be adjusted in real-time using an analog controller.

A professional OLED graphical user interface provides:

- Delay timer visualization
- Motion detection popup
- Countdown monitoring
- Animated UI effects
- Industrial-style dashboard interface

This project is suitable for:

- Factory automation
- Restricted area monitoring
- Industrial safety systems
- Smart security barriers
- Warehouse safety control

---

# Features

- OLED Animated Interface
- Adjustable Siren Delay Timer
- Laser Trigger Detection
- Countdown Popup Screen
- Analog Delay Control
- Boot Animation
- Industrial UI Design
- Smooth Analog Filtering
- Stable Countdown System
- Full Screen Delay Adjustment Popup
- Automatic Siren Release
- Professional Embedded UI

---

# Hardware Used

| Component | Description |
|---|---|
| Arduino UNO/Nano | Main controller |
| SSD1306 OLED Display | UI display |
| Laser Module | Trigger source |
| LDR / Receiver | Laser detection |
| Push Button | Manual trigger |
| Potentiometer | Delay adjustment |
| Relay Module | Siren control |
| Amplifier/Siren | Alarm output |
| Power Supply | System power |

---

# Software Used

| Software | Purpose |
|---|---|
| Arduino IDE | Code development and upload |
| Adafruit GFX Library | Graphics rendering |
| Adafruit SSD1306 Library | OLED driver |
| Git | Version control |
| GitHub | Project hosting |

---

# Pin Configuration

| Device | Arduino Pin |
|---|---|
| OLED SDA | A4 |
| OLED SCL | A5 |
| Trigger Input | D8 |
| Siren Output | D2 |
| Analog Delay Input | A0 |

---

# Working Principle

1. System powers ON
2. Boot animation starts
3. OLED enters standby screen
4. User adjusts siren delay using potentiometer
5. OLED displays selected delay time
6. Laser interruption triggers countdown
7. Siren output activates
8. Countdown popup appears
9. Countdown decreases in real-time
10. Siren output releases automatically after timer completion

---

# OLED User Interface

## Normal Screen

Displays:

- System Ready Status
- Motion Detection Status
- Current Siren Delay Time
- Sliding Website Branding

## Delay Adjustment Popup

Automatically appears when analog delay value changes:

- Full-screen popup interface
- Large countdown timer
- Animated slider
- Real-time delay preview

## Countdown Popup

During trigger event:

- Motion Detected popup
- Live decreasing countdown
- Siren active indication

---

# Project Structure

```text
Laser-Based-Industrial-Siren-System
│
├── main.ino
├── DisplayManager.h
├── boot.h
├── README.md
├── LICENSE
├── PCB
│   └── pcb_design.pdf
├── images
│   ├── ui-preview.jpg
│   ├── circuit-diagram.jpg
│   └── hardware.jpg
```

---

# Clone This Repository

```bash
git clone https://github.com/YOUR_USERNAME/Laser-Based-Industrial-Siren-System.git
```

---

# Applications

- Industrial Safety Systems
- Smart Factory Automation
- Laser Security Barrier
- Restricted Area Monitoring
- Warehouse Safety System
- Staircase Siren System
- Intrusion Detection System
- Industrial Alarm Controller

---

# Future Improvements

- RTC Integration
- WiFi Monitoring
- GSM Alert System
- IoT Dashboard
- EEPROM Setting Storage
- Multi-zone Trigger System
- Industrial Relay Expansion

---

# License

This project is licensed under the MIT License.

---

# Developed By

## Mr Jyotiprasad

Embedded Systems Developer  
Industrial Automation & Safety Systems  
Arduino • IoT • Embedded UI Design • Industrial Electronics
