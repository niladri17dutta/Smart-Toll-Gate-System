# Smart Toll Gate System Using Ultrasonic Sensor and Arduino

## 📌 Project Overview

This project presents the design and implementation of an automated smart toll gate system using an ultrasonic sensor and an embedded microcontroller platform (Arduino). The system detects incoming vehicles, automatically opens a servo-controlled gate, counts vehicles, and displays system status on an LCD screen.

The primary objective is to develop a low-cost, real-time vehicle detection and access control prototype suitable for smart transportation applications.

---

## 🎯 Features

- Real-time vehicle detection using ultrasonic sensing
- Automatic gate opening and closing using servo motor
- Vehicle counting mechanism
- LCD display for live system monitoring
- Non-blocking timing logic using `millis()`
- Filtering of unrealistic sensor readings

---

## 🛠 Hardware Components

- Arduino (Uno/Nano or compatible board)
- Ultrasonic Sensor (HC-SR04)
- Servo Motor
- 16x2 LCD Display with I2C Module
- Jumper wires
- Breadboard
- Power supply

---

## 🔌 Pin Configuration

| Component        |     Arduino Pin    |
|------------------|--------------------|
| Ultrasonic TRIG  | 9                  |
| Ultrasonic ECHO  | 8                  |
| Servo Motor      | 6                  |
| LCD (I2C)        | 0x27 (I2C Address) |

---

## ⚙️ System Working Principle

1. The ultrasonic sensor continuously measures the distance of objects in front of the gate.
2. If the measured distance falls below a predefined threshold (`DIST_LIMIT`), a vehicle is assumed to be detected.
3. The servo motor rotates to open the gate.
4. The vehicle count increments.
5. After a fixed duration (`gateDuration`), the gate automatically closes.
6. The LCD displays:
   - Current distance
   - Total vehicle count
   - System messages

Invalid or unrealistic readings are ignored to improve system stability.

---

## 🧠 Software Logic Highlights

- Distance measurement using pulse duration
- State-based detection using boolean flags
- Non-blocking delay using `millis()` instead of `delay()`
- Automatic gate reset logic
- Real-time LCD updates

---

## 📁 Project Structure

```
Smart Toll Gate
    │
    ├── SmartTollGate.ino
    └── README.md
```


---

## 🚀 How to Run the Project

1. Install Arduino IDE.
2. Install required libraries:
   - `LiquidCrystal_I2C`
   - `Servo`
3. Connect hardware as per pin configuration.
4. Upload the code to Arduino.
5. Power the system.
6. Place an object (vehicle simulation) within 50 cm to test detection.

---

## 📊 Technical Specifications

- Distance Threshold: 50 cm
- Maximum Valid Distance: 400 cm
- Gate Open Duration: 2 seconds
- Communication: Serial Monitor (9600 baud)

---

## 🔍 Limitations

- Single sensor-based detection (no direction differentiation)
- No vehicle authentication mechanism
- No payment integration
- No cloud logging or IoT capability

---

## 🔮 Future Enhancements

- RFID-based toll payment integration
- IoT logging using WiFi or GSM module
- Dual sensor entry/exit validation
- License plate recognition using camera module
- Cloud dashboard for traffic analytics

---

## 📘 Applications

- Toll booth automation prototype
- Parking gate control system
- Restricted area access control
- Smart transportation system research

---

## 👨‍💻 Author

Niladri Dutta

---

This project demonstrates a cost-effective and scalable approach toward intelligent transportation system development using embedded technologies.