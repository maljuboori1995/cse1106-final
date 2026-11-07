# Smart Classroom Comfort Monitor
## System Design

### 1. Project Overview

The Smart Classroom Comfort Monitor is a C application that runs on a Raspberry Pi 4. It allows users to enter classroom temperatures, checks whether those temperatures are acceptable, and uses an LED to indicate warnings.

### 2. System Components

Hardware:
- Raspberry Pi 4
- Red LED
- 1,000-ohm resistor
- Breadboard
- Jumper wires

Software:
- C programming language
- Raspberry Pi GPIO interface
- CSV file for temperature records
- Text file for current system status

### 3. System Workflow

1. User enters a temperature in Fahrenheit.
2. Program validates the input.
3. Program compares the temperature against the acceptable range of 68 to 76 degrees Fahrenheit, inclusive.
4. If within range, display NORMAL and turn the LED OFF.
5. If outside range, display WARNING and turn the LED ON.
6. Save the temperature and status to a file.
7. Update the average temperature.
8. Allow additional readings or changes to the acceptable range.

### 4. Hardware Integration

The red LED is connected to GPIO17 (physical pin 11) through a 1,000-ohm resistor.

The LED's negative leg connects to a Raspberry Pi ground pin.

The program controls the LED using GPIO output:
- HIGH = LED ON
- LOW = LED OFF

### 5. Data Storage

data/temperature_log.csv:
Stores temperature readings and their statuses.

status.txt:
Stores the latest NORMAL or WARNING status.

### 6. System Inputs and Outputs

Inputs:
- Classroom temperature in Fahrenheit
- Minimum acceptable temperature
- Maximum acceptable temperature

Outputs:
- NORMAL or WARNING message
- LED ON or OFF
- Average temperature
- Saved temperature records