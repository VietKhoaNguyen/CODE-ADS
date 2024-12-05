#include <stdio.h>

int searchInsert(int* nums, int numsSize, int target) {
    int left = 0, right = numsSize - 1;
    
    // Perform binary search
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (nums[mid] == target) {
            return mid;  // If the target is found, return its index
        } else if (nums[mid] < target) {
            left = mid + 1;  // Search in the right half
        } else {
            right = mid - 1;  // Search in the left half
        }
    }
    
    // If not found, 'left' is the position where the target should be inserted
    return left;
}

// Main function for testing
int main() {
    int nums[] = {1, 3, 5, 6};
    int numsSize = 4;
    int target = 5;
    
    int index = searchInsert(nums, numsSize, target);
    printf("The target should be inserted at index: %d\n", index);  // Expected output: 2
    
    target = 2;
    index = searchInsert(nums, numsSize, target);
    printf("The target should be inserted at index: %d\n", index);  // Expected output: 1
    
    target = 7;
    index = searchInsert(nums, numsSize, target);
    printf("The target should be inserted at index: %d\n", index);  // Expected output: 4
    
    target = 0;
    index = searchInsert(nums, numsSize, target);
    printf("The target should be inserted at index: %d\n", index);  // Expected output: 0
    
    return 0;
}
/*recur O(logn)
#include <stdio.h>

int searchInsertRecursive(int* nums, int left, int right, int target) {
    // Base case: if the search space is exhausted
    if (left > right) {
        return left;  // The position where the target should be inserted
    }
    
    int mid = left + (right - left) / 2;
    
    // If the target is found, return the index
    if (nums[mid] == target) {
        return mid;
    }
    
    // If the target is greater, search in the right half
    if (nums[mid] < target) {
        return searchInsertRecursive(nums, mid + 1, right, target);
    }
    
    // If the target is smaller, search in the left half
    return searchInsertRecursive(nums, left, mid - 1, target);
}

int searchInsert(int* nums, int numsSize, int target) {
    return searchInsertRecursive(nums, 0, numsSize - 1, target);
}

// Main function for testing
int main() {
    int nums[] = {1, 3, 5, 6};
    int numsSize = 4;
    int target = 5;
    
    int index = searchInsert(nums, numsSize, target);
    printf("The target should be inserted at index: %d\n", index);  // Expected output: 2
    
    target = 2;
    index = searchInsert(nums, numsSize, target);
    printf("The target should be inserted at index: %d\n", index);  // Expected output: 1
    
    target = 7;
    index = searchInsert(nums, numsSize, target);
    printf("The target should be inserted at index: %d\n", index);  // Expected output: 4
    
    target = 0;
    index = searchInsert(nums, numsSize, target);
    printf("The target should be inserted at index: %d\n", index);  // Expected output: 0
    
    return 0;
}
*/