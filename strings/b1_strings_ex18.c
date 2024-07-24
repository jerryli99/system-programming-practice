#include <stdio.h>

void remove_filename(char *url_str);

int main() {

    char url[] = "http://www.knking.com/index.html";
    printf("URL: %s\n", url);
    remove_filename(url);
    printf( "%s\n", url);

    return 0;
}

/**
 * @brief url_str points to a string containing a URL that ends with a file name, such as
 *        "http://www.knkting.com/index.html". The function should modify the url_str and 
 *        return "http://www.knkting.com"
 * 
 * @param url_str A pointer to char
 * 
 * @return Return void
 */
void remove_filename(char *url_str) {
    char *str_ptr = NULL;
    str_ptr = url_str;

    //first, go to the end of the str.
    while (*str_ptr++ != '\0');
    
    //then reverse back until encounter the first slash
    while (*str_ptr-- != '/');
    
    //we are now pointing to the left side of '/', so the 'm' in .com/ 
    //set null terminator then we are done.
    *++str_ptr = '\0';

    return;
} 