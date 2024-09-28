/*
Write a program that reads integers from a text file whose name is given as a
command line argument. Each line fo the file may contain any number of integers
(including none) separated by one or more spaces. Have the program display the 
largest number in the file, the smallest number, and the median (the number 
closest to the middle if the integers were sorted). If the file contains an
even number of integers, there will be two numbers in the middle; the program
should display their average (rounded down). 

You may assume that the file contains no mroe than 10,000 integers. 
Hint: store the integers in an array and then sort the array.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMS 10000

// Comparison function for qsort, safer than subtracting to avoid overflow
int compare_integers(const void *a, const void *b) 
{
    int num1 = *(const int *)a;
    int num2 = *(const int *)b;
    
    if (num1 < num2)
    {
        return (-1);
    }
    else if (num1 > num2)
    {
        return (1);
    }
    else
    {    
        return (0);
    }
}

int main(int argc, char *argv[]) {
    FILE *fp;
    int index = 0, number;
    int numbers[MAX_NUMS];
    float median;
    
    // Check for proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s inputfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open file and check for errors
    if ((fp = fopen(argv[1], "r")) == NULL) {
        fprintf(stderr, "Cannot open file %s.\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read integers from file and store them in the array
    while ((index < MAX_NUMS) && (fscanf(fp, "%d", &number) == 1)) {
        numbers[index++] = number;
        printf("%d, ", number);
    }

    putchar('\n');

    fclose(fp);

    // Check if we read any numbers
    if (index == 0) {
        printf("The file contains no valid integers.\n");
        exit(EXIT_SUCCESS);
    }

    // Sort the numbers
    qsort(numbers, index, sizeof(int), compare_integers);

    // Calculate the median
    if (index % 2 == 0) {
        median = (numbers[index / 2 - 1] + numbers[index / 2]) / 2.0f;
    } else {
        median = (float)numbers[index / 2];
    }

    // Print the results
    printf("Smallest: %d\n", numbers[0]);
    printf("Largest: %d\n", numbers[index - 1]);
    printf("Median: %.1f\n", median);

    return (0);
}