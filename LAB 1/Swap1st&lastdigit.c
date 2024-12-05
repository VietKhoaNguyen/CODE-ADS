#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Write a pseudocode and implement a program in C to swap the first and last digits of a positive integer
void Swap(int *n){                                      //Complexity: O(1)
    int digit = log10(*n);
    int first = *n / pow(10,digit);
    int last = *n % 10;

    *n = *n % (int) pow(10,digit); 
    *n = *n / 10;
    *n = last * pow(10,digit) + *n * 10 + first;
}

int main(){
    int number;
    printf("The number:\n",number);
    scanf("%d", &number);

    Swap(&number);
    printf("After swap first and last digit, the number become:\n%d", number);
    
    return 0;
}

// Pseudo Code: //

// Start function Swap
//    Input: n (integer)
//    digit = log10(n)
//    first = n / (10^digit)
//    last = n % 10
    
//    n = n % (10^digit)
//    n = n / 10
//    n = last * (10^digit) + n * 10 + first
// End function

// Start function main
//    number: (integer)
//    Output: Swapped number
    
//    Display "The number:"
//    Input number
    
//    Call Swap with number
//    Display "After swap first and last digit, the number become:" + number
// End function