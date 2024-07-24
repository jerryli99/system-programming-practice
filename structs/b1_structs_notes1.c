#include <stdio.h>

#define NAME_LEN 10

struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part1, part2;

void print_byte_addresses(const void *start, size_t size) {
    const unsigned char *byte = (const unsigned char *)start;
    for (size_t index = 0; index < size; index++) {
        printf("%p\n", (void *)(byte + index));
    }
}

int main(void) {
    printf("Addresses of part1 members:\n");
    printf("Address of number: %p\n", (void*)&part1.number);
    print_byte_addresses(&part1.number, sizeof(part1.number));

    printf("Address of name: %p\n", (void*)&part1.name);
    print_byte_addresses(&part1.name, sizeof(part1.name));

    printf("Address of on_hand: %p\n", (void*)&part1.on_hand);
    print_byte_addresses(&part1.on_hand, sizeof(part1.on_hand));

    printf("\nAddresses of part2 members:\n");
    printf("Address of number: %p\n", (void*)&part2.number);
    print_byte_addresses(&part2.number, sizeof(part2.number));

    printf("Address of name: %p\n", (void*)&part2.name);
    print_byte_addresses(&part2.name, sizeof(part2.name));

    printf("Address of on_hand: %p\n", (void*)&part2.on_hand);
    print_byte_addresses(&part2.on_hand, sizeof(part2.on_hand));

    return 0;
}

/*
Addresses of part1 members:
Address of number: 0x55c6f8254020
0x55c6f8254020
0x55c6f8254021
0x55c6f8254022
0x55c6f8254023
Address of name: 0x55c6f8254024
0x55c6f8254024
0x55c6f8254025
0x55c6f8254026
0x55c6f8254027
0x55c6f8254028
0x55c6f8254029
0x55c6f825402a
0x55c6f825402b
0x55c6f825402c
0x55c6f825402d
0x55c6f825402e
Address of on_hand: 0x55c6f8254030
0x55c6f8254030
0x55c6f8254031
0x55c6f8254032
0x55c6f8254033

Addresses of part2 members:
Address of number: 0x55c6f8254040
0x55c6f8254040
0x55c6f8254041
0x55c6f8254042
0x55c6f8254043
Address of name: 0x55c6f8254044
0x55c6f8254044
0x55c6f8254045
0x55c6f8254046
0x55c6f8254047
0x55c6f8254048
0x55c6f8254049
0x55c6f825404a
0x55c6f825404b
0x55c6f825404c
0x55c6f825404d
0x55c6f825404e
Address of on_hand: 0x55c6f8254050
0x55c6f8254050
0x55c6f8254051
0x55c6f8254052
0x55c6f8254053




*/