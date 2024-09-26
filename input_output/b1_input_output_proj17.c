/*
Write a program that reads a series of phone numbers from a file and displays 
them in a standard format. Each line of the file will contain a single phone 
number, but the numbers may be in a variety of formats. You may assume that
each line contains 10 digits, possibly mixed with other characters (which should
be ignored). For example, suppose that the file contains the following lines:

404.817.6900
(215) 686-1776
312-746-6000
877 275 5273
6173434200

output should be:
(404) 817-6900
(215) 686-1776
(312) 746-6000
(877) 275-5273
(617) 343-4200

*/

#include <stdio.h>

#define MAX_LINE_CHARS 1024
#define DIGIT_COUNT 10

int my_isdigit(char ch) 
{
    if (((ch >= '0') && (ch <= '9')) == 1) {
        return (0); //ok
    }
    return (-1);
}

int main(int argc, char*argv[])
{
    char line[MAX_LINE_CHARS]; //to hold each line from the file.
    int digits[DIGIT_COUNT]; // array to hold the 10 digits.
    int line_index, digit_index; 
    FILE *fp = NULL;


    if (argc != 2) 
    {
        fprintf(stderr, "Usage: ./a.out <input_file>\n");
        return (-1);
    }

    fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        fprintf(stderr, "Failed to open file.\n");
        return (-1);
    }

    while (fgets(line, sizeof(line), fp) != NULL) 
    {
        digit_index = 0;

        for (line_index = 0; line[line_index] != '\0'; line_index++) 
        {
            //implied here: if less than 10 digits per line, ignore line.
            if ((my_isdigit(line[line_index]) == 0) && 
                (digit_index < DIGIT_COUNT)) 
            {
                digits[digit_index++] = line[line_index] - '0';//char to int
            } 
        }

        //since the task is to only print out the correct format,
        //I will not store phone numbers in a struct because if for some
        //areas, the phone number is still 10 digits but have different format
        //to store area code in 2 digits and not 3 for whatever reason, I will 
        //have to change all the code. 
        //Thus, I come to a conclusion that this is the most straight forward
        //way of doing this problem.
        if (digit_index == 10) 
        {
            printf("(%d%d%d) %d%d%d-%d%d%d%d\n", 
            digits[0], digits[1], digits[2],
            digits[3], digits[4], digits[5],
            digits[6], digits[7], digits[8], digits[9]);
        }
    }

    fclose(fp);

    return (0);
}

/*
output results:
(404) 817-6900
(215) 686-1776
(312) 746-6000
(877) 275-5273
(617) 343-4200
*/