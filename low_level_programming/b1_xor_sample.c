/*
The following program encrypts  message by XORing each character with the & 
character. The original message can be entered by the user or read from a file
using input redirection; the encrypted message can be viewed on the screen or
saved in a file using output redirection. 

For example:
Trust not him with your secrets, who, when left along in your room, turns over
your papers. --Johann Kaspar Lavater (1741-1801)

To encrypt the msg file:
xor <msg >newmsg

To recover the original messageL
xor <newmsg
*/

#include <stdio.h>
#include <ctype.h>

#define KEY '&'

int main(void)
{
    int orig_char, new_char;

    while ((orig_char = getchar()) != EOF)
    {
        new_char = orig_char ^ KEY;
        if (isprint(orig_char) && isprint(new_char))
        {
            putchar(new_char);
        }
        else
        {
            putchar(orig_char);
        }
    }
    
    return (0);
}