/**
 * @brief A program that asks the user for a two-digit number, 
 *        then prints the English word for the number.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIN_NUMBER 10
#define MAX_NUMBER 99
#define BUFFER_SIZE 1024
#define DIVISOR 10
#define OFFSET_TENS 2
#define OFFSET_ONES 1
#define NUMBER_BASE 10

int main() {
    int number, tens, ones;
    char input[BUFFER_SIZE + 1];
    char *endptr;

    char *ones_tostr[] = {"one.", "two.", "three.", "four.", "five.",
                          "six.", "seven.", "eight.", "nine."};

    char *teens_tostr[] = {"ten.", "eleven.", "twelve.", "thirteen.",
                           "fourteen.", "fifteen.", "sixteen.", "seventeen.",
                           "eighteen.", "nineteen."};

    char *tens_tostr[] = {"twenty-", "thirty-", "forty-", "fifty-",
                          "sixty-", "seventy-", "eighty-", "ninety-"};

    printf("Enter a two-digit number: ");

    if (fgets(input, sizeof(input), stdin) == NULL) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    // Check if input length exceeds buffer size
    if (input[strlen(input) - 1] != '\n') {
        printf("Input is too long. Please enter a valid number within the buffer size.\n");
        return 1;
    }

    // Remove the newline character if present
    input[strlen(input) - 1] = '\0';

    number = strtol(input, &endptr, NUMBER_BASE);

    // Check for errors: No digits were found, or there are extra characters
    if (endptr == input || *endptr != '\0') {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    if (number < MIN_NUMBER || number > MAX_NUMBER) {
        printf("Error, please enter a number between %d and %d.\n", MIN_NUMBER, MAX_NUMBER);
        return 1;
    }

    tens = number / DIVISOR;
    ones = number % DIVISOR;

    printf("You entered the number ");
    
    if (tens == 1) {
        printf("%s\n", teens_tostr[ones]);
    } else if (ones == 0) {
        printf("%s\n", tens_tostr[tens - OFFSET_TENS]);
    } else {
        printf("%s%s\n", tens_tostr[tens - OFFSET_TENS], ones_tostr[ones - OFFSET_ONES]);
    }

    return 0;
}
