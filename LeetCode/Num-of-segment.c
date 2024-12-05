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
/*recur O(n)
#include <stdio.h>
#include <stdbool.h>

int countSegmentsRecursive(char* s, int index, bool inSegment) {
    // Base case: if we've reached the end of the string
    if (s[index] == '\0') {
        return 0;
    }

    // If the current character is not a space
    if (s[index] != ' ') {
        if (!inSegment) {
            // We're entering a new segment, so count this segment
            return 1 + countSegmentsRecursive(s, index + 1, true);
        } else {
            // We're already in a segment, so continue without incrementing count
            return countSegmentsRecursive(s, index + 1, true);
        }
    } else {
        // Space character, so we're not in a segment
        return countSegmentsRecursive(s, index + 1, false);
    }
}

int countSegments(char* s) {
    return countSegmentsRecursive(s, 0, false);
}

int main() {
    char s[] = "Hello,   world! This is a test.";
    int result = countSegments(s);
    printf("The number of segments is: %d\n", result);

    return 0;
}
*/