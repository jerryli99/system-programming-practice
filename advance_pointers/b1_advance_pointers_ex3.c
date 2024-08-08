#include <stdio.h>
#include <stdlib.h>

int *create_array(int n, int initial_value)
{
    int *array_ptr = NULL;
    int *array_tmp_ptr = NULL;

    if ((array_ptr = malloc(n * sizeof(int))) == NULL) {
        printf("Failed to create array\n");
        return (NULL);
    }

    for (array_tmp_ptr = array_ptr; 
         array_tmp_ptr < array_ptr + n; 
         array_tmp_ptr++)
    {
        *array_tmp_ptr = initial_value;
    }
    return (array_ptr);
}


int main(void)
{
    int array_size = 10;
    int init_value = 90;
    int *array = create_array(array_size, init_value);
    int *array_ptr = array;

    while (array_ptr < array + array_size)
    {
        printf("%d ", *array_ptr++);
    }

    free(array);

    array = NULL;
    
    printf("\n");
}