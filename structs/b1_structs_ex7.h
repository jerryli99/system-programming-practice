#ifndef B1_STRUCTS_EX7_H
#define B1_STRUCTS_EX7_H

typedef struct fraction Fraction;

struct fraction {
    int numerator;
    int denominator;
};

int get_gcd(int num1, int num2);

Fraction reduce_fraction(Fraction frac);
Fraction add_fractions(Fraction frac1, Fraction frac2);
Fraction subtract_fractions(Fraction frac1, Fraction frac2);
Fraction multiply_fractions(Fraction frac1, Fraction frac2);
Fraction divide_fractions(Fraction frac1, Fraction frac2);


#endif