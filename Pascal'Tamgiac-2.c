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
