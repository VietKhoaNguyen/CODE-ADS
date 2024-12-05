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
