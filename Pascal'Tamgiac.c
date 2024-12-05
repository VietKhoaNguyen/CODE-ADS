#include <stdlib.h>

// Function to generate Pascal's Triangle
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the result 2D array
    int** triangle = (int**)malloc(numRows * sizeof(int*));
    
    // Allocate memory for column sizes
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));
    
    // Set the returnSize
    *returnSize = numRows;
    
    for (int i = 0; i < numRows; i++) {
        // For each row, allocate an array to store the row elements
        triangle[i] = (int*)malloc((i + 1) * sizeof(int));
        
        // Set the column size for this row
        (*returnColumnSizes)[i] = i + 1;
        
        // The first and last elements of each row are always 1
        triangle[i][0] = 1;
        triangle[i][i] = 1;
        
        // Fill in the middle elements of the row
        for (int j = 1; j < i; j++) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    
    return triangle;
}
