#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 50

void read_input(char *a, int max_length);
bool check_palindrome(const char *a, int length);
bool check_palindrome_subscript(const char *a, int length);


int main() {
    char a[MAX_LENGTH];

    read_input(a, MAX_LENGTH);

    int length = strlen(a);

    // Print the stored input
    printf("You entered: %s, string length: %d\n", a, length);

    printf("Check if palidrome: %d\n", check_palindrome(a, length));
    printf("Check if palidrome version2: %d\n", check_palindrome_subscript(a, length));
    return 0;
}

void read_input(char *a, int max_length) {
    char *p = a;
    char ch;

    printf("Enter a string (up to %d characters): ", max_length - 1);

    // Read characters one by one
    while (p < a + max_length - 1 && (ch = getchar()) != '\n' && ch != EOF) { 
        if (isalpha(ch)) { // Check if the character is alphabetic
            *p++ = tolower(ch); // Convert to lowercase before adding
        }
    }

    *p = '\0'; // Null-terminate the string

    // Clear the input buffer if the user input exceeds the maximum length
    if (ch != '\n' && ch != EOF) {
        while ((ch = getchar()) != '\n' && ch != EOF);
    }
}

bool check_palindrome(const char *a, int length) {
    const char *p = NULL, *q = NULL;
    p = a;
    q = a + length - 1;

    while (p < q) {
        if (*p++ != *q--) {
            return false;
        }
    }

    return true;
}

bool check_palindrome_subscript(const char *a, int length) {
    int p = 0;
    int q = length - 1;

    while (p < q) {
        if (a[p++] != a[q--]) {
            return false;
        }
    }
    return true;
}