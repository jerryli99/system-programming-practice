#include <stdio.h>

void find_two_largest(int a[], int n, int *largest, int *second_largest);

int main(void) {
    int largest = 0;
    int second_largest = 0;    
    int a[10] = {-100, -99, 10, 3, -2, 3, 89, 1000, 11, 0};

    find_two_largest(a, sizeof(a) / sizeof(a[0]), &largest, &second_largest);
    printf("Largest: %d, Second Largest: %d\n", largest, second_largest);
    return 0;
}

void find_two_largest(int a[], int n, int *largest, int *second_largest) {

    for (int i = 0; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        } else if (a[i] > *second_largest) {
            *second_largest = a[i];
        } else {
            //do nothing... continue the iteration
        }
    }
}