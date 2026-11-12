# Smart Classroom Comfort Monitor

## Change Log

### 1. Initial Setup

- Created the GitHub repository.
- Added the project folders and files.
- Completed the requirements and design documents.

### 2. Temperature Monitoring

- Created the main C program.
- Added temperature input in Fahrenheit.
- Added NORMAL and WARNING conditions.
- Set the default temperature range to 68-76 F.
- Added simulated LED ON/OFF messages.

### 3. Multiple Readings

- Added a loop to accept multiple temperatures.
- Added the average temperature calculation.
- Tested normal and warning conditions.

### 4. File Logging

- Added CSV logging for temperature readings.
- Included timestamps and status for each reading.
- Added status.txt to save the latest status.
- Verified that previous CSV records are preserved.

### 5. Temperature Range Update

- Added an option to change the acceptable range.
- Added validation for minimum and maximum values.
- Tested the custom range of 65-80 F.

### 6. Input Validation

- Added checks for invalid temperature inputs.
- Rejected zero and negative reading counts.
- Added checks for invalid ranges and menu choices.
- Tested nan and inf inputs.

### 7. Testing

- Completed 21 software test cases.
- Verified temperature calculations and file updates.
- Recorded the results in tests/test_plan.md.
- All 21 documented software tests passed.

### 8. Remaining Work

- Connect the LED to the Raspberry Pi.
- Add physical GPIO control to the C program.
- Test the LED in class.
- Complete the hardware demonstration.
