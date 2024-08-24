//gcc file_scope_test1.c file_scope_test2.c -o test

#include <stdio.h>

// File-scope variables
int global_var = 10;         // External linkage (can be accessed in other files)

static int static_var = 20;  // Internal linkage (only accessible within this file)

void print_vars() {
    printf("In file_scope_test1.c - global_var: %d\n", global_var);
    printf("In file_scope_test1.c - static_var: %d\n", static_var);
}

void modify_vars_in_file1() {
    global_var += 5;
    static_var += 5;
}

// Forward declaration of the function in file2.c
extern void modify_var_in_file2();


//Either of these 2 can work because their scope belongs to file_scope_test2.c,
//hence no way to access them in file_scope_test1.c
//static void modify_var_in_file2_1();//
//void modify_var_in_file2_1();//


int main() {

    print_vars();
    
    modify_vars_in_file1();

    printf("Variables after modification in file_scope_test1.c\n");
    
    print_vars();

    // Call the function in file2.c
    modify_var_in_file2();

    //modify_var_in_file2_1();//there is no way this will even execute...
    
    printf("In file_scope_test1.c after file_scope_test2.c modification - global_var: %d\n", global_var);

    return 0;
}


/*

result:
In file_scope_test1.c - global_var: 10
In file_scope_test2.c - static_var: 20
In file_scope_test1.c - global_var: 15
In file_scope_test2.c - static_var: 25
In file_scope_test1.c - global_var after file_scope_test2.c modification: 35

*/