#include <stdio.h>
#include <stdbool.h>
#include "b1_structs_ex7.h"

//A note: not sure if this is good style??
//I am doing this simply because I want to see if I can print out the error location,
//and to allow the test to continue non-blocking even if a test failed in the middle.

// Macro to simplify usage of custom_assert
#define CUSTOM_ASSERT(condition, message) custom_assert(condition, message, __FILE__, __LINE__)

// Global variable to count test failures
int test_failures = 0;

// Custom assertion function
void custom_assert(bool condition, const char *message, const char *file, int line) {
    if (condition == false) {
        printf("Test failed at %s:%d: %s\n", file, line, message);
        test_failures++;
    }
}

void test_get_gcd() {
    CUSTOM_ASSERT(get_gcd(48, 18) == 6, "GCD of 48 and 18 should be 6");
    CUSTOM_ASSERT(get_gcd(101, 103) == 1, "GCD of 101 and 103 should be 1");
    CUSTOM_ASSERT(get_gcd(0, 5) == 5, "GCD of 0 and 5 should be 5");
    CUSTOM_ASSERT(get_gcd(5, 0) == 5, "GCD of 5 and 0 should be 5");
    CUSTOM_ASSERT(get_gcd(0, 0) == 0, "GCD of 0 and 0 should be 0");
}

void test_reduce_fraction() {
    Fraction frac1 = {8, 4};
    Fraction reduced1 = reduce_fraction(frac1);
    CUSTOM_ASSERT(reduced1.numerator == 2 && reduced1.denominator == 1, "8/4 should reduce to 2/1");

    Fraction frac2 = {7, 14};
    Fraction reduced2 = reduce_fraction(frac2);
    CUSTOM_ASSERT(reduced2.numerator == 1 && reduced2.denominator == 2, "7/14 should reduce to 1/2");

    Fraction frac3 = {0, 10};
    Fraction reduced3 = reduce_fraction(frac3);
    CUSTOM_ASSERT(reduced3.numerator == 0 && reduced3.denominator == 1, "0/10 should reduce to 0/1");

    Fraction frac4 = {10, -20};
    Fraction reduced4 = reduce_fraction(frac4);
    CUSTOM_ASSERT(reduced4.numerator == -1 && reduced4.denominator == 2, "10/-20 should reduce to -1/2");
}

void test_add_fractions() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {1, 3};
    Fraction result = add_fractions(frac1, frac2);
    CUSTOM_ASSERT(result.numerator == 5 && result.denominator == 6, "(1/2) + (1/3) should equal 5/6");

    Fraction frac3 = {-1, 2};
    Fraction frac4 = {1, 3};
    Fraction result2 = add_fractions(frac3, frac4);
    CUSTOM_ASSERT(result2.numerator == -1 && result2.denominator == 6, "(-1/2) + (1/3) should equal -1/6");
}

void test_subtract_fractions() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {1, 3};
    Fraction result = subtract_fractions(frac1, frac2);
    CUSTOM_ASSERT(result.numerator == 1 && result.denominator == 6, "(1/2) - (1/3) should equal 1/6");

    Fraction frac3 = {1, 2};
    Fraction frac4 = {-1, 3};
    Fraction result2 = subtract_fractions(frac3, frac4);
    CUSTOM_ASSERT(result2.numerator == 5 && result2.denominator == 6, "(1/2) - (-1/3) should equal 5/6");
}

void test_multiply_fractions() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {2, 3};
    Fraction result = multiply_fractions(frac1, frac2);
    CUSTOM_ASSERT(result.numerator == 1 && result.denominator == 3, "(1/2) * (2/3) should equal 1/3");

    Fraction frac3 = {0, 1};
    Fraction result2 = multiply_fractions(frac1, frac3);
    CUSTOM_ASSERT(result2.numerator == 0 && result2.denominator == 1, "(1/2) * (0/1) should equal 0/1");
}

void test_divide_fractions() {
    Fraction frac1 = {1, 2};
    Fraction frac2 = {1, 3};
    Fraction result = divide_fractions(frac1, frac2);
    CUSTOM_ASSERT(result.numerator == 3 && result.denominator == 2, "(1/2) / (1/3) should equal 3/2");

    Fraction frac3 = {2, 3};
    Fraction frac4 = {1, 4};
    Fraction result2 = divide_fractions(frac3, frac4);
    CUSTOM_ASSERT(result2.numerator == 8 && result2.denominator == 3, "(2/3) / (1/4) should equal 8/3");
}

int main() {
    test_get_gcd();
    test_reduce_fraction();
    test_add_fractions();
    test_subtract_fractions();
    test_multiply_fractions();
    test_divide_fractions();

    if (test_failures == 0) {
        printf("All tests passed successfully.\n");
    } else {
        printf("Some tests failed. Number of failed tests: %d\n", test_failures);
    }

    return 0;
}

/*
example output if there is an error:
Test failed at b1_structs_ex7_test.c:41: 0/10 should reduce to 0/1
Test failed at b1_structs_ex7_test.c:45: 10/-20 should reduce to -1/2
Some tests failed. Number of failed tests: 2

*/