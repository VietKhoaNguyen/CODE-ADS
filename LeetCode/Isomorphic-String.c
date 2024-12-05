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
/* recur O(n)
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Helper recursive function to check isomorphism
bool isIsomorphicRecursive(char* s, char* t, int index, int* mapS, int* mapT) {
    // Base case: if we've processed all characters
    if (s[index] == '\0') {
        return true;
    }

    // If no mapping exists, create one
    if (mapS[s[index]] == 0 && mapT[t[index]] == 0) {
        mapS[s[index]] = t[index];
        mapT[t[index]] = s[index];
    } 
    // If there's a mismatch in mapping, return false
    else if (mapS[s[index]] != t[index] || mapT[t[index]] != s[index]) {
        return false;
    }

    // Recursively check the next characters
    return isIsomorphicRecursive(s, t, index + 1, mapS, mapT);
}

// Main function that initializes the mapping and calls the recursive helper
bool isIsomorphic(char* s, char* t) {
    // If the lengths of the strings are not the same, they can't be isomorphic
    if (strlen(s) != strlen(t)) {
        return false;
    }

    // Arrays to store the mapping between characters in 's' and 't'
    int mapS[256] = {0};  // Mapping for characters in s to t
    int mapT[256] = {0};  // Mapping for characters in t to s

    // Start recursion from the first index
    return isIsomorphicRecursive(s, t, 0, mapS, mapT);
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
*/