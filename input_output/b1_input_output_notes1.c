#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *file_ptr = NULL;

    if (argc != 2)
    {
        printf("Usage: no filename.\n");
        exit(EXIT_FAILURE);
    }

    if ((file_ptr = fopen(argv[1], "r")) == NULL)
    {
        printf("%s can't be opened\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("%s can be opened\n", argv[1]);
    fclose(file_ptr);
    file_ptr = NULL;

    // FILE *tempfile_ptr = NULL;
    // tempfile_ptr = tmpfile();
    // if (tempfile_ptr == NULL)
    // {
    //     printf("Failed to create tmp file");
    //     exit(EXIT_FAILURE);
    // }
    
    return (0);
}


// #define FILE_NAME "README.md"

// int main(void)
// {
//     FILE *file_ptr = NULL;

//     file_ptr = fopen(FILE_NAME, "r");
//     if (file_ptr == NULL)
//     {
//         printf("Cannot open %s\n", FILE_NAME);
//         exit(EXIT_FAILURE);
//     }

//     fclose(file_ptr);
//     file_ptr = NULL;

//     return (0);
// }