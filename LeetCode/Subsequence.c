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
