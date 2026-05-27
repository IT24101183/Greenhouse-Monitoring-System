# Greenhouse Monitoring System

An automated Greenhouse Monitoring System built using Arduino Uno, which tracks temperature, humidity, and soil moisture levels to ensure optimal plant growth.

## Features
- **Real-time Monitoring:** Displays Temperature, Humidity, and Soil Moisture on a 16x4 I2C LCD.
- **Automated Irrigation:** Automatically activates a water pump (motor) when soil moisture drops below 60%.
- **Data Logging:** Sends sensor data via Serial/Bluetooth for external monitoring.

## Components Used
| Component | Description |
| :--- | :--- |
| **Arduino Uno** | Main microcontroller board |
| **16x4 LCD Display** | With I2C module for data output |
| **DHT11 Sensor** | Measures air temperature and humidity |
| **Soil Moisture Sensor** | Measures soil water content |
| **Water Pump (Motor)** | Controlled by the system |
| **Breadboard & Wires** | For prototyping connections |

## Circuit Connection


## How to use
1. Connect the sensors and components to the Arduino Uno as per the circuit diagram.
2. Upload the `Greenhouse_Monitor.ino` code using the Arduino IDE.
3. Open the Serial Monitor at 9600 baud rate to view the real-time data output.

---
