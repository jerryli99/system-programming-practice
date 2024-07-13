#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 10

int contents[STACK_SIZE] = {0};
int top = 0;

//for ex4
int *top_ptr = &contents[0];

void make_empty(void) {
    top_ptr = &contents[0];
}

bool is_empty(void) {
    return top_ptr == &contents[0];
}

bool is_full(void) {
    return top_ptr == &contents[STACK_SIZE];
}


void push(int i) {
    if (is_full()) {
        printf("\nStack is full\n");
        //stack_overflow();
    } else {
        top += 1;
        *top_ptr++ = i;
    }
}

void pop (void) {
    if (is_empty()) {
        printf("Stack underflow\n");
        //stack_underflow();
    } else {
        contents[--top] = 0;
        --top_ptr;
    }
}

void print_stack(const int *array, int size) {
    printf("Initial address of array in print_stack: %p\n", (void*)array);
    printf("\n--------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("[%d]: %d\n", i, *(array+ i));
    }
    printf("The address of array in print_stack finished: %p\n", (void*)array);
}



int main() {
    //just messing around
    printf("\nInitial address of array in main: %p\n", (void*)contents);

    print_stack(contents, STACK_SIZE);

    printf("\nAddress of array after function call in main: %p\n", (void*)contents);
    push(12);
    push(100);
    push(-24);
    push(42);
    print_stack(contents, top);
    pop();
    pop();
    pop();
    print_stack(contents, top);
    pop();
    print_stack(contents, top);
    //pop(); --> this gives me stack underflow
    for (int i = 1; i < 12; i++) {
        push(i);
        print_stack(contents, STACK_SIZE);
    }
    //print_stack(contents);
    return 0;
}