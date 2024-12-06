#include <stdio.h>

int brokenCalc(int startValue, int target) {
    int operations = 0;
    
    while (target > startValue) {
        // If target is even, divide by 2
        if (target % 2 == 0) {
            target /= 2;
        } else {
            // If target is odd, add 1
            target += 1;
        }
        operations++;
    }

    // If startValue is greater than target, we need to subtract the difference
    return operations + (startValue - target);
}

// Example usage
int main() {
    int startValue = 2;
    int target = 10;

    int result = brokenCalc(startValue, target);
    printf("Minimum number of operations: %d\n", result);

    return 0;
}
/*recur O(log target)
#include <stdio.h>

// Helper recursive function
int brokenCalcRecursive(int startValue, int target) {
    // Base case: when target is less than or equal to startValue
    if (target <= startValue) {
        return startValue - target;  // We only need to subtract 1 for the difference
    }

    // Recursive case:
    if (target % 2 == 0) {
        // If target is even, divide by 2
        return 1 + brokenCalcRecursive(startValue, target / 2);
    } else {
        // If target is odd, add 1 to make it even
        return 1 + brokenCalcRecursive(startValue, target + 1);
    }
}

// Main function that calls the recursive helper
int brokenCalc(int startValue, int target) {
    return brokenCalcRecursive(startValue, target);
}

// Example usage
int main() {
    int startValue = 2;
    int target = 10;

    int result = brokenCalc(startValue, target);
    printf("Minimum number of operations: %d\n", result);

    return 0;
}
*/