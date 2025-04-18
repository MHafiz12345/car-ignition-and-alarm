# 🚗 Arduino Car Alarm and Ignition System

![Arduino Car Alarm System](https://github.com/user-attachments/assets/102d4a9f-a61b-4734-91ca-0bd20e452151)

## 📋 Overview

This project simulates a basic **car alarm and ignition system** using an **Arduino Uno**, **ultrasonic sensors**, **force sensors**, and multiple **digital outputs** like LEDs or buzzers. The system detects nearby intrusions and pressure on specific zones, then triggers an alarm or ignition logic based on sensor input.

It combines both **analog** and **digital sensors** with condition-based logic to mimic real-world car security systems.

## 🎯 System Behavior

* Two **zones** monitored by **ultrasonic + force sensor** pairs
* If an object is detected **within 40cm** and force is **above 400**, the alarm blinks lights/buzzers **10 times**
* Ignition turns on if **three switches** (digital pins 1, 4, and 6) are all HIGH
* Ignition turns off if pin 1 goes LOW while pins 4 and 6 remain HIGH

## 🧩 Sensor & Pin Setup

### 🟢 Inputs

* **A4, A5**: Analog force sensors (for two zones)
* **10 & 11, 13 & 12**: Ultrasonic sensor trigger/echo pins (two zones)
* **3, 6**: Digital input triggers (for motion confirmation)
* **1, 4, 6**: Digital ignition key switch simulation

### 🔴 Outputs

* **9, 8, 7, 5**: Alarm indicators (LEDs or buzzers)
* **2**: Ignition output (e.g., motor control or status LED)

## ⚙️ Logic Flow

### 🚨 Alarm Trigger

1. Check if force sensor > 400
2. Check if ultrasonic distance <= 40cm
3. Check if motion confirmation pin is LOW
4. If all conditions met:
   * Wait 1 second
   * Flash 4 output pins ON/OFF every 300ms, 10 times

### 🔑 Ignition Logic

* Turns ON if **pins 1, 4, 6** are all HIGH
* Turns OFF if **pin 1** goes LOW but pins 4 & 6 remain HIGH

## 🧠 Concepts Used

* **Ultrasonic distance calculation**
* **Analog sensor thresholding**
* **Multiple digital input coordination**
* **Timed blinking with `delay()`**
* **State checking and control flow**


## 🔌 Hardware Requirements

* Arduino Uno
* 2 × Ultrasonic sensors (HC-SR04)
* 2 × Force sensitive resistors
* 4 × LEDs (or buzzers) for alarm indication
* 1 × LED for ignition status
* 3 × Push buttons for ignition sequence
* 2 × Push buttons for motion confirmation
* Resistors, breadboard, and jumper wires

