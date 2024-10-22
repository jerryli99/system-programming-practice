/*
Starting with the 386 processor, x86 CPUs have 32 bit registers named EAX, EBX,
ECX, and EDX. The second half (the least significant bits) of these registers is
the same as AX, BX, CX, and DX. Modify the regs union so that it includes 
these registers as well as the older ones. Your union should be set up so that 
modifying EAX changes AX and modifying AX changes the second half of EAX. 
(The other new registers will work in a similiar fashion.) You'll need to add 
some "dummy" members to the word and byte structures, corresponding to the other 
half of EAX, EBX, ECX, and EDX. Declare the type of the new registers to be 
DWORD (double word), which should be defined as unsigned long. Don't forget that
the x86 architecture is little-endian.
*/

#include <stdio.h>

typedef unsigned char BYTE;
typedef unsigned short WORD;
typedef unsigned int DWORD;

typedef union 
{
    struct 
    {
        DWORD eax;
        DWORD ebx;
        DWORD ecx;
        DWORD edx;
    } dword;

    struct 
    {
        WORD axl, axh;
        WORD bxl, bxh;
        WORD cxl, cxh;
        WORD dxl, dxh;
    } word;

    struct 
    {
        BYTE axll, axlh, axhl, axhh;
        BYTE bxll, bxlh, bxhl, bxhh;
        BYTE cxll, cxlh, cxhl, cxhh;
        BYTE dxll, dxlh, dxhl, dxhh;
    } byte;

} REGISTERS;


int main(void)
{
    REGISTERS regs;

    regs.dword.eax = 0x12345678;
    printf("Value: 0x%08x\n", regs.dword.eax); 
    printf("AX (low): 0x%04x, ", regs.word.axl);  // AX low 16 bits, 4 digits
    printf("AX (high): 0x%04x, ", regs.word.axh); // AX high 16 bits, 4 digits
    printf("EAX: 0x%08x\n", regs.dword.eax);      // EAX full 32 bits, 8 digits

    // Modify AX low part and print again
    regs.word.axl = 16;  // Set AX low to 16

    printf("AX (low): 0x%04x, ", regs.word.axl);  // AX low 16 bits
    printf("AX (high): 0x%04x, ", regs.word.axh); // AX high 16 bits
    printf("EAX: 0x%08x\n", regs.dword.eax);      // EAX full 32 bits

    printf("AXL (low byte): 0x%02x, ", regs.byte.axll);  // AXL low byte (2 digits)
    printf("AXL (high byte): 0x%02x, ", regs.byte.axlh); // AXL high byte (2 digits)
    printf("AXH (low byte): 0x%02x, ", regs.byte.axhl);  // AXH low byte (2 digits)
    printf("AXH (high byte): 0x%02x\n", regs.byte.axhh); // AXH high byte (2 digits)

    return (0);
}

/*
output:
Value: 0x12345678
AX (low): 0x5678, AX (high): 0x1234, EAX: 0x12345678
AX (low): 0x0010, AX (high): 0x1234, EAX: 0x12340010
AXL (low byte): 0x10, AXL (high byte): 0x00, AXH (low byte): 0x34, AXH (high byte): 0x12

*/