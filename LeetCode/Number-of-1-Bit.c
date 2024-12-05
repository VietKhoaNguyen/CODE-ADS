#include <stdint.h>
#include <stdio.h>

int hammingWeight(int n) {
    int count = 0;
    while (n) {
        count += n & 1;  // Increment count if the least significant bit is 1
        n >>= 1;          // Right-shift n to check the next bit
    }
    return count;
}

// Example usage
int main() {
    int n = 29;  // Example input: binary representation of 29 is 11101
    printf("Hamming weight of %d is %d\n", n, hammingWeight(n));  // Output: 4
    return 0;
}
