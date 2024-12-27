#include "blur.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Simple blur filter with a 3x3 kernel
 * 
 * @param image BMP_IMAGE pointer type. 
 * @param output_file Path to save the blurred image.
 */
void simple_blur(BMP_IMAGE *image, const char *output_file) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;

    // Allocate memory for the blurred image and initialize it
    BMP_IMAGE *output_img = malloc(sizeof(BMP_IMAGE));
    if (output_img == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image.\n");
        return;
    }
    memcpy(output_img, image, sizeof(BMP_IMAGE)); // Copy headers and metadata

    // Allocate memory for the pixel data
    output_img->data = malloc(width * height * sizeof(RGB_PIXEL));
    if (output_img->data == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image data.\n");
        free(output_img);
        return;
    }

    // Apply simple blur
    for (uint32_t y_pos = 1; y_pos < height - 1; y_pos++) 
    {
        for (uint32_t x_pos = 1; x_pos < width - 1; x_pos++) 
        {
            int r = 0, g = 0, b = 0;

            // Apply 3x3 kernel
            for (int dy = -1; dy <= 1; dy++) 
            {
                for (int dx = -1; dx <= 1; dx++) 
                {
                    RGB_PIXEL pixel = get_pixel(image, x_pos + dx, y_pos + dy);
                    r += pixel.r;
                    g += pixel.g;
                    b += pixel.b;
                }
            }

            // Compute average
            r /= 9;
            g /= 9;
            b /= 9;

            // Set the new pixel value
            RGB_PIXEL blurred_pixel = {r, g, b};
            set_pixel(output_img, x_pos, y_pos, blurred_pixel);
        }
    }

    // Save the resulting blurred image
    save_bmp_image(output_file, output_img);

    // Free allocated memory
    free(output_img->data);
    free(output_img);
}

/**
 * @brief Apply Gaussian blur filter with a 3x3 kernel
 * 
 * @param image BMP_IMAGE pointer type. 
 * @param output_file Path to save the blurred image.
 */
void gaussian_blur(BMP_IMAGE *image, const char *output_file) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;

    // Allocate memory for the blurred image and initialize it
    BMP_IMAGE *output_img = malloc(sizeof(BMP_IMAGE));
    if (output_img == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image.\n");
        return;
    }
    memcpy(output_img, image, sizeof(BMP_IMAGE)); // Copy headers and metadata

    // Allocate memory for the pixel data
    output_img->data = malloc(width * height * sizeof(RGB_PIXEL));
    if (output_img->data == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image data.\n");
        free(output_img);
        return;
    }

    // Gaussian kernel
    int kernel[3][3] = 
    {
        {1, 2, 1},
        {2, 4, 2},
        {1, 2, 1}
    };
    const int kernel_sum = 16;

    // Apply Gaussian blur
    for (uint32_t y_pos = 1; y_pos < height - 1; y_pos++) 
    {
        for (uint32_t x_pos = 1; x_pos < width - 1; x_pos++) 
        {
            int r = 0, g = 0, b = 0;

            // Apply kernel
            for (int dy = -1; dy <= 1; dy++) 
            {
                for (int dx = -1; dx <= 1; dx++) 
                {
                    RGB_PIXEL pixel = get_pixel(image, x_pos + dx, y_pos + dy);
                    int weight = kernel[dy + 1][dx + 1];
                    r += pixel.r * weight;
                    g += pixel.g * weight;
                    b += pixel.b * weight;
                }
            }

            // Normalize
            r /= kernel_sum;
            g /= kernel_sum;
            b /= kernel_sum;

            // Set the new pixel value
            RGB_PIXEL blurred_pixel = {r, g, b};
            set_pixel(output_img, x_pos, y_pos, blurred_pixel);
        }
    }

    // Save the resulting blurred image
    save_bmp_image(output_file, output_img);

    // Free allocated memory
    free(output_img->data);
    free(output_img);
}
