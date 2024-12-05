#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <unordered_map>

// Function to check if there are nearby duplicates within range k
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    // Create a hash map to store the last seen index of each number
    std::unordered_map<int, int> map;

    for (int i = 0; i < numsSize; i++) {
        // If the element has been seen and the difference of indices is <= k
        if (map.find(nums[i]) != map.end() && i - map[nums[i]] <= k) {
            return true;
        }
        // Store the current index of the element
        map[nums[i]] = i;
    }
    
    return false; // No nearby duplicates found
}
/*Recursive            O(n)
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Recursive helper function
bool containsNearbyDuplicateHelper(int* nums, int numsSize, int k, int currentIndex, int* seenIndices) {
    // Base case: If we have processed all elements, no duplicates found
    if (currentIndex >= numsSize) {
        return false;
    }

    // Check if the current element is in the seen array within range k
    for (int i = 0; i < currentIndex; i++) {
        if (nums[i] == nums[currentIndex] && abs(currentIndex - i) <= k) {
            return true; // Found a nearby duplicate
        }
    }

    // Recur for the next index
    return containsNearbyDuplicateHelper(nums, numsSize, k, currentIndex + 1, seenIndices);
}

// Wrapper function to initialize recursion
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    // Allocate memory for seen indices (not strictly necessary but consistent with recursion)
    int* seenIndices = (int*)malloc(numsSize * sizeof(int));
    bool result = containsNearbyDuplicateHelper(nums, numsSize, k, 0, seenIndices);
    free(seenIndices); // Free memory
    return result;
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
