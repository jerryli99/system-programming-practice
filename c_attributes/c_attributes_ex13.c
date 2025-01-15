//malloc

//Oh..this is interesting
//this attribute tells the compiler that a function behaves like malloc 
//and does not return a NULL pointer


#include <stdio.h>
#include <stdlib.h>

void *my_malloc(size_t size) __attribute__((malloc));

void *my_malloc(size_t size)
{
    return malloc(size);
}

int main()
{
    int *arr = my_malloc(10 * sizeof(int));
    if (arr != NULL)
    {
        printf("Memory allocated\n");
        free(arr);
        printf("Memory freed\n");
    }
    return 0;
}