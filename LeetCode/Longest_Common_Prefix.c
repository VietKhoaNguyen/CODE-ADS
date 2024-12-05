#include <stdio.h>
#include <string.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";  // No strings, return empty string.
    
    // Start with the first string as the initial prefix
    char* prefix = strs[0];
    
    // Compare the prefix with each string in the array
    for (int i = 1; i < strsSize; i++) {
        // Compare the current prefix with the current string
        int j = 0;
        while (prefix[j] != '\0' && strs[i][j] != '\0' && prefix[j] == strs[i][j]) {
            j++;
        }
        // Update the prefix to the common part
        prefix[j] = '\0';  // Truncate the prefix at the point of mismatch or end of string
        
        // If the prefix becomes empty, return an empty string
        if (prefix[0] == '\0') return "";
    }
    
    return prefix;  // Return the longest common prefix
}

int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;
    
    char* result = longestCommonPrefix(strs, strsSize);
    printf("Longest Common Prefix: %s\n", result);  // Expected output: "fl"
    
    return 0;
}
