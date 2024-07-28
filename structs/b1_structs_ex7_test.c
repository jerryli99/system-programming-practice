#include <stdio.h>
#include <assert.h>
#include "b1_structs_ex7.h"

void test_get_gcd() {
    assert(get_gcd(48, 18) == 6);
    assert(get_gcd(101, 103) == 1);
    assert(get_gcd(0, 5) == 5);
    assert(get_gcd(5, 0) == 5);
    assert(get_gcd(0, 0) == 0);
}

void test_reduce_fraction() {
    Fraction frac1 = {8, 4};
    Fraction reduced1 = reduce_fraction(frac1);
    assert(reduced1.numerator == 2);
    assert(reduced1.denominator == 1);

    Fraction frac2 = {7, 14};
    Fraction reduced2 = reduce_fraction(frac2);
    assert(reduced2.numerator == 1);
    assert(reduced2.denominator == 2);

    Fraction frac3 = {0, 10};
    Fraction reduced3 = reduce_fraction(frac3);
    assert(reduced3.numerator == 0);
    assert(reduced3.denominator == 1);

    Fraction frac4 = {10, -20};
    Fraction reduced4 = reduce_fraction(frac4);
    assert(reduced4.numerator == -1);
    assert(reduced4.denominator == 2);
}

void test_add_fractions() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {1, 3};
    Fraction result = add_fractions(frac1, frac2);
    assert(result.numerator == 5);
    assert(result.denominator == 6);

    Fraction frac3 = {-1, 2};
    Fraction frac4 = {1, 3};
    Fraction result2 = add_fractions(frac3, frac4);
    assert(result2.numerator == -1);
    assert(result2.denominator == 6);
}

void test_subtract_fractions() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {1, 3};
    Fraction result = subtract_fractions(frac1, frac2);
    assert(result.numerator == 1);
    assert(result.denominator == 6);

    Fraction frac3 = {1, 2};
    Fraction frac4 = {-1, 3};
    Fraction result2 = subtract_fractions(frac3, frac4);
    assert(result2.numerator == 5);
    assert(result2.denominator == 6);
}

void test_multiply_fractions() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {2, 3};
    Fraction result = multiply_fractions(frac1, frac2);
    assert(result.numerator == 1);
    assert(result.denominator == 3);

    Fraction frac3 = {0, 1};
    Fraction result2 = multiply_fractions(frac1, frac3);
    assert(result2.numerator == 0);
    assert(result2.denominator == 1);
}

void test_divide_fractions() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {1, 3};
    Fraction result = divide_fractions(frac1, frac2);
    assert(result.numerator == 3);
    assert(result.denominator == 2);

    Fraction frac3 = {2, 3};
    Fraction frac4 = {1, 4};
    Fraction result2 = divide_fractions(frac3, frac4);
    assert(result2.numerator == 8);
    assert(result2.denominator == 3);
}

int main() {
    test_get_gcd();
    test_reduce_fraction();
    test_add_fractions();
    test_subtract_fractions();
    test_multiply_fractions();
    test_divide_fractions();

    printf("All tests passed successfully.\n");
    return 0;
}
