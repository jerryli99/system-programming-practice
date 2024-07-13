#include <stdio.h>

int sum_array(const int *array, int size) {
    int sum = 0;
    printf("Address of array at start of function: %p\n", (void*)array);
    for (int i = 0; i < size; i++) {
        sum += *(array++);
    }
    printf("Address of array at end of function: %p\n", (void*)array);
    return sum;
}


int sum_array2(const int *array, int size) {
    int sum = 0;
    const int *p = NULL;
    printf("Address of array at start of function: %p\n", (void*)array);
    for (p = array; p < array + size; p++) {
        sum += *p;
    }
    printf("Address of array at end of function: %p\n", (void*)array);
    return sum;
}


int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};

    int size = sizeof(a) / sizeof(a[0]);

    int *initial_address = a;

    printf("Initial address of array: %p\n", (void*)initial_address);
    //int sum = sum_array(a, size); // :( we are changing the starting addr of the array in the function
    int sum = sum_array2(a, size); //we are good, nothing except the tmp pointer in the function changed
    printf("Sum of array elements: %d\n", sum);
    printf("Address of array after function call: %p\n", (void*)a);

    return 0;
}