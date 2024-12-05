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
/*recur O(n^2)
#include <stdlib.h>

// Helper function to calculate a specific element in Pascal's triangle row
int calculateElement(int rowIndex, int colIndex) {
    // Base case: when the column is at the boundary (first or last column), return 1
    if (colIndex == 0 || colIndex == rowIndex) {
        return 1;
    }

    // Recursive case: calculate element based on previous row elements
    return calculateElement(rowIndex - 1, colIndex - 1) + calculateElement(rowIndex - 1, colIndex);
}

// Recursive function to generate Pascal's Triangle
void generateRow(int** triangle, int rowIndex, int* returnColumnSizes) {
    // Allocate memory for the current row
    triangle[rowIndex] = (int*)malloc((rowIndex + 1) * sizeof(int));

    // Set the column size for this row
    returnColumnSizes[rowIndex] = rowIndex + 1;

    // Fill in the elements of the row
    for (int j = 0; j <= rowIndex; j++) {
        triangle[rowIndex][j] = calculateElement(rowIndex, j);
    }
}

// Function to generate the entire Pascal's Triangle using recursion
int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for the result 2D array
    int** triangle = (int**)malloc(numRows * sizeof(int*));

    // Allocate memory for column sizes
    *returnColumnSizes = (int*)malloc(numRows * sizeof(int));

    // Set the returnSize
    *returnSize = numRows;

    // Generate each row recursively
    for (int i = 0; i < numRows; i++) {
        generateRow(triangle, i, *returnColumnSizes);
    }

    return triangle;
}
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
