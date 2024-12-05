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
/*recur O(n*m)
#include <stdio.h>
#include <stdlib.h>

void flattenMatrix(int** mat, int matSize, int* matColSize, int* flattened, int index, int row) {
    // Base case: When we've traversed the entire matrix
    if (row == matSize) {
        return;
    }

    // Recursively flatten the current row
    for (int col = 0; col < matColSize[row]; col++) {
        flattened[index++] = mat[row][col];
    }

    // Move to the next row
    flattenMatrix(mat, matSize, matColSize, flattened, index, row + 1);
}

void buildReshapedMatrix(int* flattened, int r, int c, int index, int row, int** reshapedMatrix) {
    // Base case: When we've filled all rows
    if (row == r) {
        return;
    }

    // Fill the current row
    for (int col = 0; col < c; col++) {
        reshapedMatrix[row][col] = flattened[index++];
    }

    // Move to the next row
    buildReshapedMatrix(flattened, r, c, index, row + 1, reshapedMatrix);
}

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

    // Step 2: Flatten the matrix into a 1D array recursively
    int* flattened = (int*)malloc(matSize * matColSize[0] * sizeof(int));
    flattenMatrix(mat, matSize, matColSize, flattened, 0, 0);

    // Step 3: Create the reshaped matrix and fill it recursively
    int** reshapedMatrix = (int**)malloc(r * sizeof(int*));
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    for (int i = 0; i < r; i++) {
        reshapedMatrix[i] = (int*)malloc(c * sizeof(int));
        (*returnColumnSizes)[i] = c;
    }

    buildReshapedMatrix(flattened, r, c, 0, 0, reshapedMatrix);

    // Free the flattened array
    free(flattened);

    *returnSize = r;  // Set returnSize to the number of rows in the reshaped matrix
    return reshapedMatrix;
}

int main() {
    // Example test case
    int mat[2][2] = {{1, 2}, {3, 4}};
    int* matPtr[2];
    for (int i = 0; i < 2; i++) {
        matPtr[i] = mat[i];
    }
    int matColSize[] = {2, 2};
    int r = 1, c = 4; // Reshaped matrix dimensions

    int returnSize;
    int* returnColumnSizes;

    int** reshapedMatrix = matrixReshape(matPtr, 2, matColSize, r, c, &returnSize, &returnColumnSizes);

    // Print the reshaped matrix
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", reshapedMatrix[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < returnSize; i++) {
        free(reshapedMatrix[i]);
    }
    free(reshapedMatrix);
    free(returnColumnSizes);

    return 0;
}
*/