#include <stdio.h>

// Simulating the guess API for demonstration purposes
// Replace this with the actual implementation of the API
int pickedNumber = 6; // Example picked number for testing
int guess(int num) {
    if (num > pickedNumber) return -1;
    if (num < pickedNumber) return 1;
    return 0;
}

int guessNumber(int n) {
    int left = 1, right = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int result = guess(mid);
        
        if (result == 0) {
            return mid; // Found the correct number
        } else if (result == -1) {
            right = mid - 1; // Guess is too high
        } else {
            left = mid + 1; // Guess is too low
        }
    }
    return -1; // This should never be reached if the input is valid
}

int main() {
    int n = 10; // The range of numbers [1, n]
    int result = guessNumber(n);
    printf("The picked number is %d\n", result);
    return 0;
}
