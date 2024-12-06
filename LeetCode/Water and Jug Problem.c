#include <stdio.h>
#include <stdbool.h>
// Function to compute the greatest common divisor (GCD)
int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to determine if it's possible to measure 'target' amount of water
bool canMeasureWater(int x, int y, int target) {
    // Check if the target is larger than the combined capacity of the two jugs
    if (target > x + y) {
        return false;
    }

    // If target is 0, we can always measure it by doing nothing
    if (target == 0) {
        return true;
    }

    // The target must be a multiple of the GCD of x and y
    int commonGCD = gcd(x, y);
    return target % commonGCD == 0;
}

int main() {
    int x = 3, y = 5, target = 4;
    
    if (canMeasureWater(x, y, target)) {
        printf("Yes, it's possible to measure %d liters of water.\n", target);
    } else {
        printf("No, it's not possible to measure %d liters of water.\n", target);
    }

    return 0;
}
/*recur O(x*y)
#include <stdio.h>
#include <stdbool.h>

// Function to recursively check if the target can be measured
bool canMeasureWaterRecursive(int x, int y, int target, int currentX, int currentY) {
    // Base case: if we have measured the target amount in either jug
    if (currentX == target || currentY == target) {
        return true;
    }

    // If we've already visited this state, return false (to avoid infinite loops)
    if (currentX > x || currentY > y || currentX < 0 || currentY < 0) {
        return false;
    }

    // Try all possible actions (fill, empty, pour between jugs)
    // 1. Fill jug 1
    if (canMeasureWaterRecursive(x, y, target, x, currentY)) return true;
    // 2. Fill jug 2
    if (canMeasureWaterRecursive(x, y, target, currentX, y)) return true;
    // 3. Empty jug 1
    if (canMeasureWaterRecursive(x, y, target, 0, currentY)) return true;
    // 4. Empty jug 2
    if (canMeasureWaterRecursive(x, y, target, currentX, 0)) return true;
    // 5. Pour from jug 1 to jug 2
    if (currentX + currentY <= y) {
        if (canMeasureWaterRecursive(x, y, target, 0, currentX + currentY)) return true;
    } else {
        if (canMeasureWaterRecursive(x, y, target, currentX - (y - currentY), y)) return true;
    }
    // 6. Pour from jug 2 to jug 1
    if (currentX + currentY <= x) {
        if (canMeasureWaterRecursive(x, y, target, currentX + currentY, 0)) return true;
    } else {
        if (canMeasureWaterRecursive(x, y, target, x, currentY - (x - currentX))) return true;
    }

    // If no action leads to the target, return false
    return false;
}

// Wrapper function to start the recursive process
bool canMeasureWater(int x, int y, int target) {
    // If the target is larger than the combined capacity, it's impossible
    if (target > x + y) return false;
    // If the target is zero, it's trivially possible
    if (target == 0) return true;

    // Start the recursion with both jugs empty
    return canMeasureWaterRecursive(x, y, target, 0, 0);
}

int main() {
    int x = 3, y = 5, target = 4;
    
    if (canMeasureWater(x, y, target)) {
        printf("Yes, it's possible to measure %d liters of water.\n", target);
    } else {
        printf("No, it's not possible to measure %d liters of water.\n", target);
    }

    return 0;
}
*/