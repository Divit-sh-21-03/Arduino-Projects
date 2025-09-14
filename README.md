# Arduino Projects Repository

This repository contains two projects I've developed for the Arduino Uno platform.

1.  **Task - Temperature-Controlled Fan**: A solution to a technical challenge involving software-based PWM control.
2.  **Jwalamukhi - Multi-Sensor Alarm**: A personal project that uses several sensors to create a home safety alarm system.

---

## 1. Task - Temperature-Controlled Fan

This project is a solution to a technical task requiring a fan's speed to be controlled by temperature, using the specific constraint of a non-PWM digital pin.

### Features
* Reads temperature from a 10k NTC thermistor on pin `A0`.
* Controls a DC fan (or an LED for simulation) on digital pin `D13`.
* Uses a 3-level speed logic (OFF, 50%, 100%).
* Prints the current temperature and fan status to the Serial Monitor.

### The Pin D13 PWM Challenge

A key part of this task is the requirement to control the fan speed using only **pin D13**, which is not a hardware PWM pin on the Arduino Uno.

To solve this, the code implements a **software PWM**. This technique rapidly turns the pin on and off using precise microsecond delays to simulate a 50% duty cycle, effectively running the fan at half speed without needing built-in PWM hardware.

### Tinkercad Simulation
You can view and run the simulation for this project on Tinkercad:
* **[Task - Fan Controller Simulation Link](https://www.tinkercad.com/things/hRyj473tqh5-task?sharecode=Slw9H2rjCKdNNgzxU0fG4BGM3C3W8s72BJtEf9XYvNk)**

### Folder Contents (`/Task`)
* **Code**: The `.ino` sketch for the Arduino.
* **Video**: A short video showing the project working.
* **Photo**: An image of the circuit.

---

## 2. Jwalamukhi - Multi-Sensor Alarm System

"Jwalamukhi" is a personal project I built that acts as a home safety system by monitoring for multiple potential hazards.

### Features
* **Multiple Sensors**: Uses a temperature sensor, a gas/smoke sensor, and a PIR motion sensor all at once.
* **Fan Control**: A DC fan automatically speeds up as the room gets warmer.
* **Alarms**: A buzzer and an LED are turned on if the temperature gets too high, if smoke is detected, or if motion is seen.
* **Manual Override**: A switch is included to turn on the alarm manually.
* **LCD Display**: Shows the real-time temperature on a 16x2 LCD screen.

### Tinkercad Simulation
You can view and run the simulation for this project on Tinkercad:
* **[Jwalamukhi - Alarm System Simulation Link](https://www.tinkercad.com/things/ecgP6FilBGt-jwalamukhi?sharecode=FJZquEVQfa32q2xLxSnEFhtrOm_PuFgX1Z65pgk1jeg)**

### Folder Contents (`/Jwalamukhi`)
* **Code**: The `.ino` sketch for the Arduino.
* **Image**: A screenshot or photo of the project.
