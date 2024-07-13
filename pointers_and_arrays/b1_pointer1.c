#include <stdio.h>

/*
C suuports 3 forms of pointer arithmetic:
Adding an integer to a pointer
Subtracting an integer from a pointer
Subtracting one pointer from another

*/
int main() {
    // int a[10], *p;
    // p = &a[0]; //p points to the first addr of array a
    // *p = 5; //set a[0] to 5 via pointer p

    // int a[10], *p, *q, i;

    // // Set pointer p to the address of a[2]
    // p = &a[2];
    
    // // pointer to a[2+3]
    // q = p + 3;

    // // Print addresses of the array elements
    // for (int i = 0; i < 10; i++) {
    //     //since the i in the for loop only stays in the scope of the for loop
    //     //it will not get mixed with the i declared above.
    //     printf("Address of a[%d]: %p\n", i, (void*)&a[i]);
    // }
    // // Print address stored in pointer p
    // printf("\nAddress stored in p: %p\n", (void*)p);
    // printf("Address stored in q: %p\n", (void*)q);

    // //move pointer p to a[2+6]
    // p += 6;
    // printf("Address stored in p+6: %p\n", (void*)p);
    // printf("if we do q = p + 100?\n");
    // q = p + 100;
    // printf("Address stored in q: %p\n", (void*)q);

    // printf("\nReset pointers ...\n");

    // p = &a[8];
    // q = p - 3;
    // printf("Address stored in p: %p\n", (void*)p);
    // printf("Address stored in q: %p\n", (void*)q);
    // p -= 6;
    // printf("Address stored in p-6: %p\n", (void*)p);

    // printf("\nReset pointers ...\n");

    // p = &a[5];
    // q = &a[1];
    // printf("Address stored in p: %p\n", (void*)p);
    // printf("Address stored in q: %p\n", (void*)q);

    // i = p - q; //4
    // printf("i is : %d\n", i);
    // i = q - p;//-4
    // printf("i is : %d\n", i);

    //there is also something called a compound literal
    //meaning you do not need a variable name to create an array
    //int *p = (int[]) {1,2,3,4};
    printf("\nStart new ...\n");
    int *pp = (int[]) {99,1,2,3,4,5,6,7,8,9,10}, *p2, *pp2;
    pp2 = pp; //make a copy
    p2 = &pp[3];
    printf("value at index 0: %d\n", *p2);
    //a[i++] = j;
    *p2++ = 200;
    for (int i = 0; i < 11; i++) {
        printf("In new array, index [%d] value: %d\n", i, *pp2);
        pp2++;
    }
    //
    // pp2 = pp;
    // *(p2++) = 345;
    // printf("\nwhat will happen?\n");
    // for (int i = 0; i < 11; i++) {
    //     printf("In new array, index [%d] value: %d\n", i, *pp2);
    //     pp2++;
    // }



    return 0;
}