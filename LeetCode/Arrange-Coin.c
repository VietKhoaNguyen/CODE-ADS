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
