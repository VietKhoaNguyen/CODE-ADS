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
