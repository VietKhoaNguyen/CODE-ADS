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
