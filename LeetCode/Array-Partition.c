#include <stdio.h>
#include <stdlib.h>

// Comparator function to sort the array in ascending order
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Step 2: Sum the minimums of each pair (nums[0], nums[2], nums[4], ...)
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }
    
    return sum;
}

int main() {
    int nums[] = {1, 4, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Array pair sum: %d\n", arrayPairSum(nums, numsSize));  // Expected output: 4
    return 0;
}
/*recur O(nlogn)
#include <stdio.h>
#include <stdlib.h>

// Comparator function to sort the array in ascending order
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int arrayPairSum(int* nums, int numsSize) {
    // Step 1: Sort the array
    qsort(nums, numsSize, sizeof(int), compare);
    
    // Step 2: Sum the minimums of each pair (nums[0], nums[2], nums[4], ...)
    int sum = 0;
    for (int i = 0; i < numsSize; i += 2) {
        sum += nums[i];
    }
    
    return sum;
}

int main() {
    int nums[] = {1, 4, 3, 2};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    printf("Array pair sum: %d\n", arrayPairSum(nums, numsSize));  // Expected output: 4
    return 0;
}
*/