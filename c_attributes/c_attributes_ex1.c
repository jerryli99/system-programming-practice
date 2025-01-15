//packed
//prevent the compiler from inserting padding in structures.
#include <stdio.h>

struct __attribute__((packed)) mystruct1 
{
    char a;
    int b;
};

struct mystruct2
{
    char a;
    int b;
};

int main()
{
    printf("Size of mystruct1: %lu\n", sizeof(struct mystruct1));
    printf("Size of mystruct2: %lu\n", sizeof(struct mystruct2));
    return 0;
}

/*
Size of mystruct1: 5
Size of mystruct2: 8
*/