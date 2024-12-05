#include <stdio.h>

int missingNumber(int* nums, int numsSize) {
    // Calculate the expected sum of numbers from 0 to numsSize
    int expectedSum = (numsSize * (numsSize + 1)) / 2;
    
    // Calculate the actual sum of the numbers in the array
    int actualSum = 0;
    for (int i = 0; i < numsSize; i++) {
        actualSum += nums[i];
    }
    
    // The missing number is the difference between expected and actual sum
    return expectedSum - actualSum;
}

int main() {
    // Test cases
    int nums1[] = {3, 7, 1, 2, 8, 4, 5};
    int nums2[] = {0, 1};
    int nums3[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    
    printf("Missing number in nums1: %d\n", missingNumber(nums1, 7)); // Expected: 6
    printf("Missing number in nums2: %d\n", missingNumber(nums2, 2)); // Expected: 2
    printf("Missing number in nums3: %d\n", missingNumber(nums3, 9)); // Expected: 8
    
    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive function to calculate the sum of elements in the array
int calculateSum(int* nums, int index, int numsSize) {
    // Base case: if index is equal to numsSize, return 0 (no more elements to add)
    if (index == numsSize) {
        return 0;
    }
    
    // Recursive case: return the current element + the sum of the rest of the array
    return nums[index] + calculateSum(nums, index + 1, numsSize);
}

int missingNumber(int* nums, int numsSize) {
    // Calculate the expected sum of numbers from 0 to numsSize
    int expectedSum = (numsSize * (numsSize + 1)) / 2;
    
    // Calculate the actual sum of the numbers in the array using recursion
    int actualSum = calculateSum(nums, 0, numsSize);
    
    // The missing number is the difference between expected and actual sum
    return expectedSum - actualSum;
}

int main() {
    // Test cases
    int nums1[] = {3, 7, 1, 2, 8, 4, 5};
    int nums2[] = {0, 1};
    int nums3[] = {9, 6, 4, 2, 3, 5, 7, 0, 1};
    
    printf("Missing number in nums1: %d\n", missingNumber(nums1, 7)); // Expected: 6
    printf("Missing number in nums2: %d\n", missingNumber(nums2, 2)); // Expected: 2
    printf("Missing number in nums3: %d\n", missingNumber(nums3, 9)); // Expected: 8
    
    return 0;
}
*/