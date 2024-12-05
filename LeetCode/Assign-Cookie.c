#include <stdio.h>
#include <stdlib.h>

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // Sort the greed factor array and the cookie size array
    qsort(g, gSize, sizeof(int), (int (*)(const void*, const void*))compare);
    qsort(s, sSize, sizeof(int), (int (*)(const void*, const void*))compare);

    int childIndex = 0;  // Pointer to the current child
    int cookieIndex = 0; // Pointer to the current cookie
    int contentChildren = 0;

    // Greedily assign cookies to children
    while (childIndex < gSize && cookieIndex < sSize) {
        if (s[cookieIndex] >= g[childIndex]) { // Cookie can satisfy the child's greed
            contentChildren++; // Increment content children count
            childIndex++; // Move to the next child
        }
        cookieIndex++; // Move to the next cookie
    }

    return contentChildren; // Return the number of content children
}

// Helper function to compare two integers (needed for qsort)
int compare(const int* a, const int* b) {
    return (*a - *b);
}

int main() {
    int g[] = {1, 2, 3};  // Greed factors of children
    int s[] = {1, 1};      // Sizes of cookies
    int gSize = sizeof(g) / sizeof(g[0]);
    int sSize = sizeof(s) / sizeof(s[0]);

    int result = findContentChildren(g, gSize, s, sSize);
    printf("Number of content children: %d\n", result);

    return 0;
}
