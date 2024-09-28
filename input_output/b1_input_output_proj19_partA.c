/*
Write a prpogram that converts a Windows text file to a UNIX text file.
*/

#include <stdio.h>
#include <stdlib.h>

void windows_to_unix_file(char *input_file, char *output_file)
{
    FILE *input_fp, *output_fp;
    int ch;
    if ((input_fp = fopen(input_file, "rb")) == NULL) 
    {
        fprintf(stderr, "Cannot open input file %s.\n", input_file);
        exit(EXIT_FAILURE);
    }
    
    if ((output_fp = fopen(output_file, "wb")) == NULL) 
    {
        fprintf(stderr, "Cannot open output file %s.\n", output_file);
        exit(EXIT_FAILURE);
    }

    while ((ch = fgetc(input_fp)) != EOF) 
    {
        if (ch == '\x0d') 
        {
            fputc('\x0a', output_fp);
        } 
        else if (ch != '\x0a') 
        {
            fputc(ch, output_fp);
        }
    }

    fclose(input_fp);
    fclose(output_fp);
}


int main(int argc, char *argv[])
{
    if (argc != 3) 
    {
        fprintf(stderr, "Usage: programname inputfile outputfile.\n");
        exit(EXIT_FAILURE);
    }
    windows_to_unix_file(argv[1], argv[2]);

    return 0;
}