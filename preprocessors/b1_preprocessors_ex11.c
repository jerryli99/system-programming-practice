#include <stdio.h>

#define ERROR(str, arg) (fprintf(stderr, (str), (arg)))

int main(void)
{
    int number = 100;
    ERROR("error msg: wrong result = %d\n", number);
    
    return (0);
}