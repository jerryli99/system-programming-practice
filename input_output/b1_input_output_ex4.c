#include <stdio.h>


int main(void)
{
    printf("%#012.5g\n", 83.7361);
    printf("%#012.5g\n", 29748.6607);
    printf("%#012.5g\n", 1054932234.0);
    printf("%#012.5g\n", 0.000023218);

    return (0);
}

/*

00000083.736
00000029749.
001.0549e+09
002.3218e-05

*/