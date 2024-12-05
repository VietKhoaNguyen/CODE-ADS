#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is a power of two
bool isPowerOfTwo(int n) {
    // Check if n is greater than 0 and n & (n - 1) is 0 (power of two condition)
    return n > 0 && (n & (n - 1)) == 0;
}

int main() {
    // Test cases
    int nums[] = {1, 2, 4, 8, 16, 32, 64, 3, 5, 18};  // Test numbers
    
    for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++) {
        int num = nums[i];
        if (isPowerOfTwo(num)) {
            printf("%d is a power of two\n", num);
        } else {
            printf("%d is NOT a power of two\n", num);
        }
    }

    return 0;
}
