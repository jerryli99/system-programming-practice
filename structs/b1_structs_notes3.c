#include <stdio.h>
#include <string.h>

#define NAME_LEN 20

struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

void print_part(struct part part_var);
struct part build_part(int number, const char* name, int on_hand);

int main() {
    print_part(build_part(10, "John", 11));

    return 0;
}

void print_part(struct part part_var) {
    printf("Part number: %d\n", part_var.number);
    printf("Part name: %s\n", part_var.name);
    printf("Quantity on hand: %d\n", part_var.on_hand);

    return;
}

struct part build_part(int number, const char* name, int on_hand) {
    struct part part_var;
    part_var.number = number;
    strcpy(part_var.name, name);
    part_var.on_hand = on_hand;

    return part_var;
}

/*
Observation:
Passing a structure to a function and returning a structure from a function both require making a copy of all members
in the structure. As a result, these operations impose a fair amount of overhead on a program, especially if the 
structure is large. So, why not just pass a pointer to a structure? Ofcourse that will be easier and faster..

Remember there is a FILE type in the stdio.h? Each FILE structure will store information about the state of an open file and 
therefore must be unique in a program. Every function in stdio.h that opens a file returns a pointer to a FILE structure, and
every function that performs an operation on an open file requires a FILE pointer as argument. 


*/