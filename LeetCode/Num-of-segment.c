#include <stdio.h>
#include <stdbool.h>

int countSegments(char* s) {
    int count = 0;
    bool inSegment = false;  // Flag to track if we are currently in a segment

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {  // Non-space character
            if (!inSegment) {
                count++;  // New segment starts
                inSegment = true;  // Mark that we're in a segment
            }
        } else {
            inSegment = false;  // Space means we're not in a segment
        }
    }

    return count;
}

int main() {
    char s[] = "Hello,   world! This is a test.";
    int result = countSegments(s);
    printf("The number of segments is: %d\n", result);

    return 0;
}
