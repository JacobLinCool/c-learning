#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

int main() {
    printf("%d\n", (int)sizeof(long double));
    printf("%.19Lf\n", 1L / 0.3L);

    // for (int64_t i = 0; i < 1e10; i++) {
    //     int64_t a = INT64_MAX - i;
    //     long double b = a;
    //     if ((int64_t)b != a) {
    //         printf("%Lf != %" PRId64 "\n", b, a);
    //         return 1;
    //     }
    //     if (i % (int64_t)1e8 == 0) {
    //         printf("%Lf\n", b);
    //     }
    // }

    return 0;
}
