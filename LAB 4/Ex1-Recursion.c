/* Calculate the digit sum of a given natural number that can be used in detecting errors
in message transmission or data storage.*/
#include <stdio.h>
//  Digit sum using Recursion                  // Complexity: O(log(n))

int Digit_sum_Recursion(int num) {
    if (num == 0)
        return 0;
    return (num % 10) + Digit_sum_Recursion(num / 10);
}

int main() {
    int number;
    printf("Enter a natural number: ");
    scanf("%d", &number);
    int result = Digit_sum_Recursion(number);
    printf("Digit sum Recursion of %d: %d\n", number, result);
    return 0;
}
//Pseudo Code:

//Function Digit_sum_Recursion(num):
//Input: num (integer)
//If num == 0, return 0
//Else, return num % 10 + Digit_sum_Recursion(num // 10)

//Main Function:
//Declare number
//Display "Enter a natural number"
//Input number
//Call Digit_sum_Recursion(number) and store the result in result
//Display "Digit sum Recursion of", number, ":", result

//End