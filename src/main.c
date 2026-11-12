
#include <stdio.h>
#include <time.h>

// Saves each temperature reading to the CSV file
int save_reading(double temperature, const char *status)
{
    FILE *file = fopen("data/temperature_log.csv", "a+");

    if (file == NULL) {
        printf("Error: Could not open CSV file.\n");
        return 0;
    }

    // Add the header if the file is empty
    if (fseek(file, 0, SEEK_END) != 0) {
        fclose(file);
        return 0;
    }

    long size = ftell(file);

    if (size < 0) {
        fclose(file);
        return 0;
    }

    if (size == 0) {
        fprintf(file, "timestamp,temperature_f,status\n");
    }

    // Get the current date and time
    time_t now = time(NULL);
    struct tm *current = localtime(&now);
    char timestamp[32];

    if (current == NULL ||
        strftime(timestamp, sizeof(timestamp),
                 "%Y-%m-%d %H:%M:%S", current) == 0) {
        fclose(file);
        return 0;
    }

    // Save the temperature and status
    if (fprintf(file, "%s,%.2f,%s\n",
                timestamp, temperature, status) < 0) {
        fclose(file);
        return 0;
    }

    if (fclose(file) != 0) {
        return 0;
    }

    return 1;
}

int main(void)
{
    int count;
    double temperature;
    double total = 0.0;

    printf("=== Classroom Comfort Monitor ===\n");
    printf("How many temperature readings? ");

    if (scanf("%d", &count) != 1 || count <= 0) {
        printf("Error: Invalid number of readings.\n");
        return 1;
    }

    for (int i = 1; i <= count; i++) {

        printf("\nEnter temperature %d (F): ", i);

        if (scanf("%lf", &temperature) != 1) {
            printf("Error: Invalid temperature.\n");
            return 1;
        }

        const char *status;

        if (temperature >= 68 && temperature <= 76) {
            status = "NORMAL";
            printf("Status: NORMAL\n");
            printf("LED: OFF\n");
        } else {
            status = "WARNING";
            printf("Status: WARNING\n");
            printf("LED: ON\n");
        }

        // Write the reading to the CSV file
        if (!save_reading(temperature, status)) {
            printf("Error: Failed to save reading.\n");
            return 1;
        }

        printf("Reading saved successfully.\n");

        total += temperature;
    }

    double average = total / count;

    printf("\n=== Temperature Summary ===\n");
    printf("Total readings: %d\n", count);
    printf("Average temperature: %.2f F\n", average);

    return 0;
}
