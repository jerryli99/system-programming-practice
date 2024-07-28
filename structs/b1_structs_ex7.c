#include "b1_structs_ex7.h"

/**
 * @brief Calculates the gcd of number1 and number2
 * 
 * @param num1 an integer
 * @param num2 an integer
 * 
 * @return Returns the gcd of num1 and num2 
 */
int get_gcd(int num1, int num2) {
    int temp;

    while (num1 != 0) {
        temp = num2 % num1;
        num2 = num1;
        num1 = temp;
    }

    return num2;
}

/**
 * @brief Reduce the fraction frac to lowest terms by first 
 *        compute the greatest common divisor (GCD) of the 
 *        numerator and denominator. The divide both the 
 *        numerator and denominator by the GCD.
 * 
 * @param frac a struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns the Fraction struct, with the updated fraction.
 */
Fraction reduce_fraction(Fraction frac) {
    int gcd = get_gcd(frac.numerator, frac.denominator);
    frac.numerator /= gcd;
    frac.denominator /= gcd;

    // Ensure the denominator is positive
    if (frac.denominator < 0) {
        frac.numerator = -frac.numerator;
        frac.denominator = -frac.denominator;
    }

    return frac;
}

/**
 * @brief Add the fractions frac1 and frac2.
 * 
 * @param frac1 a struct of typedef Fraction in b1_structs_ex7.h.
 * @param frac2 a struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns a new struct, with the result stored in the new struct.
 */
Fraction add_fractions(Fraction frac1, Fraction frac2) {
    frac1.numerator = frac1.numerator * frac2.denominator;
    frac2.numerator = frac2.numerator * frac1.denominator;

    Fraction result;
    result.numerator = frac1.numerator + frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;

    result = reduce_fraction(result);

    return result;
}

/**
 * @brief Subtract the fractions frac1 and frac2.
 * 
 * @param frac1 a struct of typedef Fraction in b1_structs_ex7.h.
 * @param frac2 a struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns a new struct, with the result stored in the new struct.
 */
Fraction subtract_fractions(Fraction frac1, Fraction frac2) {
    frac1.numerator = frac1.numerator * frac2.denominator;
    frac2.numerator = frac2.numerator * frac1.denominator;

    Fraction result;
    result.numerator = frac1.numerator - frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;

    result = reduce_fraction(result);

    return result;
}

/**
 * @brief Multiply the fractions frac1 and frac2.
 * 
 * @param frac1 a struct of typedef Fraction in b1_structs_ex7.h.
 * @param frac2 a struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns a new struct, with the result stored in the new struct.
 */
Fraction multiply_fractions(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;

    result = reduce_fraction(result);

    return result;
}

/**
 * @brief Divide the fractions frac1 and frac2.
 * 
 * @param frac1 a struct of typedef Fraction in b1_structs_ex7.h.
 * @param frac2 a struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns a new struct, with the result stored in the new struct.
 */
Fraction divide_fractions(Fraction frac1, Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator;
    result.denominator = frac1.denominator * frac2.numerator;

    result = reduce_fraction(result);

    return result;
}