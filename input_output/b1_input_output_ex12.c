#include <stdio.h>

int count_periods(const char *filename) 
{
    FILE *fp;
    int count = 0;
    if ((fp = fopen(filename, "r")) != NULL) {
        while (fgetc(fp) != EOF) {
            if (fgetc(fp) == '.') {
                count++;
            }
        }
        fclose(fp);
    }
    return (count);
}

int count_periods_fixed(const char *filename) 
{
    FILE *fp;
    int count = 0;
    int ch;
    if ((fp = fopen(filename, "r")) != NULL) {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '.') {
                count++;
            }
        }
        fclose(fp);
    }
    return (count);
}


int main()
{
    printf("Answer should be 6.\n");
    printf("%d\n", count_periods("ex12_test.txt")); //got 4
    printf("%d\n", count_periods_fixed("ex12_test.txt")); //got 6

    return (0);
}