# Smart Transformer Condition Monitoring & Protection System

This repository contains an **embedded IoT-based prototype**
for real-time monitoring and protection of power distribution transformers.

## Project Objective
To improve transformer reliability by continuously monitoring
temperature, current, and voltage parameters and triggering
protective actions during abnormal operating conditions.

## System Overview
- ESP32-based embedded controller
- Temperature monitoring using DS18B20
- Load current sensing using ACS712
- Relay-based protection / load isolation
- Designed for smart grid and power system research

## Hardware Components
- ESP32 Microcontroller
- DS18B20 Temperature Sensor
- ACS712 Current Sensor
- ZMPT101B Voltage Sensor (planned)
- 2-Channel Relay Module
- 0.96” OLED Display (planned)

## Software Stack
- Programming Language: C / C++
- IDE: Arduino IDE
- ESP32 Board Package: Espressif Systems
- Libraries: OneWire, DallasTemperature

## Repository Structure
smart-transformer-monitoring/
├── docs/ # Architecture diagrams
├── firmware/ # ESP32 embedded firmware
└── README.md

## Project Status
✔ Core embedded firmware implemented  
🔄 Voltage sensing, OLED display, and cloud connectivity under development
✔ This prototype focuses on embedded monitoring logic and protection behavior rather than full substation-scale deployment.





