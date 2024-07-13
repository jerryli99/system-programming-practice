#include <stdio.h>

#define ROWS 4
#define COLS 5

int sum_two_dimensional_array(const int *a, int n) {
    int sum = 0;
    const int *p = NULL;

    for (p = a; p < a + n; p++) {
        sum += *p;
    }

    return sum;
}

int main() {
    const int a[ROWS][COLS] = { {1, 2, 3, 4, 5},
                                {6, 7, 8, 9, 10},
                                {11, 12, 13, 14, 15},
                                {16, 17, 18, 19, 20}};

    printf("%d\n", sum_two_dimensional_array(a[0], ROWS * COLS));

    return 0;
}