#include <stdio.h>
#include <assert.h>
#include "b1_structs_ex9.h"

void test_restrict_color_bounds() {
    // Test cases for restrict_color_bounds
    assert(restrict_color_bounds(-10, 0, 255) == 0);
    assert(restrict_color_bounds(300, 0, 255) == 255);
    assert(restrict_color_bounds(128, 0, 255) == 128);
}

void test_make_color() {
    // Test cases for make_color
    Color color1 = make_color(255, 255, 255);
    assert(color1.red == 255 && color1.green == 255 && color1.blue == 255);

    Color color2 = make_color(-1, 0, 256);
    assert(color2.red == 0 && color2.green == 0 && color2.blue == 255);
}

void test_getRed() {
    // Test case for getRed
    Color color = make_color(100, 150, 200);
    assert(getRed(color) == 100);
}

void test_equal_color() {
    // Test cases for equal_color
    Color color1 = make_color(255, 255, 255);
    Color color2 = make_color(255, 255, 255);
    assert(equal_color(color1, color2) == true);

    Color color3 = make_color(255, 0, 0);
    assert(equal_color(color1, color3) == false);
}

void test_brighter() {
    // Test cases for brighter
    Color darkColor = make_color(0, 0, 0);
    Color brightColor = brighter(darkColor);
    assert(brightColor.red == MIN_BRIGHTNESS_LEVEL &&
           brightColor.green == MIN_BRIGHTNESS_LEVEL &&
           brightColor.blue == MIN_BRIGHTNESS_LEVEL);

    Color color = make_color(100, 100, 100);
    Color brighterColor = brighter(color);
    assert(brighterColor.red == (int)(100 / BRIGHTNESS_SCALE_FACTOR) &&
           brighterColor.green == (int)(100 / BRIGHTNESS_SCALE_FACTOR) &&
           brighterColor.blue == (int)(100 / BRIGHTNESS_SCALE_FACTOR));
}

void test_darker() {
    // Test cases for darker
    Color color = make_color(100, 100, 100);
    Color darkerColor = darker(color);
    assert(darkerColor.red == (int)(100 * BRIGHTNESS_SCALE_FACTOR) &&
           darkerColor.green == (int)(100 * BRIGHTNESS_SCALE_FACTOR) &&
           darkerColor.blue == (int)(100 * BRIGHTNESS_SCALE_FACTOR));
}

int main() {
    test_restrict_color_bounds();
    test_make_color();
    test_getRed();
    test_equal_color();
    test_brighter();
    test_darker();

    printf("All tests passed.\n");
    return (0);
}
