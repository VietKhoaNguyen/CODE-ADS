#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquare(int num) {
    if (num < 1) return false; // Negative numbers and zero are not perfect squares.

    long long left = 1, right = num; // Use long long to prevent overflow
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        long long square = mid * mid;

        if (square == num) {
            return true; // Found a perfect square
        } else if (square < num) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return false; // Not a perfect square
}

int main() {
    int num = 16; // Test case
    if (isPerfectSquare(num)) {
        printf("%d is a perfect square.\n", num);
    } else {
        printf("%d is not a perfect square.\n", num);
    }

    return 0;
}
/*recur O(log n)
#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquareRecursive(int left, int right, int num) {
    if (left > right) {
        return false; // Not a perfect square
    }

    long long mid = left + (right - left) / 2;
    long long square = mid * mid;

    if (square == num) {
        return true; // Found a perfect square
    } else if (square < num) {
        return isPerfectSquareRecursive(mid + 1, right, num); // Search in the right half
    } else {
        return isPerfectSquareRecursive(left, mid - 1, num); // Search in the left half
    }
}

bool isPerfectSquare(int num) {
    if (num < 1) {
        return false; // Negative numbers and zero are not perfect squares
    }
    return isPerfectSquareRecursive(1, num, num); // Start the recursion
}

int main() {
    int num = 16; // Test case
    if (isPerfectSquare(num)) {
        printf("%d is a perfect square.\n", num);
    } else {
        printf("%d is not a perfect square.\n", num);
    }

    return 0;
}
*/