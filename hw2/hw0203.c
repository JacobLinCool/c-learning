#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int32_t validate_input(int32_t yy, int32_t mm, int32_t dd, int32_t h, int32_t m); // O(1)
int64_t calc_total_days(int32_t y1, int32_t m1, int32_t d1, int32_t y2, int32_t m2, int32_t d2); // O(dy)
int8_t calc_weekday(int32_t y, int32_t m, int32_t d); // O(1)
int32_t calc_single(int32_t h1, int32_t m1, int32_t h2, int32_t m2); // O(1)

int32_t main() {
    int32_t b_yy, b_mm, b_dd, b_h, b_m, e_yy, e_mm, e_dd, e_h, e_m;

    printf("From: ");
    if (scanf("%d/%d/%d %d:%d", &b_yy, &b_mm, &b_dd, &b_h, &b_m) != 5) {
        printf("Invalid Input: Only Integers Allowed.\n");
        return 1;
    }

    printf("To: ");
    if (scanf("%d/%d/%d %d:%d", &e_yy, &e_mm, &e_dd, &e_h, &e_m) != 5) {
        printf("Invalid Input: Only Integers Allowed.\n");
        return 1;
    }

    // printf("[DEBUG] %ld %ld %ld %ld %ld\n", b_yy, b_mm, b_dd, b_h, b_m);
    // printf("[DEBUG] %ld %ld %ld %ld %ld\n", e_yy, e_mm, e_dd, e_h, e_m);

    // Throw an ERROR if the date-time is not valid
    if (validate_input(b_yy, b_mm, b_dd, b_h, b_m) || validate_input(e_yy, e_mm, e_dd, e_h, e_m)) {
        printf("Invalid Input: Containing Invalid Date(s).\n");
        return 1;
    }

    int64_t result = 0;
    int64_t total_days = calc_total_days(1, 1, 1, e_yy, e_mm, e_dd) - calc_total_days(1, 1, 1, b_yy, b_mm, b_dd) + 1;
    // printf("[DEBUG] total_days: %" PRId64 "\n", total_days);

    int8_t b_weekday = calc_weekday(b_yy, b_mm, b_dd);
    // printf("[DEBUG] b_weekday: %u\n", b_weekday);

    if (total_days < 1) {
        printf("Invalid Input: End Date is earlier than Start Date.\n");
        return 1;
    }

    // full-week between start and end
    if (total_days - 2 >= 7) {
        result += ((total_days - 2) / 7) * 40 * 60;
        total_days -= ((total_days - 2) / 7) * 7;
    }

    if (total_days == 1) {
        // the start time and end time are in the same day
        result = calc_single(b_h, b_m, e_h, e_m);
        if (result < 0) {
            printf("Invalid Input: End Time is earlier than Start Time.\n");
            return 1;
        }
        if (b_weekday == 0 || b_weekday == 6) result = 0;
    }
    else {
        if (b_weekday != 0 && b_weekday != 6) result += calc_single(b_h, b_m, 24, 0);
        for (int8_t i = 2; i < total_days; i++) {
            b_weekday = (b_weekday + 1) % 7;
            if (b_weekday != 0 && b_weekday != 6) result += calc_single(0, 0, 24, 0);
        }
        b_weekday = (b_weekday + 1) % 7;
        if (b_weekday != 0 && b_weekday != 6) result += calc_single(0, 0, e_h, e_m);
    }

    // printf("[DEBUG] result: %" PRId64 "\n", result);
    printf("Working Hours : %" PRId64 " hours %" PRId64 " mins.\n", result / 60, result % 60);

    return 0;
}

// check if the input year is leap year. @return yes(1) or no(0)
int32_t is_leap(int32_t yr) {
    if (yr % 4 == 0 && yr % 100 != 0) return 1;
    if (yr % 400 == 0) return 1;
    return 0;
}

// validate the input. @return valid(0) or invalid(1)
int32_t validate_input(int32_t yy, int32_t mm, int32_t dd, int32_t h, int32_t m) {
    if (yy < 1 || mm < 0 || mm > 12 || dd < 0 || dd > 31 || h < 0 || h > 24 || m < 0 || m > 59 || (h == 24 && m != 0)) return 1;
    if ((mm == 4 || mm == 6 || mm == 9 || mm == 11) && dd > 30) return 1;
    if (mm == 2 && dd > is_leap(yy) + 28) return 1;
    return 0;
}

// calculate the first day's weekday (Thanks to the Internet) 
// @return weekday: Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6, Sunday = 0
int8_t calc_weekday(int32_t y, int32_t m, int32_t d) {
    return (d += m < 3 ? y-- : y - 2, 23 * m / 9 + d + 4 + y / 4 - y / 100 + y / 400) % 7;
}

// calculate the number of days between two dates in one specific year. @return days
int32_t calc_days_in_year(int32_t yr, int32_t m1, int32_t d1, int32_t m2, int32_t d2) {
    // printf("[DEBUG] m1: %d, d1: %d, m2: %d, d2: %d\n", m1, d1, m2, d2);
    int32_t month[12] = { 31, 28 + is_leap(yr), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // printf("[DEBUG] month[0]: %d, month[1]: %d, month[2]: %d, month[3]: %d, month[4]: %d, month[5]: %d, month[6]: %d, month[7]: %d, month[8]: %d, month[9]: %d, month[10]: %d, month[11]: %d\n", month[0], month[1], month[2], month[3], month[4], month[5], month[6], month[7], month[8], month[9], month[10], month[11]);

    int32_t days = 0;
    for (int32_t i = m1; i < m2; i++) days += month[i - 1];
    days += d2 - d1 + 1;
    // printf("[DEBUG] days: %d\n", days);
    return days;
}

// calculate the number of days between two dates. @return days
int64_t calc_total_days(int32_t y1, int32_t m1, int32_t d1, int32_t y2, int32_t m2, int32_t d2) {
    int64_t days = 0;

    // years between y1 and y2
    for (int32_t i = y1 + 1; i < y2; i++) days += 365 + is_leap(i);
    // printf("[DEBUG] days: %" PRId64 "\n", days);

    if (y1 == y2) {
        days += calc_days_in_year(y1, m1, d1, m2, d2);
    }
    else {
        days += calc_days_in_year(y1, m1, d1, 12, 31);
        days += calc_days_in_year(y2, 1, 1, m2, d2);
    }

    // printf("[DEBUG] days: %ld\n", days);
    return days;
}

// calculate the working minutes of a single day @return minutes
int32_t calc_single(int32_t h1, int32_t m1, int32_t h2, int32_t m2) {
    int32_t begin = h1 * 60 + m1, end = h2 * 60 + m2;
    if (begin > end) return end - begin;

    if (begin > 18 * 60 + 30 || end < 9 * 60) return 0;
    if (begin < 9 * 60) begin = 9 * 60;
    if (end > 18 * 60 + 30) end = 18 * 60 + 30;

    int32_t diff = end - begin;

    if (begin <= 12 * 60 && end >= 13 * 60 + 30) diff -= 90;
    else if (begin <= 12 * 60 && end >= 12 * 60) diff -= (end - 12 * 60);
    else if (begin <= 13 * 60 + 30 && end >= 13 * 60 + 30) diff -= (13 * 60 + 30 - begin);
    else if (begin >= 12 * 60 && end <= 13 * 60 + 30) diff = 0;

    return diff;
}
