#include <stdio.h>
#include <stdlib.h>

#include "blur.h"

int main(int argc, char *argv[]) 
{
    if (argc != 4) 
    {
        fprintf(stderr, "Usage: %s <input_file> <output_simple> <output_gaussian>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *input_file = argv[1];
    const char *output_simple = argv[2];
    const char *output_gaussian = argv[3];

    // Read input BMP image
    BMP_IMAGE *image = read_bmp_image(input_file);
    if (image == NULL) 
    {
        fprintf(stderr, "Failed to read input BMP image.\n");
        return EXIT_FAILURE;
    }

    // Apply simple blur and save
    simple_blur(image, output_simple);

    // Re-read the original image for Gaussian blur
    BMP_IMAGE *original_image = read_bmp_image(input_file);
    if (original_image == NULL) 
    {
        fprintf(stderr, "Failed to re-read input BMP image.\n");
        free_bmp_image(image);
        return EXIT_FAILURE;
    }

    // Apply Gaussian blur and save
    gaussian_blur(original_image, output_gaussian);

    // Free memory
    free_bmp_image(image);
    free_bmp_image(original_image);

    return EXIT_SUCCESS;
}