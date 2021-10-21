#include <stdio.h>
#include <stdint.h>

double rate[3][4] = {
    {3.4, 3.8, 4.2, 4.6},
    {1.4, 2.0, 2.3, 2.6},
    {1.1, 1.2, 1.5, 2.0}
};

int32_t main() {
    int64_t word_count, service_level, delivery_time;

    printf("Word Count\n  Please enter the word count : ");
    if (scanf("%ld", &word_count) != 1 || word_count < 0) {
        printf("  Invalid input.\n");
        return 1;
    }

    printf("Service Level\n  1) Advanced service\n  2) Standard service\n  3) Basic service\n  Your choice : ");
    if (scanf("%ld", &service_level) != 1 || service_level < 1 || service_level > 3) {
        printf("Invalid input.\n");
        return 0;
    }

    printf("Delivery Time\n  1) Economic\n  2) Standard\n  3) Fast\n  4) Deadline\n  Your choice : ");
    if (scanf("%ld", &delivery_time) != 1 || delivery_time < 1 || delivery_time > 4) {
        printf("Invalid input.\n");
        return 0;
    }

    // printf("[DEBUG] word_count: %d\n", word_count);
    // printf("[DEBUG] rate: %g\n", rate[service_level - 1][delivery_time - 1]);

    double fee = (double)word_count * rate[service_level - 1][delivery_time - 1];

    // fix IEEE 754 when rate is 2.3 or 4.6 (will not affect the other cases)
    fee += 0.000001;

    // discounts
    if (service_level == 1 && word_count >= 2000) fee *= 0.75;
    if (service_level == 2 && word_count >= 6000) fee *= 0.9;
    if (service_level == 3 && word_count >= 6000) fee *= 0.95;

    printf("Proofreading fee --> %ld\n", (int64_t)fee);

    return 0;
}
