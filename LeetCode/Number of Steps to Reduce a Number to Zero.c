#include <stdio.h>

int numberOfSteps (int num) {
    // Base case: when num is 0, return 0 steps.
    if (num == 0) {
        return 0;
    }
    
    // If the number is even, divide by 2; if odd, subtract 1.
    if (num % 2 == 0) {
        return 1 + numberOfSteps(num / 2);  // Divide by 2 and recurse.
    } else {
        return 1 + numberOfSteps(num - 1);  // Subtract 1 and recurse.
    }
}

// Example usage
int main() {
    int num = 14;
    int result = numberOfSteps(num);
    printf("Number of steps to reduce %d to 0: %d\n", num, result);  // Output should be 6
    return 0;
}
/*recur O(log n)
#include <stdio.h>

int numberOfSteps (int num) {
    // Base case: when num is 0, no more steps are needed.
    if (num == 0) {
        return 0;
    }
    
    // If num is even, divide by 2; otherwise, subtract 1.
    if (num % 2 == 0) {
        return 1 + numberOfSteps(num / 2);  // Divide by 2 and recurse.
    } else {
        return 1 + numberOfSteps(num - 1);  // Subtract 1 and recurse.
    }
}

// Example usage
int main() {
    int num = 14;
    int result = numberOfSteps(num);
    printf("Number of steps to reduce %d to 0: %d\n", num, result);  // Expected output: 6
    return 0;
}
*/