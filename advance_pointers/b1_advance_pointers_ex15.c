//Copied from the textbook
//Show the output of the following program and explain what it does.

#include <stdio.h>

int f1(int (*f)(int));
int f2(int i);

int main(void)
{
    printf("Answer: %d\n", f1(f2));
    return (0);
}

int f1(int (*f)(int))
{
    int n = 0;

    while ((*f)(n)) n++;
    return (n);
}

int f2(int i)
{
    return (i * i + i - 12);
}

/*
Explain:

n = 0
f2(n): 0 * 0 + 0 - 12 = -12

n = 1
f2(n): 1 * 1 + 1 - 12 = -10

n = 2
f2(n): 2 * 2 + 2 - 12 = -6

n = 3
f2(n): 3 * 3 + 3 - 12 = 0

return 3 as result

*/