#include <stdbool.h>
#include <stdlib.h>

// Helper function to calculate the GCD of two numbers
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// Main function to check if we can partition the deck
bool hasGroupsSizeX(int* deck, int deckSize) {
    // Edge case: if deck size is less than 2, it's impossible to partition
    if (deckSize < 2) {
        return false;
    }

    // Step 1: Count frequencies of each card
    int count[10000] = {0}; // Assume cards are within the range [0, 9999]
    for (int i = 0; i < deckSize; i++) {
        count[deck[i]]++;
    }

    // Step 2: Find the GCD of all frequencies
    int commonGCD = 0;
    for (int i = 0; i < 10000; i++) {
        if (count[i] > 0) {
            commonGCD = gcd(commonGCD, count[i]);
            if (commonGCD == 1) { // Early exit if GCD becomes 1
                return false;
            }
        }
    }

    // Step 3: Return true if GCD is greater than or equal to 2
    return commonGCD >= 2;
}

// Example usage
int main() {
    int deck[] = {1, 2, 3, 4, 4, 3, 2, 1};
    int deckSize = sizeof(deck) / sizeof(deck[0]);

    if (hasGroupsSizeX(deck, deckSize)) {
        printf("The deck can be partitioned into groups of size X.\n");
    } else {
        printf("The deck cannot be partitioned into groups of size X.\n");
    }

    return 0;
}
/*recur O(n + klog(max))
#include <stdbool.h>
#include <stdlib.h>

// Helper function to calculate the GCD of two numbers (recursive)
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// Main function to check if we can partition the deck
bool hasGroupsSizeX(int* deck, int deckSize) {
    // Edge case: if deck size is less than 2, it's impossible to partition
    if (deckSize < 2) {
        return false;
    }

    // Step 1: Count frequencies of each card
    int count[10000] = {0}; // Assume cards are within the range [0, 9999]
    for (int i = 0; i < deckSize; i++) {
        count[deck[i]]++;
    }

    // Step 2: Find the GCD of all frequencies using recursion
    int commonGCD = 0;
    for (int i = 0; i < 10000; i++) {
        if (count[i] > 0) {
            // Update the common GCD
            commonGCD = gcd(commonGCD, count[i]);
            // Early exit if GCD becomes 1
            if (commonGCD == 1) {
                return false;
            }
        }
    }

    // Step 3: Return true if GCD is greater than or equal to 2
    return commonGCD >= 2;
}

// Example usage
int main() {
    int deck[] = {1, 1, 2, 2, 2, 2};
    int deckSize = sizeof(deck) / sizeof(deck[0]);

    if (hasGroupsSizeX(deck, deckSize)) {
        printf("The deck can be partitioned into groups of size X.\n");
    } else {
        printf("The deck cannot be partitioned into groups of size X.\n");
    }

    return 0;
}
*/