# Smart Classroom Comfort Monitor

## CSE 1106 Final Project

### Project Overview

This project is a classroom temperature monitoring system written in C. The program checks whether the temperature is within an acceptable range and displays NORMAL or WARNING.

It also calculates the average temperature, saves readings to a CSV file, and keeps track of the latest status.

### Features

- Enter multiple temperature readings in Fahrenheit.
- Check temperatures against the default range of 68-76 F.
- Change the acceptable temperature range.
- Display NORMAL or WARNING.
- Display simulated LED ON/OFF messages.
- Calculate the average temperature.
- Save readings with timestamps to a CSV file.
- Update status.txt with the latest status.
- Reject invalid inputs.

### Project Files

- src/main.c - Main C program.
- docs/requirements.md - Project requirements.
- docs/design.md - System design.
- docs/change_log.md - Development history.
- tests/test_plan.md - Test cases and results.
- data/temperature_log.csv - Saved temperature readings.
- status.txt - Latest temperature status.

### How to Compile

Open a terminal in the project folder and run:

    gcc -std=c11 -Wall -Wextra -pedantic src/main.c -o comfort_monitor

### How to Run

Run the program using:

    ./comfort_monitor

The program asks whether you want to change the temperature range.

Enter the number of readings, then enter each temperature.

### Example Output

    === Classroom Comfort Monitor ===

    Current range: 68.00 F - 76.00 F
    Change the range? (y/n): n

    How many temperature readings? 3

    Enter temperature 1 (F): 72
    Status: NORMAL
    LED: OFF
    Reading saved successfully.

    Enter temperature 2 (F): 80
    Status: WARNING
    LED: ON
    Reading saved successfully.

    Enter temperature 3 (F): 65
    Status: WARNING
    LED: ON
    Reading saved successfully.

    === Temperature Summary ===
    Total readings: 3
    Average temperature: 72.33 F

### Testing

The program was tested using Ubuntu WSL and GCC 13.3.0.

I completed 21 software test cases covering:

- Normal and warning temperatures.
- Custom temperature ranges.
- Average calculations.
- CSV logging and status updates.
- Invalid inputs.

All 21 documented software tests passed.

The results are recorded in tests/test_plan.md.

### Raspberry Pi Hardware

The project will use:

- Raspberry Pi 4
- Red LED
- 1 kOhm resistor
- Breadboard
- Jumper wires

Expected LED behavior:

- NORMAL: LED OFF
- WARNING: LED ON

The program currently displays simulated LED messages. Physical GPIO control and LED testing will be completed in class.

### Current Status

The main C program is working and the software tests have passed.

The remaining work includes Raspberry Pi integration, physical LED testing, and the final demonstration.
