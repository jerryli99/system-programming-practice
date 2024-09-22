/*
Write a program that converts all letters in a file to upper case. 
(Characters other than letters should not be changed.) The program should obtain
the file name from the command line and write its output to stdout.
*/

#include <stdio.h>
#include <stdlib.h>

int toupper(int ch) 
{
    if ((ch >= 'a') && (ch <= 'z')) {
        return (ch - 'a' + 'A');
    }
    return ch;
}

int main(void)
{
    FILE *fp;
    int ch;

    fp = fopen("proj2_test.txt", "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file\n");
        exit(EXIT_FAILURE);
    }

    while ((ch = getc(fp)) != EOF) {
        putchar(toupper(ch));
    }

    fclose(fp);

    return (0);
}