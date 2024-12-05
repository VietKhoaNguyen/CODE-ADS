#include <stdio.h>

int singleNumber(int* nums, int numsSize) {
    int result = 0;
    
    // XOR all elements in the array
    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i];
    }
    
    // The result will be the single number
    return result;
}

int main() {
    // Example array where every number appears twice except for one
    int nums[] = {4, 1, 2, 1, 2};
    int numsSize = 5;
    
    // Call the function to find the single number
    int result = singleNumber(nums, numsSize);
    
    // Print the result
    printf("The single number is: %d\n", result);
    
    return 0;
}
