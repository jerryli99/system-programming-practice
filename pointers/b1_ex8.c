#include <stdio.h>

int *find_largest(int a[], int n);

int main() {
    int a[] = {1,2,3,4,56,7,8,9,10,123,0,0,-1,123,444,991,1,4,5};

    printf("largest element: %d\n", *find_largest(a, (sizeof(a) / sizeof(a[0]))));
    return 0;
}



int *find_largest(int a[], int n)
{
    int i, largest_index = 0;

    for (i = 0; i < n; i++) {
        if (a[i] > a[largest_index])
            largest_index = i;
    }

    return &a[largest_index];
}