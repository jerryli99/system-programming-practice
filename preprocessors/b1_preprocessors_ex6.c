#include <stdio.h>
#include <math.h>

#define DISP(func, num) (printf("%s(%g) = %g\n", (#func), (num), (func(num))))

#define DISP2(func, num1, num2) (printf("%s(%g,%g) = %g\n", (#func), (num1), (num2), (func((num1),(num2)))))

int main(void)
{
    DISP(sqrt, 1024.0);
    DISP2(pow, 32.0, 2.0);
    return 0;
}