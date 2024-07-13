#include <stdio.h>

double inner_product(const double *a, const double *b, int n) {
    const double *p = NULL, *q = NULL;
    double result = 0.0;
    for (p = a, q = b; p < a + n, q < b + n; p++, q++) {
        result += (*p) * (*q);
    }
    return result;
}

int main() {
    printf("%f\n", inner_product((double[]){1,2,3},  (double[]){1,1,1}, 3));
    return 0;
}