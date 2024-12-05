#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct {
    int value;
    int primeIndex;
} HeapNode;

int compare(const void* a, const void* b) {
    return ((HeapNode*)a)->value - ((HeapNode*)b)->value;
}

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    // Min-heap to keep track of the next candidate ugly numbers
    HeapNode* heap = (HeapNode*)malloc(primesSize * sizeof(HeapNode));
    int* uglyNumbers = (int*)malloc(n * sizeof(int));
    int* indices = (int*)calloc(primesSize, sizeof(int)); // Indexes for each prime
    int* values = (int*)malloc(primesSize * sizeof(int)); // Store the current value for each prime
    
    // Initialize heap and values for primes
    for (int i = 0; i < primesSize; i++) {
        values[i] = primes[i];
        heap[i].value = primes[i];
        heap[i].primeIndex = i;
    }

    // Initialize uglyNumbers array with first ugly number (1)
    uglyNumbers[0] = 1;

    // Heapify the heap
    qsort(heap, primesSize, sizeof(HeapNode), compare);

    for (int i = 1; i < n; i++) {
        // The smallest value in the heap is the next ugly number
        uglyNumbers[i] = heap[0].value;

        // Pop the smallest element from the heap and push the next multiple
        for (int j = 0; j < primesSize; j++) {
            if (heap[0].primeIndex == j && heap[0].value == values[j]) {
                indices[j]++;
                values[j] = uglyNumbers[indices[j]] * primes[j];
                heap[0].value = values[j];
                break;
            }
        }
        
        // Re-sort the heap
        qsort(heap, primesSize, sizeof(HeapNode), compare);
    }

    // The nth super ugly number is the last element in uglyNumbers
    int result = uglyNumbers[n - 1];

    // Clean up
    free(heap);
    free(uglyNumbers);
    free(indices);
    free(values);
    
    return result;
}

int main() {
    int primes[] = {2, 3, 5};
    int primesSize = sizeof(primes) / sizeof(primes[0]);
    int n = 12;
    
    int result = nthSuperUglyNumber(n, primes, primesSize);
    printf("The %d-th super ugly number is: %d\n", n, result);
    
    return 0;
}
/*recur O(n* primesize)
#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) {
    return (a < b) ? a : b;
}

// Helper function to recursively calculate nth super ugly number
int helper(int n, int* primes, int primesSize, int* uglyNumbers, int* indices, int* values) {
    // Base case: if we've calculated all ugly numbers up to nth
    if (n == 1) {
        return 1;
    }
    
    // Calculate the next potential ugly number by finding the minimum value from all the current primes
    int minVal = INT_MAX;
    for (int i = 0; i < primesSize; i++) {
        minVal = min(minVal, values[i]);
    }
    
    // Add the next ugly number
    uglyNumbers[n - 1] = minVal;
    
    // Update values for all primes that generated the minimum value
    for (int i = 0; i < primesSize; i++) {
        if (values[i] == minVal) {
            indices[i]++;
            values[i] = primes[i] * uglyNumbers[indices[i]];
        }
    }

    // Recursively calculate the next ugly number
    return helper(n - 1, primes, primesSize, uglyNumbers, indices, values);
}

int nthSuperUglyNumber(int n, int* primes, int primesSize) {
    // Array to store the ugly numbers
    int* uglyNumbers = (int*)malloc(n * sizeof(int));
    
    // Arrays to store the current index and the next value to be used for each prime
    int* indices = (int*)calloc(primesSize, sizeof(int));
    int* values = (int*)malloc(primesSize * sizeof(int));
    
    // Initialize the values array with the primes
    for (int i = 0; i < primesSize; i++) {
        values[i] = primes[i];
    }
    
    // The first ugly number is always 1
    uglyNumbers[0] = 1;
    
    // Recursively calculate the nth ugly number
    helper(n, primes, primesSize, uglyNumbers, indices, values);
    
    // The nth ugly number will be the last in the array
    int result = uglyNumbers[n - 1];
    
    // Clean up
    free(uglyNumbers);
    free(indices);
    free(values);
    
    return result;
}

int main() {
    int primes[] = {2, 3, 5};
    int primesSize = sizeof(primes) / sizeof(primes[0]);
    int n = 12;
    
    int result = nthSuperUglyNumber(n, primes, primesSize);
    printf("The %d-th super ugly number is: %d\n", n, result);
    
    return 0;
}
*/