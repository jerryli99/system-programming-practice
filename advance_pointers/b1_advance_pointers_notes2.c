
//Experiment what if this happened...

#include <stdio.h>
#include <stdlib.h>

int main() {

    int *array = NULL;

    int array_size = 10;

    array = malloc(array_size * sizeof(int)); 

    for (int index = 0; index < array_size; index++) {
        *(array + index) = 0; 
    }

    for (int index = 0; index < array_size; index++) {
        printf("%d\n", *(array + index)); 
    }

    // printf("sizeof(int): %ld\n", sizeof(int));

    // array = malloc(array_size * 2);

    // for (int index = 0; index < array_size; index++) {
    //     *(array + index) = 16777215; 
    // }

    // printf("%d\n", *(array+8));

    // printf("\n");

    free(array);
    array = NULL;
    
    return (0);
}