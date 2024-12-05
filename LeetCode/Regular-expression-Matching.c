#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Dynamic Programming based solution to check if the string matches the pattern
bool isMatch(char* s, char* p) {
    int m = strlen(s);
    int n = strlen(p);

    // dp[i][j] represents whether s[0..i-1] matches p[0..j-1]
    bool dp[m + 1][n + 1];

    // Initialize dp table
    dp[0][0] = true;  // Empty string matches empty pattern
    for (int j = 1; j <= n; j++) {
        dp[0][j] = (p[j - 1] == '*') ? dp[0][j - 1] : false;
    }
    for (int i = 1; i <= m; i++) {
        dp[i][0] = false;  // A non-empty string cannot match an empty pattern
    }

    // Fill the dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];  // Characters match
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];  // '*' matches zero or more characters
            } else {
                dp[i][j] = false;  // Characters don't match and no special character
            }
        }
    }

    return dp[m][n];  // Final answer
}

int main() {
    char* s = "adceb";
    char* p = "*a*b";
    
    if (isMatch(s, p)) {
        printf("Match\n");
    } else {
        printf("No Match\n");
    }

    return 0;
}
/*recur O(m*n)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Memoization cache
bool memo[1001][1001];

// Recursive function with memoization
bool isMatchRecursive(char* s, char* p, int i, int j) {
    // If the result is already computed, return the cached value
    if (memo[i][j] != -1) {
        return memo[i][j];
    }

    // Base case: both strings are empty
    if (s[i] == '\0' && p[j] == '\0') {
        return true;
    }

    // If the pattern is empty but the string is not, no match
    if (p[j] == '\0') {
        return false;
    }

    // If the string is empty and the pattern is not empty, handle the pattern
    if (s[i] == '\0') {
        if (p[j] == '*') {
            return isMatchRecursive(s, p, i, j + 1);
        } else {
            return false;
        }
    }

    // Match current characters or handle '?'
    if (p[j] == s[i] || p[j] == '?') {
        return memo[i][j] = isMatchRecursive(s, p, i + 1, j + 1);
    }

    // Handle '*' in the pattern
    if (p[j] == '*') {
        // Try to match 0 characters (move to the next character in the pattern)
        // Or try to match one or more characters (move to the next character in the string)
        return memo[i][j] = isMatchRecursive(s, p, i + 1, j) || isMatchRecursive(s, p, i, j + 1);
    }

    // If characters don't match, return false
    return memo[i][j] = false;
}

bool isMatch(char* s, char* p) {
    // Initialize memoization table with -1 (indicating no result computed yet)
    memset(memo, -1, sizeof(memo));

    // Start recursion from the beginning of both strings
    return isMatchRecursive(s, p, 0, 0);
}

int main() {
    char* s = "adceb";
    char* p = "*a*b";

    if (isMatch(s, p)) {
        printf("Match\n");
    } else {
        printf("No Match\n");
    }

    return 0;
}
*/