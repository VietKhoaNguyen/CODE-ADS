#include <stdio.h>
#include <stdbool.h>

bool isSubsequence(char* s, char* t) {
    int i = 0, j = 0;

    // Iterate through both strings
    while (s[i] != '\0' && t[j] != '\0') {
        if (s[i] == t[j]) {
            i++; // Move to the next character in s
        }
        j++; // Always move to the next character in t
    }

    // If we have traversed all characters of s, it is a subsequence
    return s[i] == '\0';
}

int main() {
    char s[] = "abc";
    char t[] = "ahbgdc";

    if (isSubsequence(s, t)) {
        printf("\"%s\" is a subsequence of \"%s\".\n", s, t);
    } else {
        printf("\"%s\" is not a subsequence of \"%s\".\n", s, t);
    }

    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdbool.h>

bool isSubsequenceRecursive(char* s, int i, char* t, int j) {
    // Base case: If we've processed all characters in s, it's a subsequence
    if (s[i] == '\0') {
        return true;
    }

    // Base case: If we've exhausted string t without processing all of s, it's not a subsequence
    if (t[j] == '\0') {
        return false;
    }

    // If the characters match, move to the next character in s
    if (s[i] == t[j]) {
        return isSubsequenceRecursive(s, i + 1, t, j + 1);
    }

    // Otherwise, just move to the next character in t
    return isSubsequenceRecursive(s, i, t, j + 1);
}

bool isSubsequence(char* s, char* t) {
    return isSubsequenceRecursive(s, 0, t, 0);
}

int main() {
    char s[] = "abc";
    char t[] = "ahbgdc";

    if (isSubsequence(s, t)) {
        printf("\"%s\" is a subsequence of \"%s\".\n", s, t);
    } else {
        printf("\"%s\" is not a subsequence of \"%s\".\n", s, t);
    }

    return 0;
}
*/