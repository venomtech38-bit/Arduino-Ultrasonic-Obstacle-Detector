# Arduino Ultrasonic Obstacle Detector 🤖

An Arduino-based obstacle detection system using an HC-SR04 ultrasonic sensor.

## 🚀 Features

- Detects nearby obstacles
- Measures distance in centimeters
- LED turns ON when an obstacle is within 20 cm
- Buzzer sounds when an obstacle is detected
- Displays distance through the Serial Monitor

## 🧰 Components

- Arduino UNO
- HC-SR04 Ultrasonic Sensor
- LED
- 220Ω Resistor
- Buzzer
- Jumper Wires
- Breadboard

## 🔌 Wiring

| Component | Arduino |
|-----------|---------|
| HC-SR04 VCC | 5V |
| HC-SR04 GND | GND |
| HC-SR04 TRIG | D9 |
| HC-SR04 ECHO | D10 |
| LED (+) | D7 through 220Ω |
| LED (-) | GND |
| Buzzer (+) | D8 |
| Buzzer (-) | GND |

## ⚙️ How It Works

The HC-SR04 sends an ultrasonic pulse and measures the time taken for the echo to return.

The Arduino calculates the distance and checks whether an obstacle is within 20 cm.

If an obstacle is detected:

- 💡 LED turns ON
- 🔊 Buzzer sounds

Otherwise, the LED and buzzer remain OFF.

## 📁 Files

- `Arduino_Ultrasonic_Obstacle_Detector.ino` — Arduino source code
- `README.md` — Project documentation

## 👨‍💻 Author

venomtech38-bit
