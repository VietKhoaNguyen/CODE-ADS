#include <stdio.h>

char findTheDifference(char* s, char* t) {
    char result = 0;

    // XOR all characters of both strings
    while (*s) {
        result ^= *s;
        s++;
    }
    while (*t) {
        result ^= *t;
        t++;
    }

    return result;
}

int main() {
    char s[] = "abcd";
    char t[] = "abcde";

    char extraChar = findTheDifference(s, t);
    printf("The extra character is '%c'.\n", extraChar);

    return 0;
}
/*recur O(n)
#include <stdio.h>

char findTheDifferenceRecursive(char* s, char* t) {
    // Base case: when both strings are empty
    if (*s == '\0' && *t == '\0') {
        return 0;  // No more characters to compare, return 0
    }

    // XOR the current characters
    char result = *s ^ *t;

    // If one string is finished, XOR the rest of the characters from the other string
    if (*s != '\0' && *t != '\0') {
        return result ^ findTheDifferenceRecursive(s + 1, t + 1);
    }

    // If one string is finished, continue XORing the remaining characters of the other string
    while (*s == '\0' && *t != '\0') {
        result ^= *t;
        t++;
    }

    while (*s != '\0' && *t == '\0') {
        result ^= *s;
        s++;
    }

    return result;
}

int main() {
    char s[] = "abcd";
    char t[] = "abcde";

    char extraChar = findTheDifferenceRecursive(s, t);
    printf("The extra character is '%c'.\n", extraChar);

    return 0;
}
 */