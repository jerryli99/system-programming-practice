#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME_LEN 256
#define EXTENSION_LEN 4

void uncompress_file(const char *input_filename) 
{
    char output_filename[FILENAME_LEN];
    
    int count, byte;

    FILE *input_file = NULL;
    FILE *output_file = NULL;

    // Check if the filename ends with .rle
    if ((strstr(input_filename, ".rle") == NULL) || 
        (strcmp(
            (input_filename + strlen(input_filename) - EXTENSION_LEN), 
            (".rle")) != 0)) 
    {
        fprintf(stderr, "Error: Input file must have .rle extension.\n");
        exit(EXIT_FAILURE);
    }

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for reading.\n", input_filename);
        exit(EXIT_FAILURE);
    }

    // Create the output filename by removing the .rle extension
    strncpy(output_filename, input_filename, strlen(input_filename) - EXTENSION_LEN);
    output_filename[strlen(input_filename) - EXTENSION_LEN] = '\0';

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", output_filename);
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    // Read the count and byte pairs from the input file
    while ((count = fgetc(input_file)) != EOF) 
    {
        byte = fgetc(input_file);
        if (byte == EOF) {
            fprintf(stderr, "Error: Unexpected end of file.\n");
            fclose(input_file);
            fclose(output_file);
            exit(EXIT_FAILURE);
        }

        // Write the byte 'count' times to the output file
        for (int index = 0;  index < count; index++) {
            fputc(byte, output_file);
        }
    }

    // Close the files
    fclose(input_file);
    fclose(output_file);

    return;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <compressed-file.rle>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    uncompress_file(argv[1]);
    return (0);
}
