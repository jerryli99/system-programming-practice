#include "b1_structs_ex9.h"

/** 
 * @brief A helper function for make_color(const int red, const int green, const int blue) 
 *        and for other future potential functions that need to restrict color in specific
 *        ranges.
 * 
 *        This function will reset the values of RGB to 0 or 255 if the color value in 
 *        the make_color function has values less than c_min or more than c_max.
 *        
 * 
 * @param color_val a constant integer representing the color value, i.e. red, blue, or green.
 * @param c_min a constant integer representing the min value of color c.
 * @param c_max a constant integer representing the max value of color c.
 * 
 * @return Returns the color value passed in if the value is in the range (c_min, c_max); else, 
 *         the value will be reset value of either c_min or c_max if color value exceeds either one of them. 
 */
int restrict_color_bounds(const int color_val, const int c_min, const int c_max) {
    if (color_val < c_min)  {
        return c_min;
    }

    if (color_val > c_max) {
        return c_max;
    }

    return color_val;
}

/**
 * @brief Create a struct with color values stored inside. If any 
 *        argument is less than zero, the corresponding member of the
 *        structure will contain zero instead. If any argument is 
 *        greater than 255, the corresponding member of the structure
 *        will contain 255.
 * 
 * @param red a constant integer of holding the red color channel.
 * @param green a constant integer of holding the green color channel.
 * @param blue a constant integer of holding the blue color channel.
 * 
 * @return Returns a struct of type Color.
 */
Color make_color(const int red, const int green, const int blue) {
    Color new_color;
    new_color.red = restrict_color_bounds(red, MIN_COLOR_VAL, MAX_COLOR_VAL);
    new_color.green = restrict_color_bounds(green, MIN_COLOR_VAL, MAX_COLOR_VAL);
    new_color.blue = restrict_color_bounds(blue, MIN_COLOR_VAL, MAX_COLOR_VAL);
    return new_color;
}

/**
 * @brief Get the red color from the Color struct.
 * 
 * @param c a constant Color struct.
 * 
 * @return Returns the member red of integer type from the Color struct.
 */
int getRed(const Color c) {
    return c.red;
}

/**
 * @brief compare two Color structs.
 * 
 * @param color1 a constant Color struct.
 * @param color2 a constant Color struct.
 * 
 * @return Returns boolean type of value true if color1 and color2 have all 
 *         struct members equal, and false if not all struct members are equal.
 */
bool equal_color(const Color color1, const Color color2) {
    if (color1.red != color2.red) {
        return false;
    }

    if (color1.green != color2.green) {
        return false;
    }

    if (color1.blue != color2.blue) {
        return false;
    }

    return true;
}

/**
 * @brief make color brighter
 * 
 * @param c a constant struct of type Color
 * 
 * @return Returns a color structure that represents a brighter version of the color c.
 */
Color brighter(const Color c) {
    Color new_color = {.red = c.red, .green = c.green, .blue = c.blue};

    //If all members are 0, set each new_color member to 3 and return.
    //Note: The 3 is MIN_BRIGHTNESS_LEVEL
    if ((new_color.red   == MIN_COLOR_VAL) && 
        (new_color.green == MIN_COLOR_VAL) && 
        (new_color.blue  == MIN_COLOR_VAL)) {
        new_color.red = new_color.green = new_color.blue = MIN_BRIGHTNESS_LEVEL;
        return new_color;
    }

    //Set any member that lies between 0 and 3 to 3.
    if ((new_color.red > MIN_COLOR_VAL) && (new_color.red < MIN_BRIGHTNESS_LEVEL)) {
        new_color.red = MIN_BRIGHTNESS_LEVEL;
    }

    if ((new_color.green > MIN_COLOR_VAL) && (new_color.green < MIN_BRIGHTNESS_LEVEL)) {
        new_color.green = MIN_BRIGHTNESS_LEVEL;
    }

    if ((new_color.blue > MIN_COLOR_VAL) && (new_color.blue < MIN_BRIGHTNESS_LEVEL)) {
        new_color.blue = MIN_BRIGHTNESS_LEVEL;
    }

    //Get the new_color values by dividing struct color c members by 0.7,
    // with the result truncated to an integer.
    new_color.red   = (int) (new_color.red / BRIGHTNESS_SCALE_FACTOR);
    new_color.green = (int) (new_color.green / BRIGHTNESS_SCALE_FACTOR);
    new_color.blue  = (int) (new_color.blue / BRIGHTNESS_SCALE_FACTOR);

    //Set any member of new_color that exceeds 255 to 255.
    if (new_color.red > MAX_COLOR_VAL) {
        new_color.red = MAX_COLOR_VAL;
    }

    if (new_color.green > MAX_COLOR_VAL) {
        new_color.green = MAX_COLOR_VAL;
    }

    if (new_color.blue > MAX_COLOR_VAL) {
        new_color.blue = MAX_COLOR_VAL;
    }

    return new_color;
}

/**
 * @brief make color darker
 * 
 * @param c a constant struct of type Color
 * 
 * @return Returns a struct of type Color, with all member values 
 *         multiplied by the brightness scale factor 0.7
 */
Color darker(const Color c) {
    Color new_color = {.red = c.red, .green = c.green, .blue = c.blue};
    
    //each member multiply by 0.7 (with the result truncated to an integer)
    new_color.red   = (int) (new_color.red * BRIGHTNESS_SCALE_FACTOR);
    new_color.green = (int) (new_color.green * BRIGHTNESS_SCALE_FACTOR);
    new_color.blue  = (int) (new_color.blue * BRIGHTNESS_SCALE_FACTOR);

    return new_color;
}