#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "image_resize.h"

/**
 * @brief resize an image using nearest-neighbor interpolation
 * 
 * @param image BMP_IMAGE pointer type
 * @param new_width uint32_t type
 * @param new_height uint32_t type
 * 
 * @return resized_image a pointer BMP_IMAGE type 
 * 
 */

BMP_IMAGE* resize_nearest_neighbor(BMP_IMAGE *image, 
                                   uint32_t new_width, 
                                   uint32_t new_height) 
{
    BMP_IMAGE *resized_image = malloc(sizeof(BMP_IMAGE));
    if (!resized_image) 
    {
        fprintf(stderr, "Memory allocation failed for resized image.\n");
        return NULL;
    }

    //copy headers and adjust dimensions
    memcpy(&resized_image->bmp_header, &image->bmp_header, sizeof(BMP_HEADER));
    memcpy(&resized_image->dib_header, &image->dib_header, sizeof(DIB_HEADER));

    resized_image->dib_header.bitmap_width = new_width;
    resized_image->dib_header.bitmap_height = new_height;

    uint32_t old_width = image->dib_header.bitmap_width;
    uint32_t old_height = image->dib_header.bitmap_height;
    size_t row_size = (new_width * 3 + 3) & ~3;

    resized_image->data = calloc(row_size * new_height, sizeof(uint8_t));
    if (!resized_image->data) 
    {
        fprintf(stderr, "Memory allocation failed for resized image data.\n");
        free(resized_image);
        return NULL;
    }

    //scaling factors
    double x_ratio = (double)old_width / new_width;
    double y_ratio = (double)old_height / new_height;

    for (uint32_t y = 0; y < new_height; y++) 
    {
        for (uint32_t x = 0; x < new_width; x++) 
        {
            uint32_t src_x = (uint32_t)(x * x_ratio);
            uint32_t src_y = (uint32_t)(y * y_ratio);

            RGB_PIXEL pixel = get_pixel(image, src_x, src_y);
            set_pixel(resized_image, x, y, pixel);
        }
    }

    return resized_image;
}