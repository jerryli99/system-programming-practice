#include <stdio.h>
#include <stdlib.h>

#include "edge_detection.h"

int main(int argc, char *argv[]) 
{
    if (argc < 3) 
    {
        fprintf(stderr, "Usage: %s <input_file> <output_file>\n", argv[0]);
        return (EXIT_FAILURE);
    }

    BMP_IMAGE *image = read_bmp_image(argv[1]);
    if (image == NULL) 
    {
        return (EXIT_FAILURE);
    }

    print_bmp_info(image);
    
    // Perform edge detection
    sobel_edge_detection(image, argv[2]);

    free_bmp_image(image);
    return (EXIT_SUCCESS);
}
