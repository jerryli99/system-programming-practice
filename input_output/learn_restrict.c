/*
I feel kind of lost when learning about the restrict keyword,
so I am here experimenting some.
*/

#include <stdio.h>

void modify1(int *a, int *b)
{
    *a = 10;
    *b = 20;
}

void modify2(int *restrict a, int *restrict b)
{
    *a = 10;
    *b = 20;
}

int main()
{
    int x = 5;
    int *ptr1 = &x;
    int *ptr2 = &x;

    int y = 5;
    int *ptr3 = &y;
    int *ptr4 = &y;

    modify1(ptr1, ptr2);

    printf("%d, %d, %d\n", *ptr1, *ptr2, x);

    modify2(ptr3, ptr4);

    printf("%d, %d, %d\n", *ptr3, *ptr4, y);

    return (0);
}