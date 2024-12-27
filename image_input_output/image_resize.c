#include "image_resize.h"



#include <math.h>

// Function to resize an image using nearest-neighbor interpolation
BMP_IMAGE* resize_nearest_neighbor(BMP_IMAGE *image, uint32_t new_width, uint32_t new_height) {
    BMP_IMAGE *resized_image = malloc(sizeof(BMP_IMAGE));
    if (!resized_image) {
        fprintf(stderr, "Memory allocation failed for resized image.\n");
        return NULL;
    }

    // Copy headers and adjust dimensions
    memcpy(&resized_image->bmp_header, &image->bmp_header, sizeof(BMP_HEADER));
    memcpy(&resized_image->dib_header, &image->dib_header, sizeof(DIB_HEADER));
    resized_image->dib_header.bitmap_width = new_width;
    resized_image->dib_header.bitmap_height = new_height;

    uint32_t old_width = image->dib_header.bitmap_width;
    uint32_t old_height = image->dib_header.bitmap_height;
    size_t row_size = (new_width * 3 + 3) & ~3;

    resized_image->data = calloc(row_size * new_height, sizeof(uint8_t));
    if (!resized_image->data) {
        fprintf(stderr, "Memory allocation failed for resized image data.\n");
        free(resized_image);
        return NULL;
    }

    // Scaling factors
    double x_ratio = (double)old_width / new_width;
    double y_ratio = (double)old_height / new_height;

    for (uint32_t y = 0; y < new_height; y++) {
        for (uint32_t x = 0; x < new_width; x++) {
            uint32_t src_x = (uint32_t)(x * x_ratio);
            uint32_t src_y = (uint32_t)(y * y_ratio);

            RGB_PIXEL pixel = get_pixel(image, src_x, src_y);
            set_pixel(resized_image, x, y, pixel);
        }
    }

    return resized_image;
}


// Function to resize an image using bilinear interpolation
BMP_IMAGE* resize_bilinear(BMP_IMAGE *image, uint32_t new_width, uint32_t new_height) {
    BMP_IMAGE *resized_image = malloc(sizeof(BMP_IMAGE));
    if (!resized_image) {
        fprintf(stderr, "Memory allocation failed for resized image.\n");
        return NULL;
    }

    // Copy headers and adjust dimensions
    memcpy(&resized_image->bmp_header, &image->bmp_header, sizeof(BMP_HEADER));
    memcpy(&resized_image->dib_header, &image->dib_header, sizeof(DIB_HEADER));
    
    resized_image->dib_header.bitmap_width = new_width;
    resized_image->dib_header.bitmap_height = new_height;

    uint32_t old_width = image->dib_header.bitmap_width;
    uint32_t old_height = image->dib_header.bitmap_height;
    size_t row_size = (new_width * 3 + 3) & ~3;

    resized_image->data = calloc(row_size * new_height, sizeof(uint8_t));
    if (!resized_image->data) {
        fprintf(stderr, "Memory allocation failed for resized image data.\n");
        free(resized_image);
        return NULL;
    }

    // Scaling factors
    double x_ratio = (double)old_width / new_width;
    double y_ratio = (double)old_height / new_height;

    for (uint32_t y = 0; y < new_height; y++) {
        for (uint32_t x = 0; x < new_width; x++) {
            double gx = x * x_ratio;
            double gy = y * y_ratio;

            int x0 = (int)floor(gx);
            int x1 = (x0 + 1 < old_width) ? x0 + 1 : x0;
            int y0 = (int)floor(gy);
            int y1 = (y0 + 1 < old_height) ? y0 + 1 : y0;

            RGB_PIXEL p00 = get_pixel(image, x0, y0);
            RGB_PIXEL p01 = get_pixel(image, x0, y1);
            RGB_PIXEL p10 = get_pixel(image, x1, y0);
            RGB_PIXEL p11 = get_pixel(image, x1, y1);

            double dx = gx - x0;
            double dy = gy - y0;

            RGB_PIXEL pixel;
            pixel.r = (uint8_t)(
                (1 - dx) * (1 - dy) * p00.r + dx * (1 - dy) * p10.r +
                (1 - dx) * dy * p01.r + dx * dy * p11.r);
            pixel.g = (uint8_t)(
                (1 - dx) * (1 - dy) * p00.g + dx * (1 - dy) * p10.g +
                (1 - dx) * dy * p01.g + dx * dy * p11.g);
            pixel.b = (uint8_t)(
                (1 - dx) * (1 - dy) * p00.b + dx * (1 - dy) * p10.b +
                (1 - dx) * dy * p01.b + dx * dy * p11.b);

            set_pixel(resized_image, x, y, pixel);
        }
    }

    return resized_image;
}