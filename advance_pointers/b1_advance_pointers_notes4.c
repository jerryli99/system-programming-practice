/*
Copied from the book. 
*/

#include <math.h>
#include <stdio.h>

void tabulate(double (*f)(double), double first, double last, double incr);

int main(void) 
{
    double final, increment, initial;
    printf("Enter initial value: ");
    scanf("%lf", &initial);

    printf("Enter final value: ");
    scanf("%lf", &final);

    printf("Enter increment: ");
    scanf("%lf", &increment);

    printf("\n     x         cos(x)"
           "\n ---------   -------\n");
    tabulate(cos, initial, final, increment);

    printf("\n     x         sin(x)"
           "\n ---------   -------\n");
    tabulate(sin, initial, final, increment);

    printf("\n     x         tan(x)"
           "\n ---------   -------\n");
    tabulate(tan, initial, final, increment);




    return (0);
}


void tabulate(double (*f)(double), double first, double last, double incr)
{
    double x;
    int index, number_intervals;

    number_intervals = ceil((last - first) / incr);

    for (index = 0; index <= number_intervals; index++)
    {
        x = first + index * incr;
        printf("%10.5f %10.5f\n", x, (*f)(x));
    }
}

/*

an array of function pointers
void (*file_cmd[])(void) = 
{
    new_cmd, open_cmd, close_cmd, close_all_cmd, print_cmd, exit_cmd
}


int compare_parts(const void *p, const void *q)
{
    if ((struct part *) p)->number < 
        ((struct part *) q)->number)
        return -1;
    else if ((struct part *) p)->number ==
             ((struct part *) q)->number)
        return 0;
    else
        return 1;
}


*/