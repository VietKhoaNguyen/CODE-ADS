#include <stdlib.h>

int* getRow(int rowIndex, int* returnSize) {
    // Allocate memory for the row. The number of elements in the row is rowIndex + 1.
    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));
    
    // Set the returnSize to the number of elements in the row
    *returnSize = rowIndex + 1;
    
    // The first element in the row is always 1
    row[0] = 1;
    
    // Calculate the rest of the elements based on the previous ones
    for (int j = 1; j <= rowIndex; j++) {
        // Use the formula: row[j] = row[j-1] * (rowIndex - j + 1) / j
        row[j] = (row[j - 1] * (rowIndex - j + 1)) / j;
    }
    
    return row;
}
/*recur O(2^n)
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

// Main function to generate the row
int* getRow(int rowIndex, int* returnSize) {
    // Allocate memory for the row. The number of elements in the row is rowIndex + 1.
    int* row = (int*)malloc((rowIndex + 1) * sizeof(int));
    
    // Set the returnSize to the number of elements in the row
    *returnSize = rowIndex + 1;

    // Calculate each element in the row recursively
    for (int j = 0; j <= rowIndex; j++) {
        row[j] = calculateElement(rowIndex, j);
    }

    return row;
}
*/
