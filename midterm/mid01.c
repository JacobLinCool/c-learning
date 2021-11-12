// Computer Programming I - Midterm Exam #1
// Copyright © 2021 JacobLinCool. All rights reserved.
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

/* #region Input */

long double ask(char* question, long double min, long double max) {
    long double answer;
    printf("%s", question);
    scanf("%Lf", &answer);
    while (answer < min || answer > max) {
        printf("Please enter a number between %Lf and %Lf: ", min, max);
        scanf("%Lf", &answer);
    }
    return answer;
}

/* #endregion */

int main() {


    return 0;
}
