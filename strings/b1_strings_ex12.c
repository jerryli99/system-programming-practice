#include <stdio.h>
#include <string.h>

#define FILE_EXTENSION_MAX_LEN 100 

void get_extension(const char *file_name, char *extension);

int main() {

    char filename[] = "memo.txt";
    char extension[FILE_EXTENSION_MAX_LEN];
    get_extension(filename, extension);
    printf("%s, %s\n", filename, extension);
    return 0;
}

/**
 * @brief Store the input file extension in the variable extension.
 * 
 * @param file_name A pointer to constant char
 * @param extension A pointer to char
 * 
 * @return Return void 
 */
void get_extension(const char *file_name, char *extension) {
    const char *filename_ptr = file_name;

    while (*filename_ptr != '\0') {
        if (*filename_ptr == '.') {
            //skip the '.' here to get only the txt, for example.
            strcpy(extension, filename_ptr + 1); 
            return;
        }

        filename_ptr++;
    }

    strcpy(extension, "");
    return;
}