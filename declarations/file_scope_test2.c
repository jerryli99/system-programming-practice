// file2.c
#include <stdio.h>

extern int global_var;  // Declare the external variable
//extern int static_var; //this will fail can give us the undefined reference to static_var error.


void modify_var_in_file2() 
{
    global_var += 20;
    //static_var += 30;
}

 //how about this guy then? well, only visible to this file.
static void modify_var_in_file2_1() 
{
    global_var += 40;
}

// int strlen(const char *str)
// {
//    const char *tmp = str;
//    int len = 0;
//    while (*tmp != '\0')
//    {
//         ++len;
//         ++tmp;
//    }
//    return len;
// }

// int strcmp(const char *str1, const char *str2)
// {
//     while (*str1 && (*str1 == *str2))
//     {
//         str1++;
//         str2++;
//     }

//     return *(unsigned char *)str1 - *(unsigned char *)str2;
// }