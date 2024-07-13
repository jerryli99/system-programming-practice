#include <stdio.h>

#define N 5


int main() {
    double ident[N][N];
    double *p = NULL;
    int row, col;
    int count_zeros = N;

    for (p = &ident[0][0]; p <= &ident[N - 1][N - 1]; p++) {
        if (count_zeros == N) {
            *p = 1;
            count_zeros = 0;
        } else {
            *p = 0;
            count_zeros++;
        }
        printf("count zeros: %d\n", count_zeros);
    }

    for (row = 0; row < N; row++) {
        for (col = 0; col < N; col++) {
            printf("%f ", ident[row][col]);
        }
        printf("\n");
    }

    return 0;
}