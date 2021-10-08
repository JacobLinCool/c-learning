#include <stdio.h>
#define STRING_COUNT 9
#define MAX_SIZE 200

int main() {
    char s[STRING_COUNT][MAX_SIZE] = {
        "THE LAST BUG",
        "\"But you're out of your mind ,\"\nThey said with a shrug.\n\"The customer's happy;\nWhat's one little bug?\"",
        "But he was determined.\nThe others went home.\nHe spread out the program ,\nDeserted , alone.",
        "The cleaning men came,\nThe whole room was cluttered\nWith memory -dumps , punch cards.\n\"I'm close ,\" he muttered.",
        "The mumbling got louder ,",
        "Simple deduction ,\n\"I've got it, it's right ,\nJust change one instruction.\"",
        "It still wasn't perfect ,\nAs year followed year ,\nAnd strangers would comment ,\n\"Is that guy still here?\"",
        "He died at the console ,\nOf hunger and thirst.\nNext day he was buried ,\nFace down , nine -edge first.",
        "And the last bug in sight ,\nAn ant passing by,\nSaluted his tombstone ,\nAnd whispered , \"Nice try.\""
    };

    for (int i = 0; i < STRING_COUNT; i++) {
        printf("%s\n\n", s[i]);
    }
    return 0;
}
