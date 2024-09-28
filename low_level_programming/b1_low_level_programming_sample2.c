#include <stdio.h>

int main()
{

    /*
    Using the bitwise operators to access bits.
    In graphics programming, for example, we may want to squeeze two or more
    pixels into a single byte. Using the bitwise operator, we can extract or
    modify data that's stored in a small number of bits.
    */

    //setting a bit
    /*
    say we want to set bit 4 of i. The easiest way to set bit 4 is to "or" the
    value of i with the constant 0x0010 (a "mask" that contains a 1 bit in
    position 4)
    */
    unsigned short i, j = 3;
    i = 0x0000;  //0000 0000 0000 0000
    i |= 0x0010; //0000 0000 0001 0000


    /*
    More generally, if the position of the bit is stored in the variable j,
    we can use a shift operator to create the mask.
    */
   i |= 1 << j; 

    /*
    Clearing a bit. To clear bit 4 of i, we would use a mask with a 0 bit in 
    position 4 and 1 bit everywhere else:
    */
   i = 0x00ff;   //0000 0000 1111 1111
   i &= ~0x0010; //0000 0000 1110 1111

   /*
   Using the same idea, we can easily write a statement that clears a bit whose
   position is stored in a variable:
   */
    i &= ~(1 << j);

    /*
    Testing a bit. The following if statement tests whether bit 4 of i is set:
    if (i & 0x0010) ... //tests bit 4

    To test whether bit j is set, we would use the following statement:
    if (i & (1 << j)) ... //tests bit j
    */

   /*
   To make working with bits easier, we will often give them names. For example,
   suppose that we want bits 0,1,2 of a number to correspond to the color blue,
   green, and red, respectively. First, we define names that represent the 
   three bit positions:
   #define BLUE 1
   #define GREEN 2
   #define RED   4

   Setting, clearing, and testing the BLUE bit would be done as follows:
   i |= BLUE; //sets BLUE bit
   i &= ~BLUE //clears BLUE bit
   if (i & BLUE) //tests BLUE bit

   i |= BLUE | GREEN; //sets BLUE and GREEN bits
   i &= ~(BLUE | GREEN); //clears BLUE and GREEN bits
   if (i & (BLUE | GREEN))... //tests BLUE and GREEN bits
   */
   //==========================================================================
    /*
    Using the bitwise operators to access bit-fields
    Dealing with a group of several consecutive bits.
    */


   /*
   Modifying a bit-field. It requires a bitwise and (to clear the bit-field),
   followed by a bitwise or (to store new bits in the bit-field).
   */
  i = i & ~0x0070 | 0x0050;

  /*
  So the & operator clears bits 4-6 of i; the | operator then sets bits 6 and 4.
  Notice that i |= 0x0050 by itself wouldn't always work: it would set bits
  6 and 4 but not change bit 5. 

  To generalize the example a little, let us assume that the variable j contains
  the value to be stored in bits 4-6 of i. Then we will need to shift j into 
  position before performing the bitwise or:

  i = (i & ~0x0070) | (j << 4);
  */

  /*
  Retrieving a bit-field.
  When the bit-field is at the right end of a number (in the least significant
  bits), fetching its value is easy. For example, the following statement 
  retrieves bits 0-2 in the variable i:
  j = i & 0x0007

  If the bit-field is not at the right end of i, then we can first shift the 
  bit-field to the end before extracting the field using the & operator. To 
  extract bits 4-6 of i, for example, we could use the following statement:
  j = (i >> 4) & 0x0007;
  */
    return (0);
}