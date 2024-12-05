#include <stdio.h>

// Function to find the maximum number of consecutive 1s
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int maxCount = 0; // To store the maximum count of consecutive 1s
    int currentCount = 0; // To track the current streak of 1s

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == 1) {
            currentCount++; // Increment the current streak of 1s
            if (currentCount > maxCount) {
                maxCount = currentCount; // Update maxCount if currentCount is greater
            }
        } else {
            currentCount = 0; // Reset the streak if the current element is 0
        }
    }

    return maxCount; // Return the maximum count of consecutive 1s
}

// Main function to test the implementation
int main() {
    // Test case
    int nums[] = {1, 1, 0, 1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Call the function and print the result
    int result = findMaxConsecutiveOnes(nums, numsSize);
    printf("Maximum consecutive ones: %d\n", result); // Expected Output: 3

    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive helper function to find the maximum consecutive 1s
int findMaxConsecutiveOnesRecursive(int* nums, int numsSize, int index, int currentCount, int maxCount) {
    // Base case: If index reaches the end of the array
    if (index == numsSize) {
        return maxCount; // Return the maxCount when the recursion ends
    }

    // If the current element is 1, increment the current streak
    if (nums[index] == 1) {
        currentCount++;
        // Update maxCount if currentCount is greater
        if (currentCount > maxCount) {
            maxCount = currentCount;
        }
    } else {
        // Reset the streak if the current element is 0
        currentCount = 0;
    }

    // Recurse with the next index
    return findMaxConsecutiveOnesRecursive(nums, numsSize, index + 1, currentCount, maxCount);
}

int findMaxConsecutiveOnes(int* nums, int numsSize) {
    // Call the recursive helper function starting from index 0
    return findMaxConsecutiveOnesRecursive(nums, numsSize, 0, 0, 0);
}

// Main function to test the implementation
int main() {
    // Test case
    int nums[] = {1, 1, 0, 1, 1, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Call the function and print the result
    int result = findMaxConsecutiveOnes(nums, numsSize);
    printf("Maximum consecutive ones: %d\n", result); // Expected Output: 3

    return 0;
}
 */