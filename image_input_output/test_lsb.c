#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lsb_steganography.h"


int main() {
    // Load the BMP image
    BMP_IMAGE *image = read_bmp_image("art.bmp");

    // Message to hide in the image
    const char *message = "Machine learning is a subset of artificial intelligence " \
                          "where a computer system learns from data, identifies " \
                          "patterns within it, and improves its ability to make " \
                          "predictions or decisions without being explicitly " \
                          "programmed, essentially mimicking how humans learn " \
                          "through experience by analyzing large amounts of data " \
                          "and adapting over time.";

    size_t message_size = strlen(message) + 1; // Include null terminator

    // Embed the message into the image
    lsb_embed_data(image, (const uint8_t *)message, message_size, "output_lsb_1.bmp");

    // Prepare buffer to extract the hidden message
    uint8_t extracted_data[1024] = {0}; // Adjust size to expected data length

    // Extract the data from the image
    lsb_extract_data(image, extracted_data, sizeof(extracted_data));

    // Print the extracted message
    printf("Extracted Data: %s\n", extracted_data);

    // Free allocated memory
    free(image->data);
    free(image);

    return 0;
}