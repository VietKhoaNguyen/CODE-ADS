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
/*recursive O(log n)
#include <stdio.h>
#include <math.h>

// Recursive function to convert the integral part to binary
void convertIntegralPart(int integralPart) {
    if (integralPart == 0) {
        return;
    }
    
    // Recursively call for the next digit
    convertIntegralPart(integralPart / 2);
    
    // Print the current digit
    printf("%d", integralPart % 2);
}

// Recursive function to convert the fractional part to binary
void convertFractionalPart(double fractionalPart, int precision, int count) {
    if (count >= precision) {
        return;
    }

    // Multiply the fractional part by 2
    fractionalPart *= 2;
    
    // Get the current binary digit (integer part of the result)
    int fractionalDigit = (int)fractionalPart;
    
    // Print the current binary digit
    printf("%d", fractionalDigit);

    // Recur for the next digit in the fractional part
    convertFractionalPart(fractionalPart - fractionalDigit, precision, count + 1);
}

// Function to convert decimal to binary with recursion
void decimalToBinary(double n, int k) {
    // Extract the integral part of the number
    int integralPart = (int)n;
    
    // Extract the fractional part of the number
    double fractionalPart = n - integralPart;

    // Handle the integral part
    if (integralPart == 0) {
        printf("0");
    } else {
        convertIntegralPart(integralPart);
    }

    // Handle the fractional part
    if (fractionalPart > 0) {
        printf(".");
        convertFractionalPart(fractionalPart, k, 0);
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
*/
