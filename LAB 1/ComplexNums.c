#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//Write a structure to represent complex numbers and complete operators: add and multiply.
struct complex{
    float real; 
    float imagin;
};

int main(){
    
    struct complex a, b, value_add, value_mul;
    // a present the numbers in the first complex number. (both real & imaginary part)
    // b present the numbers in the second complex number. (both real & imaginary part)
    // value_add is the result of the addition of 2 complex numbers. 
    // value_mul is the result of the multiplication of 2 complex numbers. 
    printf("The first complex number:\n");
    scanf("%f %f", &a.real, &a.imagin);
    printf("The second complex number:\n");
    scanf("%f %f", &b.real, &b.imagin);

    value_add.real  = a.real + b.real;
    value_add.imagin = a.imagin + b.imagin;

    value_mul.real  = a.real * b.real - a.imagin * b.imagin;
    value_mul.imagin = a.real * b.imagin + b.real * a.imagin;

    printf("The addition of 2 complex numbers: %0.2f +  %0.2fi\n", value_add.real, value_add.imagin);
    printf("The multiplication of 2 complex numbers: %0.2f +  %0.2fi", value_mul.real, value_mul.imagin);

    return 0;
}