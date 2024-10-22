/*
Describe a simple way to "toggle" a bit (change it from 0 to 1 or from 1 to 0). 
Illustrate the technique by writing a statement that toggles bit 4 of the 
variable i.
*/

/*
Answer:

First, what is toggle the bit? Well, it means if we have 0, then change it to 1;
if we have 1, then chang eit to 0.

We can shift 1 to the left 4 bits, then xor the target bit. 

i ^= (1 << 4);

*/
#include <stdio.h>

int main(void) {

    unsigned char num = 5; // 0000 0101
    
    num ^= (1 << 4); // 0001 0101

    printf("%d\n", num);

    return (0);
}