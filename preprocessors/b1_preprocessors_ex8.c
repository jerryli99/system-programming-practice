#include <stdio.h>

/* Macro to stringize the values of the macro __LINE__ */
#define STRINGIZE(value) #value
#define EXPAND_TO_STRING(value) STRINGIZE(value)
#define LINE_FILE ("Line " EXPAND_TO_STRING(__LINE__) " of file " __FILE__)

int main(void)
{
    const char *str = LINE_FILE;
    printf("%s\n", str);
}