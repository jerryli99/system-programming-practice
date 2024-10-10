#include <stdio.h>

int main()
{

    unsigned short num_i, num_j, num_k;
    num_i = 8;
    num_j = 9;
    printf("%d\n", (num_i >> 1) + (num_j >> 1));

    num_i = 1;
    printf("%d\n", (num_i & (~num_i)));

    num_i = 2;
    num_j = 1;
    num_k = 0;
    printf("%d\n", ((~num_i) & (num_j ^ num_k)));

    num_i = 7;
    num_j = 8;
    num_k = 9;
    printf("%d\n", ((num_i ^ num_j) & num_k));
    return (0);
}

/*
output:
8
0
1
9
*/