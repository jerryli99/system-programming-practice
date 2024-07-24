#include <stdio.h>

//write strcmp not strncmp
 
/**
 * @brief This is my 1st version strcmp. It will compare the string byte by byte.
 * @param str1 A constant pointer to a constant char.
 * @param str2 A constant pointer to a constant char.
 * 
 * @return An integer either 0 for equal, -1 for str1 less than str2, 
 *         and 1 for str1 greater than str2.
 */
int my_strcmp(const char *const str1, const char *const str2) {
    const char *str1_ptr = NULL;
    const char *str2_ptr = NULL;
    int cmp_result = 0;

    str1_ptr = str1;
    str2_ptr = str2;

    while (*str1_ptr != '\0' && (*str1_ptr == *str2_ptr)) {
        str1_ptr++;
        str2_ptr++;
    }

    if (*str1_ptr < *str2_ptr) {
        cmp_result = -1;
    }

    if (*str1_ptr > *str2_ptr) {
        cmp_result = 1;
    }

    return cmp_result; 
}

//This version of strcmp fixed the signed char issue of comparison.
//I am wondering if we can compare word by word and not byte by byte.
int my_strcmp_v2(const char *const str1, const char *const str2) {
    const char *str1_ptr = NULL;
    const char *str2_ptr = NULL;

    str1_ptr = str1;
    str2_ptr = str2;

    while (*str1_ptr != '\0' && (*str1_ptr == *str2_ptr)) {
        str1_ptr++;
        str2_ptr++;
    }

    // Compare the characters as unsigned char to avoid signed character issues?? 
    //uhmmmm, alignment after type cast? uhmmm..
    unsigned int casted_str1 = *(const unsigned int *)str1_ptr;
    unsigned int casted_str2 = *(const unsigned int *)str2_ptr;

    printf("%d, %d\n", casted_str1, casted_str2);

    if (casted_str1 < casted_str2) {
        return -1;
    }

    if (casted_str1 > casted_str2) {
        return 1;
    }

    return 0;  // Strings are equal
}

int main() {
    char str1[] = "Hello";
    char str2[] = "Hello Dude";

    char str3[6] = {'H', 'e', 'l', 'l', 0xff, '\0'};//?? maybe the first version of my_strcmp is not handling it.

    printf("%d\n", my_strcmp(str1, str3));
    printf("%d\n", my_strcmp_v2(str1, str3));

    return 0;
}