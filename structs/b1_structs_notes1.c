#include <stdio.h>

/**
 * This is bad style for writing structs. Could have used typedef here.
 * I will leave the "bad style code" here for future reminder.
 */

#define NAME_LEN 6

struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part1, part2;

void print_byte_addresses_and_contents(const void *start, size_t size) {
    const unsigned char *byte = (const unsigned char *)start;
    for (size_t index = 0; index < size; index++) {
        printf("Address: %p, Content: 0x%02x\n", (void *)(byte + index), byte[index]);
    }
}

int main(void) {
    // Initialize the structure with some values
    part1.number = 12345;
    snprintf(part1.name, NAME_LEN + 1, "hello");
    part1.on_hand = 50;

    part2.number = 67890;
    snprintf(part2.name, NAME_LEN + 1, "away");
    part2.on_hand = 10000;

    // Print addresses and contents of members of part1
    printf("Addresses and contents of part1 members:\n");
    printf("Address of number: %p\n", (void*)&part1.number);
    print_byte_addresses_and_contents(&part1.number, sizeof(part1.number));

    printf("Address of name: %p\n", (void*)&part1.name);
    print_byte_addresses_and_contents(&part1.name, sizeof(part1.name));

    printf("Address of on_hand: %p\n", (void*)&part1.on_hand);
    print_byte_addresses_and_contents(&part1.on_hand, sizeof(part1.on_hand));

    // Print addresses and contents of members of part2
    printf("\nAddresses and contents of part2 members:\n");
    printf("Address of number: %p\n", (void*)&part2.number);
    print_byte_addresses_and_contents(&part2.number, sizeof(part2.number));

    printf("Address of name: %p\n", (void*)&part2.name);
    print_byte_addresses_and_contents(&part2.name, sizeof(part2.name));

    printf("Address of on_hand: %p\n", (void*)&part2.on_hand);
    print_byte_addresses_and_contents(&part2.on_hand, sizeof(part2.on_hand));

    return (0);
}


/*
Addresses and contents of part1 members:
Address of number: 0x562726c7c020
Address: 0x562726c7c020, Content: 0x39
Address: 0x562726c7c021, Content: 0x30
Address: 0x562726c7c022, Content: 0x00
Address: 0x562726c7c023, Content: 0x00
Address of name: 0x562726c7c024
Address: 0x562726c7c024, Content: 0x68
Address: 0x562726c7c025, Content: 0x65
Address: 0x562726c7c026, Content: 0x6c
Address: 0x562726c7c027, Content: 0x6c
Address: 0x562726c7c028, Content: 0x6f
Address: 0x562726c7c029, Content: 0x00
Address: 0x562726c7c02a, Content: 0x00
Address of on_hand: 0x562726c7c02c
Address: 0x562726c7c02c, Content: 0x32
Address: 0x562726c7c02d, Content: 0x00
Address: 0x562726c7c02e, Content: 0x00
Address: 0x562726c7c02f, Content: 0x00

Addresses and contents of part2 members:
Address of number: 0x562726c7c030
Address: 0x562726c7c030, Content: 0x32
Address: 0x562726c7c031, Content: 0x09
Address: 0x562726c7c032, Content: 0x01
Address: 0x562726c7c033, Content: 0x00
Address of name: 0x562726c7c034
Address: 0x562726c7c034, Content: 0x61
Address: 0x562726c7c035, Content: 0x77
Address: 0x562726c7c036, Content: 0x61
Address: 0x562726c7c037, Content: 0x79
Address: 0x562726c7c038, Content: 0x00
Address: 0x562726c7c039, Content: 0x00
Address: 0x562726c7c03a, Content: 0x00
Address of on_hand: 0x562726c7c03c
Address: 0x562726c7c03c, Content: 0x10
Address: 0x562726c7c03d, Content: 0x27
Address: 0x562726c7c03e, Content: 0x00
Address: 0x562726c7c03f, Content: 0x00

*/