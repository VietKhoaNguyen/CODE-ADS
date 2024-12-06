#include <stdio.h>
#include <stdlib.h>

int numIdenticalPairs(int* nums, int numsSize) {
    // Frequency array to count occurrences of each number (since we are assuming numbers are in a range)
    int freq[101] = {0};  // Assuming the numbers are in the range [1, 100]
    int goodPairsCount = 0;

    // Count frequency of each number
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i]]++;
    }

    // Calculate the number of good pairs for each unique number
    for (int i = 0; i < 101; i++) {
        if (freq[i] > 1) {
            goodPairsCount += (freq[i] * (freq[i] - 1)) / 2;
        }
    }

    return goodPairsCount;
}

// Example usage:
int main() {
    int nums[] = {1, 2, 3, 1, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = numIdenticalPairs(nums, numsSize);
    printf("Number of good pairs: %d\n", result);  // Expected output: 4
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

int countGoodPairs(int* nums, int numsSize, int index, int* freq) {
    // Base case: If we have processed all elements, return 0 pairs
    if (index == numsSize) {
        return 0;
    }

    // Get the number at the current index
    int currentNum = nums[index];

    // Count the number of good pairs formed by the current number
    int goodPairs = freq[currentNum] > 0 ? freq[currentNum] : 0;

    // Increment the frequency of the current number
    freq[currentNum]++;

    // Recurse to process the next number
    int result = goodPairs + countGoodPairs(nums, numsSize, index + 1, freq);

    return result;
}

int numIdenticalPairs(int* nums, int numsSize) {
    // Frequency array to count occurrences of each number
    int freq[101] = {0};  // Assuming the numbers are in the range [1, 100]

    // Start recursion from the first index
    return countGoodPairs(nums, numsSize, 0, freq);
}

// Example usage:
int main() {
    int nums[] = {1, 2, 3, 1, 1, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int result = numIdenticalPairs(nums, numsSize);
    printf("Number of good pairs: %d\n", result);  // Expected output: 4
    return 0;
}
*/