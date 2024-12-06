#include <stdlib.h>
#include <limits.h>

int minAreaRect(int** points, int pointsSize, int* pointsColSize) {
    // Hash table to store points
    int hashSize = 40001; // Assuming the coordinates fit within the range [-20000, 20000]
    int offset = 20000;   // Offset for negative coordinates
    int* hashTable = (int*)calloc(hashSize, sizeof(int));

    // Fill the hash table with all the points
    for (int i = 0; i < pointsSize; i++) {
        int x = points[i][0] + offset;
        int y = points[i][1] + offset;
        hashTable[x * hashSize + y] = 1; // Store the point in a 1D hash
    }

    int minArea = INT_MAX;

    // Iterate over all pairs of points
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];

            // Check if they can form a diagonal of a rectangle
            if (x1 != x2 && y1 != y2) {
                // Check if the other two corners exist
                if (hashTable[(x1 + offset) * hashSize + (y2 + offset)] &&
                    hashTable[(x2 + offset) * hashSize + (y1 + offset)]) {
                    int area = abs(x1 - x2) * abs(y1 - y2);
                    minArea = (area < minArea) ? area : minArea;
                }
            }
        }
    }

    free(hashTable);
    return minArea == INT_MAX ? 0 : minArea;
}

// Example usage

#include <stdio.h>

int main() {
    int pointsArray[6][2] = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
    int* points[6];
    for (int i = 0; i < 6; i++) {
        points[i] = pointsArray[i];
    }
    int pointsColSize = 2;
    int result = minAreaRect(points, 6, &pointsColSize);
    printf("Minimum area rectangle: %d\n", result);
    return 0;
}
/*recur O(n^3)
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Helper function to check if a point exists in the points array
bool pointExists(int** points, int pointsSize, int* target) {
    for (int i = 0; i < pointsSize; i++) {
        if (points[i][0] == target[0] && points[i][1] == target[1]) {
            return true;
        }
    }
    return false;
}

// Recursive function to compute the minimum area
int minAreaRectRecursive(int** points, int pointsSize, int index, int currentMin) {
    // Base case: If we have checked all pairs
    if (index >= pointsSize) {
        return currentMin;
    }

    // Iterate over all pairs starting from the current index
    for (int i = index + 1; i < pointsSize; i++) {
        int* p1 = points[index];
        int* p2 = points[i];

        // If points are diagonally opposite
        if (p1[0] != p2[0] && p1[1] != p2[1]) {
            int other1[] = {p1[0], p2[1]};
            int other2[] = {p2[0], p1[1]};

            // Check if the other two corners exist
            if (pointExists(points, pointsSize, other1) && pointExists(points, pointsSize, other2)) {
                int area = abs(p1[0] - p2[0]) * abs(p1[1] - p2[1]);
                currentMin = (area < currentMin) ? area : currentMin;
            }
        }
    }

    // Recurse for the next index
    return minAreaRectRecursive(points, pointsSize, index + 1, currentMin);
}

// Main function to find the minimum area rectangle
int minAreaRect(int** points, int pointsSize, int* pointsColSize) {
    int result = minAreaRectRecursive(points, pointsSize, 0, INT_MAX);
    return result == INT_MAX ? 0 : result; // Return 0 if no rectangle found
}

// Example usage
/*
#include <stdio.h>

int main() {
    int pointsArray[5][2] = {{1, 1}, {1, 3}, {3, 1}, {3, 3}, {2, 2}};
    int* points[5];
    for (int i = 0; i < 5; i++) {
        points[i] = pointsArray[i];
    }
    int pointsColSize = 2;
    int result = minAreaRect(points, 5, &pointsColSize);
    printf("Minimum area rectangle: %d\n", result);
    return 0;
}
*/

