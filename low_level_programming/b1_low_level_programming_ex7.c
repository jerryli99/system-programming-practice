/*
Write the following functions:

unsigned int rotate_left(unsigned int i, int n);
unsigned int rotate_right(unsigned int i, int n);

rotate_left should return the result of shifting the bits in i to the left by n
places, with the bits that were "shifted off" moved to the right end of i.

For example, the call rotate_left(0x1234678, 4) should return 
0x23456781 if integers are 32 bits long. rotate_right is similiar as well.
*/

#include <stdio.h>

unsigned int rotate_left(unsigned int number, int n_shifts);
unsigned int rotate_right(unsigned int number, int n_shifts);

int main(void)
{
    int shift = 4;
    unsigned int value = 0x12345678;

    unsigned int left_result = rotate_left(value, shift);
    unsigned int right_result = rotate_right(value, shift);

    printf("Original value: 0x%08x\n", value);
    printf("Rotate left by %d: 0x%08x\n", shift, left_result);
    printf("Rotate right by %d: 0x%08x\n", shift, right_result);

    return (0);
}

unsigned int rotate_left(unsigned int number, int n_shifts)
{
    return ((number << n_shifts) | (number >> (sizeof(unsigned int) * 8 - n_shifts)));
}

unsigned int rotate_right(unsigned int number, int n_shifts)
{
    return ((number >> n_shifts) | (number << (sizeof(unsigned int) * 8 - n_shifts)));
}

/*
result:
Original value: 0x12345678
Rotate left by 4: 0x23456781
Rotate right by 4: 0x81234567

*/