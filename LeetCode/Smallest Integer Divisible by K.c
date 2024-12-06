#include <stdio.h>

int smallestRepunitDivByK(int k) {
    // Special case where k is 1, the answer is always 1 (as 1 is divisible by 1)
    if (k == 1) return 1;

    int remainder = 1;
    int length = 1;

    // We use a set of seen remainders to detect a cycle (loop)
    int *seen = (int *)calloc(k, sizeof(int)); // Array to track seen remainders
    while (remainder % k != 0) {
        // If we've seen this remainder before, it means we are in a cycle
        if (seen[remainder]) {
            free(seen); // Free memory before returning
            return -1;
        }
        seen[remainder] = 1; // Mark this remainder as seen

        // Update the remainder for the next repunit by adding a '1' at the end
        remainder = (remainder * 10 + 1) % k;
        length++;
    }

    free(seen); // Free memory before returning
    return length;
}

// Example usage
int main() {
    int k = 3;
    int result = smallestRepunitDivByK(k);
    printf("Smallest repunit divisible by %d is of length: %d\n", k, result);
    return 0;
}
/*recur O(k)
#include <stdio.h>
#include <stdlib.h>

int smallestRepunitDivByKRecursive(int k, int remainder, int length, int* seen) {
    // Base case: If remainder % k == 0, we found the valid repunit
    if (remainder % k == 0) {
        return length;
    }

    // If we've seen this remainder, we are in a cycle and should return -1
    if (seen[remainder]) {
        return -1;
    }

    // Mark this remainder as seen
    seen[remainder] = 1;

    // Recursively explore the next remainder
    // Update the remainder for the next repunit by appending '1'
    return smallestRepunitDivByKRecursive(k, (remainder * 10 + 1) % k, length + 1, seen);
}

int smallestRepunitDivByK(int k) {
    // Special case: If k == 1, the answer is always 1
    if (k == 1) return 1;

    // Initialize the seen array to keep track of the remainders we've seen
    int* seen = (int*)calloc(k, sizeof(int));

    // Start with remainder = 1, representing the number '1', and length = 1
    int result = smallestRepunitDivByKRecursive(k, 1, 1, seen);

    // Free the memory allocated for the seen array
    free(seen);

    return result;
}

int main() {
    int k = 3;
    int result = smallestRepunitDivByK(k);
    printf("Smallest repunit divisible by %d is of length: %d\n", k, result);
    return 0;
}
*/