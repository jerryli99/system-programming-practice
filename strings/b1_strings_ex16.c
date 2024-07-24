#include <stdio.h>

int count_spaces(const char *string);

int main(void) {
    const char str1[] = "Hello this a a wer hhh ";
    printf("Number of spaces: %d\n", count_spaces(str1));
    return 0;
}

int count_spaces(const char *string) {
    const char *str_ptr = NULL;
    int count = 0;

    str_ptr = string;

    while (*str_ptr != '\0') {
        if (*str_ptr++ == ' ') {
            count++;
        }
    }

    return count;
}