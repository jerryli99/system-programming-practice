//code is a little bit off the textbook.
//the textbook only asks me to create a Point and Rectangle struct,
//then compute the area and the center of the rectangle, and then 
//compute the modified version of rectangle after moving x and y units in 
//x and y direction, and then check if point p lies within the rectangle.

//I was just trying to experiment a bit more.

#include <stdio.h>
#include <stdbool.h>

typedef struct point2d_ {
    int x_2d;
    int y_2d;
} Point2d;

// Define a base structure for a 2D shape with common operations
typedef struct shape_operations_2d_ {
    int (*compute_area)(const void *shape2d);
    Point2d (*find_shape_center)(const void *shape2d);
    void (*move_shape)(const void *shape2d, const int x_units, const int y_units);
    bool (*contains_point)(const void *shape2d, const Point2d point2d);
} ShapeOperations2d;

typedef struct rectangle_ {
    Point2d upper_left;
    Point2d lower_right;
    ShapeOperations2d operation;
} Rectangle;

/**
 * @brief compute the rectangle area.
 * 
 * @param shape2d a void point to a constant.
 * 
 * @return Reurns the area of rectangle (width * length).
 */
int compute_rectangle_area(const void *shape2d) {
    Rectangle *rect = (Rectangle*)shape2d;
    int width = (rect->lower_right.x_2d)  - (rect->upper_left.x_2d);
    int length = (rect->lower_right.y_2d) - (rect->upper_left.y_2d);
    
    if (width < 0) {
        width = (width);
    }

    if (length < 0) {
        length = (-length);
    }

    return (width * length);
}

/**
 * @brief This function finds the center of the rectangle.
 * 
 * @param shape2d a void pointer to a constant.
 * 
 * @return Returns the center of the rectangle.
 */
Point2d find_rectangle_center(const void *shape2d) {
    Rectangle *rect2d = (Rectangle*)shape2d;
    Point2d center;
    center.x_2d = (rect2d->upper_left.x_2d + rect2d->lower_right.x_2d) / 2;
    center.y_2d = (rect2d->upper_left.y_2d + rect2d->lower_right.y_2d) / 2;

    return (center);
}

/**
 * @brief This function will move the rectangle left, right, up, or down in 2D.
 * 
 * @param shape2d a void pointer to a constant.
 * @param x_units a constant integer representing the move units in x direction.
 * @param y_units a constant integer representing the move units in y direction.
 * 
 * @return Return void.
 */
void move_rectangle(const void *shape2d, const int x_units, const int y_units) {
    Rectangle *rect2d = (Rectangle*)shape2d;

    rect2d->upper_left.x_2d  =  (rect2d->upper_left.x_2d) + x_units;
    rect2d->upper_left.y_2d  =  (rect2d->upper_left.y_2d) + y_units;
    rect2d->lower_right.x_2d = (rect2d->lower_right.x_2d) + x_units;
    rect2d->lower_right.y_2d = (rect2d->lower_right.y_2d) + y_units;
}

/**
 * @brief check if point is within the rectangle's horizonal bounds.
 * 
 * @param point2d a constant struct of type Point2d.
 * @param rect2d a constant struct of type Rectangle.
 * 
 * @return Return true if point2d is in horizontal bounds; otherwise, return false.
 */
bool check_rect_horizontal_bounds(const Point2d point2d, const Rectangle *rect2d) {
    if ((point2d.x_2d >= rect2d->upper_left.x_2d) &&
        (point2d.x_2d <= rect2d->lower_right.x_2d)) {
        return (true);
    }
    return (false);
}

/**
 * @brief check if point is within the rectangle's vertical bounds.
 * 
 * @param point2d a constant struct of type Point2d.
 * @param rect2d a constant struct of type Rectangle.
 * 
 * @return Return true if point2d is in vertical bounds; otherwise, return false.
 */
bool check_rect_vertical_bounds(const Point2d point2d, const Rectangle *rect2d) {
    if ((point2d.y_2d >= rect2d->lower_right.y_2d) &&
        (point2d.y_2d <= rect2d->upper_left.y_2d)) {
        return (true);
    }
    return (false);
}

/**
 * @brief check to see if the given point is within the rectangle
 * 
 * @param shape2d a void pointer to a constant
 * @param point2d a constant struct of type Point2d
 * 
 * @return Return false if not in rectangle; otherwise, true.
 */
bool contains_point_rectangle(const void *shape2d, const Point2d point2d) {
    Rectangle *rect2d = (Rectangle*)shape2d;
    if (check_rect_horizontal_bounds(point2d, rect2d) == false) {
        return (false);
    }

    if (check_rect_vertical_bounds(point2d, rect2d) == false) {
        return (false);
    }

    return (true);
}

/**
 * @brief Create rectangle with 2 points and setup function pointers from the 
 *        ShapeOperations struct.
 * 
 * @param upper_left a constant struct of type Point2d
 * @param lower_right a constant struct of type Point2d
 * 
 * @return Return the created rectangle struct. 
 */
Rectangle create_rectangle(const Point2d upper_left, const Point2d lower_right) {
    Rectangle rect2d;
    
    rect2d.upper_left = upper_left;
    rect2d.lower_right = lower_right;

    rect2d.operation.compute_area = compute_rectangle_area;
    rect2d.operation.find_shape_center = find_rectangle_center;
    rect2d.operation.move_shape = move_rectangle;
    rect2d.operation.contains_point = contains_point_rectangle;

    return (rect2d);
}

//just a quick test
int main() { 
    Point2d upper_left = {0, 5};
    Point2d lower_right = {10, 0};
    Point2d random_point = {10, -1};

    Rectangle rect2d = create_rectangle(upper_left, lower_right);
    printf("Rectangle created with coordinates upper-left (%d, %d) and low-right (%d, %d)\n", 
    rect2d.upper_left.x_2d, rect2d.upper_left.y_2d, 
    rect2d.lower_right.x_2d, rect2d.lower_right.y_2d);

    int area = rect2d.operation.compute_area(&rect2d);
    printf("Rectangle area: %d\n", area);

    Point2d center = rect2d.operation.find_shape_center(&rect2d);
    printf("Rectangle center: (%d, %d)\n", center.x_2d, center.y_2d);

    bool in_bound = rect2d.operation.contains_point(&rect2d, random_point);
    printf("Point (%d, %d) is %sinside the rectangle\n", 
    random_point.x_2d, random_point.y_2d, in_bound ? "" : "not ");

    rect2d.operation.move_shape(&rect2d, 2, -1);
    printf("Rectangle moved to upper-left (%d, %d) and lower-right (%d, %d)\n", 
    rect2d.upper_left.x_2d, rect2d.upper_left.y_2d, 
    rect2d.lower_right.x_2d, rect2d.lower_right.y_2d);

    bool in_bound2 = rect2d.operation.contains_point(&rect2d, random_point);
    printf("Point (%d, %d) is %sinside the rectangle\n", 
    random_point.x_2d, random_point.y_2d, in_bound2 ? "" : "not ");

    return (0);
}

/*
Rectangle created with coordinates upper-left (0, 5) and low-right (10, 0)
Rectangle area: 50
Rectangle center: (5, 2)
Point (10, -1) is not inside the rectangle
Rectangle moved to upper-left (2, 4) and lower-right (12, -1)
Point (10, -1) is inside the rectangle
*/