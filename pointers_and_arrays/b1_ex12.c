#include <stdio.h>

void find_two_largest(const int *a, int n, int *largest, int *second_largest) {
    const int *p, *p_largest, *p_second_largest;
    for (p = p_largest = p_second_largest = a; p < a + n; p++) {
        if (*p > *p_largest) {
            p_second_largest = p_largest;
            p_largest = p;
        } else if (*p > *p_second_largest) {
            p_second_largest = p;
        } else {
            //nothing happens, move on next iteration...
        }
    }
    
    *largest = *p_largest;
    *second_largest = *p_second_largest;
}

int main() {
    int a[] = {1,2,3,4,10,0,11,100,99,124};
    int size = sizeof(a) / sizeof(a[0]);
    int largest = 0;
    int second_largest = 0;

    find_two_largest(a, size, &largest, &second_largest);
    printf("%d, %d\n", largest, second_largest);


    return 0;
}