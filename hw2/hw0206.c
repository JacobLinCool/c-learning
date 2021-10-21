#include <stdio.h>

int front_color = 91;

void ranbow_print(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        printf("\033[1;%dm%c\033[0m", front_color, str[i]);
        front_color = front_color == 96 ? 91 : front_color + 1;
    }
}

int main() {
    ranbow_print("Hello, World!\n");
    return 0;
}
