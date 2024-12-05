#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    // If the array is empty, there are no duplicates to remove
    if (numsSize == 0) {
        return 0;
    }
    
    int j = 1;  // Pointer to keep track of the position of the next unique element
    
    // Start from the second element and compare with the previous one
    for (int i = 1; i < numsSize; i++) {
        if (nums[i] != nums[i - 1]) {
            nums[j] = nums[i];  // Place the unique element at the correct position
            j++;  // Increment the pointer for the next unique element
        }
    }
    
    return j;  // The length of the array with unique elements
}

// Function to print the array (for testing purposes)
void printArray(int* nums, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 3, 4};
    int numsSize = 7;
    
    int newLength = removeDuplicates(nums, numsSize);
    
    // Print the modified array with unique elements
    printArray(nums, newLength);  // Expected output: 1 2 3 4
    
    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive function to remove duplicates from the sorted array
int removeDuplicatesRecursive(int* nums, int numsSize, int currentIndex, int j) {
    // Base case: If we have processed all elements, return the number of unique elements
    if (currentIndex == numsSize) {
        return j;
    }

    // If the current element is not equal to the previous one, it is unique
    if (nums[currentIndex] != nums[currentIndex - 1]) {
        nums[j] = nums[currentIndex];  // Place the unique element at the correct position
        j++;  // Increment the pointer for the next unique element
    }

    // Recursively call the function for the next element
    return removeDuplicatesRecursive(nums, numsSize, currentIndex + 1, j);
}

// Function to print the array (for testing purposes)
void printArray(int* nums, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {1, 1, 2, 2, 3, 3, 4};
    int numsSize = 7;

    // Initial call to the recursive function, starting at index 1 (second element)
    int newLength = removeDuplicatesRecursive(nums, numsSize, 1, 1);

    // Print the modified array with unique elements
    printArray(nums, newLength);  // Expected output: 1 2 3 4

    return 0;
}
*/