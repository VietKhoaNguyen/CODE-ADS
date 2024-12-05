#include <stdio.h>
/*Given a positive natural number N = 3450, we would like to study numbers by:
- Count the number of odd, even digits of N. Note that 0 is even.
Example:
- The number of odd digits of N = 3450 is 2 with odd digits = {3, 5};
- The number of even digits of N = 3450 is 2 with even digits = {4, 0}.
Propose only one pseudo-code function to count the number of odd and even digits of N. (2
pts)
 Implement the proposed function (only one function) that returns the number of odd and even
digits at the same time using Pass-by-Reference in C/C++
*/
// Function to count odd and even digits
void countOddEvenDigits(int N, int* oddCount, int* evenCount) {
    if (N == 0) return;  // Base case

    int lastDigit = N % 10;  // Get the last digit
    if (lastDigit % 2 != 0) {
        (*oddCount)++;  // Increment odd count
    } else {
        (*evenCount)++;  // Increment even count
    }
    
    countOddEvenDigits(N / 10, oddCount, evenCount);  // Recursive call
}

int main() {
    int N = 3450;
    int oddCount = 0;
    int evenCount = 0;

    // Call the function to count odd and even digits
    countOddEvenDigits(N, &oddCount, &evenCount);

    // Output the results
    printf("Number of odd digits: %d\n", oddCount);
    printf("Number of even digits: %d\n", evenCount);

    return 0;
}
/*function countOddEvenDigits(N, oddCount, evenCount):
    if N == 0:
        return
    lastDigit = N % 10
    if lastDigit is odd:
        oddCount = oddCount + 1
    else:
        evenCount = evenCount + 1
    countOddEvenDigits(N // 10, oddCount, evenCount)  // Recursive call with updated counts
*/