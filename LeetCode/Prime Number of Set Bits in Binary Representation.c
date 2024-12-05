#include <stdio.h>
#include <stdbool.h>

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true; // 2 is prime
    if (num % 2 == 0) return false; // No even number greater than 2 is prime
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Helper function to count the number of set bits in the binary representation of a number
int countSetBits(int num) {
    int count = 0;
    while (num) {
        count += num & 1; // Increment count if the least significant bit is 1
        num >>= 1; // Right shift the number
    }
    return count;
}

// Function to count how many numbers in the range [left, right] have a prime number of set bits
int countPrimeSetBits(int left, int right) {
    int result = 0;
    
    // Iterate through all numbers in the range [left, right]
    for (int i = left; i <= right; i++) {
        int setBits = countSetBits(i); // Count the number of set bits
        if (isPrime(setBits)) { // Check if the count is prime
            result++; // Increment the result if it's prime
        }
    }
    
    return result;
}

int main() {
    int left = 10, right = 15;
    printf("Count of numbers with prime set bits in range [%d, %d]: %d\n", left, right, countPrimeSetBits(left, right));
    return 0;
}
/*recur O((right−left)⋅logn+(right−left)*sqrt(n))
#include <stdio.h>
#include <stdbool.h>

// Helper function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) return false;
    if (num == 2) return true; // 2 is prime
    if (num % 2 == 0) return false; // No even number greater than 2 is prime
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

// Helper function to count the number of set bits in the binary representation of a number recursively
int countSetBits(int num) {
    // Base case: when num is 0, no set bits left
    if (num == 0) return 0;
    // Recursive case: count the current set bit + count the remaining set bits
    return (num & 1) + countSetBits(num >> 1); // num & 1 checks if the least significant bit is 1
}

// Recursive function to count the numbers with prime set bits in the range [left, right]
int countPrimeSetBitsRecursive(int left, int right, int count) {
    // Base case: when left exceeds right, return the current count
    if (left > right) {
        return count;
    }
    
    // Count the number of set bits in the current number
    int setBits = countSetBits(left);
    
    // Check if the number of set bits is prime
    if (isPrime(setBits)) {
        count++;
    }
    
    // Recur for the next number
    return countPrimeSetBitsRecursive(left + 1, right, count);
}

// Wrapper function to initiate the recursion and pass initial parameters
int countPrimeSetBits(int left, int right) {
    return countPrimeSetBitsRecursive(left, right, 0);
}

int main() {
    int left = 10, right = 15;
    printf("Count of numbers with prime set bits in range [%d, %d]: %d\n", left, right, countPrimeSetBits(left, right));
    return 0;
}
*/