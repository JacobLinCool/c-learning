#include <stdio.h>

int main() {
    float acceleration, time, velocity, altitude;

    printf("Please enter the acceleration due to gravity: ");
    scanf("%f", &acceleration);

    printf("Please enter the time (s): ");
    scanf("%f", &time);

    velocity = acceleration * time;
    altitude = (acceleration * time * time) / 2;

    // print the results, only print 2 decimal places of velocity and 3 decimal places of altitude
    printf("Final velocity: %.2f m/s\nThe altitude: %.3f m\n", velocity, altitude);

    return 0;
}