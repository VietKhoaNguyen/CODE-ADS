#include <stdio.h>

int numSub(char* s) {
    int count = 0;    // Count of consecutive '1's
    int result = 0;   // Total number of substrings
    const int MOD = 1000000007; // To prevent overflow for large results

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '1') {
            count++;
            result = (result + count) % MOD;
        } else {
            count = 0; // Reset count when encountering a '0'
        }
    }

    return result;
}

int main() {
    char s[100];

    // Input the binary string
    printf("Enter a binary string: ");
    scanf("%s", s);

    // Calculate and display the result
    int result = numSub(s);
    printf("Number of substrings formed by consecutive '1's: %d\n", result);

    return 0;
}
/*recur O(n)
#include <stdio.h>

#define MOD 1000000007

// Recursive helper function
int countConsecutiveOnes(char* s, int index, int currentCount) {
    if (s[index] == '\0') {
        return 0; // Base case: end of the string
    }

    if (s[index] == '1') {
        // If the current character is '1', increase the current count
        currentCount++;
        // Recursive call to process the next character and add the current contribution
        return (currentCount + countConsecutiveOnes(s, index + 1, currentCount)) % MOD;
    } else {
        // If the current character is not '1', reset the current count and continue
        return countConsecutiveOnes(s, index + 1, 0);
    }
}

// Main recursive function
int numSub(char* s) {
    return countConsecutiveOnes(s, 0, 0);
}

int main() {
    char s[100];

    // Input the binary string
    printf("Enter a binary string: ");
    scanf("%s", s);

    // Calculate and display the result
    int result = numSub(s);
    printf("Number of substrings formed by consecutive '1's: %d\n", result);

    return 0;
}
*/