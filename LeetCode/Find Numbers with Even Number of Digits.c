#include <stdio.h>
#include <math.h>

int findNumbers(int* nums, int numsSize) {
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        int num = nums[i];
        
        // Calculate the number of digits in the number
        int numDigits = (int)log10(num) + 1;
        
        // Check if the number of digits is even
        if (numDigits % 2 == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int nums[] = {12, 345, 2, 6, 7896};
    int numsSize = 5;

    int result = findNumbers(nums, numsSize);
    printf("Count of numbers with even digits: %d\n", result);  // Expected output: 2

    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <math.h>

// Helper function to calculate the number of digits in a number
int countDigits(int num) {
    // Base case: if the number is 0, it has 1 digit.
    if (num == 0) return 1;
    
    // Recursive case: divide the number by 10 and count the digits
    return 1 + countDigits(num / 10);
}

// Recursive function to count how many numbers in the array have an even number of digits
int findNumbersRecursive(int* nums, int numsSize, int index) {
    // Base case: if we've reached the end of the array, return 0
    if (index == numsSize) {
        return 0;
    }
    
    // Calculate the number of digits in the current number
    int numDigits = countDigits(nums[index]);
    
    // Check if the number of digits is even
    int isEvenDigits = (numDigits % 2 == 0) ? 1 : 0;
    
    // Recur for the next element and add the result from the current element
    return isEvenDigits + findNumbersRecursive(nums, numsSize, index + 1);
}

int findNumbers(int* nums, int numsSize) {
    return findNumbersRecursive(nums, numsSize, 0);  // Start recursion from index 0
}

int main() {
    int nums[] = {12, 345, 2, 6, 7896};
    int numsSize = 5;

    int result = findNumbers(nums, numsSize);
    printf("Count of numbers with even digits: %d\n", result);  // Expected output: 2

    return 0;
}
*/