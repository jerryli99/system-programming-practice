/*
Let f be the following function:

unsigned int f (unsigned int i, int m, int n)
{
    return (i >> (m + 1 - n)) & ~(~0 << n);
}

(a) what is the value of ~(~0 << n)?
Answer:
~0 means 11111111 11111111 11111111 11111111
~0 << n means shift to the left n bits, for example n = 4
11111111 11111111 11111111 11110000

~(~0 << n) means flip everything again, so
00000000 00000000 00000000 00001111
A binary number with the least significant n bits set to 1 <=> 2^n - 1

(b) what does this function do?

  Still thinking about it.....

*/

#include <stdio.h>

unsigned int func (unsigned int i_val, int m_val, int n_val)
{
    return (i_val >> (m_val + 1 - n_val)) & ~(~0 << n_val);
}

int main(void)
{

    return (0);
}