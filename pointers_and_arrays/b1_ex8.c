#include <stdio.h>

void store_zeros(int *a, int n) {
    int *p = a;

    while (p < a + n) {
        *p++ = 0;
    }
}

int main() {
    int a[] = {1,2,3,4,5,6,7,8,9,10};
    store_zeros(a, 10);

    for (int i = 0; i < 10; i++) {
        printf("%d ", *(a + i));
    }

    return 0;
}