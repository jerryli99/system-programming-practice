#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    struct point 
    { 
        int x;
        int y; 
    };

    struct rectangle 
    { 
        struct point upper_left;
        struct point lower_right; 
    };

    struct rectangle *rect_ptr;

    if ((rect_ptr = malloc(sizeof(struct rectangle))) == NULL) 
    {
        printf("Error, malloc failed.\n");
        exit(EXIT_FAILURE);
    }

    rect_ptr->upper_left.x = 10;
    rect_ptr->upper_left.y = 25;
    rect_ptr->lower_right.x = 20;
    rect_ptr->lower_right.y = 15;

    printf("Rectangle upper left = (%d, %d)\n", 
            rect_ptr->upper_left.x, rect_ptr->upper_left.y);

    printf("Rectangle lower right = (%d, %d)\n", 
            rect_ptr->lower_right.x, rect_ptr->lower_right.y);

    return (0);
}