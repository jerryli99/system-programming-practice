#include <stdio.h>
#include <string.h>

//Google tells me the max url length is 1024
#define MAX_URL_LEN 1024

void build_index_url(const char *domain, char *index_url);

int main() {
    const char domain[] = "knking.com";
    char index_url[MAX_URL_LEN];
    build_index_url(domain, index_url);
    printf("Domain: %s, index_url: %s\n", domain, index_url);
    
    return 0;
}


/**
 * @brief domain points to a string containing an internet domain, such as "knking.com". 
 *        The function should add "http://www." to the beginning of the domain string and
 *        "/index.html" to the end of the string, storing the result of the string pointed to
 *        by index_url.
 * 
 * @param domain A pointer to constant char
 * @param index_url A pointer to char
 * 
 * @return Return void
 */
void build_index_url(const char *domain, char *index_url) {
    strcpy(index_url, "http://www.");
    strcat(index_url, domain);
    strcat(index_url, "/index.html");
    return;
}