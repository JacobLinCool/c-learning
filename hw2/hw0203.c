#include <stdio.h>
#include <stdint.h>

int64_t validate_input(int64_t yy, int64_t mm, int64_t dd, int64_t h, int64_t m);
int64_t calc_total_days(int64_t y1, int64_t m1, int64_t d1, int64_t y2, int64_t m2, int64_t d2);
int8_t calc_weekday(int64_t y, int64_t m, int64_t d);
int64_t calc_single(int64_t h1, int64_t m1, int64_t h2, int64_t m2);

int64_t main() {
    int64_t b_yy, b_mm, b_dd, b_h, b_m, e_yy, e_mm, e_dd, e_h, e_m;

    printf("From: ");
    // Throw an ERROR if the input is not accepted
    if (scanf("%lld/%lld/%lld %lld:%lld", &b_yy, &b_mm, &b_dd, &b_h, &b_m) != 5) {
        printf("Invalid Input: Only Integers Allowed.\n");
        return 1;
    }

    printf("To: ");
    // Throw an ERROR if the input is not accepted
    if (scanf("%lld/%lld/%lld %lld:%lld", &e_yy, &e_mm, &e_dd, &e_h, &e_m) != 5) {
        printf("Invalid Input: Only Integers Allowed.\n");
        return 1;
    }

    // Throw an ERROR if the number is not valid
    if (validate_input(b_yy, b_mm, b_dd, b_h, b_m) || validate_input(e_yy, e_mm, e_dd, e_h, e_m)) {
        printf("Invalid Input: Containing Invalid Number(s).\n");
        return 1;
    }

    int64_t result = 0;
    int64_t total_days = calc_total_days(b_yy, b_mm, b_dd, e_yy, e_mm, e_dd);
    // printf("[DEBUG] total_days: %lld\n", total_days);
    int8_t weekday = calc_weekday(b_yy, b_mm, b_dd);
    // printf("[DEBUG] weekday: %u\n", weekday);

    // if the start time and end time are in the same day
    if (total_days == 0) {
        if (weekday != 0 && weekday != 6) result += calc_single(b_h, b_m, e_h, e_m);
    }
    else {
        if (weekday != 0 && weekday != 6) result += calc_single(b_h, b_m, 24, 0);
        for (int64_t i = 1; i < total_days; i++) {
            weekday = (weekday + 1) % 7;
            if (weekday != 0 && weekday != 6) result += calc_single(0, 0, 24, 0);
        }
        weekday = (weekday + 1) % 7;
        if (weekday != 0 && weekday != 6) result += calc_single(0, 0, e_h, e_m);
    }

    printf("Working Hours : %lld hours %lld mins.\n", result / 60, result % 60);

    return 0;
}

// validate the input. @return valid(0) or invalid(1)
int64_t validate_input(int64_t yy, int64_t mm, int64_t dd, int64_t h, int64_t m) {
    if (yy < 0 || mm < 0 || mm > 12 || dd < 0 || dd > 31 || h < 0 || h > 23 || m < 0 || m > 59) return 1;
    return 0;
}

// calculate the first day's weekday (Thanks to the Internet) 
// @return weekday: Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 0
int8_t calc_weekday(int64_t y, int64_t m, int64_t d) {
    return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
    // m = (m == 1 || m == 2) ? m + 10 : m - 2;
    // int64_t c = y / 100 - 1;
    // y -= (m == 1 || m == 2) ? 1 : 0;
    // int8_t weekday = (((y % 100) * 5 / 4) + m + d - 2 * (c % 4) + 7) % 7;
    // return weekday;
}

// check if the input year is leap year. @return yes(1) or no(0)
int64_t is_leap(int64_t yr) {
    if (yr % 4 == 0 && yr % 100 != 0) return 1;
    if (yr % 400 == 0) return 1;
    return 0;
}

// calculate the number of days between two dates in one specific year. @return days
int64_t calc_days_in_year(int64_t yr, int64_t m1, int64_t d1, int64_t m2, int64_t d2) {
    int64_t month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (is_leap(yr)) month[1] = 29;

    int64_t days = 0;
    for (int64_t i = m1; i < m2; i++) days += month[i];
    days += d2 - d1;
    return days;
}

// calculate the number of days between two dates. @return days
int64_t calc_total_days(int64_t y1, int64_t m1, int64_t d1, int64_t y2, int64_t m2, int64_t d2) {
    int64_t days = 0;

    // years between y1 and y2
    for (int64_t i = y1 + 1; i < y2; i++) days += is_leap(i) ? 366 : 365;

    if (y1 == y2) {
        days += calc_days_in_year(y1, m1, d1, m2, d2);
    }
    else {
        days += calc_days_in_year(y1, m1, d1, 12, 31);
        days += calc_days_in_year(y2, 1, 1, m2, d2);
    }

    return days;
}

// calculate the working minutes of a single day @return minutes
int64_t calc_single(int64_t h1, int64_t m1, int64_t h2, int64_t m2) {
    int64_t begin = h1 * 60 + m1, end = h2 * 60 + m2;
    if (begin < 9 * 60) begin = 9 * 60;
    if (end > 18 * 60 + 30) end = 18 * 60 + 30;

    int64_t diff = end - begin;

    if (begin < 12 * 60 && end > 13 * 60 + 30) diff -= 90;
    else if (begin < 12 * 60) diff -= (end - 12 * 60);
    else if (end > 13 * 60 + 30) diff -= (13 * 60 - 30 - begin);

    return diff;
}
