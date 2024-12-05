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
/*recur O(n*m)
#include <stdio.h>
#include <string.h>

// Recursive helper function to find the longest common prefix between two strings
char* commonPrefixBetweenTwoStrings(char* str1, char* str2) {
    int i = 0;
    
    // Compare the two strings character by character
    while (str1[i] != '\0' && str2[i] != '\0' && str1[i] == str2[i]) {
        i++;
    }
    
    // Return the common prefix (substring of str1 or str2)
    str1[i] = '\0';  // Truncate at the point of mismatch or end of string
    return str1;
}

// Recursive function to find the longest common prefix in the array of strings
char* longestCommonPrefixHelper(char** strs, int strsSize, int index) {
    if (index == strsSize - 1) {
        return strs[index];  // Base case: return the last string in the array
    }
    
    // Recursively find the longest common prefix between the current string and the result of the rest
    char* prefix = longestCommonPrefixHelper(strs, strsSize, index + 1);
    
    // Compare the current string with the recursively found prefix
    return commonPrefixBetweenTwoStrings(strs[index], prefix);
}

char* longestCommonPrefix(char** strs, int strsSize) {
    if (strsSize == 0) return "";  // No strings, return empty string
    
    return longestCommonPrefixHelper(strs, strsSize, 0);
}

// Example usage
int main() {
    char* strs[] = {"flower", "flow", "flight"};
    int strsSize = 3;
    
    char* result = longestCommonPrefix(strs, strsSize);
    printf("Longest Common Prefix: %s\n", result);  // Expected output: "fl"
    
    return 0;
}
*/