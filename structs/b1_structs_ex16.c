#include <stdio.h>

//just a quick test

int main() {
    enum {FALSE, TRUE} b;
    int i=-1;

    //b = FALSE;      
    //b = i;              
    // b++;
    // b++;
    // b++;                
    //i = b;              
    i = 2 * b + 1;
    printf("%d\n", i);

    return (0);
}