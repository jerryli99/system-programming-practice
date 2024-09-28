#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[]) 
{
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <bmp_filename> <threshold>\n", argv[0]);
        return EXIT_FAILURE;
    }

    uint8_t threshold = (uint8_t)atoi(argv[2]);
    BMP_IMAGE *image = read_bmp_image(argv[1]);
    if (!image) 
    {
        return EXIT_FAILURE;
    }

    print_bmp_info(image);
    extract_rgb_layers(image, argv[1]);
    binarize_image(image, threshold, "binarized.bmp");

    free_bmp_image(image); // Use the free function to avoid memory leaks
    
    return EXIT_SUCCESS;
}