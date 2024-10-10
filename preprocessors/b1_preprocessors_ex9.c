#include <stdio.h>

#define CHECK(x_val, y_val, n_val) (((x_val) >= 0 && (x_val) <= ((n_val)-1)) && ((y_val) >= 0 && (y_val) <= ((n_val)-1)))
#define MEDIAN(x_val, y_val, z_val) (((x_val) - (y_val)) * ((z_val) - (x_val)) >= 0 ? x_val : ((y_val) - (x_val)) * ((z_val) - (y_val)) >= 0 ? y_val : z_val)
#define POLYNOMIAL(x_val) ((3 * ((x_val) * (x_val) * (x_val) * (x_val) * (x_val)))  \
                           +(2 * ((x_val) * (x_val) * (x_val) * (x_val)))           \
                           -(5 * ((x_val) * (x_val) * (x_val)))                     \
                           -((x_val) * (x_val)) + (7 * (x_val)) - 6)

int main(void)
{
    int x_val, y_val, z_val, n_val;
    x_val = 2; 
    y_val = 4; 
    z_val = 3;
    n_val = 20;

    printf("CHECK(%d, %d, %d) = %d\n", x_val, y_val, n_val, CHECK(x_val, y_val, n_val));
    printf("MEDIAN(%d, %d, %d) = %d\n", x_val, y_val, z_val, MEDIAN(x_val, y_val, z_val));
    printf("POLYNOMIAL(%d) = %d\n", x_val + 1, POLYNOMIAL(x_val + 1));
}