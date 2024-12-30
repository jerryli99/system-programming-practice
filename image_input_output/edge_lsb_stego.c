/*

Just for quick experiment mentioned in lsb_steganography.c

*/

#include <stdio.h>
#include "bmp.h"



/**
 * @brief Perform Sobel edge detection on an image and return the edge-detected image.
 *
 * @param image Pointer to the input BMP_IMAGE
 * @return Pointer to the edge-detected BMP_IMAGE, or NULL if memory allocation fails.
 */
BMP_IMAGE *sobel_edge_detection(const BMP_IMAGE *image) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;

    // Sobel kernels for horizontal and vertical gradients
    int8_t sobel_x[3][3] = {
        { -1, 0, 1 },
        { -2, 0, 2 },
        { -1, 0, 1 }
    };

    int8_t sobel_y[3][3] = {
        { -1, -2, -1 },
        {  0,  0,  0 },
        {  1,  2,  1 }
    };

    // Create a new image for the output
    BMP_IMAGE *output_img = malloc(sizeof(BMP_IMAGE));
    if (output_img == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image.\n");
        return NULL;
    }

    memcpy(&output_img->bmp_header, &image->bmp_header, sizeof(BMP_HEADER));
    memcpy(&output_img->dib_header, &image->dib_header, sizeof(DIB_HEADER));

    output_img->data = calloc(image->dib_header.raw_bitmap_size, sizeof(uint8_t));
    if (output_img->data == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image data.\n");
        free(output_img);
        return NULL;
    }

    // Apply the Sobel filter
    for (uint32_t y_pos = 1; y_pos < height - 1; y_pos++) 
    {
        for (uint32_t x_pos = 1; x_pos < width - 1; x_pos++) 
        {
            int32_t gx = 0, gy = 0;

            // Iterate over the Sobel filter kernel
            for (int dy = -1; dy <= 1; dy++) 
            {
                for (int dx = -1; dx <= 1; dx++) 
                {
                    RGB_PIXEL pixel = get_pixel(image, x_pos + dx, y_pos + dy);
                    uint8_t gray = (uint8_t)(0.299 * pixel.r + 
                                             0.587 * pixel.g + 
                                             0.114 * pixel.b);

                    gx += gray * sobel_x[dy + 1][dx + 1];
                    gy += gray * sobel_y[dy + 1][dx + 1];
                }
            }

            // Compute the magnitude of the gradient
            uint8_t edge_intensity = (uint8_t)((sqrt(gx * gx + gy * gy) > 255) ? 255 : sqrt(gx * gx + gy * gy));

            RGB_PIXEL edge_pixel = { .r = edge_intensity, 
                                     .g = edge_intensity, 
                                     .b = edge_intensity };

            set_pixel(output_img, x_pos, y_pos, edge_pixel);
        }
    }

    return output_img; ///modified from the original code in edge_detection.c
}
