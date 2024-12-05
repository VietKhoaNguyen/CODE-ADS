#include <stdio.h>
#include <math.h>

void convertIntegralPart(int integralPart) {
    // Array to store the binary digits
    int binary[32];
    int i = 0;
    
    // Special case: when the integral part is 0
    if (integralPart == 0) {
        printf("0");
        return;
    }

    // Convert the integral part to binary
    while (integralPart > 0) {
        binary[i] = integralPart % 2;
        integralPart = integralPart / 2;
        i++;
    }

    // Print the binary digits in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

void convertFractionalPart(double fractionalPart, int precision) {
    printf(".");

    // Convert the fractional part to binary up to the given precision
    for (int i = 0; i < precision; i++) {
        fractionalPart *= 2;
        int fractionalDigit = (int)fractionalPart;
        printf("%d", fractionalDigit);
        fractionalPart -= fractionalDigit;
    }
}

void decimalToBinary(double n, int k) {
    // Extract the integral part of the number
    int integralPart = (int)n;
    
    // Extract the fractional part of the number
    double fractionalPart = n - integralPart;

    // Convert and print the integral part
    convertIntegralPart(integralPart);

    // Convert and print the fractional part up to k precision
    if (fractionalPart > 0) {
        convertFractionalPart(fractionalPart, k);
    }
}

int main() {
    double n;
    int k;

    // Input the decimal number and precision
    printf("Enter a decimal number: ");
    scanf("%lf", &n);
    printf("Enter the precision after the decimal point: ");
    scanf("%d", &k);

    // Call the function to convert decimal to binary
    printf("Binary representation: ");
    decimalToBinary(n, k);
    printf("\n");

    return 0;
}
    