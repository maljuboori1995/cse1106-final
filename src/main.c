#include <stdio.h>

int main(void)
{
    double temperature;

    printf("=== Classroom Comfort Monitor ===\n");
    printf("Enter classroom temperature (F): ");

    if (scanf("%lf", &temperature) != 1) {
        printf("Error: Invalid temperature.\n");
        return 1;
    }

    if (temperature >= 68 && temperature <= 76) {
        printf("Status: NORMAL\n");
        printf("LED: OFF\n");
    } else {
        printf("Status: WARNING\n");
        printf("LED: ON\n");
    }

    return 0;
}
