#include <stdio.h>
#include <stdlib.h>

void *my_malloc(const int bytes)
{
    void *malloc_ptr = NULL;
    if ((malloc_ptr = malloc(bytes)) == NULL) {
        printf("Error, malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    return (malloc_ptr);
}

int main() 
{
    int array_size = 10;
    int *array = my_malloc(array_size * sizeof(int));
    free(array);
    return (0);
}