#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 50

void read_input(char *a, int max_length);
void print_input_reverse(const char *a);
void print_input_reverse_subscript(const char a[], int n);
void reverse_array(char *a);

int main() {
    char a[MAX_LENGTH];

    read_input(a, MAX_LENGTH);

    // Print the stored input
    printf("You entered: \"%s\", string length %ld\n", a, strlen(a));
    print_input_reverse(a);
    print_input_reverse_subscript(a, strlen(a));
    reverse_array(a);

    printf("Reversed input:  %s\n", a);

    return 0;
}

void read_input(char *a, int max_length) {
    char *p = a;
    char ch;

    printf("Enter a string (up to %d characters): ", max_length - 1);

    // Read characters one by one
    while (p < a + max_length - 1 && (ch = getchar()) != '\n' && ch != EOF) {
        *p++ = ch;
    }
    *p = '\0'; // Null-terminate the string

    // Clear the input buffer if the user input exceeds the maximum length
    if (ch != '\n' && ch != EOF) {
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

void print_input_reverse(const char *a) {
    const char *p = NULL;
    printf("print input in reverse order: ");
    for (p = a + strlen(a) - 1; p >= &a[0]; p--) {
        printf("%c", *p);
    }
    printf("\n");
}

void print_input_reverse_subscript(const char a[], int n) {
    printf("print input in reverse using array subscripting: ");
    for (int i = n - 1; i >= 0; i--) {
        printf("%c", a[i]);
    }
    printf("\n");
}

void reverse_array(char *a) {
    char *start = a;
    char *end = a + strlen(a) - 1;
    char temp;

    while (start < end) {
        temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
}

// With integer to keep track of the current position of array.
// void read_input(char *a, int max_length) {
//     int i = 0;
//     char ch;

//     printf("Enter a string (up to %d characters): ", max_length - 1);

//     // Read characters one by one
//     while (i < max_length - 1 && (ch = getchar()) != '\n' && ch != EOF) {
//         a[i++] = ch;
//     }
//     a[i] = '\0'; // Null-terminate the string

//     // Clear the input buffer if the user input exceeds the maximum length
//     if (ch != '\n' && ch != EOF) {
//         while ((ch = getchar()) != '\n' && ch != EOF);
//     }
// }

// void reverse_array(char *a) {
//     int len = strlen(a);

//     for (int i = 0; i < len / 2; i++) {
//         char temp = a[i];
//         a[i] = a[len - 1 - i];
//         a[len - 1 - i] = temp;
//     }
// }
