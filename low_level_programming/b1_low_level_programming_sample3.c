/*
Bit-field in Structures:
The bit-field techniques in sample2.c is quite confusing. There is a clearer
way: declaring structures whose members represent bit-fields.

*/

/*
Other low level techniques:
1. defining types that represent units of storage, 

2. using unions to bypass normal
type-checking

3. using pointers as addresses. 

4. the volatile type qualifier?

*/

/*
1. Defining the char type--by definition--occupies one byte, we'll 
sometimes treat characters as bytes, using them to store data that is not 
necessarily in character form. When we do so, it is a good idea to define 
a BYTE type:

typedef unsigned char BYTE;

typedef unsigned short WORD;


2. Using unions to provide multiple views of data:
Uninos are often used in C for an entirely different purpose: viewing a block of
memory in two or more different ways.

Say the file_date structure.
You can fit 2 bytes in the structure. In particular, we could view an unsigned
short value as a file_date structure (assuming that short integers are 16 bits
long.) The following union allows us to easily convert a short integer to a 
file date or vice versa.
union int_date {
    unsigned short i;
    struct file_date fd;
};

With the help of this union, we could fetch a file data from disk as two bytes,
then extractits month, day, and year fields. Conversely, we could construct a
date as a file_date structure, then write it to disk as a pair of bytes.
*/

#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;

struct file_date //fits 16 bits (2 bytes)
{
    unsigned int day: 5;
    unsigned int month: 4;
    unsigned int year: 7;
};

union int_date 
{
    unsigned short i;
    struct file_date fd;
};

void print_date(unsigned short n)
{
    union int_date date;
    date.i = n;
    printf("%d/%d/%d\n", date.fd.month, date.fd.day, date.fd.year + 1980);
}

int main()
{
    struct file_date fd;
    fd.day = 28;
    fd.month = 12;
    fd.year = 8;

    print_date(1220);

    //registers experiment union 
    union {
        struct {
            WORD ax, bx, cx, dx;
        } word;

        struct {
            BYTE al, ah, bl, bh, cl, ch, dl, dh;
        } byte;
    } regs;

    regs.byte.ah = 0x12;
    regs.byte.al = 0x34;
    printf("AX: %02x\n", regs.word.ax);
    /*
    Note:
    the low byte al is placed before high byte ah. Why? The reason is that when 
    data item consists of more than one byte, there are two logical ways to store
    it in memory: with the bytes in the "natural" order (big endian) or with 
    the bytes in reverse order (little endian).

    C does not require a specific byte ordering, since that depends on the CPU
    on which a program will be executed. Some CPUs use the big-endian approach
    and some use the little endian approach. What does this have to do with the
    byte structure? 

    It turns out that x86 processors assume that data is stored in little endian
    order, so the first byte of regs.word.ax is the low byte.
    */

   /*
   Another interesting thing about pointers is that we can use it as addresses.
   */
    BYTE *ptr;
    ptr = (BYTE *)0x1000; // ptr contains address 0x1000
    
    return (0);
}

/*
Using unions to allow multiple views of data is especially useful when working 
with registers, which are often divided into smaller units.

x86 processors, for example, have 16-bit registers named AX, BX, CX, and DX.

Each of these registers can be treated as two 8-bit registers.

Ax, for example, is divided into registers named AH and AL. (H is high, L is low)

When writing low level applications for x86-based computers, we may need
variables that represent the contents of the AX< BX, CX, and DX registers. We 
want access to both the 16- and 8-bit registers; at the same time, we need to
take their relationships into account (a change to AX affects both AH and AL);
changing h or AL modifies AX. 

The solution is to set up two structures, one containing members that correspond
to the 16-bit registers, and the other containing members that match the 8-bit
registers. We then create a union that encloses the two structures:

union {
    struct {
        WORD ax, bx, cx, dx;
    } word;

    struct {
        BYTE al, ah, bl, bh, cl, ch, dl, dh;
    } byte;
} regs;

Since it is a union, ax will occupy the same memory as al and ah.
bx will occupy the same memory as bl and bh, etc...
For example
regs.byte.ah = 0x12;
regs.byte.al = 0x34;

AX: 1234

*/