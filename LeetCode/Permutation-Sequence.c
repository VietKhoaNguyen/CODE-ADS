#include <stdio.h>
#include <stdlib.h>

// Helper function to calculate factorial
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

char* getPermutation(int n, int k) {
    // Initialize the list of numbers and the result string
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0'; // Null-terminate the result string
    int* nums = (int*)malloc(n * sizeof(int)); // To store numbers 1 to n
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    // Adjust k to be zero-based for easier calculations
    k--;

    // Generate the permutation
    for (int i = 0; i < n; i++) {
        int fact = factorial(n - 1 - i);  // Factorial of remaining numbers
        int index = k / fact;            // Determine which number should be at the current position
        result[i] = nums[index] + '0';  // Append the character to the result (convert int to char)
        // Remove the chosen number from the list
        for (int j = index; j < n - 1; j++) {
            nums[j] = nums[j + 1];
        }
        k %= fact;  // Reduce k to the new position in the block
    }

    free(nums);  // Free the memory allocated for nums
    return result;
}

int main() {
    int n = 3;
    int k = 3;
    char* result = getPermutation(n, k);
    printf("The %d-th permutation of numbers 1 to %d is: %s\n", k, n, result);
    free(result);  // Free the memory allocated for result
    return 0;
}
/*recur O(n^2)
#include <stdio.h>
#include <stdlib.h>

// Helper function to calculate factorial
int factorial(int n) {
    int result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// Recursive helper function to get the k-th permutation
void getPermutationRecursive(int n, int k, int* nums, char* result, int index) {
    if (n == 0) {
        return;  // Base case: no more digits to process
    }

    int fact = factorial(n - 1);  // Factorial of (n-1) to determine the block size
    int idx = (k - 1) / fact;     // Find the index of the current number
    result[index] = nums[idx] + '0';  // Add the corresponding number to the result

    // Shift the remaining numbers in the array
    for (int i = idx; i < n - 1; i++) {
        nums[i] = nums[i + 1];
    }

    // Recur for the next position with the updated k and reduced n
    getPermutationRecursive(n - 1, (k - 1) % fact + 1, nums, result, index + 1);
}

char* getPermutation(int n, int k) {
    // Allocate space for the result string
    char* result = (char*)malloc((n + 1) * sizeof(char));
    result[n] = '\0';  // Null-terminate the result string
    
    // Initialize the nums array to contain numbers from 1 to n
    int* nums = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        nums[i] = i + 1;
    }

    // Call the recursive function
    getPermutationRecursive(n, k, nums, result, 0);

    free(nums);  // Free the nums array
    return result;
}

int main() {
    int n = 3;
    int k = 3;
    char* result = getPermutation(n, k);
    printf("The %d-th permutation of numbers 1 to %d is: %s\n", k, n, result);
    free(result);  // Free the memory allocated for result
    return 0;
}
*/