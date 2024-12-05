#include <stdio.h>

void rotate(int** matrix, int matrixSize, int* matrixColSize) {
    // Step 1: Transpose the matrix (swap matrix[i][j] with matrix[j][i])
    for (int i = 0; i < matrixSize; i++) {
        for (int j = i + 1; j < matrixSize; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }

    // Step 2: Reverse each row
    for (int i = 0; i < matrixSize; i++) {
        int left = 0, right = matrixSize - 1;
        while (left < right) {
            int temp = matrix[i][left];
            matrix[i][left] = matrix[i][right];
            matrix[i][right] = temp;
            left++;
            right--;
        }
    }
}

// Helper function to print the matrix (for testing)
void printMatrix(int** matrix, int matrixSize) {
    for (int i = 0; i < matrixSize; i++) {
        for (int j = 0; j < matrixSize; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Example usage
int main() {
    int matrixSize = 3;
    int matrixColSize = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Convert matrix to a pointer array for passing to the function
    int* matrixPtr[3];
    for (int i = 0; i < matrixSize; i++) {
        matrixPtr[i] = matrix[i];
    }

    printf("Original matrix:\n");
    printMatrix(matrixPtr, matrixSize);

    rotate(matrixPtr, matrixSize, &matrixColSize);

    printf("\nRotated matrix:\n");
    printMatrix(matrixPtr, matrixSize);

    return 0;
}
/*recur O(n^2)
#include <stdio.h>

// Helper function to rotate a specific layer of the matrix
void rotateLayer(int** matrix, int n, int layer) {
    int first = layer;
    int last = n - layer - 1;
    for (int i = first; i < last; i++) {
        int offset = i - first;
        
        // Save the top element
        int top = matrix[first][i];
        
        // Move left to top
        matrix[first][i] = matrix[last - offset][first];
        
        // Move bottom to left
        matrix[last - offset][first] = matrix[last][last - offset];
        
        // Move right to bottom
        matrix[last][last - offset] = matrix[i][last];
        
        // Move top to right
        matrix[i][last] = top;
    }
}

// Recursive function to rotate the matrix by 90 degrees
void rotate(int** matrix, int n, int layer) {
    // Base case: if we've reached the center layer, stop
    if (layer >= n / 2) return;
    
    // Rotate the current layer
    rotateLayer(matrix, n, layer);
    
    // Recurse for the next inner layer
    rotate(matrix, n, layer + 1);
}

// Helper function to print the matrix
void printMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Example usage
int main() {
    int n = 3;
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Convert matrix to a pointer array for passing to the function
    int* matrixPtr[3];
    for (int i = 0; i < n; i++) {
        matrixPtr[i] = matrix[i];
    }

    printf("Original matrix:\n");
    printMatrix(matrixPtr, n);

    // Rotate the matrix by 90 degrees recursively
    rotate(matrixPtr, n, 0);

    printf("\nRotated matrix:\n");
    printMatrix(matrixPtr, n);

    return 0;
}
*/