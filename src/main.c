
#include <stdio.h>

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

        total += temperature;

        if (temperature >= 68 && temperature <= 76) {
            printf("Status: NORMAL\n");
            printf("LED: OFF\n");
        } else {
            printf("Status: WARNING\n");
            printf("LED: ON\n");
        }
    }

    double average = total / count;

    printf("\n=== Temperature Summary ===\n");
    printf("Total readings: %d\n", count);
    printf("Average temperature: %.2f F\n", average);

    return 0;
}
