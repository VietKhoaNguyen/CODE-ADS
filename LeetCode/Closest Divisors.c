#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Helper function to find divisors of a number
void findDivisors(int num, int** divisors, int* size) {
    *size = 0;
    *divisors = (int*)malloc(20 * sizeof(int)); // Arbitrary size allocation, we will resize if necessary

    // Find divisors of the number
    for (int i = 1; i <= sqrt(num); i++) {
        if (num % i == 0) {
            (*divisors)[(*size)++] = i;
            if (i != num / i) {
                (*divisors)[(*size)++] = num / i;
            }
        }
    }
}

// Function to find the closest divisors
int* closestDivisors(int num, int* returnSize) {
    int *divisors1, *divisors2;
    int size1, size2;
    
    // Find divisors of num + 1
    findDivisors(num + 1, &divisors1, &size1);
    // Find divisors of num + 2
    findDivisors(num + 2, &divisors2, &size2);

    int minDiff = INT_MAX;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Compare divisors of num + 1
    for (int i = 0; i < size1; i++) {
        for (int j = i; j < size1; j++) {
            int diff = abs(divisors1[i] - divisors1[j]);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = divisors1[i];
                result[1] = divisors1[j];
            }
        }
    }
    
    // Compare divisors of num + 2
    for (int i = 0; i < size2; i++) {
        for (int j = i; j < size2; j++) {
            int diff = abs(divisors2[i] - divisors2[j]);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = divisors2[i];
                result[1] = divisors2[j];
            }
        }
    }

    *returnSize = 2; // Size of the result array is 2, as we're returning a pair of divisors
    return result;
}

int main() {
    int num = 8;
    int returnSize;
    int* result = closestDivisors(num, &returnSize);
    printf("Closest Divisors: %d, %d\n", result[0], result[1]);
    free(result);  // Don't forget to free the memory
    return 0;
}
/*recur O(sqrt(n))
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Helper recursive function to find divisors
void findDivisorsRecursive(int num, int current, int* divisors, int* index) {
    if (current > sqrt(num)) {
        return;
    }
    
    if (num % current == 0) {
        divisors[*index] = current;
        (*index)++;
        
        if (current != num / current) {  // Avoid adding the square root twice
            divisors[*index] = num / current;
            (*index)++;
        }
    }
    
    findDivisorsRecursive(num, current + 1, divisors, index);  // Recursively check next number
}

// Function to find the closest divisors
int* closestDivisors(int num, int* returnSize) {
    int *divisors1 = (int*)malloc(20 * sizeof(int));  // Arbitrary size for divisors array
    int *divisors2 = (int*)malloc(20 * sizeof(int));  // Arbitrary size for divisors array
    int size1 = 0, size2 = 0;
    
    // Find divisors of num + 1 using recursion
    findDivisorsRecursive(num + 1, 1, divisors1, &size1);
    
    // Find divisors of num + 2 using recursion
    findDivisorsRecursive(num + 2, 1, divisors2, &size2);

    int minDiff = INT_MAX;
    int* result = (int*)malloc(2 * sizeof(int));
    
    // Compare divisors of num + 1
    for (int i = 0; i < size1; i++) {
        for (int j = i; j < size1; j++) {
            int diff = abs(divisors1[i] - divisors1[j]);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = divisors1[i];
                result[1] = divisors1[j];
            }
        }
    }
    
    // Compare divisors of num + 2
    for (int i = 0; i < size2; i++) {
        for (int j = i; j < size2; j++) {
            int diff = abs(divisors2[i] - divisors2[j]);
            if (diff < minDiff) {
                minDiff = diff;
                result[0] = divisors2[i];
                result[1] = divisors2[j];
            }
        }
    }

    *returnSize = 2;  // Return an array of size 2 (a pair of divisors)
    free(divisors1);  // Free memory for divisors1 array
    free(divisors2);  // Free memory for divisors2 array
    return result;
}

int main() {
    int num = 8;
    int returnSize;
    int* result = closestDivisors(num, &returnSize);
    printf("Closest Divisors: %d, %d\n", result[0], result[1]);
    free(result);  // Don't forget to free the memory
    return 0;
}
*/