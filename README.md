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

**Important:** The default build is **simulation mode** and does **not** control a real LED. The Raspberry Pi build uses `pigpio` to control physical GPIO17. Software tests have passed in simulation; the real Pi wiring and LED still require an in-person check.

## Run on a laptop or desktop (no Raspberry Pi needed)

From the project directory, using a terminal with `gcc` and `make` installed:

```bash
make sim
./build/comfort_monitor
```

The program automatically creates runtime files under `data/`.

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

1. Turn off the Pi before wiring. Use **BCM GPIO17 / physical pin 11 → 1 kΩ resistor → LED positive (long leg)**, and **LED negative (short leg) → any GND, e.g. physical pin 6**. Do **not** connect the LED directly across GPIO and ground without a resistor, or to a 5 V supply. See [`docs/hardware_setup.md`](docs/hardware_setup.md).
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

> Note: These instructions target the **Raspberry Pi 4 used in the provided CSE 1106 handout**. `pigpio` installation and compatibility depend on the operating-system image; do not assume this GPIO build works on a different Pi model without checking.

## Run the automated tests

```bash
make test
```

The 12 software tests use temporary data folders and do not change your real project data. They check the comfort-range boundaries, invalid inputs, logging, average, range changes, and persistence across restarts. The physical LED requires a separate live test.

## Files in this project

```text
cse1106_comfort_monitor/
├── src/
│   └── main.c                 C program
├── docs/
│   ├── week1_plan.md          One-page team planning worksheet
│   ├── requirements.md        Functional requirements and acceptance criteria
│   ├── design.md              Architecture and software/hardware flowchart
│   ├── hardware_setup.md      Raspberry Pi GPIO wiring and operation
│   ├── change_log.md          Changes and outstanding verification
│   ├── demo_guide.md          3–5 minute demo sequence
│   └── reflection_template.md Individual reflection prompts
├── tests/
│   ├── test_plan.md           Software and hardware test cases
│   ├── test_results.md        Actual software simulation results
│   └── run_tests.py           Automated software test runner
├── data/
│   └── .gitkeep               Keeps empty folder in GitHub
├── Makefile
├── .gitignore
└── README.md
```

When the program runs, it creates these *local* files:

- `data/temperature_log.csv` — timestamp, temperature, classification, limits used.
- `data/status.txt` — most recent status: `NO_DATA`, `NORMAL`, or `WARNING`.
- `data/config.txt` — saved minimum and maximum temperature limits.

Runtime files are excluded by `.gitignore`, so personal test data is not accidentally committed. For an instructor demonstration, show the generated files or copy an appropriate sanitized example into your submission if required.

## Publish the repository to GitHub

Create a new **empty** repository in GitHub (do not let GitHub generate a separate README). Then from this project's directory run:

```bash
git init
git add .
git commit -m "Initial CSE 1106 comfort monitor"
git branch -M main
git remote add origin https://github.com/YOUR_USERNAME/cse1106-comfort-monitor.git
git push -u origin main
```

Replace `YOUR_USERNAME` with the account or organization that owns the team repository. Team members can clone it with `git clone <repository-URL>` and commit their assigned work.

## Instructor deliverables checklist

- [ ] GitHub repository with code, README, and documents
- [ ] Names/NetIDs and instructor section completed in the planning document
- [x] Requirements and system-design documents prepared
- [x] Working C program and simulation build prepared
- [x] At least five documented software test cases; 12 software tests passed locally
- [ ] Raspberry Pi `pigpio` build and physical LED verified in the lab
- [ ] Change log updated with actual team debugging and lab changes
- [ ] 3–5 minute live team demonstration performed; every member participates
- [ ] Each team member submits their own truthful individual reflection

### Note on tested status

The software test report includes **actual results observed from the non-hardware simulation**. It does not claim that the physical LED or Raspberry Pi build has been tested. Do not mark hardware integration as complete until you have demonstrated it on your Pi.
