#include <stdio.h>

int maxCount(int m, int n, int** ops, int opsSize, int* opsColSize) {
    if (opsSize == 0) {
        // If no operations, the whole matrix has the maximum value
        return m * n;
    }

    int minRow = m;
    int minCol = n;

    // Iterate through each operation and find the smallest range
    for (int i = 0; i < opsSize; i++) {
        if (ops[i][0] < minRow) {
            minRow = ops[i][0];
        }
        if (ops[i][1] < minCol) {
            minCol = ops[i][1];
        }
    }

    // The intersection area gives the count of maximum integers
    return minRow * minCol;
}

// Example usage
int main() {
    int m = 3, n = 3;
    int opsArray[][2] = {{2, 2}, {3, 3}};
    int opsSize = 2;
    int* ops[2];
    for (int i = 0; i < opsSize; i++) {
        ops[i] = opsArray[i];
    }
    int opsColSize[2] = {2, 2};

    int result = maxCount(m, n, ops, opsSize, opsColSize);
    printf("Maximum count of integers: %d\n", result);

    return 0;
}
