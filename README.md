# Serial-Based Ultrasonic Distance Monitoring System

## Project Overview
This project involves the design and implementation of a distance monitoring system that interfaces an **Arduino Nano** with an intelligent ultrasonic module using **Serial (UART) communication**. Instead of measuring raw pulse widths, this system interprets ASCII data streams to classify distance into three safety zones (Safe, Warning, Danger) visualized via a traffic-light LED system.

## Key Features
* **Simplified Interfacing:** Uses a specialized "Distance Display Module" that handles automatic distance calculation, offloading the microcontroller from pulse-timing tasks.
* **UART Communication:** Implements asynchronous serial communication to read ASCII data strings (e.g., '20cm').
* **Software Serial Emulation:** Emulates a secondary serial port on digital pins D7 and D8 to keep the hardware serial port free for PC debugging.
* **Data Parsing:** Includes a custom C++ function to "clean" raw text streams by filtering out non-digit characters for logical processing.

## Hardware Implementation
The system is prototyped on a breadboard with the following components:
* **Arduino Nano V3:** The central processing unit.
* **HC-SR04 + Distance Display Module:** For automated ultrasonic measurement via TX.
* **LED Interface:** Green, Yellow, and Red LEDs representing safety thresholds.
* **Protection:** 220 Ohm resistors used in series with each LED to limit current.

## Logic & Thresholds
The software processes the incoming text, converts it to an integer, and triggers outputs based on the following:
* **Safe Zone:** Distance > 20cm (Green LED)
* **Warning Zone:** Distance between 10cm and 20cm (Yellow LED)
* **Danger Zone:** Distance < 10cm (Red LED)

## Technical Skills Demonstrated
* **Embedded Systems:** Microcontroller programming and hardware-software interfacing.
* **Data Processing:** String manipulation and ASCII-to-Integer conversion in C++.
* **Communication Protocols:** Practical application of UART and SoftwareSerial libraries.
* **Circuit Design:** Basic digital electronics including current-limiting and I/O management.
