#include <stdio.h>

void swap(int *p, int *q);

int main() {
    int a = 100, b = 42;
    printf("a: %d,  b: %d\n", a, b);
    swap(&a, &b);
    printf("a: %d,  b: %d\n", a, b);

    return 0;
}

void swap(int *p, int *q) {
    int tmp = 0;
    tmp = *p;
    *p = *q;
    *q = tmp;
}