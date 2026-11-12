#include <math.h>
#include <stdio.h>
#include <time.h>
#ifdef RASPBERRY_PI
    #include <pigpio.h>
    #include <unistd.h>
    #define PIN 17
#endif
void set_led(int state)
{
    
#ifdef RASPBERRY_PI
    gpioWrite(PIN, state);
    
#endif

        if (state == 0)
            printf("LED: OFF\n");
    
        else if (state == 1)
            printf("LED: ON\n");

}

// Save each temperature reading to the CSV file
int save_reading(double temperature, const char *status) {
  FILE *file = fopen("data/temperature_log.csv", "a+");

  if (file == NULL) {
    printf("Error: Could not open CSV file.\n");
    return 0;
  }

  // Check if the file is empty
  if (fseek(file, 0, SEEK_END) != 0) {
    fclose(file);
    return 0;
  }

  long size = ftell(file);

  if (size < 0) {
    fclose(file);
    return 0;
  }

  // Add the header if the file is empty
  if (size == 0) {
    if (fprintf(file, "timestamp,temperature_f,status\n") < 0) {
      fclose(file);
      return 0;
    }
  }

  // Get the current date and time
  time_t now = time(NULL);
  struct tm *current = localtime(&now);
  char timestamp[32];

  if (current == NULL || strftime(timestamp, sizeof(timestamp),
                                  "%Y-%m-%d %H:%M:%S", current) == 0) {
    fclose(file);
    return 0;
  }

  // Save the temperature and status
  if (fprintf(file, "%s,%.2f,%s\n", timestamp, temperature, status) < 0) {
    fclose(file);
    return 0;
  }

  if (fclose(file) != 0) {
    return 0;
  }

  return 1;
}

// Save the latest temperature status
int save_status(const char *status) {
  FILE *file = fopen("status.txt", "w");

  if (file == NULL) {
    printf("Error: Could not open status file.\n");
    return 0;
  }

  if (fprintf(file, "%s\n", status) < 0) {
    fclose(file);
    return 0;
  }

  if (fclose(file) != 0) {
    return 0;
  }

  return 1;
}

int main(void) {
#ifdef RASPBERRY_PI

    if (gpioInitialise() < 0) {
        printf("Error: GPIO initialization failed.\n");
        return 1;
    }

    if (gpioSetMode(PIN, PI_OUTPUT) < 0) {
        printf("Error: Could not configure GPIO pin.\n");
        gpioTerminate();
        return 1;
    }
#endif
    
    int exit_code = 0;
    
  int count;
  char choice;
  double temperature;
  double total = 0.0;

  // Default acceptable temperature range
  double min_temp = 68.0;
  double max_temp = 76.0;

  printf("=== Classroom Comfort Monitor ===\n");

  printf("\nCurrent range: %.2f F - %.2f F\n", min_temp, max_temp);

  printf("Change the range? (y/n): ");

  if (scanf(" %c", &choice) != 1 ||
      (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
    printf("Error: Please enter Y or N.\n");
    exit_code = 1;
    goto cleanup;
  }

  // Allow the user to change the temperature range
  if (choice == 'y' || choice == 'Y') {

    printf("Enter minimum temperature (F): ");

    if (scanf("%lf", &min_temp) != 1 || !isfinite(min_temp)) {
      printf("Error: Invalid minimum temperature.\n");
      exit_code = 1;
      goto cleanup;
    }

    printf("Enter maximum temperature (F): ");

    if (scanf("%lf", &max_temp) != 1 || !isfinite(max_temp)) {
      printf("Error: Invalid maximum temperature.\n");
      exit_code = 1;
      goto cleanup;
    }

    // Check that the range is valid
    if (min_temp >= max_temp) {
      printf("Error: Minimum must be less than maximum.\n");
      exit_code = 1;
      goto cleanup;
    }

    printf("New range: %.2f F - %.2f F\n", min_temp, max_temp);
  }

  // Ask for the number of temperature readings
  printf("\nHow many temperature readings? ");

  if (scanf("%d", &count) != 1 || count <= 0) {
    printf("Error: Invalid number of readings.\n");
    exit_code = 1;
    goto cleanup;
  }

  // Process each temperature reading
  for (int i = 1; i <= count; i++) {

    printf("\nEnter temperature %d (F): ", i);

    if (scanf("%lf", &temperature) != 1 || !isfinite(temperature)) {
      printf("Error: Invalid temperature.\n");
      exit_code = 1;
      goto cleanup;
    }

    const char *status;

    // Check the selected temperature range
    if (temperature >= min_temp && temperature <= max_temp) {
      status = "NORMAL";
      printf("Status: NORMAL\n");
      int state = 0;
      set_led(state);
        
    } else {
      status = "WARNING";
      printf("Status: WARNING\n");
      int state = 1;
      set_led(state);
    }

    // Save the reading to the CSV file
    if (!save_reading(temperature, status)) {
      printf("Error: Failed to save reading.\n");
      exit_code = 1;
      goto cleanup;
    }

    // Update status.txt with the latest result
    if (!save_status(status)) {
      printf("Error: Failed to update status.\n");
      exit_code = 1;
      goto cleanup;
    }

    printf("Reading saved successfully.\n");

    // Add the temperature to the total
    total += temperature;
  }

  // Calculate the average temperature
  double average = total / count;

  printf("\n=== Temperature Summary ===\n");
  printf("Total readings: %d\n", count);
  printf("Average temperature: %.2f F\n", average);
    
#ifdef RASPBERRY_PI
    sleep(5); // pauses for 5 seconds before turning off the program so LED stays on.
#endif
    
cleanup:
#ifdef RASPBERRY_PI
    gpioWrite(PIN, 0);
    gpioTerminate();
#endif
  return exit_code;
}
