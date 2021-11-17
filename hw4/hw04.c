#include "hw04.h"

// hw0401
int64_t print_K(int64_t n) {
    for (int64_t i = 0; i < n; i++) {
        int64_t len = (n / 2) - (i > (n - i - 1) ? (n - i - 1) : i);

        for (int64_t j = 0; j <= len; j++) {
            if (j == 0 || j == len) printf("*");
            else printf(" ");
        }

        printf("\n");
    }

    return 1;
}

// hw0402
int64_t hanoi_recursive(int64_t n, int64_t from, int64_t to, int64_t temp, int64_t now) {
    if (n == 1) {
        printf("move disk %" PRId64 " to rod %" PRId64 "\n", now, to);
        return 1;
    }

    hanoi_recursive(n - 1, from, temp, to, now - 1);
    printf("move disk %" PRId64 " to rod %" PRId64 "\n", now, to);
    hanoi_recursive(n - 1, temp, to, from, now - 1);

    return 1;
}

int64_t hanoi_iterative(int64_t n) {
    Rod from = create_rod(n, 1), to = create_rod(n, 0), temp = create_rod(n, 0);

    int64_t moves = power(2, n) - 1;

    for (int64_t i = 1; i <= moves; i++) {
        int64_t reversed = 0;
        if (i % 3 == 1) {
            int64_t disk = transfer_disk(&from, &to, &reversed);
            printf("move disk %" PRId64 " to rod %d\n", disk, reversed ? 1 : 3);
        }
        else if (i % 3 == 2) {
            int64_t disk = transfer_disk(&from, &temp, &reversed);
            printf("move disk %" PRId64 " to rod %d\n", disk, reversed ? 1 : 2);
        }
        else {
            int64_t disk = transfer_disk(&temp, &to, &reversed);
            printf("move disk %" PRId64 " to rod %d\n", disk, reversed ? 2 : 3);
        }
    }

    return 1;
}

int64_t power(int64_t base, int64_t exp) {
    if (exp == 0) return 1;
    if (exp == 1) return base;

    int64_t result = power(base, exp / 2);
    result *= result;

    if (exp % 2 == 1) result *= base;

    return result;
}

Rod create_rod(int64_t n, int8_t fill) {
    Rod rod;

    if (fill) {
        rod.top = n - 1;
        for (int64_t i = 0; i < n; i++) rod.disks[n - 1 - i] = i + 1;
    }
    else {
        rod.top = -1;
        for (int64_t i = 0; i < n; i++) rod.disks[i] = 0;
    }

    return rod;
}

int64_t move_disk(Rod* from, Rod* to) {
    int64_t disk = from->disks[from->top];

    from->top--;
    to->top++;

    to->disks[to->top] = disk;

    return disk;
}

int64_t transfer_disk(Rod* a, Rod* b, int64_t* reversed) {
    if (a->top == -1) {
        *reversed = 1;
        return move_disk(b, a);
    }
    if (b->top == -1) {
        *reversed = 0;
        return move_disk(a, b);
    }

    if (a->disks[a->top] > b->disks[b->top]) {
        *reversed = 1;
        return move_disk(b, a);
    }
    else {
        *reversed = 0;
        return move_disk(a, b);
    }
}

// hw0403

// hw0404
