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
/*recur O(1)
#include <stdio.h>
#include <stdbool.h>

// Recursive function to determine if the first player can win
bool canWinNimRecursive(int n) {
    // Base case: if there are no stones left, the current player loses
    if (n <= 0) {
        return false;
    }
    
    // The first player can win if they can leave the opponent with a losing configuration
    for (int i = 1; i <= 3; i++) {
        if (n - i >= 0 && !canWinNimRecursive(n - i)) {
            return true;
        }
    }

    // If no move leads to a win, the first player cannot win
    return false;
}

// Function to determine if the first player can win based on mathematical rule
bool canWinNim(int n) {
    return n % 4 != 0;
}

int main() {
    int n1 = 4;
    int n2 = 5;

    // Test the recursive version of the function
    if (canWinNimRecursive(n1)) {
        printf("First player can win with %d stones (recursive)\n", n1);
    } else {
        printf("First player cannot win with %d stones (recursive)\n", n1);
    }

    if (canWinNimRecursive(n2)) {
        printf("First player can win with %d stones (recursive)\n", n2);
    } else {
        printf("First player cannot win with %d stones (recursive)\n", n2);
    }

    // Test the mathematical version of the function
    if (canWinNim(n1)) {
        printf("First player can win with %d stones (mathematical)\n", n1);
    } else {
        printf("First player cannot win with %d stones (mathematical)\n", n1);
    }

    if (canWinNim(n2)) {
        printf("First player can win with %d stones (mathematical)\n", n2);
    } else {
        printf("First player cannot win with %d stones (mathematical)\n", n2);
    }

    return 0;
}
*/