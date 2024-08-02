#include "b1_structs_ex7.h"

/**
 * @brief Calculates the gcd of number1 and number2
 * 
 * @param num1 a constant integer
 * @param num2 a constant integer
 * 
 * @return Returns the gcd of num1 and num2 
 */
int get_gcd(const int num1, const int num2) {
    int tmp_num1 = num1;
    int tmp_num2 = num2;
    int temp;

    while (tmp_num1 != 0) {
        temp = tmp_num2 % tmp_num1;
        tmp_num2 = tmp_num1;
        tmp_num1 = temp;
    }

    return tmp_num2;
}

/**
 * @brief Reduces the fraction frac to lowest terms by first 
 *        computing the greatest common divisor (GCD) of the 
 *        numerator and denominator. Then divides both the 
 *        numerator and denominator by the GCD.
 * 
 * @param frac a constant struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns the Fraction struct with the updated fraction.
 */
Fraction reduce_fraction(const Fraction frac) {
    Fraction result = frac;
    int result_gcd = get_gcd(result.numerator, result.denominator);
    result.numerator = result.numerator / result_gcd;
    result.denominator = result.denominator / result_gcd;

    // Ensure the denominator is positive
    if (result.denominator < 0) {
        result.numerator = (-result.numerator);
        result.denominator = (-result.denominator);
    }

    return result;
}

/**
 * @brief Adds the fractions frac1 and frac2.
 * 
 * @param frac1 a constant struct of typedef Fraction in b1_structs_ex7.h.
 * @param frac2 a constant struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns a new struct with the result stored in the new struct.
 */
Fraction add_fractions(const Fraction frac1, const Fraction frac2) {
    Fraction result;
    result.numerator = (frac1.numerator * frac2.denominator) + (frac2.numerator * frac1.denominator);
    result.denominator = frac1.denominator * frac2.denominator;

    return reduce_fraction(result);
}

/**
 * @brief Subtracts the fractions frac1 and frac2.
 * 
 * @param frac1 a constant struct of typedef Fraction in b1_structs_ex7.h.
 * @param frac2 a constant struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns a new struct with the result stored in the new struct.
 */
Fraction subtract_fractions(const Fraction frac1, const Fraction frac2) {
    Fraction result;
    result.numerator = (frac1.numerator * frac2.denominator) - (frac2.numerator * frac1.denominator);
    result.denominator = frac1.denominator * frac2.denominator;

    return reduce_fraction(result);
}

/**
 * @brief Multiplies the fractions frac1 and frac2.
 * 
 * @param frac1 a constant struct of typedef Fraction in b1_structs_ex7.h.
 * @param frac2 a constant struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns a new struct with the result stored in the new struct.
 */
Fraction multiply_fractions(const Fraction frac1, const Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.numerator;
    result.denominator = frac1.denominator * frac2.denominator;

    return reduce_fraction(result);
}

/**
 * @brief Divides the fractions frac1 and frac2.
 * 
 * @param frac1 a constant struct of typedef Fraction in b1_structs_ex7.h.
 * @param frac2 a constant struct of typedef Fraction in b1_structs_ex7.h.
 * 
 * @return Returns a new struct with the result stored in the new struct.
 */
Fraction divide_fractions(const Fraction frac1, const Fraction frac2) {
    Fraction result;
    result.numerator = frac1.numerator * frac2.denominator;
    result.denominator = frac1.denominator * frac2.numerator;

    return reduce_fraction(result);
}
