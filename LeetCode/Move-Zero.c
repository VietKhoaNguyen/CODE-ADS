#include <stdio.h>

void moveZeroes(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;  // Pointer to track the position of last non-zero element

    // Traverse the array
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            // Swap elements at i and lastNonZeroFoundAt if nums[i] is non-zero
            if (i != lastNonZeroFoundAt) {
                int temp = nums[i];
                nums[i] = nums[lastNonZeroFoundAt];
                nums[lastNonZeroFoundAt] = temp;
            }
            lastNonZeroFoundAt++;
        }
    }
}

// Helper function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Before moving zeroes:\n");
    printArray(nums, numsSize);

    moveZeroes(nums, numsSize);

    printf("After moving zeroes:\n");
    printArray(nums, numsSize);

    return 0;
}
/*recur O(n)
#include <stdio.h>

void moveZeroesHelper(int* nums, int numsSize, int currentIndex, int lastNonZeroFoundAt) {
    // Base case: If the current index is beyond the array size, return
    if (currentIndex >= numsSize) {
        return;
    }

    // If the current element is non-zero, swap it with the last non-zero element
    if (nums[currentIndex] != 0) {
        if (currentIndex != lastNonZeroFoundAt) {
            int temp = nums[currentIndex];
            nums[currentIndex] = nums[lastNonZeroFoundAt];
            nums[lastNonZeroFoundAt] = temp;
        }
        lastNonZeroFoundAt++;
    }

    // Recur to the next element
    moveZeroesHelper(nums, numsSize, currentIndex + 1, lastNonZeroFoundAt);
}

void moveZeroes(int* nums, int numsSize) {
    moveZeroesHelper(nums, numsSize, 0, 0);
}

// Helper function to print the array
void printArray(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

int main() {
    int nums[] = {0, 1, 0, 3, 12};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    printf("Before moving zeroes:\n");
    printArray(nums, numsSize);

    moveZeroes(nums, numsSize);

    printf("After moving zeroes:\n");
    printArray(nums, numsSize);

    return 0;
}
*/