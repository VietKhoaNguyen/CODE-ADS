#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator function for sorting the scores in descending order
int compare(const void *a, const void *b) {
    return (*(int*)b - *(int*)a); // Sort in descending order
}

char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    
    // Allocate memory for the result array
    char** result = (char**)malloc(scoreSize * sizeof(char*));
    
    // Create an array of indices to track the original positions of the scores
    int* sortedIndices = (int*)malloc(scoreSize * sizeof(int));
    for (int i = 0; i < scoreSize; i++) {
        sortedIndices[i] = i;
    }
    
    // Sort the indices based on their corresponding scores in descending order
    qsort(sortedIndices, scoreSize, sizeof(int), 
          [](const void *a, const void *b) {
              return score[*(int*)b] - score[*(int*)a];
          });

    // Assign the ranks (medals or numeric)
    for (int i = 0; i < scoreSize; i++) {
        int index = sortedIndices[i];
        
        if (i == 0) {
            result[index] = "Gold Medal";
        } else if (i == 1) {
            result[index] = "Silver Medal";
        } else if (i == 2) {
            result[index] = "Bronze Medal";
        } else {
            // For the rest, use the rank as a string
            result[index] = (char*)malloc(12 * sizeof(char)); // Max length of rank (integer) in string
            sprintf(result[index], "%d", i + 1);
        }
    }

    free(sortedIndices); // Free the auxiliary index array
    return result;
}
int main() {
    int score[] = {5, 4, 3, 2, 1};
    int scoreSize = 5;
    int returnSize;

    char** result = findRelativeRanks(score, scoreSize, &returnSize);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i]);
    }
    printf("\n");

    // Free the memory allocated for result
    for (int i = 0; i < returnSize; i++) {
        if (result[i] != "Gold Medal" && result[i] != "Silver Medal" && result[i] != "Bronze Medal") {
            free(result[i]);  // Free dynamically allocated strings
        }
    }
    free(result); // Free the result array

    return 0;
}
/*recur O(n log n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper function to perform Quick Sort recursively
void quickSort(int* score, int* indices, int low, int high) {
    if (low < high) {
        // Partition the array
        int pivot = score[indices[high]];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (score[indices[j]] > pivot) {
                i++;
                int temp = indices[i];
                indices[i] = indices[j];
                indices[j] = temp;
            }
        }

        // Swap the pivot with the element at index i + 1
        int temp = indices[i + 1];
        indices[i + 1] = indices[high];
        indices[high] = temp;

        // Recursively sort the two halves
        quickSort(score, indices, low, i);
        quickSort(score, indices, i + 2, high);
    }
}

// Function to find relative ranks using recursion
char** findRelativeRanks(int* score, int scoreSize, int* returnSize) {
    *returnSize = scoreSize;
    
    // Allocate memory for the result array
    char** result = (char**)malloc(scoreSize * sizeof(char*));
    
    // Create an array of indices to track the original positions of the scores
    int* sortedIndices = (int*)malloc(scoreSize * sizeof(int));
    for (int i = 0; i < scoreSize; i++) {
        sortedIndices[i] = i;
    }

    // Recursively sort the indices based on their corresponding scores in descending order
    quickSort(score, sortedIndices, 0, scoreSize - 1);

    // Assign the ranks (medals or numeric)
    for (int i = 0; i < scoreSize; i++) {
        int index = sortedIndices[i];
        
        if (i == 0) {
            result[index] = "Gold Medal";
        } else if (i == 1) {
            result[index] = "Silver Medal";
        } else if (i == 2) {
            result[index] = "Bronze Medal";
        } else {
            // For the rest, use the rank as a string
            result[index] = (char*)malloc(12 * sizeof(char)); // Max length of rank (integer) in string
            sprintf(result[index], "%d", i + 1);
        }
    }

    free(sortedIndices); // Free the auxiliary index array
    return result;
}

int main() {
    int score[] = {5, 4, 3, 2, 1};
    int scoreSize = 5;
    int returnSize;

    char** result = findRelativeRanks(score, scoreSize, &returnSize);

    // Print the result
    for (int i = 0; i < returnSize; i++) {
        printf("%s ", result[i]);
    }
    printf("\n");

    // Free the memory allocated for result
    for (int i = 0; i < returnSize; i++) {
        if (result[i] != "Gold Medal" && result[i] != "Silver Medal" && result[i] != "Bronze Medal") {
            free(result[i]);  // Free dynamically allocated strings
        }
    }
    free(result); // Free the result array

    return 0;
}
*/