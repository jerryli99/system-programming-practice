//constructor and detructor
//constructor runs before main() and destructor runs after the program terminates
#include <stdio.h>
#include <stdlib.h>

void init() __attribute__((constructor));
void cleanup() __attribute__((destructor));

void init()
{
    printf("Initialization function before main\n");
}

void cleanup()
{
    printf("Cleanup function after main\n");
}

int main()
{
    printf("Main function \n");
    return 0;
}
