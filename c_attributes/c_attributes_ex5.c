//noreturn 
//it is used to indicate that the function will not return

#include <stdio.h>
#include <stdlib.h>

void fatal_error() __attribute__((noreturn));

void fatal_error()
{
    printf("Fatal error! Exiting program.\n");
    exit(1);
}

int main()
{
    fatal_error(); //this will end the program
    printf("you are not supposed to see this get printed out");
    return 0;
}