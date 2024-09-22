/*
The program is in book1 page 568, chapter 22.
The fcopy.c program has one minor flaw: it does not check for errors as it is
writing to the destination file. Errors during writing are rare, but do 
occasionally occur (the disk might become full, for example). Show how to add 
the missing error check to the program, assuming that we want it to display a 
message and terminate immediately if an error occurs.
*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *source_fp, *dest_fp;
    int ch;

    if (argc != 3) {
        fprintf(stderr, "usage: fcopy source dest\n");
        exit(EXIT_FAILURE);
    }

    source_fp = fopen(argv[1], "r");
    if (source_fp == NULL) {
        fprintf(stderr, "Cannot open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    dest_fp = fopen(argv[2], "w");
    if (dest_fp == NULL) {
        fprintf(stderr, "Cannot open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    while(ch = getc(source_fp) != EOF) {
        if (putc(ch, dest_fp) == EOF) {
            fprintf(stderr, "Error encountered during file write, terminate.\n");
            exit(EXIT_FAILURE);
        }
    }

    fclose(source_fp);
    fclose(dest_fp);

    return (0);
}

/*
 ./a.out ex10_test1.txt ex10_test2.txt 
 and it worked.
*/