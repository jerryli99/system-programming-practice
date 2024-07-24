#include <stdio.h>
#include <string.h>

//this is just sketching, no need to make it formal...

char digit_to_hex_char(int digit) {
    return "0123456789ABCDEF"[digit];
}


int main() {
    //the string literal "abc" is stored as an array of 4 characters a,b,c,\0
    //the empty string literal "" is stored as a single null character \0
    // char *p;
    // p = "abc";
    // printf("%c\n",*p); // output is a

    // char ch;
    // ch = "abc"[1]; //interesting but not used that often.
    // printf("%c\n", ch);

    // printf("%c\n", (digit_to_hex_char(10)));

    //string literals are stored as array of chars

    //This is equivelant to "June 14", the '\0' for this string literal will get added by the compiler
    char date1[8] = {'J', 'u', 'n', 'e', ' ', '1', '4', '\0'};// char array

    //This looks like: [J, u, n, e,  , 1, 4, \0, \0]
    char date2[9]= "June 15";

    //This looks like: [J, u, n, e,  , 1, 4]
    char data3[7] = "June 16"; //there is no room for '\0', so the compiler makes no attempt to store '\0'
    printf("%s\n", data3);//what will happen if i print this? June 16June 14
    //Uhm? Why is that? since we are using %s to print string, data3 has no '\0', so it will continue to loop for
    //'\0'. In this case of how the strings data1, data2, data3 are stored, it will print out Junw16 and then June 14, and then terminate. 

    char data4[8] = "June 17th, 2024";//if we exceed the length, compiler throws a warning array of chars too long
    printf("%s\n", data4);//output: June 17t 

    char data5[] = "June 18"; //the compiler will set 8 chars for data5 ('\0' included)

    // char str1[20];
    // char str2[20] = "June 19th, 2024";
    // strncpy(str1, str2, 20 - 1);
    // str1[20 - 1] = '\0';
    // printf("%s\n", str1);

    return 0;
}