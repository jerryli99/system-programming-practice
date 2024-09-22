#include <stdio.h>

#define RECORD_BYTES 64L

int main(void) 
{
    FILE *fp;
    long int record_n = 100;

    //(a)
    fseek(fp, (record_n * RECORD_BYTES), SEEK_SET);

    //(b)
    fseek(fp, -RECORD_BYTES, SEEK_END);

    //(c)
    fseek(fp, RECORD_BYTES, SEEK_CUR);

    //(d)
    fseek(fp, 2 * (-RECORD_BYTES), SEEK_CUR);

    fclose(fp);

    return (0);
}