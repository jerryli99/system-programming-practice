/*
(a) Write the following function:
int count_ones(unsigned char ch);
count_ones should return the number of 1 bits in ch.

(b) Write the function in part(a) without using a loop.

*/

#include <stdio.h>

#define UCHAR_BITS 8

int count_ones(unsigned char character);
int count_ones_v2(unsigned char character);


int main(void)
{
    unsigned char character = 213; //11010101
    
    int ones = count_ones_v2(character);
    printf("Number of 1 bits: %d\n", ones);

    int ones_v2 = count_ones_v2(character);
    printf("Number of 1 bits: %d\n", ones_v2);

    return (0);
}

int count_ones(unsigned char character)
{
    int count = 0;
    for (int bit_idx = 0; bit_idx < UCHAR_BITS; bit_idx++) {
        if ((character & (1 << bit_idx)) != 0) {
            count++;
        }
    }
    return count;
}

int count_ones_v2(unsigned char character)
{
    if (character == 0)
    {
        return 0;
    }
    return count_ones_v2(character & (character - 1)) + 1;
}