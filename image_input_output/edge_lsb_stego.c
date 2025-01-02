/*
Just for quick experiment. Try to test it on https://www.aperisolve.com/
there is nothing this stegnography analysis online tool can find from the image,
but the simple lsb method can be detected since it is simple...
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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
            uint8_t edge_intensity = (uint8_t)((sqrt(gx * gx + gy * gy) > 255) ? 
                                     (255) : sqrt(gx * gx + gy * gy));

            RGB_PIXEL edge_pixel = { .r = edge_intensity, 
                                     .g = edge_intensity, 
                                     .b = edge_intensity };

            set_pixel(output_img, x_pos, y_pos, edge_pixel);
        }
    }

    return output_img;
}


/**
 * @brief perform gaussian blur to the image
 * 
 * @param image BMP_IMAGE pointer type
 * 
 * @return BMP_IMAGE pointer type.
 * 
 */
BMP_IMAGE *gaussian_blur(BMP_IMAGE *image) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;

    // Allocate memory for the blurred image and initialize it
    BMP_IMAGE *output_img = malloc(sizeof(BMP_IMAGE));
    if (output_img == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image.\n");
        return NULL;
    }
    memcpy(output_img, image, sizeof(BMP_IMAGE)); // Copy headers and metadata

    // Allocate memory for the pixel data
    output_img->data = malloc(width * height * sizeof(RGB_PIXEL));
    if (output_img->data == NULL) 
    {
        fprintf(stderr, "Memory allocation failed for output image data.\n");
        free(output_img);
        return NULL;
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
    return output_img;
}

/**
 * @brief Edge Least Significant Bit steganography algorithm
 * 
 * @param blurred_image BMO_IMAGE pointer type in which the message will be hidden
 * @param edge_image BMP_IMAGE with detected edge pixels
 * @param info constant char pointer -- the message to hide
 * @param output_filename constant char pointer -- the saved output file name
 * 
 * 
 * @details 
 * 
 * Initialize: width <-- blurred_image_width
 *             height <-- blurred_image_height
 *             info_len <-- length of info
 *             bit_idx <-- 0
 * 
 * Iterate Through pixels
 * For y <-- 1 to height - 1
 *    For x <-- 1 to width - 1
 *       if bit_id >= info_len * 8, exit()
 *       edge_pixel <-- get_pixel(edge_image, x, y)
 *       if edge_pixel.red > 0 or edge_pixel.green > 0 or edge_pixel.blue > 0
 *           bit <-- (info[bit_idx/8] >> (7 - (bit_idx%8))) & 1
 *           blurred_pixel <-- get_pixel(blurred_pixel.red & ~1) | bit
 *           set_pixel(blurred_image, x, y, blurred_pixel)
 *           bit_idx <-- bit_idx + 1
 * 
 * If bit_idx < info_len * 8
 *    throw error
 * 
 * save stego image
 * 
 * @return void. Throw error to stderr if info length exceeds available storage spaece.
 */
void edge_lsb_stego(BMP_IMAGE *blurred_img, 
                    const BMP_IMAGE *edge_img, 
                    const char *info, 
                    const char *output_filename) 
{
    uint32_t width = blurred_img->dib_header.bitmap_width;
    uint32_t height = blurred_img->dib_header.bitmap_height;

    size_t info_len = strlen(info);
    size_t bit_idx = 0;

    for (uint32_t y_pos = 1; y_pos < height - 1 && bit_idx < info_len * 8; y_pos++) 
    {
        for (uint32_t x_pos = 1; x_pos < width - 1 && bit_idx < info_len * 8; x_pos++) 
        {
            //check if the current pixel is an edge
            RGB_PIXEL edge_pixel = get_pixel(edge_img, x_pos, y_pos);
            if (edge_pixel.r > 0 || edge_pixel.g > 0 || edge_pixel.b > 0) 
            {
                //get the next bit to hide
                uint8_t bit = (info[bit_idx / 8] >> (7 - (bit_idx % 8))) & 1;

                //modify the blurred image's LSB
                RGB_PIXEL blurred_pixel = get_pixel(blurred_img, x_pos, y_pos);
                blurred_pixel.r = (blurred_pixel.r & ~1) | bit; //modify LSB of red channel
                set_pixel(blurred_img, x_pos, y_pos, blurred_pixel);

                bit_idx++;
            }
        }
    }

    if (bit_idx < info_len * 8) 
    {
        fprintf(stderr, "Warning: Not enough edge pixels to hide the entire message.\n");
    }

    save_bmp_image(output_filename, blurred_img);
}


/**
 * @brief a reverse process of the edge_lsb_stego function
 * 
 * @param stego_img constant BMP_IMAGE pointer type
 * @param edge_img constant BMP_IMAGE pointer type
 * @param max_info_len size_t
 * 
 * @return the extracted message, pointer to char
 */
char *decode_edge_lsb_stego(const BMP_IMAGE *stego_img, 
                            const BMP_IMAGE *edge_img, 
                            size_t max_info_len) 
{
    uint32_t width = stego_img->dib_header.bitmap_width;
    uint32_t height = stego_img->dib_header.bitmap_height;

    char *decoded_info = (char *)malloc(max_info_len + 1);
    if (decoded_info == NULL) 
    {
        fprintf(stderr, "Error: Memory allocation failed for decoded info.\n");
        return NULL;
    }

    size_t bit_idx = 0;
    memset(decoded_info, 0, max_info_len + 1);

    for (uint32_t y_pos = 1; y_pos < height - 1 && bit_idx < max_info_len * 8; y_pos++) 
    {
        for (uint32_t x_pos = 1; x_pos < width - 1 && bit_idx < max_info_len * 8; x_pos++) 
        {
            //check if the current pixel is an edge
            RGB_PIXEL edge_pixel = get_pixel(edge_img, x_pos, y_pos);
            if (edge_pixel.r > 0 || edge_pixel.g > 0 || edge_pixel.b > 0) 
            {
                //extract the LSB from the red channel of the stego image
                RGB_PIXEL stego_pixel = get_pixel(stego_img, x_pos, y_pos);
                uint8_t bit = stego_pixel.r & 1;

                //set the corresponding bit in the decoded_info
                decoded_info[bit_idx / 8] |= (bit << (7 - (bit_idx % 8)));

                bit_idx++;
            }
        }
    }

    if (bit_idx < max_info_len * 8) 
    {
        fprintf(stderr, "Warning: Decoded information may be incomplete.\n");
    }

    decoded_info[max_info_len] = '\0';
    return decoded_info;
}


int main() 
{
    // Load the input BMP image
    BMP_IMAGE *original_image = read_bmp_image("art.bmp");
    if (!original_image) 
    {
        fprintf(stderr, "Error: Failed to load input.bmp\n");
        return (1);
    }

    //do gaussian blur
    BMP_IMAGE *blurred_image = gaussian_blur(original_image);
    if (blurred_image == NULL) 
    {
        fprintf(stderr, "Error: Failed to blur the image.\n");
        free_bmp_image(original_image);
        return (1);
    }

    //do edge detection
    BMP_IMAGE *edge_image = sobel_edge_detection(original_image);
    if (edge_image == NULL) 
    {
        fprintf(stderr, "Error: Failed to detect edges.\n");
        free_bmp_image(original_image);
        free_bmp_image(blurred_image);
        return (1);
    }

    const char *hidden_info = "what a day today. It is sunny and warm, but i know this is just true...";

    //perform LSB Steganography and save result
    edge_lsb_stego(blurred_image, edge_image, hidden_info, "output_edge_lsb_stego.bmp");

    //load the stego image to verify decoding
    BMP_IMAGE *stego_image = read_bmp_image("output_edge_lsb_stego.bmp");
    if (!stego_image) 
    {
        fprintf(stderr, "Error: Failed to load output_stego.bmp\n");
        free_bmp_image(original_image);
        free_bmp_image(blurred_image);
        free_bmp_image(edge_image);
        return (1);
    }

    //decode the message
    char *decoded_info = decode_edge_lsb_stego(stego_image, edge_image, strlen(hidden_info));
    if (decoded_info) 
    {
        printf("Decoded Info: %s\n", decoded_info);
        free(decoded_info);
    }

    free_bmp_image(original_image);
    free_bmp_image(blurred_image);
    free_bmp_image(edge_image);
    free_bmp_image(stego_image);

    return (0);
}
