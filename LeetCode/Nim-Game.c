#include <stdbool.h>

// Function to determine if the first player can win in the Nim game
bool canWinNim(int n) {
    // If n is divisible by 4, the first player will lose
    return n % 4 != 0;
}

// Example usage of the function
int main() {
    int n1 = 4;
    int n2 = 5;
    
    // Test the function with the example inputs
    if (canWinNim(n1)) {
        printf("First player can win with %d stones\n", n1);
    } else {
        printf("First player cannot win with %d stones\n", n1);
    }

    if (canWinNim(n2)) {
        printf("First player can win with %d stones\n", n2);
    } else {
        printf("First player cannot win with %d stones\n", n2);
    }

    return 0;
}
