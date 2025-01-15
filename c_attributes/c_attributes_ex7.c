//visibility
//control the visibility of a function
#include <stdio.h>

void __attribute__((visibility("hidden"))) hidden_function() {
    printf("This function is hidden from external linkage\n");
}

int main() {
    hidden_function();  // Accessible within the program but not from outside
    return 0;
}
//In a shared library, this function would not be accessible externally, as it's marked as "hidden."
//Primarily used in shared library development to control the interface exposed to 
//other components and minimize symbol collisions.

/*

Difference between static and the visibility attribute?

// file1.c
static int x = 10; // x is only accessible within file1.c

int y = 20; // y is accessible from other files

__attribute__((visibility("hidden"))) int z = 30; // z is only accessible within the shared library

Hidden visibility indicates that the symbol will not be placed into the dynamic symbol 
table, so no other "module" (executable or shared library) can reference it directly.

TODO: explore more,  https://www.quora.com/How-exactly-does-static-limits-function-visibility-in-C
#include <stdio.h> 
 
// You can't call this directly from outside. 
static void hidden_callback(void) { 
  puts("I am in the hidden function!"); 
} 
 
typedef void callback_fxn(void); 
 
// This passes a pointer to the hidden callback 
// so it can be invoked indirectly via the pointer. 
callback_fxn *get_callback(void) { 
  return hidden_callback; 
} 
*/