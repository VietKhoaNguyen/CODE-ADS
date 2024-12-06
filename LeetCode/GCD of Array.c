#include <stdio.h>

// Helper function to calculate GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a; // Base case
    }
    return gcd(b, a % b); // Recursive step
}

// Function to find GCD of the smallest and largest numbers in the array
int findGCD(int* nums, int numsSize) {
    // Find the smallest and largest numbers in the array
    int minNum = nums[0];
    int maxNum = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < minNum) {
            minNum = nums[i];
        }
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }

    // Calculate and return the GCD of the smallest and largest numbers
    return gcd(minNum, maxNum);
}

int main() {
    int nums[] = {6, 12, 15, 18, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Find and display the GCD
    int result = findGCD(nums, numsSize);
    printf("The GCD of the smallest and largest numbers is: %d\n", result);

    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive function to find the minimum number in the array
int findMin(int* nums, int index, int numsSize) {
    if (index == numsSize - 1) {
        return nums[index];
    }
    int nextMin = findMin(nums, index + 1, numsSize);
    return nums[index] < nextMin ? nums[index] : nextMin;
}

// Recursive function to find the maximum number in the array
int findMax(int* nums, int index, int numsSize) {
    if (index == numsSize - 1) {
        return nums[index];
    }
    int nextMax = findMax(nums, index + 1, numsSize);
    return nums[index] > nextMax ? nums[index] : nextMax;
}

// Recursive helper function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Main function to find the GCD of the smallest and largest numbers in the array
int findGCD(int* nums, int numsSize) {
    int minNum = findMin(nums, 0, numsSize);
    int maxNum = findMax(nums, 0, numsSize);
    return gcd(minNum, maxNum);
}

int main() {
    int nums[] = {6, 12, 15, 18, 9};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    // Find and display the GCD
    int result = findGCD(nums, numsSize);
    printf("The GCD of the smallest and largest numbers is: %d\n", result);

    return 0;
}
*/