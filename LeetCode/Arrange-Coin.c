#include <stdio.h>

int arrangeCoins(int n) {
    int rows = 0;
    while (n >= rows + 1) {
        rows++;
        n -= rows;
    }
    return rows;
}

int main() {
    int n = 8;
    int result = arrangeCoins(n);
    printf("Number of complete rows: %d\n", result);
    return 0;
}
/*recur O(sqrt(n))
#include <stdio.h>

// Recursive function to calculate the number of complete rows
int arrangeCoinsRecursive(int n, int rows) {
    if (n < rows + 1) {
        return rows;
    }
    return arrangeCoinsRecursive(n - (rows + 1), rows + 1);
}

// Wrapper function that calls the recursive function with initial values
int arrangeCoins(int n) {
    return arrangeCoinsRecursive(n, 0);
}

int main() {
    int n = 8;
    int result = arrangeCoins(n);
    printf("Number of complete rows: %d\n", result);
    return 0;
}
 */