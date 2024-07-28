#include <stdio.h>

typedef struct complex Complex;

struct complex {
    double real;
    double imaginary;
};

struct complex make_complex(double real, double imaginary) {
    struct complex new_complex;
    new_complex.real = real;
    new_complex.imaginary = imaginary;

    return new_complex;
}

struct complex add_complex(struct complex struct1, struct complex struct2) {
    struct complex new_complex;
    new_complex.real = struct1.real + struct2.real;
    new_complex.imaginary = struct1.imaginary + struct2.imaginary;

    return new_complex;
}

int main() {

    Complex complex1;
    Complex complex2;
    Complex complex3;

    complex1 = make_complex(1.0, 2.0);
    complex2 = make_complex(3.0, 4.0);
    complex3 = add_complex(complex1, complex2);

    printf("%.2f %.2f\n", complex3.real, complex3.imaginary);

    return 0;
}