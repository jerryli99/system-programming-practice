#include <stdio.h>

int main(void) {
    int a[] = {5, 15, 34, 54, 14, 2, 52,72};
    int *p = &a[1], *q = &a[5];
    printf("%d", *p<*q);


    return 0;
}