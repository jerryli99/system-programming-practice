#include <stdio.h>

typedef struct number_ {
    double real;
    double imaginary;
} Number;

int main() {

    Number num1 = {.real=0.0, .imaginary=1.0};
    Number num2 = {.real=1.0, .imaginary=0.0};
    Number num3;

    num2 = num1;
    printf("%.2f %.2f\n", num2.real, num2.imaginary);

    num3.real = num1.real + num2.real;
    num3.imaginary = num1.imaginary + num2.imaginary;
    printf("%.2f %.2f\n", num3.real, num3.imaginary);

    return (0);
}