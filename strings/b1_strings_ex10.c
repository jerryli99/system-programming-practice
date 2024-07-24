#include <stdio.h>
#include <string.h>

//ignore the style here. Just to quickly test the concept...
char *duplicate(const char *p)
{
    char *q = "";

    strcpy(q, p);

    return q;
}

int main() {

    printf("%s\n", duplicate("abcdefgH"));

    return 0;
}