/*
Write the following function:
unsigned int reverse_bits(unsigned int n);

reverse_bits should return an unsigned integer whose bits are the same as those
in n but in reverse order.
*/

#include <stdio.h>

#define BYTE_BITS 8

void print_uint_bits(unsigned int value)
{
    int total_bits = sizeof(value) * BYTE_BITS;  // Number of bits in an unsigned int

    for (int bit_idx = total_bits - 1; bit_idx >= 0; bit_idx--) {
        printf("%d", (value >> bit_idx) & 1);  // Print each bit by shifting and masking
    }
}

unsigned int reverse_bits(unsigned int value)
{
    unsigned int reversed = 0;
    int total_bits = sizeof(value) * BYTE_BITS;

    printf("Original bits: ");
    print_uint_bits(value);  // Print the original bits

    for (int bit_idx = 0; bit_idx < total_bits; bit_idx++)
    {
        unsigned int least_significant_bit = value & 1; //get the LSB 
        reversed <<= 1; //shift the reversed value left to make space for new bit
        reversed |= least_significant_bit; //add to reversed
        value >>= 1; //shift value to the right to process the next bit
    }

    printf("\nReversed bits: ");
    print_uint_bits(reversed);  // Print the reversed bits
    printf("\n");

    return reversed;
}


int main(void)
{
    unsigned int value = 0x12345678;
    unsigned int result = reverse_bits(value);

    printf("Original: 0x%08X\n", value);
    printf("Reversed: 0x%08X\n", result);

    return (0);
}

/*

Original bits: 00010010001101000101011001111000
Reversed bits: 00011110011010100010110001001000
Original: 0x12345678
Reversed: 0x1E6A2C48

*/