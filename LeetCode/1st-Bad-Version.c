#include <stdio.h>
#include <stdbool.h>

// Assuming the API isBadVersion is defined for you
bool isBadVersion(int version) {
    // This is a placeholder. In actual code, the function will be provided by the system.
    // You should not define this in your solution.
}

// Function to find the first bad version
int firstBadVersion(int n) {
    int left = 1, right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;  // To avoid overflow
        if (isBadVersion(mid)) {
            right = mid;  // First bad version is at mid or to the left
        } else {
            left = mid + 1;  // First bad version is to the right of mid
        }
    }

    return left;  // left == right is the first bad version
}

// Main function to test
int main() {
    // Test case: Assuming we know that the first bad version is 4
    // The isBadVersion function would be simulated or provided in actual use
    int n = 5;  // Number of versions
    printf("The first bad version is: %d\n", firstBadVersion(n));  // Expected output: 4

    return 0;
}
/*Recursive approach          O(log n)
#include <stdio.h>
#include <stdbool.h>

// Placeholder for the API isBadVersion
bool isBadVersion(int version) {
    // Example implementation for testing:
    // Assuming version 4 and onward are bad.
    return version >= 4;
}

// Recursive helper function
int firstBadVersionHelper(int left, int right) {
    if (left == right) {
        return left;  // Found the first bad version
    }

    int mid = left + (right - left) / 2;  // To avoid overflow
    if (isBadVersion(mid)) {
        return firstBadVersionHelper(left, mid);  // Search in the left half
    } else {
        return firstBadVersionHelper(mid + 1, right);  // Search in the right half
    }
}

// Wrapper function for clarity
int firstBadVersion(int n) {
    return firstBadVersionHelper(1, n);  // Start the search from version 1 to n
}

// Main function to test
int main() {
    int n = 5;  // Number of versions
    printf("The first bad version is: %d\n", firstBadVersion(n));  // Expected output: 4
    return 0;
}

*/