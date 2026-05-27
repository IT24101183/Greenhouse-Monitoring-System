# Greenhouse Monitoring System

An automated Greenhouse Monitoring System built using Arduino Uno, designed to track temperature, humidity, and soil moisture levels to ensure optimal plant growth and automatic irrigation.

---

## Project Gallery

The following gallery showcases the complete system from schematic design to deployment.

| Circuit Diagram | Prototype Setup |
| :---: | :---: |
| <img src="https://res.cloudinary.com/dbbihgoyy/image/upload/q_auto/f_auto/v1779894539/Gemini_Generated_Image_ufsdcpufsdcpufsd_baxuz4.png" width="350"> | <img src="https://res.cloudinary.com/dbbihgoyy/image/upload/q_auto/f_auto/v1779894418/WhatsApp_Imcage_2026-05-27_at_19.41.11_zbvqwh.jpg" width="350"> |
| *Accurate wiring schematic.* | *Components assembled on breadboard.* |

| Sensor Deployment | Final Output Display |
| :---: | :---: |
| <img src="https://res.cloudinary.com/dbbihgoyy/image/upload/q_auto/f_auto/v1779895229/Gemini_Generated_Image_oc5hngoc5hngoc5h_xy8zmd.png" width="350"> | <img src="https://res.cloudinary.com/dbbihgoyy/image/upload/q_auto/f_auto/v1779893926/Gemini_Generated_Image_w2r6rnw2r6rnw2r6_jz1bt3.png" width="350"> |
| *Sensors monitoring the environment.* | *Live data on the 16x4 LCD.* |

---

## Features

- **Real-time Monitoring:** Displays Temperature, Humidity, and Soil Moisture percentage on a professional 16x4 I2C LCD.
- **Automated Irrigation:** A soil moisture threshold controls a water pump (motor). It automatically activates the pump (motor ON) when the soil is dry (<60%) and deactivates it (motor OFF) when moisture is sufficient (>60%).
- **Bluetooth Data Logging:** Sensor data is framed and sent via the Serial TX port every 5 seconds for external Bluetooth reception (useful for mobile apps).
- **Startup Splash Screen:** Displays "GREEN HOUSE" and the project ID "KANDU_UNI_26" on boot.

---

## Component List

| # | Component | Description |
| :- | :--- | :--- |
| 1 | **Arduino Uno** | Main microcontroller board (Development Board). |
| 2 | **16x4 LCD Display (I2C)** | Displays data (Temperature, Humidity, Moisture, Motor Status). |
| 3 | **DHT11 Sensor** | Measures air temperature and surrounding humidity. |
| 4 | **Soil Moisture Sensor** | Detects the water level in the soil. |
| 5 | **Water Pump (Motor)** | 5V DC motor (controlled by Arduino Digital Pin 9). |
| 6 | **Breadboard & Wires** | Used for component connections without soldering. |

---

## Schematic and Wiring (Reference: image_0.png)

Ensure the connections are made precisely according to the circuit diagram:

- **DHT11:** VCC -> 5V, GND -> GND, DATA -> **Pin 2**.
- **16x4 LCD (I2C):** VCC -> 5V, GND -> GND, SDA -> **A4**, SCL -> **A5**.
- **Soil Moisture:** VCC -> 5V, GND -> GND, Analog Out -> **A0**.
- **Motor/Pump:** Positive -> **Pin 9**, Negative -> GND (Use a flyback diode/transistor driver for optimal motor control).

---

## Deployment Setup (Reference: image_2.png)

1.  **Assemble Components:** Following the schematic (image_0.png), mount the Arduino, Breadboard, LCD, and sensors as shown in the Prototype View.
2.  **Sensor Placement:** Submerge the Soil Moisture probe into the soil/water medium you wish to monitor. Place the DHT11 nearby for ambient air reading.
3.  **Verify LCD Output:** Upon powering up, the startup screens will display, followed by live sensor data and the motor status (Reference: image_2.png).

---

## How to use

1.  Open the `Greenhouse_Monitor.ino` sketch in the Arduino IDE.
2.  Install the required libraries (Sketch > Include Library > Manage Libraries...):
    - **`DHT sensor library`** by Adafruit.
    - **`LiquidCrystal I2C`** by Frank de Brabander.
3.  Connect your Arduino Uno via USB and select the correct Board and Port.
4.  Upload the code.

---
*Developed for KANDU_UNI_26 project.*
