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
/*recur O(n)
#include <stdio.h>

int singleNumberRecursive(int* nums, int index, int numsSize) {
    // Base case: if we've processed all elements, return 0
    if (index == numsSize) {
        return 0;
    }
    
    // XOR the current element with the result of the rest of the array
    return nums[index] ^ singleNumberRecursive(nums, index + 1, numsSize);
}

int singleNumber(int* nums, int numsSize) {
    return singleNumberRecursive(nums, 0, numsSize);
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
*/