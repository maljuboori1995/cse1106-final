# Smart Classroom Comfort Monitor

## Test Plan

### 1. Testing Environment

- Operating System: Ubuntu WSL
- Compiler: GCC 13.3.0
- Programming Language: C11
- Hardware: Raspberry Pi 4 (physical LED testing pending)
- Repository: cse1106-final

### 2. Testing Objective

The goal is to verify that the program correctly reads temperatures, identifies NORMAL and WARNING conditions, calculates averages, and saves results to files.

The software is tested before connecting the LED to the Raspberry Pi.

### 3. Software Test Cases

| Test | Input                   | Expected Result      | Status |
| ---- | ----------------------- | -------------------- | ------ |
| 1    | 72 F                    | NORMAL, LED OFF      | Passed |
| 2    | 80 F                    | WARNING, LED ON      | Passed |
| 3    | 65 F                    | WARNING, LED ON      | Passed |
| 4    | 68 F                    | NORMAL, LED OFF      | Passed |
| 5    | 76 F                    | NORMAL, LED OFF      | Passed |
| 6    | Change range to 65-80 F | New range accepted   | Passed |
| 7    | 65 F with custom range  | NORMAL, LED OFF      | Passed |
| 8    | 80 F with custom range  | NORMAL, LED OFF      | Passed |
| 9    | 81 F with custom range  | WARNING, LED ON      | Passed |
| 10   | Readings: 65, 80, 81    | Average: 75.33 F     | Passed |
| 11   | Multiple readings       | CSV records saved    | Passed |
| 12   | Latest reading: 81 F    | status.txt = WARNING | Passed |
| 13   | Default range, 70 F     | NORMAL, LED OFF      | Passed |
| 14   | Latest reading: 70 F    | status.txt = NORMAL  | Passed |

### 4. File Testing

The program saves temperature readings to data/temperature_log.csv.

Each record contains:

- Timestamp
- Temperature in Fahrenheit
- NORMAL or WARNING status

The CSV file keeps previous records when new readings are added.

The status.txt file stores only the latest temperature status.

Both files were tested successfully.

### 5. Additional Tests Needed

The following tests still need to be completed:

- Invalid temperature input
- Invalid number of readings
- Minimum temperature greater than maximum
- Invalid menu choice
- Physical LED ON/OFF operation

### 6. Hardware Testing

Hardware testing will be completed in class using:

- Raspberry Pi 4
- Red LED
- 1 kOhm resistor
- Breadboard
- Jumper wires

Expected behavior:

- NORMAL: LED OFF
- WARNING: LED ON

The current software displays simulated LED states. Physical GPIO functionality has not been verified.

### 7. Test Results

All 14 documented software test cases passed.

The program correctly handles temperature readings, configurable limits, averages, CSV logging, and status updates.

### 8. Conclusion

The software features tested so far are working correctly. The next step is to connect the LED to the Raspberry Pi and verify the hardware behavior.

Final testing will be completed after hardware integration.
