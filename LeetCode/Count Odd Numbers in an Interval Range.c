#include <stdio.h>

int countOdds(int low, int high) {
    // If both are even, exclude one end point from the range
    if (low % 2 == 0) low++;
    if (high % 2 == 0) high--;
    
    if (low > high) return 0; // No odd numbers if range is invalid

    // Calculate the number of odd numbers in the range
    return (high - low) / 2 + 1;
}

int main() {
    int low, high;

    // Input the range
    printf("Enter the low value: ");
    scanf("%d", &low);
    printf("Enter the high value: ");
    scanf("%d", &high);

    // Calculate and display the result
    int result = countOdds(low, high);
    printf("Number of odd numbers in the range [%d, %d]: %d\n", low, high, result);

    return 0;
}
/*recur O(n)
#include <stdio.h>

int countOdds(int low, int high) {
    // Base case: if the range is invalid
    if (low > high) {
        return 0;
    }

    // Check if the current `low` is odd
    if (low % 2 != 0) {
        // Include `low` and recurse on the rest of the range
        return 1 + countOdds(low + 1, high);
    } else {
        // If `low` is even, skip it and recurse
        return countOdds(low + 1, high);
    }
}

int main() {
    int low, high;

    // Input the range
    printf("Enter the low value: ");
    scanf("%d", &low);
    printf("Enter the high value: ");
    scanf("%d", &high);

    // Calculate and display the result
    int result = countOdds(low, high);
    printf("Number of odd numbers in the range [%d, %d]: %d\n", low, high, result);

    return 0;
}
*/