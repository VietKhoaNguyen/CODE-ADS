#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle formed by points (x1, y1), (x2, y2), and (x3, y3)
double calculateArea(int* p1, int* p2, int* p3) {
    return 0.5 * fabs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1]));
}

// Function to find the largest triangle area
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double maxArea = 0.0;

    // Iterate through all triplets of points
    for (int i = 0; i < pointsSize; i++) {
        for (int j = i + 1; j < pointsSize; j++) {
            for (int k = j + 1; k < pointsSize; k++) {
                // Calculate the area of the triangle formed by points i, j, k
                double area = calculateArea(points[i], points[j], points[k]);

                // Update maxArea if the current area is larger
                if (area > maxArea) {
                    maxArea = area;
                }
            }
        }
    }

    return maxArea;
}

// Example usage
int main() {
    int pointsSize = 4;
    int pointsColSize = 2;

    // Define points
    int points[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    // Convert points array to a pointer array
    int* pointsPtrs[4];
    for (int i = 0; i < pointsSize; i++) {
        pointsPtrs[i] = points[i];
    }

    // Call the function and print the result
    double area = largestTriangleArea(pointsPtrs, pointsSize, &pointsColSize);
    printf("Largest Triangle Area: %.2f\n", area);

    return 0;
}
/*recur O(n^3)
#include <stdio.h>
#include <math.h>

// Function to calculate the area of a triangle formed by points (x1, y1), (x2, y2), and (x3, y3)
double calculateArea(int* p1, int* p2, int* p3) {
    return 0.5 * fabs(p1[0] * (p2[1] - p3[1]) + p2[0] * (p3[1] - p1[1]) + p3[0] * (p1[1] - p2[1]));
}

// Helper function for recursion
void findMaxArea(int** points, int pointsSize, int* returnMaxArea, int i, int j, int k) {
    // Base case: when all triplets have been checked
    if (i >= pointsSize - 2) {
        return;
    }

    // Calculate area for the current triplet (i, j, k)
    double area = calculateArea(points[i], points[j], points[k]);
    if (area > *returnMaxArea) {
        *returnMaxArea = area; // Update the max area if the current area is larger
    }

    // Recursive calls for the next triplet (i, j, k)
    if (k < pointsSize) {
        findMaxArea(points, pointsSize, returnMaxArea, i, j, k + 1); // Move k to the next index
    } else if (j < pointsSize - 1) {
        findMaxArea(points, pointsSize, returnMaxArea, i, j + 1, j + 2); // Move j to the next index
    } else {
        findMaxArea(points, pointsSize, returnMaxArea, i + 1, i + 2, i + 3); // Move i to the next index
    }
}

// Function to find the largest triangle area
double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double maxArea = 0.0;

    // Start the recursion from the first triplet (i = 0, j = 1, k = 2)
    findMaxArea(points, pointsSize, &maxArea, 0, 1, 2);

    return maxArea;
}

// Example usage
int main() {
    int pointsSize = 4;
    int pointsColSize = 2;

    // Define points
    int points[4][2] = {
        {0, 0},
        {0, 1},
        {1, 0},
        {1, 1}
    };

    // Convert points array to a pointer array
    int* pointsPtrs[4];
    for (int i = 0; i < pointsSize; i++) {
        pointsPtrs[i] = points[i];
    }

    // Call the function and print the result
    double area = largestTriangleArea(pointsPtrs, pointsSize, &pointsColSize);
    printf("Largest Triangle Area: %.2f\n", area);

    return 0;
}
*/