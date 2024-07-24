/**
 * @brief This program will echo its command-line arguments in reverse order.
 * 
 */

#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

    //method 1
    for (int index = argc - 1; index >= 1; index--) {
        printf("%s ", argv[index]);
    }

    printf("\n");

    //method 2
    char **argv_ptr = NULL;

    for (argv_ptr = argv + argc - 1; argv_ptr > argv; argv_ptr--) {
        printf("%s ", *argv_ptr);
    }

    printf("\n");

    return 0;
}