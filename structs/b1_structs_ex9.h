#ifndef B1_STRUCTS_EX9_H
#define B1_STRUCTS_EX9_H

#include <stdbool.h>

#define MIN_COLOR_VAL 0
#define MAX_COLOR_VAL 255
#define MIN_BRIGHTNESS_LEVEL 3
#define BRIGHTNESS_SCALE_FACTOR 0.7

typedef struct color_ {
    int red;
    int green;
    int blue;
} Color;

int restrict_color_bounds(const int color_val, const int c_min, const int c_max);
Color make_color(const int red, const int green, const int blue);
int getRed(const Color c);
bool equal_color(const Color color1, const Color color2);
Color brighter(const Color c);
Color darker(const Color c);

#endif