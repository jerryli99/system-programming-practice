#include <stdio.h>

size_t my_strlen(const char *const string) {
    size_t str_len;
    const char *str_ptr = string;

    for (str_len = 0; *str_ptr != '\0'; str_ptr++) {
        str_len++;
    }
    return str_len;
}

size_t my_strlen_version2(const char *const string) {
   const char *str_ptr = string;

   while (*str_ptr) {
    str_ptr++;
   }

   return (str_ptr - string);
}

char *my_strcat(char *str1, const char *const str2) {
    char *str1_ptr = str1;
    const char *str2_ptr = str2;

    while (*str1_ptr != '\0') {
        str1_ptr++;
    }

    //now, str1_ptr is pointing to '\0'
    while (*str2_ptr != '\0') {
        *str1_ptr = *str2_ptr;
        str1_ptr++;
        str2_ptr++;
    }

    *str1_ptr = '\0';
    return str1;
}

int main() {

    char str1[10] = "abcdfg";
    char str2[4] = "_rr";
    printf("%ld\n", my_strlen(str1)); // 6
    printf("%ld\n", my_strlen_version2(str1));

    printf("%s\n", my_strcat(str1, str2));

    //Topic: array of strings

    //this is a 2d array, '\0' will be filled if the length 8 is not met.
    // char planets[][8] = {"Mercury", "Venus", "Earth", 
    //                     "Mars", "Jupiter", "Saturn",
    //                     "Uranus", "Neptune", "Pluto"};

    //the case above might not be efficient to work with. Remember in C we have ragged array.
    //That basicall means a 2d array with different lengths of rows.
    char *planets[] = {"Mercury", "Venus", "Earth", 
                        "Mars", "Jupiter", "Saturn",
                        "Uranus", "Neptune", "Pluto"};

/*
planets index
    0   -----> [M, e, r, c, u, r, y, \0]
    1   -----> [V, e, n, u, s, \0]
    2   -----> [E, a, r, t, h, \0]
    3   ...
    4   ...
    5   ...
    6
    7
    etc
*/
    for (int index = 0; index < 9; index++) {
        if (planets[index][0] == 'M') {
            printf("%s begins with M\n", planets[index]);
        }
    }

    return 0;
}