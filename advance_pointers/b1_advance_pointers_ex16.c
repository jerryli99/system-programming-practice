#include <stdio.h>
#include <stdlib.h>

int square(int value)
{
    return (value * value);
}

int sum(int (*func)(int), int start, int end)
{
    int sum = 0;
    for (int index = start; index <= end; index++)
    {
        sum = sum + func(index);
        //I can also do 
        //sum = sum + (*func)(index); still works
    }
    return (sum);
}


int main(void)
{
    //1^2 + 2^2 + 3^2 + 4^2 + 5^2 + 6^2 + 7^2 + 8^2 + 9^2 + 10^2 = 385
    printf("sum: %d\n", sum(square, 1, 10));
    return (0);
}