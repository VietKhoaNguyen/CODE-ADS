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
/*recur O(n)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unordered_set>  // For hash set in C++

bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    if (k <= 0) return false;  // No need to check for k <= 0

    // Hash set to track elements in the sliding window
    unordered_set<int> seen;

    for (int i = 0; i < numsSize; i++) {
        // Check if the current number is in the set (duplicate found)
        if (seen.find(nums[i]) != seen.end()) {
            return true;
        }

        // Add the current number to the set
        seen.insert(nums[i]);

        // If the window size exceeds k, remove the oldest element (out of range)
        if (i >= k) {
            seen.erase(nums[i - k]);
        }
    }

    return false;  // No duplicates found within range k
}

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