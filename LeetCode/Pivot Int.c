#include <stdio.h>

int pivotInteger(int n) {
    // Total sum of numbers from 1 to n
    int totalSum = n * (n + 1) / 2;

    int leftSum = 0; // Sum of numbers from 1 to x
    for (int x = 1; x <= n; x++) {
        leftSum += x; // Add current x to left sum

        // Right sum = Total sum - Left sum + current x
        int rightSum = totalSum - leftSum + x;

        if (leftSum == rightSum) {
            return x; // Found the pivot
        }
    }

    return -1; // No pivot found
}

int main() {
    int n;

    // Input value of n
    printf("Enter n: ");
    scanf("%d", &n);

    // Find and display the pivot integer
    int result = pivotInteger(n);
    if (result != -1) {
        printf("The pivot integer is: %d\n", result);
    } else {
        printf("No pivot integer exists.\n");
    }

    return 0;
}
/*recur O(n)
#include <stdio.h>

// Helper function to compute the sum of integers from 1 to k
int sumUpTo(int k) {
    if (k == 0) {
        return 0; // Base case
    }
    return k + sumUpTo(k - 1); // Recursive step
}

// Recursive function to find the pivot integer
int findPivot(int x, int n, int totalSum, int leftSum) {
    if (x > n) {
        return -1; // No pivot found
    }

    leftSum += x; // Add the current x to the left sum

    // Calculate the right sum
    int rightSum = totalSum - leftSum + x;

    if (leftSum == rightSum) {
        return x; // Found the pivot
    }

    // Recurse for the next integer
    return findPivot(x + 1, n, totalSum, leftSum);
}

// Main function to find the pivot integer
int pivotInteger(int n) {
    int totalSum = sumUpTo(n); // Total sum of integers from 1 to n
    return findPivot(1, n, totalSum, 0);
}

int main() {
    int n;

    // Input value of n
    printf("Enter n: ");
    scanf("%d", &n);

    // Find and display the pivot integer
    int result = pivotInteger(n);
    if (result != -1) {
        printf("The pivot integer is: %d\n", result);
    } else {
        printf("No pivot integer exists.\n");
    }

    return 0;
}
*/