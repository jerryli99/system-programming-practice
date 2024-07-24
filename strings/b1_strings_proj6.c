#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define NUM_PLANETS 9

bool ignore_case(const char *str1, const char *str2);

int main(int argc, char *argv[]) {

    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};

    int index, planet_index;

    for (index = 1; index < argc; index++) {
        for (planet_index = 0; planet_index < NUM_PLANETS; planet_index++) {
            if (ignore_case(argv[index], planets[planet_index])) {
                printf("%s is planet %d\n", argv[index], planet_index + 1);
                break;
            }
        }

        if (planet_index == NUM_PLANETS) {
            printf("%s is not a planet\n", argv[index]);
        }
    }

    return 0;
}

/**
 * @brief This program improves the program from Book Section 13.7 by habing it ignore case when 
 *        comparing command-line arguments ith strings ni the planets array.
 * 
 * @param str1 A pointer to constant char
 * @param str2 A pointer to contant char
 * 
 * @return Return boolean value true or false
 */
bool ignore_case(const char *str1, const char *str2) {
    for ( ; toupper(*str1) == toupper(*str2); str1++, str2++) {
        if (*str1 != '\0') {
            return true;
        }
    }

    return false;
}