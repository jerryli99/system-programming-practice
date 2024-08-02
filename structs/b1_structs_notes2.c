//topic is structure types in the book

//

#include <stdio.h>

#define NAME_LEN 10

struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part1;

struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part2;

struct {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} part3, part4;


struct part5 {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};


typedef struct part6 {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} Part6;




int main() {

    //part1 = part2; //syntax error a value of type "struct <unnamed>" cannot be assigned to an entity of type "struct <unnamed>"
    part3 = part4; //this is fine but bad style?

    struct part5 part5_var1 = {.number=528, .name="John", .on_hand=10}; //--> part5 is actually not a typename, so it will be meaningless without the struct keyword
    struct part5 part5_var2;
    part5_var2 = part5_var1; //copied
    printf("%d\n", part5_var2.number);

    //ok, fine...
    struct part6 part6_var1 = {.number=528, .name="John", .on_hand=10};
    Part6 part6_var2 = part6_var1;
    printf("%s\n", part6_var2.name);

    /*
    From part1 and 2, we can see that they don't have compatible types. Part1 is a variable but we don't have a name for the type of part1!!
    or part2!!, so we can't use them as arguments in function calls.

    To avoid the difficulties, we need to be able to define a name that represents a type of structure, not a particular structure variable.
    We can either declare a "structure tag" or use typedef to define a type name.

    See part5, it has a structure tag "part5".

    struct part5 {
        int number;
        char name[NAME_LEN + 1];
        int on_hand;
    } --> missing semicolumn here...

    f(void) {  ... return 0; } --> missing function return type...
    Interestingly, in the situation above, since the preceding structure declaration wasn't terminated properly, the compiler
    assumes that f returns a value of type struct part5. The error won't be detected until the compiler reaches the first return 
    in the function, resulting a weird error message.
    
    */
    return (0);
}