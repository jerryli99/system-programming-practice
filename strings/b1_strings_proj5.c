/**
 * @brief This program adds up its commmand-line arguments, which are assumed to be integers.
 * 
 */

#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[]) {
    int sum = 0;
    char **argv_ptr = NULL;

    if (argc < 2) {
        printf("Usage: %s number1 number2 ... numberN\n", argv[0]);
        return 1;
    }

    for (argv_ptr = argv + 1; argv_ptr < argv + argc; argv_ptr++) {
        sum = sum + atoi(*argv_ptr); //the books asks me to use this function...
    }

    printf("Total: %d\n", sum);

    return 0;
}