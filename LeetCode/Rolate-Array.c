#include <stdio.h>

// Function to reverse the array in place
void reverse(int* nums, int left, int right) {
    while (left < right) {
        // Swap elements at left and right
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
        
        // Move pointers towards the center
        left++;
        right--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    // Handle the case when the array is empty or k is 0
    if (numsSize == 0 || k == 0 || k % numsSize == 0) {
        return;
    }

    // Ensure k is within the array size bounds
    k = k % numsSize;

    // Step 1: Reverse the entire array
    reverse(nums, 0, numsSize - 1);

    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse the remaining elements
    reverse(nums, k, numsSize - 1);
}

// Helper function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    printf("Original array: ");
    printArray(nums, numsSize);
    
    rotate(nums, numsSize, k);

    printf("Array after rotation: ");
    printArray(nums, numsSize);

    return 0;
}
/*recur O(n)
#include <stdio.h>

// Function to reverse a portion of the array from 'left' to 'right'
void reverse(int* nums, int left, int right) {
    if (left >= right) {
        return;  // Base case: if only one element or no elements to reverse
    }
    
    // Swap elements at left and right
    int temp = nums[left];
    nums[left] = nums[right];
    nums[right] = temp;

    // Recur for the next elements
    reverse(nums, left + 1, right - 1);
}

// Recursive rotate function
void rotate(int* nums, int numsSize, int k) {
    // Edge case: no need to rotate
    if (numsSize == 0 || k == 0 || k % numsSize == 0) {
        return;
    }

    // Ensure k is within bounds
    k = k % numsSize;

    // Step 1: Reverse the entire array
    reverse(nums, 0, numsSize - 1);

    // Step 2: Reverse the first k elements
    reverse(nums, 0, k - 1);

    // Step 3: Reverse the remaining n - k elements
    reverse(nums, k, numsSize - 1);
}

// Helper function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 2, 3, 4, 5, 6, 7};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 3;

    printf("Original array: ");
    printArray(nums, numsSize);
    
    rotate(nums, numsSize, k);

    printf("Array after rotation: ");
    printArray(nums, numsSize);

    return 0;
}
*/