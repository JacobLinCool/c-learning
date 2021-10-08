#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t input;

    printf("Please enter an unsigned 16-bits number: ");
    scanf("%hu", &input);

    printf("Before Flip:\n%u_10 = %x_16\n", input, input);

    uint16_t flipped = (input & 0xF000) >> 12 | (input & 0x0F00) >> 4 | (input & 0x00F0) << 4 | (input & 0x000F) << 12;

    printf("After Flip:\n%u_10 = %x_16\n", flipped, flipped);

    return 0;
}
