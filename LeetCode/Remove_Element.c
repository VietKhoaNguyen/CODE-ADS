#include <stdio.h>

int removeElement(int* nums, int numsSize, int val) {
    int j = 0;  // Pointer to track the position of the next valid element
    
    // Traverse through the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[j] = nums[i];  // Place the element at the next valid position
            j++;  // Increment the pointer for valid elements
        }
    }
    
    return j;  // The length of the array after removing all occurrences of 'val'
}

// Function to print the array (for testing purposes)
void printArray(int* nums, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {3, 2, 2, 3, 4, 3, 5};
    int numsSize = 7;
    int val = 3;
    
    int newLength = removeElement(nums, numsSize, val);
    
    // Print the modified array with 'val' removed
    printArray(nums, newLength);  // Expected output: 2 2 4 5
    
    return 0;
}
