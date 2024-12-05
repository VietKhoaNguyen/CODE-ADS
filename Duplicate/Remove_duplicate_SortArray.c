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
<<<<<<< HEAD
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
=======
/*Recursive         O(n)
#include <stdio.h>

// Recursive function to remove duplicates from the sorted array
int removeDuplicatesRecursive(int* nums, int index, int numsSize) {
    // Base case: If we reach the end of the array, return the current index
    if (index >= numsSize) {
        return index;
    }

    // If the current element is a duplicate, skip it
    if (nums[index] == nums[index - 1]) {
        return removeDuplicatesRecursive(nums, index + 1, numsSize);
    }

    // Otherwise, update the next unique position
    nums[index] = nums[index];  // This is implicitly true, but here for clarity
    return removeDuplicatesRecursive(nums, index + 1, numsSize);
}

// Wrapper function to initialize the recursion
int removeDuplicates(int* nums, int numsSize) {
    // If the array is empty or has only one element, there are no duplicates
    if (numsSize == 0) {
        return 0;
    }
    return removeDuplicatesRecursive(nums, 1, numsSize);  // Start from the second element
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
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

<<<<<<< HEAD
    // Initial call to the recursive function, starting at index 1 (second element)
    int newLength = removeDuplicatesRecursive(nums, numsSize, 1, 1);
=======
    int newLength = removeDuplicates(nums, numsSize);
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae

    // Print the modified array with unique elements
    printArray(nums, newLength);  // Expected output: 1 2 3 4

    return 0;
}
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
