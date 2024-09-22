#include <stdio.h>
//just quick test

int main()
{
    FILE *source_fp = stdin, *dest_fp = stdout;
    int ch;
    
    // while ((ch = getc(source_fp)) != EOF) 
    //     putc(ch, dest_fp);

    while (ch = getc(source_fp) != EOF)
        putc(ch, dest_fp);
    
    return (0);
}