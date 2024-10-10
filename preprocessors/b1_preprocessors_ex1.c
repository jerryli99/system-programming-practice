#include <stdio.h>

#define CUBE(number) ((number)*(number)*(number))

#define REMAINDER(number) ((number) % 4)

#define CONDITION(number1, number2) ((((number1)*(number2)) < (1000)) ? (1) : (0))

int main()
{
    printf("%f\n", CUBE(2.0));
    printf("%d\n", CUBE(2));
    printf("%d\n", CUBE(3));
    printf("%d\n", REMAINDER(8));
    printf("%d\n", REMAINDER(2));
    printf("%d\n", REMAINDER(1));
    printf("%d\n", CONDITION(100, 200));
    printf("%d\n", CONDITION(10, 1));
    return (0);
}