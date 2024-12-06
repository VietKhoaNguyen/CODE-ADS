#include <stdio.h>

// Helper function to calculate the sum of digits of a number
int sumOfDigits(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;  // Add the last digit
        num /= 10;         // Remove the last digit
    }
    return sum;
}

// Function to count the largest group of numbers by sum of digits
int countLargestGroup(int n) {
    int count[37] = {0};  // Sum of digits can range from 0 to 36 (for n <= 999999)
    
    // Count the frequency of each sum of digits
    for (int i = 1; i <= n; i++) {
        int sum = sumOfDigits(i);
        count[sum]++;
    }
    
    // Find the maximum group size
    int maxCount = 0;
    for (int i = 0; i < 37; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }
    
    // Count how many groups have the maximum size
    int largestGroupCount = 0;
    for (int i = 0; i < 37; i++) {
        if (count[i] == maxCount) {
            largestGroupCount++;
        }
    }
    
    return largestGroupCount;
}

int main() {
    int n = 13;  // Example input
    int result = countLargestGroup(n);
    printf("The count of largest groups is: %d\n", result);  // Expected output: 4
    return 0;
}
/*recur O(n)
#include <stdio.h>

// Helper function to calculate the sum of digits of a number recursively
int sumOfDigits(int num) {
    if (num == 0) {
        return 0;
    }
    return num % 10 + sumOfDigits(num / 10);  // Add the last digit and call recursively on the rest
}

// Helper recursive function to count frequencies of sum of digits
void countDigits(int n, int* count) {
    if (n == 0) {
        return;  // Base case, stop recursion when n reaches 0
    }
    
    int sum = sumOfDigits(n);  // Calculate the sum of digits of n
    count[sum]++;  // Increment the count for the current sum
    
    countDigits(n - 1, count);  // Recursively process the previous number
}

// Function to count the largest group of numbers by sum of digits
int countLargestGroup(int n) {
    int count[37] = {0};  // Sum of digits can range from 0 to 36 (for n <= 999999)
    
    countDigits(n, count);  // Recursively count the frequencies of sum of digits
    
    // Find the maximum group size
    int maxCount = 0;
    for (int i = 0; i < 37; i++) {
        if (count[i] > maxCount) {
            maxCount = count[i];
        }
    }
    
    // Count how many groups have the maximum size
    int largestGroupCount = 0;
    for (int i = 0; i < 37; i++) {
        if (count[i] == maxCount) {
            largestGroupCount++;
        }
    }
    
    return largestGroupCount;
}

int main() {
    int n = 13;  // Example input
    int result = countLargestGroup(n);
    printf("The count of largest groups is: %d\n", result);  // Expected output: 4
    return 0;
}
*/