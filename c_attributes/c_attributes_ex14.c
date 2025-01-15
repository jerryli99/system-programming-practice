//may_alias

//The may_alias attribute tells the compiler that ptr may alias another pointer, 
//allowing for better optimization.
#include <stdio.h>

int *ptr __attribute__((may_alias));

int main()
{
    int x = 42;
    ptr = &x;
    printf("Value of x: %d\n", *ptr);
    return 0;
}