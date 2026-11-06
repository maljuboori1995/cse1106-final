# CSE 1106 Final Project — Smart Classroom Comfort Monitor

**Chosen project:** Option 1 — Smart Classroom Comfort Monitor  
**Language:** C  
**Hardware:** Raspberry Pi 4 with a red LED and a 1 kΩ resistor  
**LED GPIO:** BCM GPIO17 (physical pin 11)

A classroom monitoring program that records temperature readings in Fahrenheit, checks whether each is in the **68°F–76°F inclusive** comfort range, saves results, calculates the average, and turns on an LED whenever the latest temperature is outside the range. The minimum and maximum temperatures can be changed and are retained for future runs.

## What the program does

- Enter a temperature; see **NORMAL** or **WARNING** and LED **OFF** or **ON**.
- Save each reading, its classification, and the range used to a CSV log.
- Show the overall average and number of recorded readings, including previous runs.
- Change the acceptable temperature range without editing the C source code.
- Re-evaluate the latest temperature when a new range is configured.
- Reject invalid numeric input and ranges where minimum is not less than maximum.



A demonstration of the menu:

```text
1. Enter a temperature reading       -> enter 72 -> NORMAL, LED OFF
1. Enter a temperature reading       -> enter 79 -> WARNING, LED ON
3. View summary                      -> average: 75.50 F
2. Change acceptable temperature range -> enter 60 then 80
                                        -> last reading is now NORMAL
4. Exit
```

## Run on the Raspberry Pi 4

1. Turn off the Pi before wiring. Use **BCM GPIO17 / physical pin 11 → 1 kΩ resistor → LED positive (long leg)**, and **LED negative (short leg) → any GND, e.g. physical pin 6**. Do **not** connect the LED directly across GPIO and ground without a resistor, or to a 5 V supply. 
2. On the lab Raspberry Pi, confirm the `pigpio` C library and headers (`pigpio.h`) are available. Ask the lab instructor if the image does not include them.
3. Compile from the project root:

   ```bash
   make pi
   ```

4. Run the GPIO-enabled program from the project root:

   ```bash
   sudo ./build/comfort_monitor_pi
   ```

5. Enter a reading outside the comfort range and confirm that the **physical red LED turns on**. Enter a reading in range and confirm it turns off.

The LED is switched off when the program exits. The saved status file retains the classification of the most recently recorded reading.

## Run the automated tests

```bash
make test
```
## Files in this project

cse1106_comfort_monitor/
├── src/
│   └── main.c                 C program
├── docs/
│   ├── requirements.md        Functional requirements and acceptance criteria
│   ├── design.md              Architecture and software/hardware flowchart
├── tests/
│   ├── test_plan.md           Software and hardware test cases
├── data/
│   └── tempreture_log.csv             
├── status.txt                 NORMAL or WARNING
└── README.md
```


