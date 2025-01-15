//likely and unlikely

//This example uses likely and unlikely to provide branch prediction hints to the compiler.
#include <stdio.h>

int main()
{
    int x = 5;
    if (__builtin_expect(x == 0, 0)) 
    {
        printf("This branch is unlikely\n");
    }
    else 
    {
        printf("This branch is likely\n");
    }
    return 0;
}
/*
__builtin_expect tells the compiler that the condition is unlikely to be true 
(since x == 0 is unlikely).
Purpose
Indicates that an expression is likely to evaluate to a specified value. 
The compiler may use this knowledge to direct optimizations.
*/