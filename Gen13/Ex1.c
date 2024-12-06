/*The image you provided outlines a problem involving the verification of whether numbers in a given array are pentagonal numbers. The pentagonal number is defined by the formula:
 f(n) = 3n^2 - n/2
Additionally, the task requires:
- Writing pseudo-code using recursion (or iteration) to check if all values in the given array are pentagonal numbers.
- Writing a program in C/C++ to implement the algorithm.
- Calculating and justifying the time complexity of the algorithm.*/
#include <stdio.h>
#include <stdbool.h>
// O(n)
// Function to check if a number is pentagonal
bool isPentagonal(int num, int n) {
    // Calculate the nth pentagonal number
    int pentagonal = (3 * n * n - n) / 2;

    // Base case: if pentagonal number matches num, return true
    if (pentagonal == num) {
        return true;
    }
    // If pentagonal number exceeds num, return false
    if (pentagonal > num) {
        return false;
    }
    // Recursive call to check the next pentagonal number
    return isPentagonal(num, n + 1);
}

// Function to check if all numbers in the array are pentagonal
void checkPentagonalArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (isPentagonal(arr[i], 1)) {
            printf("%d is a pentagonal number.\n", arr[i]);
        } else {
            printf("%d is NOT a pentagonal number.\n", arr[i]);
        }
    }
}

int main() {
    // Example array of numbers to check
    int arr[] = {1, 5, 12, 22, 35};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Check if all values in the array are pentagonal
    checkPentagonalArray(arr, size);

    return 0;
}
