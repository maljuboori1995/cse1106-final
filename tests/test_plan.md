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

The software was tested before connecting the LED to the Raspberry Pi.

### 3. Software Test Cases

The LED ON/OFF results refer to simulated console output, not physical GPIO operation.

| Test | Input                   | Expected Result            | Actual Output                             | Status |
| ---- | ----------------------- | -------------------------- | ----------------------------------------- | ------ |
| 1    | 72 F                    | NORMAL, LED OFF            | NORMAL, LED OFF                           | Passed |
| 2    | 80 F                    | WARNING, LED ON            | WARNING, LED ON                           | Passed |
| 3    | 65 F                    | WARNING, LED ON            | WARNING, LED ON                           | Passed |
| 4    | 68 F                    | NORMAL, LED OFF            | NORMAL, LED OFF                           | Passed |
| 5    | 76 F                    | NORMAL, LED OFF            | NORMAL, LED OFF                           | Passed |
| 6    | Change range to 65-80 F | Range accepted             | New range: 65.00 F - 80.00 F              | Passed |
| 7    | 65 F, custom range      | NORMAL, LED OFF            | NORMAL, LED OFF                           | Passed |
| 8    | 80 F, custom range      | NORMAL, LED OFF            | NORMAL, LED OFF                           | Passed |
| 9    | 81 F, custom range      | WARNING, LED ON            | WARNING, LED ON                           | Passed |
| 10   | Readings: 65, 80, 81    | Average: 75.33 F           | Average: 75.33 F                          | Passed |
| 11   | Multiple readings       | CSV records saved          | All readings saved                        | Passed |
| 12   | Latest warning: 65 F    | status.txt = WARNING       | WARNING                                   | Passed |
| 13   | Default range, 70 F     | NORMAL, LED OFF            | NORMAL, LED OFF                           | Passed |
| 14   | Latest reading: 70 F    | status.txt = NORMAL        | NORMAL                                    | Passed |
| 15   | Temperature: abc        | Invalid temperature error  | Error: Invalid temperature.               | Passed |
| 16   | Reading count: 0        | Invalid number of readings | Error: Invalid number of readings.        | Passed |
| 17   | Reading count: -3       | Invalid number of readings | Error: Invalid number of readings.        | Passed |
| 18   | Range: 85-70 F          | Invalid range error        | Error: Minimum must be less than maximum. | Passed |
| 19   | Menu choice: x          | Invalid Y/N selection      | Error: Please enter Y or N.               | Passed |
| 20   | Temperature: nan        | Invalid temperature error  | Error: Invalid temperature.               | Passed |
| 21   | Temperature: inf        | Invalid temperature error  | Error: Invalid temperature.               | Passed |

### 4. File Testing

The program saves temperature readings to data/temperature_log.csv.

Each record contains:

- Timestamp
- Temperature in Fahrenheit
- NORMAL or WARNING status

Example of actual saved records:

    2026-11-11 21:42:40,65.00,NORMAL
    2026-11-11 21:42:42,80.00,NORMAL
    2026-11-11 21:42:45,81.00,WARNING

These readings used the custom range of 65-80 F.

The CSV file keeps previous records when new readings are added.

The status.txt file stores the latest NORMAL or WARNING status. I verified that it updated correctly after new readings.

Both files worked as expected.

### 5. Additional Tests Needed

All planned software input-validation tests have passed.

The following hardware tests still need to be completed:

- Connect the red LED to the Raspberry Pi.
- Verify the LED turns ON during WARNING conditions.
- Verify the LED turns OFF during NORMAL conditions.
- Confirm GPIO control works with the C program.
- Rerun software tests on the Raspberry Pi.

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

All 21 documented software test cases passed.

The program correctly handles:

- Normal and warning temperatures
- Custom temperature ranges
- Multiple readings and averages
- CSV logging and status updates
- Invalid inputs and error handling

Physical LED testing is still pending.

### 8. Conclusion

The software features tested so far are working correctly. The program processes temperatures, calculates averages, and saves results to files.

The remaining steps are to run the program on the Raspberry Pi, connect the LED, and verify that it works with the GPIO interface.

Final testing will be completed after hardware integration.
