# Smart Classroom Comfort Moniter

## Functional Requierments

1. Allow the user to enter classroom temperature readings in Fahrenheit.
2. Determine whether a temperature is within the acceptable range of range of 68 F-76 F, inclusive.
3. Display an appropriate NORMAL or WARNING status.
4. Calculate the average of the recorded temperatures.
5. Save temperature readings and their statuses to a file.
6. Use an LED connected to the Raspberry Pi to indicate a warning condition.
7. Allow the acceptable temperature range to be changed according to a new client.

## System Requierments

- The application must be written in C.
- The application must be run on Raspberry Pi.
- The system must use a GPIO-connected LED for status indication.
- The system must save its's result for later inspection.
- The system must reject invalid input.

