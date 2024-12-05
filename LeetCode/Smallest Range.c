#include <stdio.h>
#include <limits.h>

int smallestRangeI(int* nums, int numsSize, int k) {
    // Find the minimum and maximum values in the array
    int minVal = INT_MAX, maxVal = INT_MIN;
    
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < minVal) {
            minVal = nums[i];
        }
        if (nums[i] > maxVal) {
            maxVal = nums[i];
        }
    }
    
    // The smallest range after applying the changes
    int range = maxVal - minVal - 2 * k;
    
    // The range cannot be negative, so return max(0, range)
    return range > 0 ? range : 0;
}

// Example usage
int main() {
    int nums[] = {1, 3, 6};
    int numsSize = 3;
    int k = 3;
    
    int result = smallestRangeI(nums, numsSize, k);
    printf("The smallest range is: %d\n", result);  // Expected output: 0

    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <limits.h>

// Helper function to find the minimum value in the array recursively
int findMin(int* nums, int index, int numsSize) {
    // Base case: if we've gone through all elements, return INT_MAX
    if (index == numsSize) {
        return INT_MAX;
    }

    // Recursively find the minimum of the remaining elements
    int minRest = findMin(nums, index + 1, numsSize);

    // Return the minimum of the current element and the rest
    return (nums[index] < minRest) ? nums[index] : minRest;
}

// Helper function to find the maximum value in the array recursively
int findMax(int* nums, int index, int numsSize) {
    // Base case: if we've gone through all elements, return INT_MIN
    if (index == numsSize) {
        return INT_MIN;
    }

    // Recursively find the maximum of the remaining elements
    int maxRest = findMax(nums, index + 1, numsSize);

    // Return the maximum of the current element and the rest
    return (nums[index] > maxRest) ? nums[index] : maxRest;
}

// Main function to calculate the smallest range
int smallestRangeI(int* nums, int numsSize, int k) {
    // Recursively find the minimum and maximum values in the array
    int minVal = findMin(nums, 0, numsSize);
    int maxVal = findMax(nums, 0, numsSize);
    
    // Calculate the smallest range
    int range = maxVal - minVal - 2 * k;
    
    // The range cannot be negative, so return max(0, range)
    return range > 0 ? range : 0;
}

// Example usage
int main() {
    int nums[] = {1, 3, 6};
    int numsSize = 3;
    int k = 3;
    
    int result = smallestRangeI(nums, numsSize, k);
    printf("The smallest range is: %d\n", result);  // Expected output: 0

    return 0;
}
*/