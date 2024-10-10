#include <stdio.h>

#define NELEMS(array) ((unsigned int) (sizeof(array)) / (sizeof(array[0])))

int main() 
{
    int array1[10] = {0};
    char array2[23423];

    printf("%zu\n", NELEMS(array1));
    printf("%zu\n", NELEMS(array2));

    return (0);
}