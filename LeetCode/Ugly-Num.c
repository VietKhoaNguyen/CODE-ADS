#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is ugly
bool isUgly(int n) {
    // Special case: Ugly numbers are positive
    if (n <= 0) {
        return false;
    }

    // Continuously divide by 2, 3, and 5
    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }

    // If n becomes 1, it means it only had 2, 3, and 5 as factors
    return n == 1;
}

// Main function to test the isUgly function
int main() {
    // Test cases
    int nums[] = {6, 8, 14, 1, -6};
    for (int i = 0; i < 5; i++) {
        printf("Is %d ugly? %s\n", nums[i], isUgly(nums[i]) ? "Yes" : "No");
    }

    return 0;
}
