//Don't judge the style, just a short problem from textbook
#include <stdio.h>

#define PI 3.1415926
#define CIRCLE 0
#define RECTANGLE 1

struct point { int x, y; };

struct shape {
    int shape_kind;
    struct point center;
    union {
        struct {
            int height, width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

double compute_area(const struct shape s);
struct shape shift_shape(struct shape s, int x, int y);
struct shape scale_shape(struct shape s, double scalefactor);

int main() {
    s.shape_kind = CIRCLE;
    s.u.circle.radius = 10;
    printf("Area of circle with radius %d: %.2f\n", s.u.circle.radius,
            compute_area(s));

    s.shape_kind = RECTANGLE;
    s.center.x = -1;
    s.center.y = 2;
    s.u.rectangle.height = 10;
    s.u.rectangle.width = 20;
    printf("Center of rectangle: (%d, %d)\n", s.center.x, s.center.y);
    printf("Area of rectangle with height %d and width %d: %.0f\n", 
            s.u.rectangle.height, s.u.rectangle.width, compute_area(s));

    s = shift_shape(s, -10, 30);
    printf("Center of shifted rectangle: (%d, %d)\n", s.center.x,
            s.center.y);

    s.shape_kind = CIRCLE;
    s.u.circle.radius = 10;
    s = scale_shape(s, 1.5);
    printf("Circle new radius after scaled by 1.5: %d\n", s.u.circle.radius);

    return 0;
}

double compute_area(struct shape s) {
    if (s.shape_kind == CIRCLE) {
        return (PI * s.u.circle.radius * s.u.circle.radius);
    } else if (s.shape_kind == RECTANGLE) {
        return (s.u.rectangle.width * s.u.rectangle.height);
    } else {
        return 0.0;
    }
}

struct shape shift_shape(struct shape s, int x, int y) {
    s.center.x = s.center.x + x;
    s.center.y = s.center.y + y;

    return s;
}

struct shape scale_shape(struct shape s, double scale_factor) {
    if (s.shape_kind == CIRCLE) {
        s.u.circle.radius = (s.u.circle.radius * scale_factor);
    } else if (s.shape_kind == RECTANGLE) {
        s.u.rectangle.height = (s.u.rectangle.height * scale_factor);
        s.u.rectangle.width *= (s.u.rectangle.width * scale_factor);
    } else {
        //nothing
    }

    return s;
}
