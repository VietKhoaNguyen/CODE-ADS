#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Function to check if there are nearby duplicates within range k
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    // Iterate over the array
    for (int i = 0; i < numsSize; i++) {
        // Check all previous elements to see if the same number exists within the range
        for (int j = i + 1; j < numsSize && j <= i + k; j++) {
            if (nums[i] == nums[j]) {
                return true; // Found a duplicate within range k
            }
        }
    }
    return false; // No nearby duplicates found
}

// Example usage
int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    if (containsNearbyDuplicate(nums, numsSize, k)) {
        printf("The array contains nearby duplicates.\n");
    } else {
        printf("The array does not contain nearby duplicates.\n");
    }

    return 0;
}
/*Recur: O(n*k)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Recursive helper function
bool containsNearbyDuplicateHelper(int* nums, int numsSize, int k, int currentIndex) {
    // Base case: If we have processed all elements, return false
    if (currentIndex >= numsSize) {
        return false;
    }

    // Check if any element from the current index to currentIndex + k is equal to nums[currentIndex]
    for (int i = currentIndex + 1; i <= currentIndex + k && i < numsSize; i++) {
        if (nums[i] == nums[currentIndex]) {
            return true; // Found a duplicate within the range k
        }
    }

    // Recur for the next index
    return containsNearbyDuplicateHelper(nums, numsSize, k, currentIndex + 1);
}

// Wrapper function to initialize recursion
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    return containsNearbyDuplicateHelper(nums, numsSize, k, 0);
}

// Example usage
int main() {
    int nums[] = {1, 2, 3, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    if (containsNearbyDuplicate(nums, numsSize, k)) {
        printf("The array contains nearby duplicates.\n");
    } else {
        printf("The array does not contain nearby duplicates.\n");
    }

    return 0;
}
*/
