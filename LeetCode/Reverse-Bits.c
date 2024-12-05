#include <stdint.h>
#include <stdio.h>

uint32_t reverseBits(uint32_t n) {
    uint32_t result = 0;

    for (int i = 0; i < 32; i++) {
        result = (result << 1) | (n & 1); // Shift result left, and append the last bit of n
        n >>= 1;                         // Shift n right to process the next bit
    }

    return result;
}

// Example usage
int main() {
    uint32_t n = 43261596; // Example input (binary: 00000010100101000001111010011100)
    uint32_t reversed = reverseBits(n);
    printf("Input: %u, Reversed: %u\n", n, reversed); // Expected output: 964176192 (binary: 00111001011110000010100101000000)
    return 0;
}
/*recur O(1)
#include <stdint.h>
#include <stdio.h>

// Helper function to recursively reverse bits
uint32_t reverseBitsHelper(uint32_t n, uint32_t result, int bitIndex) {
    if (bitIndex == 32) {
        return result; // Base case: when we've processed all 32 bits
    }

    result = (result << 1) | (n & 1); // Shift result and append the last bit of n
    n >>= 1; // Shift n to the right to process the next bit

    // Recur for the next bit
    return reverseBitsHelper(n, result, bitIndex + 1);
}

// Function to reverse the bits of a 32-bit unsigned integer
uint32_t reverseBits(uint32_t n) {
    return reverseBitsHelper(n, 0, 0); // Start the recursion with an empty result
}

// Example usage
int main() {
    uint32_t n = 43261596; // Example input (binary: 00000010100101000001111010011100)
    uint32_t reversed = reverseBits(n);
    printf("Input: %u, Reversed: %u\n", n, reversed); // Expected output: 964176192 (binary: 00111001011110000010100101000000)
    return 0;
}
*/