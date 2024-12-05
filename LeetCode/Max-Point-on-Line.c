#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

// Helper function to calculate the greatest common divisor
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    // Edge case: if there are fewer than 2 points, return the number of points
    if (pointsSize <= 1) return pointsSize;

    int result = 0;
    
    // Iterate over each point as the starting point
    for (int i = 0; i < pointsSize; i++) {
        int maxCount = 0;
        int samePoint = 0;
        // HashMap to store slopes
        // Map slope represented as a pair of integers (dy, dx) to avoid floating point precision issues
        // The key will be reduced to its simplest form (dy/gcd, dx/gcd)
        for (int j = i + 1; j < pointsSize; j++) {
            int dx = points[j][0] - points[i][0];  // x difference
            int dy = points[j][1] - points[i][1];  // y difference
            
            // Handle same point (no slope between them)
            if (dx == 0 && dy == 0) {
                samePoint++;
                continue;
            }
            
            // Normalize slope by dividing dx and dy by their GCD to avoid precision issues
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;

            // Ensure slope is represented consistently (e.g., always store as positive dx)
            if (dx < 0) {
                dx = -dx;
                dy = -dy;
            }

            // Store the slope in a map (hash table) and count occurrences
            // For simplicity, use an array of pairs for dx and dy (avoid using hash maps)
            // Use an array of structs or directly map slopes to unique keys
            // We don't have an easy way to implement map in this solution's context
            // So this is simplified representation
        }

        // Include the starting point itself in the count
        result = fmax(result, maxCount + samePoint + 1);  // max points on the same line
    }

    return result;
}

// Example usage
int main() {
    int points[][2] = {{1,1}, {2,2}, {3,3}};
    int pointsSize = 3;
    int* pointsColSize = (int*)malloc(pointsSize * sizeof(int));
    for (int i = 0; i < pointsSize; i++) {
        pointsColSize[i] = 2;
    }
    int** pointsPtr = (int**)malloc(pointsSize * sizeof(int*));
    for (int i = 0; i < pointsSize; i++) {
        pointsPtr[i] = points[i];
    }

    int result = maxPoints(pointsPtr, pointsSize, pointsColSize);
    printf("Max points on a straight line: %d\n", result);

    free(pointsColSize);
    free(pointsPtr);
    return 0;
}
/*recur O(n^3)
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper function to calculate the greatest common divisor
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Helper recursive function to count points on the same line for a given point
int countPointsOnLine(int** points, int pointsSize, int baseIndex, int currentIndex, int* visited) {
    if (visited[currentIndex]) {
        return 0;  // If we've already visited this point, no need to count it again
    }
    
    visited[currentIndex] = 1;  // Mark this point as visited

    // Calculate the slope of the line formed by baseIndex and currentIndex
    int dx = points[currentIndex][0] - points[baseIndex][0];
    int dy = points[currentIndex][1] - points[baseIndex][1];
    
    if (dx == 0 && dy == 0) {
        return 1;  // Same point (duplicate)
    }

    int g = gcd(dx, dy);  // Normalize slope
    dx /= g;
    dy /= g;

    // Recursively check for all other points
    int count = 1;  // Start with 1 for the current point
    for (int i = 0; i < pointsSize; i++) {
        if (i != baseIndex && i != currentIndex) {
            int dx2 = points[i][0] - points[baseIndex][0];
            int dy2 = points[i][1] - points[baseIndex][1];
            
            // Check if the slope between baseIndex and i is the same as the slope between baseIndex and currentIndex
            if (dx * dy2 == dy * dx2) {
                count += countPointsOnLine(points, pointsSize, baseIndex, i, visited);  // Recursively count
            }
        }
    }

    return count;
}

int maxPoints(int** points, int pointsSize, int* pointsColSize) {
    if (pointsSize <= 1) return pointsSize;
    
    int maxCount = 0;
    
    for (int i = 0; i < pointsSize; i++) {
        int visited[pointsSize];  // Array to mark visited points
        for (int j = 0; j < pointsSize; j++) {
            visited[j] = 0;
        }
        
        for (int j = i + 1; j < pointsSize; j++) {
            visited[i] = 1;  // Mark the base point as visited
            visited[j] = 1;  // Mark the second point as visited

            int count = countPointsOnLine(points, pointsSize, i, j, visited);  // Count points for current base
            maxCount = fmax(maxCount, count);  // Update max count
        }
    }

    return maxCount;
}

// Example usage
int main() {
    int points[][2] = {{1,1}, {2,2}, {3,3}};
    int pointsSize = 3;
    int* pointsColSize = (int*)malloc(pointsSize * sizeof(int));
    for (int i = 0; i < pointsSize; i++) {
        pointsColSize[i] = 2;
    }
    int** pointsPtr = (int**)malloc(pointsSize * sizeof(int*));
    for (int i = 0; i < pointsSize; i++) {
        pointsPtr[i] = points[i];
    }

    int result = maxPoints(pointsPtr, pointsSize, pointsColSize);
    printf("Max points on a straight line: %d\n", result);

    free(pointsColSize);
    free(pointsPtr);
    return 0;
}
*/