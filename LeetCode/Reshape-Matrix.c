#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    // Step 1: Check if reshape is possible
    if (matSize * matColSize[0] != r * c) {
        *returnSize = matSize;
        *returnColumnSizes = (int*)malloc(matSize * sizeof(int));
        for (int i = 0; i < matSize; i++) {
            (*returnColumnSizes)[i] = matColSize[i];
        }
        return mat;  // No reshaping, return the original matrix
    }

    // Step 2: Flatten the matrix into a 1D array
    int* flattened = (int*)malloc(matSize * matColSize[0] * sizeof(int));
    int index = 0;
    for (int i = 0; i < matSize; i++) {
        for (int j = 0; j < matColSize[i]; j++) {
            flattened[index++] = mat[i][j];
        }
    }

    // Step 3: Create the reshaped matrix
    int** reshapedMatrix = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        reshapedMatrix[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
        for (int j = 0; j < c; j++) {
            reshapedMatrix[i][j] = flattened[i * c + j];
        }
    }

    // Free the flattened array
    free(flattened);

    *returnSize = r;  // Set returnSize to the number of rows in the reshaped matrix
    return reshapedMatrix;
}
