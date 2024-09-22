/*
Of the many techniques for compressing the content of a file, one of the simplest
and fastest known as run-length encoding. This technique compresses a file by 
replacing sequences of identical bytes by a pair of bytes: a repetition count
followed by a byte to be repeated. For example, suppose that the file to be 
compressed begins with the following sequence of bytes (hex):

46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20

The compressed file will contain the following bytes:

01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20

Run-length encoding wors well if the original file contains many long sequences
of identical bytes. In the worst case (a file with no repeated bytes), run-length
encoding can actually double the length of the file.

(a) Write a program named compress_file that uses run-length encoding to compress
a file. To run compress_file, we'd e a command of the form:
compress_file original-file

this will write the compressed ersion of original file to original file.rle.

So, foo.txt --> foo.txt.rle

(b) Write a program named uncompress_file that reverses the compression performed
by the compress_file program. The uncompress_file will open the foo.txt.rle 
file and write an uncompressed version of its contents to foo.txt. 
uncompress_file should display an error message if its command-line argument 
does not end with the .rle extension. 

*/

#include <stdio.h>
#include <stdlib.h>

#define FILENAME_LEN 256
#define MAX_COUNT 255

void compress_file(const char *input_filename) 
{    
    char output_filename[FILENAME_LEN];

    int current_byte, previous_byte;
    int count = 1;

    FILE *input_file = NULL;
    FILE *output_file = NULL;

    input_file = fopen(input_filename, "rb");
    if (input_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for reading.\n", input_filename);
        exit(EXIT_FAILURE);
    }

    // Create the output filename with .rle extension
    snprintf(output_filename, sizeof(output_filename), "%s.rle", input_filename);

    output_file = fopen(output_filename, "wb");
    if (output_file == NULL) {
        fprintf(stderr, "Error: Could not open file %s for writing.\n", output_filename);
        fclose(input_file);
        exit(EXIT_FAILURE);
    }

    previous_byte = fgetc(input_file);

    while ((current_byte = fgetc(input_file)) != EOF) 
    {
        if (current_byte == previous_byte && count < MAX_COUNT) {
            count++;
        } else {
            fputc(count, output_file);
            fputc(previous_byte, output_file);
            previous_byte = current_byte;
            count = 1;
        }
    }

    if (previous_byte != EOF) {
        fputc(count, output_file);
        fputc(previous_byte, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    return;
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <original-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    compress_file(argv[1]);
    return (0);
}
