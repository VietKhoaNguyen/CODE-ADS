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
