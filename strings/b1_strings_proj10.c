#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 100

void reverse_name(const char *const name);

int main(void) {
    char name[MAX_LEN + 1];
    printf("Input first and last name: ");

    fgets(name, sizeof(name), stdin); 
    reverse_name(name);

    return 0;
}

/**
 * @brief This function will print out the users name in reverse order. 
 *        Thus expect Lastname, firstname's initial as result.
 * 
 * @param name A contant pointer to conatant char.
 * 
 * @return Return void.
 */
void reverse_name(const char *const name) {
    const char *name_ptr = name;
    char initial;

    while (*name_ptr != '\0' && *name_ptr == ' ') {
        name_ptr++;
    }

    initial = *name_ptr++;

    while (*name_ptr != '\0' && *name_ptr++ != ' ');

    while (*name_ptr != '\0' && *name_ptr != '\n') {
        putchar(*name_ptr++);
    }

    printf(", %c\n", initial);
}