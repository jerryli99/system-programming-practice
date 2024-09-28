//examples from the book
#include <stdio.h>

int main()
{
    // unsigned short i, j; //short is like 16 bits
    // i = 13;     // 0000 0000 0000 1101
    // j = i << 2; // 0000 0000 0011 0100 
    // j = i >> 2; // 0000 0000 0000 0011

    /*
    The bitwise shift operators have lower precedence than the arithmetic
    operators, which can cause surprises. For example, i << 2 + 1 means
    i << (2 + 1) and not (i << 2) + 1    
    */

    unsigned short i, j, k;
    i = 21;     //0000 0000 0001 0101 = 21
    j = 56;     //0000 0000 0011 1000 = 56
    k = ~i;     //1111 1111 1110 1010 = 65514
    k = i & j;  //0000 0000 0001 0000 = 16
    k = i ^ j;  //0000 0000 0001 0000 = 45
    k = i | j;  //0000 0000 0011 1101 = 61

    


    return (0);
}