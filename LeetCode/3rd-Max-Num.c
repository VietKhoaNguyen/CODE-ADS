#include <stdio.h>
#include <limits.h>

int thirdMax(int* nums, int numsSize) {
    // Initialize the three variables to the smallest possible integer
    long long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    // Count distinct numbers
    int distinctCount = 0;

    for (int i = 0; i < numsSize; i++) {
        // Skip duplicates by checking if the number is already considered
        if (nums[i] == first || nums[i] == second || nums[i] == third) {
            continue;
        }

        // Update the three maximums
        if (nums[i] > first) {
            third = second;
            second = first;
            first = nums[i];
        } else if (nums[i] > second) {
            third = second;
            second = nums[i];
        } else if (nums[i] > third) {
            third = nums[i];
        }

        distinctCount++;
    }

    // If there are at least 3 distinct numbers, return the third maximum
    if (distinctCount >= 3) {
        return (int)third;
    }

    // Otherwise, return the maximum number
    return (int)first;
}

int main() {
    int nums[] = {3, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = thirdMax(nums, numsSize);
    printf("The third maximum number is: %d\n", result);

    return 0;
}
/*Recursive approach                O(n)
#include <stdio.h>
#include <limits.h>

// Recursive helper function
void findMaxRec(int* nums, int size, int index, long long* first, long long* second, long long* third) {
    // Base case: End of the array
    if (index == size) {
        return;
    }

    // Skip duplicates
    if (nums[index] == *first || nums[index] == *second || nums[index] == *third) {
        findMaxRec(nums, size, index + 1, first, second, third);
        return;
    }

    // Update first, second, and third
    if (nums[index] > *first) {
        *third = *second;
        *second = *first;
        *first = nums[index];
    } else if (nums[index] > *second) {
        *third = *second;
        *second = nums[index];
    } else if (nums[index] > *third) {
        *third = nums[index];
    }

    // Recur for the next element
    findMaxRec(nums, size, index + 1, first, second, third);
}

// Wrapper function
int thirdMax(int* nums, int numsSize) {
    long long first = LONG_MIN, second = LONG_MIN, third = LONG_MIN;

    // Call the recursive helper
    findMaxRec(nums, numsSize, 0, &first, &second, &third);

    // Return the result based on the number of distinct maximums
    if (third == LONG_MIN) {
        return (int)first;
    }
    return (int)third;
}

// Main function to test the implementation
int main() {
    int nums[] = {3, 2, 1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = thirdMax(nums, numsSize);
    printf("The third maximum number is: %d\n", result);

    return 0;
}
*/