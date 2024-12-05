#include <stdio.h>

int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;  // The square root of 0 is 0 and the square root of 1 is 1
    }
    
    int left = 0, right = x / 2, mid;
    
    // Binary search for the square root
    while (left <= right) {
        mid = left + (right - left) / 2;
        
        // Check if mid*mid is equal to x
        if (mid * mid == x) {
            return mid;
        }
        
        // If mid*mid is less than x, move to the right half
        if (mid * mid < x) {
            left = mid + 1;
        }
        // If mid*mid is greater than x, move to the left half
        else {
            right = mid - 1;
        }
    }
    
    // If no exact square root is found, return the integer part (floor)
    return right;
}

// Main function to test mySqrt
int main() {
    int x = 8;
    printf("The square root of %d is %d\n", x, mySqrt(x));  // Expected output: 2
    
    x = 16;
    printf("The square root of %d is %d\n", x, mySqrt(x));  // Expected output: 4
    return 0;
}
/*recur O(log x)
#include <stdio.h>

int mySqrtRecursive(int left, int right, int x) {
    if (left > right) {
        return right;  // Return the integer part (floor) of the square root
    }

    int mid = left + (right - left) / 2;
    
    // Check if mid * mid is equal to x
    if (mid * mid == x) {
        return mid;
    }
    
    // If mid * mid is less than x, move to the right half
    if (mid * mid < x) {
        return mySqrtRecursive(mid + 1, right, x);
    }
    
    // If mid * mid is greater than x, move to the left half
    return mySqrtRecursive(left, mid - 1, x);
}

int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;  // The square root of 0 is 0 and the square root of 1 is 1
    }
    
    return mySqrtRecursive(0, x / 2, x);
}

// Main function to test mySqrt
int main() {
    int x = 8;
    printf("The square root of %d is %d\n", x, mySqrt(x));  // Expected output: 2
    
    x = 16;
    printf("The square root of %d is %d\n", x, mySqrt(x));  // Expected output: 4
    return 0;
}
*/