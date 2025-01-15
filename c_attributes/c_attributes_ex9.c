//pure and const

#include <stdio.h>

int square(int x) __attribute__((pure)); //pure function
int add(int x, int y) __attribute__((const)); //const function

int square(int x)
{
    return (x * x);
}

int add(int x, int y)
{
    return (x + y);
}

int main()
{
    printf("Square of 5: %d\n", square(5));
    printf("Add 2 + 3: %d\n", add(2,3));
    return 0;
}

/*


Both square and add are treated as functions with no side effects. The compiler 
may optimize these functions better based on the attributes.

TODO: learn about side effects. I am not too familiar with the concept. 
Haven't put in the time to learn about it.
*/

