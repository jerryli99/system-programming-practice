#include <stdio.h>
#include <ctype.h>

void captialize(char *const string) {
    char *str_ptr = NULL;

    for (str_ptr = string; *str_ptr != '\0'; str_ptr++) {
        *str_ptr = toupper(*str_ptr);
    }

    return;
}


int main() {
    char str1[] = "oqiuweAoyeg@#IuhoqIUA";
    captialize(str1);
    printf("%s\n", str1);

    return 0;
}