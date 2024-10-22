/*
In computer graphics, colors are often stored as three numbers, representing 
red, green, and blue intensities. Suppose that each number requires eight bits,
and we'd like to store all three values in a single long integer. Write a macro 
named MK_COLOR should return a long in which the last three bytes contain the
red, green, and blue intensities, with the red value as the last byte and the 
green value as the next-to-last byte.

Write macros named GET_RED, GET_GREEN, GET_BLUE that, when given a color as an
argument, return its 8-bit red, green, and blue intentities.
*/

#include <stdio.h>

#define ML_COLOR(red, green, blue) ((long) ((blue) << 16) | ((green) << 8) | (red))
#define GET_RED(color) ((color) & 0xFF)
#define GET_GREEN(color) (((color) >> 8) & 0xFF)
#define GET_BLUE(color) (((color) >> 16) & 0xFF)


int main(void)
{
    // Create a color using ML_COLOR macro
    long color = ML_COLOR(255, 255, 255); // Orange color (R=255, G=165, B=0)

    // Extract individual color components
    int red = GET_RED(color);
    int green = GET_GREEN(color);
    int blue = GET_BLUE(color);

    // Print the results
    printf("Color: 0x%06lX\n", color);
    printf("Red: %d\n", red);
    printf("Green: %d\n", green);
    printf("Blue: %d\n", blue);

    return (0);
}

/*
results:
Color: 0xFFFFFF
Red: 255
Green: 255
Blue: 255
*/