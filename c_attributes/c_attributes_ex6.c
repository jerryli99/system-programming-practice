//deprecated
//marks a function as deprecated and issues a warning if used

#include <stdio.h>

void old_function() __attribute__((deprecated));

void old_function()
{
    printf("This function is deprecated\n");
}

int main()
{
    old_function();//trigger a warning
    return 0;
}