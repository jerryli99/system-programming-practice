#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator,
            int *reduced_denominator);

int main(void) {
    int num, denom, reduced_numerator = 0, reduced_denominator = 0;

    printf("Enter a fraction: ");
    scanf("%d /%d", &num, &denom);

    reduce(num, denom, &reduced_numerator, &reduced_denominator); 

    printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);

    return 0;
}

void reduce(int numerator, int denominator, int *reduced_numerator, 
            int *reduced_denominator) {

    int tmp, p = numerator, q = denominator;

    while (q != 0) {
       tmp = p % q;
       p = q;
       q = tmp;
    }

    *reduced_numerator = numerator / p;
    *reduced_denominator = denominator / p;
}