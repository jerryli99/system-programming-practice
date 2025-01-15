//unused
//this attribute suppresses warnings about unused parameters

#include <stdio.h>

void foo(int x, int y __attribute__((unused)))
{
    printf("x: %d\n", x);
}

void bar(int x, int y)
{
    printf("x: %d\n", x);
}

int main()
{
    foo(50, 100);
    bar(10, 110);
    return 0;
}