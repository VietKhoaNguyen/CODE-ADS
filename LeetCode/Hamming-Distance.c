#include <stdio.h>

int hammingDistance(int x, int y) {
    // XOR the two numbers to find the positions where bits differ
    int diff = x ^ y;
    
    // Count the number of 1's in the result
    int distance = 0;
    while (diff != 0) {
        distance += diff & 1;  // Add 1 if the last bit is 1
        diff >>= 1;  // Shift right to check the next bit
    }
    
    return distance;
}

int main() {
    int x = 1;
    int y = 4;

    printf("Hamming distance between %d and %d is %d\n", x, y, hammingDistance(x, y));

    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive function to calculate the number of 1's in the binary representation of a number
int countBits(int diff) {
    // Base case: when diff is 0, no more bits to count
    if (diff == 0) {
        return 0;
    }

    // Add 1 if the last bit is 1, otherwise add 0, and recurse on the rest of the bits
    return (diff & 1) + countBits(diff >> 1);
}

int hammingDistance(int x, int y) {
    // XOR the two numbers to find the positions where bits differ
    int diff = x ^ y;
    
    // Recursively count the number of 1's in the diff (Hamming distance)
    return countBits(diff);
}

int main() {
    int x = 1;
    int y = 4;

    printf("Hamming distance between %d and %d is %d\n", x, y, hammingDistance(x, y));

    return 0;
}
*/