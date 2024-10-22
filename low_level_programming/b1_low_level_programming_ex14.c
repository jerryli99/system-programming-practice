/*
When stored according to the IEEE floating-point standard, a float value consists
of a 1-bit sign (the leftmost--or most significant--bit), an 8-bit exponent, and
a 23-bit fraction, in that order. Design a structure type that occupies 32 bits,
with bit-field members corresponding to the sign, exponent, and fraction. 
Declare the bit-fields to have type unsigned int. Check the manual for your 
compiler to determine the order of the bit fields.

*/

#include <stdio.h>

typedef union 
{
    float value;
    struct 
    {
        unsigned int fraction : 23; //(mantissa)
        unsigned int exponent : 8;
        unsigned int sign     : 1;
    } ieee754;
} Float_Union;


int main(void)
{

    Float_Union f_union;
    f_union.value = -13.55f;

    printf("%f\n", f_union.value);
    printf("Sign: %u\n", f_union.ieee754.sign);
    printf("Exponent: %u\n", f_union.ieee754.exponent);
    printf("Fraction: %u\n", f_union.ieee754.fraction);

    return (0);
}

/*

-13.550000
Sign: 1
Exponent: 130
Fraction: 5819597

*/