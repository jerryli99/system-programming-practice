/* 

This program will read the bmp image file, assuming we are on a little-endian 
system to make things easier. Then print the necessary header file meta data.

The code to check endian:
int num = 0x12345678;
char* pc = (char*) &num;
for (int i = 0; i < 4; i++) {
    printf("%p: %02x \n", pc, (unsigned char) *pc++);
}
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "bmp.h"

//Note: I will probably change a lot of code here, so I will not write the
//comments for now.

// Function to get the base filename without extension
void get_base_filename(const char *full_name, char *base_name, size_t size) 
{
    snprintf(base_name, size, "%s", full_name);
    char *dot = strrchr(base_name, '.');
    if (dot) 
    {
        *dot = '\0'; // Remove extension
    }
}

// Free BMP image memory
void free_bmp_image(BMP_IMAGE *image) 
{
    if (image != NULL) 
    {
        if (image->data != NULL) 
        {
            free(image->data); // Free pixel data
        }
        free(image);             // Free BMP_IMAGE structure
    }
    return;
}

// Error handling for BMP read
void read_bmp_error(const char *message, FILE *img_fp, BMP_IMAGE *image) 
{
    fprintf(stderr, "%s\n", message);
    if (img_fp != NULL) 
    {
        fclose(img_fp); // Ensure file is closed in case of error
    }
    free_bmp_image(image); // Free image memory
    exit(EXIT_FAILURE);
}

// Read BMP image
BMP_IMAGE* read_bmp_image(const char *file_name) 
{
    FILE *img_fp = fopen(file_name, "rb");
    if (img_fp == NULL) 
    {
        read_bmp_error("Failed to open file", NULL, NULL); // File open failure
    }

    BMP_IMAGE *image = malloc(sizeof(BMP_IMAGE)); // Allocate memory for image
    if (image == NULL) 
    {
        read_bmp_error("Memory allocation failed", img_fp, NULL); // Allocation failure
    }

    // Read BMP header
    if (fread(&image->bmp_header, sizeof(BMP_HEADER), 1, img_fp) != 1 || 
        image->bmp_header.file_type != BMP_FILE_TYPE) 
    {
        read_bmp_error("Invalid BMP file", img_fp, image); // Header read failure
    }

    // Read DIB header
    if (fread(&image->dib_header, sizeof(DIB_HEADER), 1, img_fp) != 1) 
    {
        read_bmp_error("Failed to read DIB header", img_fp, image); // DIB header read failure
    }

    // Move file pointer to pixel data location
    if (fseek(img_fp, image->bmp_header.pixel_array_offset, SEEK_SET) != 0) 
    {
        read_bmp_error("Error seeking to pixel data", img_fp, image);
    }

    uint32_t bitmap_size = image->dib_header.raw_bitmap_size;

    // Allocate memory for image pixel data
    image->data = malloc(bitmap_size);
    if (image->data == NULL) 
    {
        read_bmp_error("Memory allocation failed for image data", img_fp, image);
    }

    // Read pixel data from file
    if (fread(image->data, 1, bitmap_size, img_fp) != bitmap_size) 
    {
        read_bmp_error("Failed to read pixel data", img_fp, image);
    }

    fclose(img_fp); // Close file after successful read
    return (image);   // Return BMP image struct
}

// Print BMP information
void print_bmp_info(const BMP_IMAGE *image) 
{
    printf("BMP File Information:\n");
    printf("File Size: %u bytes\n", image->bmp_header.file_size);
    printf("Bitmap Width: %u pixels\n", image->dib_header.bitmap_width);
    printf("Bitmap Height: %u pixels\n", image->dib_header.bitmap_height);
    printf("Bits Per Pixel: %u\n", image->dib_header.bits_per_pixel);
    printf("Compression Method: %u\n", image->dib_header.compression_method);
    printf("Raw Bitmap Size: %u bytes\n", image->dib_header.raw_bitmap_size);
}

// Save BMP image
void save_bmp_image(const char *file_name, BMP_IMAGE *image) 
{
    FILE *img_fp = fopen(file_name, "wb");
    if (img_fp == NULL) 
    {
        fprintf(stderr, "Failed to open file for writing: %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    fwrite(&image->bmp_header, sizeof(BMP_HEADER), 1, img_fp);
    fwrite(&image->dib_header, sizeof(DIB_HEADER), 1, img_fp);
    fwrite(image->data, 1, image->dib_header.raw_bitmap_size, img_fp);

    fclose(img_fp);
    return;
}

// Get a pixel from the image
RGB_PIXEL get_pixel(const BMP_IMAGE *image, uint32_t x, uint32_t y) 
{
    RGB_PIXEL pixel;
    uint32_t width = image->dib_header.bitmap_width;
    size_t row_size = (width * 3 + 3) & ~3;  // Row size must be a multiple of 4
    size_t pixel_index = y * row_size + x * 3;

    pixel.b = image->data[pixel_index + 0];
    pixel.g = image->data[pixel_index + 1];
    pixel.r = image->data[pixel_index + 2];

    return pixel;
}

// Set a pixel in the image
void set_pixel(BMP_IMAGE *image, uint32_t x, uint32_t y, RGB_PIXEL pixel) 
{
    uint32_t width = image->dib_header.bitmap_width;
    size_t row_size = (width * 3 + 3) & ~3;  // Row size must be a multiple of 4
    size_t pixel_index = y * row_size + x * 3;

    image->data[pixel_index + 0] = pixel.b;
    image->data[pixel_index + 1] = pixel.g;
    image->data[pixel_index + 2] = pixel.r;
}

// Binarize image based on a threshold
void binarize_image(BMP_IMAGE *image, uint8_t threshold, const char *output_file) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;

    for (uint32_t y = 0; y < height; y++) 
    {
        for (uint32_t x = 0; x < width; x++) 
        {
            RGB_PIXEL pixel = get_pixel(image, x, y);
            uint8_t gray = (uint8_t)(0.299 * pixel.r + 0.587 * pixel.g + 0.114 * pixel.b);
            uint8_t binary_value = (gray > threshold) ? 255 : 0;
            RGB_PIXEL binary_pixel = { .r = binary_value, .g = binary_value, .b = binary_value };
            set_pixel(image, x, y, binary_pixel);
        }
    }
    
    save_bmp_image(output_file, image);
    printf("Binarized image saved to %s\n", output_file);
}

// Extract RGB layers from the image
void extract_rgb_layers(BMP_IMAGE *image, const char *file_name) 
{
    uint32_t width = image->dib_header.bitmap_width;
    uint32_t height = image->dib_header.bitmap_height;

    BMP_IMAGE *layers[RGB_COLOR_CHANNELS] = {
        malloc(sizeof(BMP_IMAGE)), 
        malloc(sizeof(BMP_IMAGE)), 
        malloc(sizeof(BMP_IMAGE))
    };
    
    char layer_names[RGB_COLOR_CHANNELS][MAX_FILE_NAME_LEN]; 
    char base_name[FILE_BASE_NAME_LEN];

    get_base_filename(file_name, base_name, sizeof(base_name));

    snprintf(layer_names[0], sizeof(layer_names[0]), "%s_red.bmp", base_name);
    snprintf(layer_names[1], sizeof(layer_names[1]), "%s_green.bmp", base_name);
    snprintf(layer_names[2], sizeof(layer_names[2]), "%s_blue.bmp", base_name);

    for (int index = 0; index < RGB_COLOR_CHANNELS; index++) 
    {
        if (layers[index] == NULL) 
        {
            fprintf(stderr, "Memory allocation failed for color layers.\n");
            return;
        }

        memcpy(&layers[index]->bmp_header, &image->bmp_header, sizeof(BMP_HEADER));
        memcpy(&layers[index]->dib_header, &image->dib_header, sizeof(DIB_HEADER));
        layers[index]->data = calloc(image->dib_header.raw_bitmap_size, sizeof(uint8_t));
    }

    for (uint32_t y = 0; y < height; y++) 
    {
        for (uint32_t x = 0; x < width; x++) 
        {
            RGB_PIXEL pixel = get_pixel(image, x, y);

            RGB_PIXEL red_layer_pixel   = { .r = pixel.r, .g = 0,       .b = 0 };
            RGB_PIXEL green_layer_pixel = { .r = 0,       .g = pixel.g, .b = 0 };
            RGB_PIXEL blue_layer_pixel  = { .r = 0,       .g = 0,       .b = pixel.b };

            set_pixel(layers[0], x, y, red_layer_pixel);
            set_pixel(layers[1], x, y, green_layer_pixel);
            set_pixel(layers[2], x, y, blue_layer_pixel);
        }
    }

    for (int index = 0; index < RGB_COLOR_CHANNELS; index++) 
    {
        save_bmp_image(layer_names[index], layers[index]);
        printf("Layer %d saved to %s\n", index, layer_names[index]);
        free(layers[index]->data); 
        free(layers[index]);       
    }
}

