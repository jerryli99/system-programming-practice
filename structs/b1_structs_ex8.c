//ignore style, just from book
#include <stdio.h>

struct color {
    int red;
    int green;
    int blue;
};

int main() {
    //part a
    const struct color MAGENTA = {.red=255, .green=0, .blue=255};

    //part b 
    //const struct color MAGENTA = {.red = 255, .blue = 255};
    return 0;
}