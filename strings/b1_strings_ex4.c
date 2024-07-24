#include <stdio.h>
#include <ctype.h>

#define MESSAGE_MAX_LEN 20

int read_line_part_a(char string[], const int size) {
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

int read_line_part_b(char string[], const int size) {
    int input_char = 0;
    int index = 0;

    while (isspace(input_char = getchar) == 1) {
        if (index < size) {
            string[index++] = input_char;
        }
    }

    string[index] = '\0';
    return index;
}

int read_line_part_c(char string[], const int size) {
    int input_char = 0;
    int index = 0;

    do {
        input_char = getchar();
        if (index < size) {
            string[index++] = input_char;
        }
    } while (input_char != '\n');

    string[index] = '\0';
    return index;
}

int read_line_part_d(char string[], const int size) {
    int input_char = 0;
    int index = 0; //just in case

    for (index = 0; index < size - 1; index++) {
        input_char = getchar();
        if (input_char == '\n') {
            break;
        }
        string[index] = input_char;
    }

    string[index] = '\0';
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
    char message_a[MESSAGE_MAX_LEN];
    char message_b[MESSAGE_MAX_LEN];
    char message_c[MESSAGE_MAX_LEN];
    char message_d[MESSAGE_MAX_LEN];

    printf("Enter a message: ");
    printf("%d\n", read_line_part_a(message_a, MESSAGE_MAX_LEN));
    print_line(message_a);

    printf("Enter a message: ");
    printf("%d\n", read_line_part_a(message_b, MESSAGE_MAX_LEN));
    print_line(message_b);

    printf("Enter a message: ");
    printf("%d\n", read_line_part_a(message_c, MESSAGE_MAX_LEN));
    print_line(message_c);

    printf("Enter a message: ");
    printf("%d\n", read_line_part_a(message_d, MESSAGE_MAX_LEN));
    print_line(message_d);

    return 0;
}
