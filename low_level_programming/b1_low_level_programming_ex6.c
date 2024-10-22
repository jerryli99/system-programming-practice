/*
Use the bitwise operators to write the following functions:
unsigned short swap_bytes(unsigned short i);

swap_bytes should return the number that results from swapping the two bytes in
i. (Short integers occpy two bytes on most computers.) For example, if i has the
value 0x1234 (00010010 00110100 in binary), then swap bytes should return 0x3412
(00110100 00010010 in binary). Test your function by writing a program that reads
a number in hexadecimal, then writes the number with its bytes swapped.

Enter a hexadecimal number (up to 4 digits): 1234
Number with bytes swapped: 3412

Hint: Use the %hx conversion to read and write the hex numbers.


*/

#include <stdio.h>

unsigned short swap_bytes(unsigned short num);


int main(void) {
    unsigned short number;
    printf("Enter a hexadecimal number (up to 4 digits): ");
    scanf("%hx", &number);

    unsigned short swapped;
    swapped = swap_bytes(number);
    printf("Number with bytes swapped: %04hx\n", swapped);

    return (0);
}

unsigned short swap_bytes(unsigned short number)
{
    return ((number >> 8) | (number << 8));
}

/*
result:
Enter a hexadecimal number (up to 4 digits): 5678
Number with bytes swapped: 7856
*/