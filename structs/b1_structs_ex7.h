#ifndef B1_STRUCTS_EX7_H
#define B1_STRUCTS_EX7_H

typedef struct fraction_ {
    int numerator;
    int denominator;
} Fraction;

int get_gcd(const int num1, const int num2);

Fraction reduce_fraction(const Fraction frac);
Fraction add_fractions(const Fraction frac1, const Fraction frac2);
Fraction subtract_fractions(const Fraction frac1, const Fraction frac2);
Fraction multiply_fractions(const Fraction frac1, const Fraction frac2);
Fraction divide_fractions(const Fraction frac1, const Fraction frac2);

#endif
