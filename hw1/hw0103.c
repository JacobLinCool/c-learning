#include <stdio.h>
#include <stdint.h>

int main() {
    int16_t input;

    printf("Please enter an unsigned 16-bits number: ");
    scanf("%d", &input);

    printf("Before Flip:\n%d_10 = %x_16\n", input, input);

    int16_t flipped = (input & 0xF000) >> 12 | (input & 0x0F00) >> 4 | (input & 0x00F0) << 4 | (input & 0x000F) << 12;

    printf("After Flip:\n%d_10 = %x_16\n", flipped, flipped);

    return 0;
}
