/*
dynamic storage allocation means:
the ability to allocate sotrage during program execution.
It is used most often for strings, arrays, and structures.

in the header <stdlib.h>
malloc -- allocates a block of memory but doesn't initialize it.
calloc -- allocates a block of memory and clears it.
realloc -- resizes a previously allocated block of memory.

malloc is most used, and it is more efficient than calloc, since it doesn't have to
clear the memory block that it allocates.

When we call a memory allocation function to request a block of memory, the 
function has no idea what type of data we're planning to store in the block,
so it can't return a pointer to an ordinary type such as int or char. Instead,
the function returns a value of type void*. A void* value is a "generic" pointer --
essentially, just a memory address.

When a memory allocation function is called, there's always a possibility that it 
won't be able to locate a block of memory large enough to satisfy our request.
If that should happen, the function will return a null pointer. A null pointer is
a "pointer to nothing" -- a special value that an be distinguished from all valid
pointers. After we've stored the function's return value in a pointer variable, we must test
to see if it's a null pointer.

void *malloc(size_t size);


 */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_str_concat(const char *str1, const char *str2) {
    char *result;

    result = (char*) malloc(strlen(str1) + strlen(str2) + 1);
    if (result == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }

    strcpy(result, str1);
    strcat(result, str2);

    return result;
}


int main() {
    char *var1 = "Hello";
    char *var2 = " World!";
    char *result = my_str_concat(var1, var2);
    
    printf("%s\n", result);

    free(result);

    return 0;
}