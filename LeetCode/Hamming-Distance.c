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
