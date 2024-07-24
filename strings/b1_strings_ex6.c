#include <stdio.h>

void censor(char *const string) 
{
    char *str_ptr = NULL;

    for (str_ptr = string; *str_ptr != '\0'; str_ptr++) 
    {
        if (*str_ptr == 'f' && 
            *(str_ptr + 1) == 'o' && 
            *(str_ptr + 2) == 'o') 
        {
            *str_ptr = 'x';
            *(str_ptr + 1) = 'x';
            *(str_ptr + 2) = 'x';
        }
    }
}

int main() {
    char str1[] = "food fool foofppooo affoo";
    printf("before censor: %s\n", str1);
    censor(str1);
    printf("after censor:  %s\n", str1);
    return 0;
}