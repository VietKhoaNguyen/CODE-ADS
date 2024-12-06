#include <stdio.h>

// Helper function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    if (num == 0) {
        return 0; // Base case: no more digits
    }
    return num % 10 + sumOfDigits(num / 10); // Add the last digit and recurse with the rest
}

// Main function to calculate the difference of the sum
int differenceOfSum(int* nums, int numsSize) {
    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < numsSize; i++) {
        sum1 += sumOfDigits(nums[i]); // Sum of digits of each number
        int temp = nums[i];

        // Sum of digits of the individual digits of the number
        while (temp > 0) {
            sum2 += temp % 10;
            temp /= 10;
        }
    }

    return sum1 - sum2; // Return the difference
}

int main() {
    int nums[] = {123, 456, 789};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Call the function and display the result
    int result = differenceOfSum(nums, numsSize);
    printf("The difference of sums is: %d\n", result);

    return 0;
}
/*recur O(n)
#include <stdio.h>

// Helper recursive function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    if (num == 0) {
        return 0; // Base case: no more digits
    }
    return num % 10 + sumOfDigits(num / 10); // Add last digit and recurse
}

// Recursive function to calculate the total sum of digits of all numbers in the array
int calculateSum1(int* nums, int index, int numsSize) {
    if (index == numsSize) {
        return 0; // Base case: when we've processed all numbers
    }
    // Recursively calculate sum of digits of current number and move to the next
    return sumOfDigits(nums[index]) + calculateSum1(nums, index + 1, numsSize);
}

// Recursive function to calculate the total sum of digits of individual digits in all numbers
int calculateSum2(int* nums, int index, int numsSize) {
    if (index == numsSize) {
        return 0; // Base case: when we've processed all numbers
    }

    // Calculate sum of digits of the current number's digits
    int currentSum = 0;
    int num = nums[index];
    
    // For each number, sum the digits of its digits
    while (num > 0) {
        currentSum += num % 10;
        num /= 10;
    }

    // Recursively calculate sum for the next number
    return currentSum + calculateSum2(nums, index + 1, numsSize);
}

// Main function to compute the difference of the sums
int differenceOfSum(int* nums, int numsSize) {
    int sum1 = calculateSum1(nums, 0, numsSize); // Sum of digits of all numbers
    int sum2 = calculateSum2(nums, 0, numsSize); // Sum of the digits of the digits of all numbers
    return sum1 - sum2; // Return the difference
}

int main() {
    int nums[] = {123, 456, 789};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Call the recursive function and print the result
    int result = differenceOfSum(nums, numsSize);
    printf("The difference of sums is: %d\n", result);

    return 0;
}
*/