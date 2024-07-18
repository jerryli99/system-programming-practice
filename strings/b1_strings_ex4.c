#include <stdio.h>
#include <ctype.h>

#define MESSAGE_MAX_LEN 20

int read_line_part_a(char string[], int size) {
    int input_char = 0;
    int index = 0;

    while ((input_char = getchar()) != '\n') {
        if (index == 0 && isspace(input_char) == 1) {
            //nothing to do
        } 

        if (index < size) {
            string[index] = input_char;
            index++;
        }
    }

    string[index] =  '\0';
    return index;
}

void print_line(const char string[]) {
    const char *str_ptr;

    for (str_ptr = string; *str_ptr != '\0'; str_ptr++) {
        printf("%c", *str_ptr);
    }
    putchar('\n');
    return;
}

int main() {
    char message[MESSAGE_MAX_LEN];
    printf("Enter a message: ");
    printf("%d\n", read_line_part_a(message, MESSAGE_MAX_LEN));
    print_line(message);

    return 0;
}
