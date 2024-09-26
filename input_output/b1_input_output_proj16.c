/*
Modify the fcopy.c program of Section 22.4 so that it uses fread and fwrite to 
copy the file in blocks of 512 bytes. (The block may contain fewer than 
512 bytes, of course.)
*/

#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 512

int main(int argc, char *argv[]) 
{
    FILE *source_fp, *dest_fp;
    char buffer[BUFFER_SIZE];
    size_t bytes_read, bytes_written;

    if (argc != 3) 
    {
        fprintf(stderr, "Usage: %s <source> <destination>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    source_fp = fopen(argv[1], "rb");
    if (source_fp == NULL) 
    {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "wb");
    if (dest_fp == NULL) 
    {
        perror("Error opening destination file");
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }

    // Copy file content in blocks of BUFFER_SIZE
    while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, source_fp)) > 0) 
    {
        bytes_written = fwrite(buffer, 1, bytes_read, dest_fp);
        if (bytes_written < bytes_read) 
        {
            perror("Error writing to destination file");
            fclose(source_fp);
            fclose(dest_fp);
            exit(EXIT_FAILURE);
        }
    }

    // Check for reading error after the loop
    if (ferror(source_fp)) 
    {
        perror("Error reading source file");
        fclose(source_fp);
        fclose(dest_fp);
        exit(EXIT_FAILURE);
    }

    fclose(source_fp);
    fclose(dest_fp);

    return (0);
}
