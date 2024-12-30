#include "edge_detection.h"

#include <stdlib.h>
#include <string.h>
#include <math.h>


/**
 * @brief apply edge detection with the sobel filter and save the result in 
 *        a new bmp file.
 * 
 * @param image BMP_IMAGE pointer type
 * @param output_file the output filename
 * 
 * @return void, result is saved to a new bmp file. 
 *         Stderr will display the error if there are any.
 * 
 */
void sobel_edge_detection(BMP_IMAGE *image, const char *output_file) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;

    //sobel kernels for horizontal and vertical gradients
    int8_t sobel_x[3][3] = 
    {
        { -1, 0, 1 },
        { -2, 0, 2 },
        { -1, 0, 1 }
    };

    int8_t sobel_y[3][3] = 
    {
        { -1, -2, -1 },
        {  0,  0,  0 },
        {  1,  2,  1 }
    };

    // Create a new image for the output
    BMP_IMAGE *output_img = malloc(sizeof(BMP_IMAGE));
    if (output_img == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image.\n");
        return;
    }

    memcpy(&output_img->bmp_header, &image->bmp_header, sizeof(BMP_HEADER));
    memcpy(&output_img->dib_header, &image->dib_header, sizeof(DIB_HEADER));

    output_img->data = calloc(image->dib_header.raw_bitmap_size, sizeof(uint8_t));
    if (output_img->data == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image data.\n");
        free_bmp_image(output_img);
        return;
    }

    //apply the Sobel filter, yes, 4 for-loops, a lot...of loops
    for (uint32_t y_pos = 1; y_pos < height - 1; y_pos++) 
    {
        for (uint32_t x_pos = 1; x_pos < width - 1; x_pos++) 
        {
            int32_t gx = 0, gy = 0;

            /*
                iterate the sobel filter 2d array
                (dx=-1,dy=-1) (dx=0,dy=-1) (dx=1,dy=-1)
                (dx=-1,dy=0)  (dx=0,dy=0)  (dx=1,dy=0)
                (dx=-1,dy=1)  (dx=0,dy=1)  (dx=1,dy=1)
            */
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

            //compute the magnitude of the gradient
            //For style, I tried to use if-else, but this experssion is much easier.
            uint8_t edge_intensity = (uint8_t)((sqrt(gx * gx + gy * gy) > 255) ? (255) : sqrt(gx * gx + gy * gy));

            RGB_PIXEL edge_pixel = { .r = edge_intensity, 
                                     .g = edge_intensity, 
                                     .b = edge_intensity };

            set_pixel(output_img, x_pos, y_pos, edge_pixel);
        }
    }

    save_bmp_image(output_file, output_img);
    printf("Edge-detected image saved to %s\n", output_file);

    free_bmp_image(output_img);
}


/**
 * @brief do Roberts Cross edge detection and save the result in a new bmp file.
 * 
 * @param image BMP_IMAGE pointer type
 * @param output_file the output filename
 * 
 * @return void, and if memory allocation failed, show msg in stderr
 */
void roberts_cross_edge_detection(BMP_IMAGE *image, const char *output_file) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;

    BMP_IMAGE *output_image = malloc(sizeof(BMP_IMAGE));
    if (output_image == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image.\n");
        return;
    }

    // Copy headers to the output image
    memcpy(&output_image->bmp_header, &image->bmp_header, sizeof(BMP_HEADER));
    memcpy(&output_image->dib_header, &image->dib_header, sizeof(DIB_HEADER));

    output_image->data = calloc(image->dib_header.raw_bitmap_size, sizeof(uint8_t));
    
    if (output_image->data == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image data.\n");
        free(output_image);
        return;
    }

    size_t row_size = (width * 3 + 3) & ~3;  //row size padded to multiple of 4

    for (uint32_t y_pos = 0; y_pos < height - 1; y_pos++) 
    {
        for (uint32_t x_pos = 0; x_pos < width - 1; x_pos++) 
        {
            //get neighboring pixels for Roberts Cross
            RGB_PIXEL p1 = get_pixel(image, x_pos, y_pos);
            RGB_PIXEL p2 = get_pixel(image, x_pos + 1, y_pos + 1);
            RGB_PIXEL p3 = get_pixel(image, x_pos + 1, y_pos);
            RGB_PIXEL p4 = get_pixel(image, x_pos, y_pos + 1);

            //compute Gx and Gy using Roberts Cross kernels
            //Gx and Gy measure the change in intensity (brightness) in the 
            //horizontal and vertical directions, respectively
            int gx = (int)p1.r - (int)p2.r;
            int gy = (int)p3.r - (int)p4.r;

            //gradient magnitude...approximated
            uint8_t edge_magnitude = (uint8_t)(sqrt(gx * gx + gy * gy));

            //set the pixel in the output image
            RGB_PIXEL edge_pixel = { .r = edge_magnitude, 
                                     .g = edge_magnitude, 
                                     .b = edge_magnitude };

            set_pixel(output_image, x_pos, y_pos, edge_pixel);
        }
    }

    save_bmp_image(output_file, output_image);
    printf("Roberts Cross edge-detected image saved to %s\n", output_file);

    free_bmp_image(output_image);
}

//Canny edge detection, well, this is just too much, so to get my priorities right,
//I will have to give up on implementing this for now. I will implement this if I
//can live until retirement. 