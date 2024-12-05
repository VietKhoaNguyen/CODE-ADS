#include <stdio.h>

// Function to find the minimum steps to reach 1 iteratively
int minSteps(int n) {
    int steps = 0;
    
    // Keep reducing n until we reach 1
    while (n > 1) {
        // If n is even, divide by 2
        if (n % 2 == 0) {
            n /= 2;
        } else {
            // If n is odd, subtract 1 to make it even
            n -= 1;
        }
        // Increment the step counter
        steps++;
    }

    return steps;
}

int main() {
    int n = 10;
    int result = minSteps(n);
    printf("Minimum steps to reach %d: %d\n", n, result);
    return 0;
}
/*recur O(logn)
#include <stdio.h>

// Function to find the minimum steps to reach 1
int minSteps(int n) {
    // Base case: if n is 1, we don't need any steps
    if (n == 1) {
        return 0;
    }

    // If n is even, we divide by 2
    if (n % 2 == 0) {
        return 1 + minSteps(n / 2);
    }
    
    // If n is odd, we subtract 1 and then apply the same logic
    return 1 + minSteps(n - 1);
}

int main() {
    int n = 10;
    int result = minSteps(n);
    printf("Minimum steps to reach %d: %d\n", n, result);
    return 0;
}
*/