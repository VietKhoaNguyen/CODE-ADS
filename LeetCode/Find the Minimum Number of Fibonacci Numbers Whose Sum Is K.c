#include <stdio.h>
#include <stdlib.h>

// Function to find the minimum number of Fibonacci numbers that sum up to k
int findMinFibonacciNumbers(int k) {
    // Generate all Fibonacci numbers up to k
    int fib[50];  // Fibonacci numbers array, 50 is a safe upper bound for k <= 10^9
    fib[0] = 1;
    fib[1] = 2;
    
    int i = 2;
    while (fib[i - 1] <= k) {
        fib[i] = fib[i - 1] + fib[i - 2];  // Generate the next Fibonacci number
        i++;
    }

    int count = 0;
    // Greedily subtract the largest Fibonacci number from k
    while (k > 0) {
        // Find the largest Fibonacci number smaller than or equal to k
        int j = i - 1;
        while (fib[j] > k) {
            j--;
        }

        k -= fib[j];  // Subtract the Fibonacci number from k
        count++;       // Increment the count of Fibonacci numbers used
    }

    return count;  // Return the number of Fibonacci numbers used
}

int main() {
    int k = 10;
    printf("Minimum Fibonacci numbers that sum up to %d: %d\n", k, findMinFibonacciNumbers(k));  // Expected output: 2
    return 0;
}
/*recur O(log k)
#include <stdio.h>
#include <stdlib.h>

// Function to generate all Fibonacci numbers less than or equal to k
void generateFibonacci(int* fib, int* size, int k) {
    fib[0] = 1;
    fib[1] = 2;
    *size = 2;
    
    while (fib[*size - 1] <= k) {
        fib[*size] = fib[*size - 1] + fib[*size - 2];
        (*size)++;
    }
}

// Recursive function to find the minimum number of Fibonacci numbers that sum up to k
int findMinFibonacciNumbersRecursive(int k, int* fib, int size) {
    if (k == 0) {
        return 0;  // Base case: If k is 0, no Fibonacci numbers are needed
    }

    // Find the largest Fibonacci number smaller than or equal to k
    int i = size - 1;
    while (fib[i] > k) {
        i--;
    }

    // Subtract the Fibonacci number and call recursively for the remaining value
    return 1 + findMinFibonacciNumbersRecursive(k - fib[i], fib, size);
}

int findMinFibonacciNumbers(int k) {
    int fib[50];  // Fibonacci numbers array (50 is more than enough for k <= 10^9)
    int size;
    
    // Generate Fibonacci numbers up to k
    generateFibonacci(fib, &size, k);
    
    // Call the recursive function
    return findMinFibonacciNumbersRecursive(k, fib, size);
}

int main() {
    int k = 10;
    printf("Minimum Fibonacci numbers that sum up to %d: %d\n", k, findMinFibonacciNumbers(k));  // Expected output: 2
    return 0;
}
*/