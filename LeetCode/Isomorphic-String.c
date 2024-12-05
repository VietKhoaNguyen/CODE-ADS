#include <stdio.h>
#include <stdbool.h>

bool isIsomorphic(char* s, char* t) {
    // If the lengths of the strings are not the same, they can't be isomorphic
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Arrays to store the mapping between characters in 's' and 't'
    int mapS[256] = {0};  // Mapping for characters in s to t
    int mapT[256] = {0};  // Mapping for characters in t to s

    // Traverse both strings
    for (int i = 0; s[i] != '\0'; i++) {
        if (mapS[s[i]] == 0 && mapT[t[i]] == 0) {
            // If no mapping exists, create one
            mapS[s[i]] = t[i];
            mapT[t[i]] = s[i];
        } else if (mapS[s[i]] != t[i] || mapT[t[i]] != s[i]) {
            // If there is a mismatch in mapping, return false
            return false;
        }
    }

    return true;
}

// Example usage
int main() {
    char s[] = "egg";
    char t[] = "add";
    
    if (isIsomorphic(s, t)) {
        printf("The strings are isomorphic.\n");
    } else {
        printf("The strings are not isomorphic.\n");
    }

    return 0;
}
