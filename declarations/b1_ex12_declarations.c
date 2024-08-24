//ignore style, just a quick test here

#include <stdio.h>

// Function definitions
float float_function(long x) {
    return (float)x / 2.0;
}

int int_function(double x) {
    return (int)(x * 2);
}

// Function f that returns a pointer to int_function
int (*f(float (*func)(long), char *str))(double) {
    printf("Received string: %s\n", str);
    return int_function; // Return a pointer to int_function
}

int main() {
    // Call f with float_function and a string, and receive a function pointer
    int (*returned_function)(double) = f(float_function, "Hello, World!");

    // Now, we can use the returned function pointer to call int_function
    int result = returned_function(4.5);
    printf("Result: %d\n", result); // This should print "Result: 9"

    return 0;
}


/*
Received string: Hello, World!
Result: 9

*/