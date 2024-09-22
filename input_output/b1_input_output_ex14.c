#include <stdio.h>

#define MAX_LEN 1024

/**
 * @brief read characters until it reaches the first new-line character or
 * sizeof(str) - 1 characters have been read, whichever happens first. In
 * this implementation, my_fgets will not add the '\n' at the end.
 * 
 * @param str a char pointer with restrict type qualifier.
 * @param num_bytes an integer.
 * @param stream a FILE pointer with restrict type qualifier.
 * 
 * @return return a null pointer if a read error occurs or they reach 
 *         the end of the input stream before storing. 
 */
char *my_fgets(char * restrict str, int num_bytes, FILE * restrict stream)
{
    int ch;
    int char_count = 0;

    if ((str == NULL) || (num_bytes <= 0) || (stream == NULL)) {
        return (NULL);
    }

    while ((char_count < (num_bytes - 1)) && ((ch = getc(stream)) != EOF)) {
        str[char_count++] = ch;
        if (ch == '\n') {
            break;
        }
    }
    str[char_count] = '\0';

    if ((char_count == 0) && (ch == EOF)) {
        return (NULL);
    }

    return (str);
}

/**
 * @brief write a string of characters to the user specified stream.
 * 
 * @param str a constant char with restrict type qualifier.
 * @param stream a FILE pointer with restrict type qualifier.
 * 
 * @return return EOF if error encountered, and 0 when everything works fine.
 */
int my_fputs(const char * restrict str, FILE * restrict stream)
{
    if ((str == NULL) || (stream == NULL)) {
        return (EOF);
    }

    while (*str != '\0') {
        if (putc(*str++, stream) == EOF) {
            return (EOF);
        }
    }

    return (0);
}

int main()
{
    char *filename = "ex14_test.txt";
    char buffer[MAX_LEN];
    FILE *fp = fopen(filename, "r+");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    if (my_fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("Read: %s\n", buffer);
    } else {
        printf("Error reading file or EOF encountered.\n");
    }

    if (my_fputs("Hello, World\n", fp) == EOF) {
        printf("Error writing to file.\n");
    } else {
        printf("Successfully wrote to file.\n");
    }

    fclose(fp);

    return (0);
}