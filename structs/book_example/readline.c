#include <ctype.h>
#include <stdio.h>
#include "readline.h"

int read_line(char str[], int n) {
    int character, index = 0;

    while (isspace(character=getchar()));

    while (character != '\n' && character != EOF) {
        if (index < n) {
            str[index++] = character;
        }
        character = getchar();
    }
    
    str[index] = '\0';

    return index;
}