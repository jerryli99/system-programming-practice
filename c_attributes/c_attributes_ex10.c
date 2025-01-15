//hot and cold
//these attributes help optimize functions that are frequently (hot) or rarely (cold) executed.

//haha, I have no idea we can do this stuff...
//TODO: what about inline? Uhmm..I know it is different, but which one can be better?

#include <stdio.h>

void hot_function() __attribute__((hot));
void cold_function() __attribute__((cold));

void hot_function()
{
    printf("This function is frequently called.\n");
}

void cold_function() 
{
    printf("This function is rarely called\n");
}


int main()
{
    hot_function();
    hot_function();
    hot_function();
    hot_function();
    hot_function();
    hot_function();
    cold_function();
    hot_function();
    hot_function();
    hot_function();

    return 0;
}

