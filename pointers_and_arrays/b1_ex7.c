#include <stdio.h>
#include <stdbool.h>

bool search(const int a[], int n, int key) {
    const int *p = NULL;
    for (p = a; p < a + n; p++) {
        if (*p == key) {
            return true;
        } 
    }
    return false;
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    printf("%d\n", search(a, 10, 12));

    return 0;
}