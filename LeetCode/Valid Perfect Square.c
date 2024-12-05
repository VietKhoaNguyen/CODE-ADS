#include <stdio.h>
#include <stdbool.h>

bool isPerfectSquare(int num) {
    if (num < 0) {
        return false; // Negative numbers cannot be perfect squares
    }

    int left = 0, right = num;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        long long square = (long long)mid * mid;  // Avoid overflow for large numbers

        if (square == num) {
            return true;  // Found the perfect square
        } else if (square < num) {
            left = mid + 1;  // Move right if square is smaller
        } else {
            right = mid - 1;  // Move left if square is larger
        }
    }

    return false;  // If no square root found, return false
}

int main() {
    int num = 16;
    
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
        return false; // No perfect square found
    }

    int mid = left + (right - left) / 2;
    long long square = (long long)mid * mid;  // Avoid overflow for large numbers

    if (square == num) {
        return true;  // Found the perfect square
    } else if (square < num) {
        return isPerfectSquareRecursive(mid + 1, right, num); // Search in the right half
    } else {
        return isPerfectSquareRecursive(left, mid - 1, num); // Search in the left half
    }
}

bool isPerfectSquare(int num) {
    if (num < 0) {
        return false; // Negative numbers cannot be perfect squares
    }

    return isPerfectSquareRecursive(0, num, num); // Start binary search
}

int main() {
    int num = 16;
    
    if (isPerfectSquare(num)) {
        printf("%d is a perfect square.\n", num);
    } else {
        printf("%d is not a perfect square.\n", num);
    }

    return 0;
}
*/