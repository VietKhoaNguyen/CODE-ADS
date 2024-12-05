#include <stdbool.h>

bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    // Check if the rectangles do not overlap:
    // 1. If one rectangle is to the left of the other
    // 2. If one rectangle is above the other
    if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1]) {
        return false;
    }

    // If none of the conditions for no overlap are met, then the rectangles overlap
    return true;
}

// Example usage
int main() {
    int rec1[] = {0, 0, 2, 2};
    int rec2[] = {1, 1, 3, 3};

    bool result = isRectangleOverlap(rec1, 4, rec2, 4);
    if (result) {
        printf("The rectangles overlap.\n");
    } else {
        printf("The rectangles do not overlap.\n");
    }

    return 0;
}
/*recur O(1)
#include <stdbool.h>

// Recursive helper function to check overlap conditions
bool isOverlapHelper(int* rec1, int* rec2) {
    // Base case: check if one rectangle is completely to the left or above the other
    if (rec1[2] <= rec2[0] || rec2[2] <= rec1[0] || rec1[3] <= rec2[1] || rec2[3] <= rec1[1]) {
        return false;
    }
    // If none of the conditions for no overlap are met, then the rectangles overlap
    return true;
}

// Wrapper function to call the helper recursively
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size) {
    return isOverlapHelper(rec1, rec2);
}

// Example usage
int main() {
    int rec1[] = {0, 0, 2, 2};
    int rec2[] = {1, 1, 3, 3};

    bool result = isRectangleOverlap(rec1, 4, rec2, 4);
    if (result) {
        printf("The rectangles overlap.\n");
    } else {
        printf("The rectangles do not overlap.\n");
    }

    return 0;
}
*/