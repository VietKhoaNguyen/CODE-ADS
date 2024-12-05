#include <stdio.h>

int majorityElement(int* nums, int numsSize) {
    int candidate = 0, count = 0;

    // Step 1: Find a candidate using Boyer-Moore Voting Algorithm
    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i]; // Set new candidate
        }
        count += (nums[i] == candidate) ? 1 : -1;
    }

    // Step 2 (Optional for guaranteed input): Verify the candidate
    // Since the problem guarantees a majority element, this step is unnecessary.
    // Uncomment if you want verification:
    /*
    count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }
    if (count > numsSize / 2) {
        return candidate;
    } else {
        return -1; // This case shouldn't occur as per the problem guarantee
    }
    */

    return candidate;
}

// Example usage
int main() {
    int nums[] = {3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("Majority Element: %d\n", result); // Output: 3
    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive helper function for Boyer-Moore Voting Algorithm
int majorityElementRecursiveHelper(int* nums, int numsSize, int index, int candidate, int count) {
    if (index == numsSize) {
        return candidate;
    }

    // Update the candidate based on the current element
    if (count == 0) {
        candidate = nums[index]; // Set new candidate
    }

    // Update the count
    count += (nums[index] == candidate) ? 1 : -1;

    // Recurse with the next index
    return majorityElementRecursiveHelper(nums, numsSize, index + 1, candidate, count);
}

int majorityElement(int* nums, int numsSize) {
    return majorityElementRecursiveHelper(nums, numsSize, 0, 0, 0);
}

// Example usage
int main() {
    int nums[] = {3, 2, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = majorityElement(nums, numsSize);
    printf("Majority Element: %d\n", result); // Output: 3
    return 0;
}
*/