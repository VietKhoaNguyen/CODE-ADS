#define MOD 1337

// Function to calculate (x^y) % MOD using modular exponentiation
int modPow(int x, int y) {
    int result = 1;
    x = x % MOD;  // To handle the case where x >= MOD

    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % MOD;  // If y is odd, multiply x with result
        }
        y = y / 2;  // y = y / 2
        x = (x * x) % MOD;  // x = x^2
    }

    return result;
}

int superPow(int a, int* b, int bSize) {
    a = a % MOD;  // Reduce a to fit within MOD
    int result = 1;

    for (int i = 0; i < bSize; i++) {
        // For each digit in b, use the current result to account for previous digits
        result = modPow(result, 10) * modPow(a, b[i]) % MOD;
    }

    return result;
}
/*recur O(bSize×logMOD)
#define MOD 1337

// Helper function for modular exponentiation
int modPow(int x, int y) {
    int result = 1;
    x = x % MOD;  // To handle the case where x >= MOD

    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % MOD;  // If y is odd, multiply x with result
        }
        y = y / 2;  // y = y / 2
        x = (x * x) % MOD;  // x = x^2
    }

    return result;
}

// Recursive function to compute superPow
int superPowRecursive(int a, int* b, int bSize, int index) {
    if (index == bSize) {
        return 1;  // Base case: return 1 if we've processed all digits
    }

    // Recursive call: calculate the power for the current digit
    int part1 = modPow(a, b[index]);  // a^b[index] % MOD
    int part2 = modPow(superPowRecursive(a, b, bSize, index + 1), 10);  // Recursive part for the next digits

    // Combine the results
    return (part1 * part2) % MOD;
}

// Main superPow function
int superPow(int a, int* b, int bSize) {
    a = a % MOD;  // Reduce a to fit within MOD
    return superPowRecursive(a, b, bSize, 0);
}
*/