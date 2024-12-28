#include <stdio.h>
#include <stdlib.h>

#include "image_resize.h"

int main(int argc, char *argv[]) 
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s <input.bmp> <output.bmp>\n", argv[0]);
        return EXIT_FAILURE;
    }

    BMP_IMAGE *image = read_bmp_image(argv[1]);

    uint32_t new_width = 224;
    uint32_t new_height = 224;

    BMP_IMAGE *resized_image = resize_nearest_neighbor(image, new_width, new_height);
    if (resized_image) 
    {
        save_bmp_image(argv[2], resized_image);
        free_bmp_image(resized_image);
    }

    free_bmp_image(image);
    return EXIT_SUCCESS;
}
