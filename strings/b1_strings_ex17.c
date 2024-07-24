#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

bool test_extension(const char *file_name, 
                    const char *extension);


int main() {
    const char file_name[] = "memo.txt";
    const char extension[] = "TXT";
    printf("%s\n", test_extension(file_name, extension) ? "True" : "False");

    return 0;
}


bool test_extension(const char *file_name, 
                    const char *extension) {
    const char *filename_ptr = NULL;
    filename_ptr = file_name;

    while (*filename_ptr != '\0') {
        if (*filename_ptr == '.') {
            filename_ptr++;
            break;
        }
        filename_ptr++;
    }

    if (strlen(filename_ptr) != strlen(extension)) {
        return false;
    }

    while (*filename_ptr != '\0') {
        if (toupper(*filename_ptr++) != toupper(*extension++)) {
            return false;
        }
    }
    return true;
} 