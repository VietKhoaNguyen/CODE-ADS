#include <stdio.h>

int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    // Calculate the area of rectangle A and rectangle B
    int areaA = (ax2 - ax1) * (ay2 - ay1);
    int areaB = (bx2 - bx1) * (by2 - by1);

    // Calculate the overlap dimensions
    int overlapWidth = (ax2 > bx1 && bx2 > ax1) ? (ax2 < bx2 ? ax2 : bx2) - (ax1 > bx1 ? ax1 : bx1) : 0;
    int overlapHeight = (ay2 > by1 && by2 > ay1) ? (ay2 < by2 ? ay2 : by2) - (ay1 > by1 ? ay1 : by1) : 0;

    // Calculate the overlap area
    int overlapArea = overlapWidth * overlapHeight;

    // Total area is the sum of both areas minus the overlap area
    return areaA + areaB - overlapArea;
}

// Example usage
int main() {
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4;
    int bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;

    int totalArea = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    printf("Total area covered by the rectangles: %d\n", totalArea); // Expected output: 45

    return 0;
}
/*recur O(1)
#include <stdio.h>

// Recursive function to calculate the area of a rectangle
int area(int x1, int y1, int x2, int y2) {
    if (x1 >= x2 || y1 >= y2) {
        return 0; // No area if dimensions are invalid
    }
    return (x2 - x1) * (y2 - y1);
}

// Recursive function to compute the overlap area
int overlapArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    // Calculate the overlap width and height recursively
    int overlapWidth = (ax2 > bx1 && bx2 > ax1)
                           ? overlapArea(ax1 > bx1 ? ax1 : bx1, ay1, ax2 < bx2 ? ax2 : bx2, ay2, bx1, by1, bx2, by2)
                           : 0;
    int overlapHeight = (ay2 > by1 && by2 > ay1)
                            ? overlapArea(ax1, ay1 > by1 ? ay1 : by1, ax2, ay2 < by2 ? ay2 : by2, bx1, by1, bx2, by2)
                            : 0;

    return overlapWidth && overlapHeight
               ? (overlapWidth * overlapHeight)
               : 0; // Return the product of overlap width and height if valid
}

// Recursive function to compute the total area
int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
    // Calculate areas of individual rectangles
    int areaA = area(ax1, ay1, ax2, ay2);
    int areaB = area(bx1, by1, bx2, by2);

    // Calculate overlap area recursively
    int overlap = overlapArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);

    // Total area is the sum of the two areas minus the overlap
    return areaA + areaB - overlap;
}

// Example usage
int main() {
    int ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4;
    int bx1 = 0, by1 = -1, bx2 = 9, by2 = 2;

    int totalArea = computeArea(ax1, ay1, ax2, ay2, bx1, by1, bx2, by2);
    printf("Total area covered by the rectangles: %d\n", totalArea); // Expected output: 45

    return 0;
}
*/