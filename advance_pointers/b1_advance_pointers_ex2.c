#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *duplicate(char *input_str)
{
    char *output_str = malloc(strlen(input_str) + 1);
    if (output_str == NULL)
    {
        printf("Error: malloc failed");
        exit(EXIT_FAILURE);
    } 
    strcpy(output_str, input_str);
    return (output_str);
}

int main() 
{
    char *str1 = "abcdef!@#$%";
    char *str2 = duplicate(str1);

    printf("Original String: %s\n", str1);
    printf("Duplicated String: %s\n", str2);

    free(str2);
    
    str2 = NULL;

    return (0);
}