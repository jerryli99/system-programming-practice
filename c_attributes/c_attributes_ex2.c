//aligned
//shows how to align a variable on a specific boundary
#include <stdio.h>
#include <stdint.h>

uint64_t var_a __attribute__((aligned(32)));
uint64_t var_b __attribute__((aligned(16)));
uint64_t var_c __attribute__((aligned(8)));

uint64_t var_d __attribute__((aligned(16)));
uint32_t var_e __attribute__((aligned(16)));
uint32_t var_f __attribute__((aligned(8)));

uint32_t var_g __attribute__((aligned(4)));
uint32_t var_h __attribute__((aligned(4)));
uint32_t var_i __attribute__((aligned(4)));

// Function to get the shortened hexadecimal part of an address
void print_short_address(uintptr_t base, uintptr_t address) {
    printf("0x%04lx", address - base);
}

// Function to print memory layout visualization
void draw_memory_layout() {
    uintptr_t base = (uintptr_t)&var_a; // Use var_a as the base address

    printf("Memory Layout (Vertical Representation with Ranges):\n");
    printf("---------------------------------------------\n");
    printf(" Variable   | Start Address  | End Address    \n");
    printf("---------------------------------------------\n");
    printf(" var_a      | ");
    print_short_address(base, (uintptr_t)&var_a);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_a + sizeof(var_a) - 1);
    printf("          \n");

    printf(" var_b      | ");
    print_short_address(base, (uintptr_t)&var_b);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_b + sizeof(var_b) - 1);
    printf("          \n");

    printf(" var_c      | ");
    print_short_address(base, (uintptr_t)&var_c);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_c + sizeof(var_c) - 1);
    printf("          \n");

    printf(" var_d      | ");
    print_short_address(base, (uintptr_t)&var_d);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_d + sizeof(var_d) - 1);
    printf("          \n");

    printf(" var_e      | ");
    print_short_address(base, (uintptr_t)&var_e);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_e + sizeof(var_e) - 1);
    printf("          \n");

    printf(" var_f      | ");
    print_short_address(base, (uintptr_t)&var_f);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_f + sizeof(var_f) - 1);
    printf("          \n");

    printf(" var_g      | ");
    print_short_address(base, (uintptr_t)&var_g);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_g + sizeof(var_g) - 1);
    printf("          \n");

    printf(" var_h      | ");
    print_short_address(base, (uintptr_t)&var_h);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_h + sizeof(var_h) - 1);
    printf("          \n");

    printf(" var_i      | ");
    print_short_address(base, (uintptr_t)&var_i);
    printf("          | ");
    print_short_address(base, (uintptr_t)&var_i + sizeof(var_i) - 1);
    printf("          \n");

    printf("---------------------------------------------\n");
}

int main()
{
    uintptr_t base = (uintptr_t)&var_a; 
    //wait, why use uintptr_t??? Well, usually, for cross platform, 32-bit, 64-bit systems
    //this is something I learned recently...
    /*
    Types for `void *' pointers.
        #if __WORDSIZE == 64
        # ifndef __intptr_t_defined
        typedef long int		intptr_t;
        #  define __intptr_t_defined
        # endif
        typedef unsigned long int	uintptr_t;
        #else
        # ifndef __intptr_t_defined
        typedef int			intptr_t;
        #  define __intptr_t_defined
        # endif
        typedef unsigned int		uintptr_t;
        #endif
    
    */

    printf("Address of var_a: 0x%lx\n", (unsigned long)&var_a);
    printf("Address of var_b: 0x%lx\n", (unsigned long)&var_b);
    printf("Address of var_c: 0x%lx\n", (unsigned long)&var_c);

    printf("Address of var_d: 0x%lx\n", (unsigned long)&var_d);
    printf("Address of var_e: 0x%lx\n", (unsigned long)&var_e);
    printf("Address of var_f: 0x%lx\n", (unsigned long)&var_f);

    printf("Address of var_g: 0x%lx\n", (unsigned long)&var_g);
    printf("Address of var_h: 0x%lx\n", (unsigned long)&var_h);
    printf("Address of var_i: 0x%lx\n", (unsigned long)&var_i);

    printf("Base address for memory layout: 0x%lx\n", base);

    draw_memory_layout();
    return 0;
}

/*
Address of var_a: 0x557067cc4040
Address of var_b: 0x557067cc4050
Address of var_c: 0x557067cc4058
Address of var_d: 0x557067cc4060
Address of var_e: 0x557067cc4070
Address of var_f: 0x557067cc4078
Address of var_g: 0x557067cc407c
Address of var_h: 0x557067cc4080
Address of var_i: 0x557067cc4084
Base address for memory layout: 0x557067cc4040
Memory Layout (Vertical Representation with Ranges):
---------------------------------------------
 Variable   | Start Address  | End Address    
---------------------------------------------
 var_a      | 0x0000          | 0x0007          
 var_b      | 0x0010          | 0x0017          
 var_c      | 0x0018          | 0x001f          
 var_d      | 0x0020          | 0x0027          
 var_e      | 0x0030          | 0x0033          
 var_f      | 0x0038          | 0x003b          
 var_g      | 0x003c          | 0x003f          
 var_h      | 0x0040          | 0x0043          
 var_i      | 0x0044          | 0x0047          
---------------------------------------------

*/