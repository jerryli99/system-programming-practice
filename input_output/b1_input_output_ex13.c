#include <stdio.h>
/**
 * @brief count the number of character of the line in the text file
 * @param filename a constant char pointer
 * @param target_line an integer
 * 
 * @return the number of chars in a line from start to '\n' at the user 
 * specified line number
 */
int line_length(const char *filename, int target_line)
{
    FILE *fp = NULL;
    int length = 0;
    int line_count = 1;
    int ch;

    if ((fp = fopen(filename, "r")) == NULL) {
        return (0);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (line_count == target_line) {
            if (ch == '\n') {
                break; //finished counting so exit loop
            }
            length++; //count chars of the line
        } 
        
        if (ch == '\n') { //keep looping chars until we get to the next line
            line_count++;
        }
    }

    fclose(fp);

    return (length);
}

int main() 
{
    printf("In the file %s, line %d, there are %d characters\n", 
    "ex13_test.txt", 
    2, 
    line_length("ex13_test.txt", 2));
    
    return (0);
}