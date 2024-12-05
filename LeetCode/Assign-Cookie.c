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
/*recur O(nlogn)
#include <stdio.h>
#include <stdlib.h>

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// Recursive function to find the number of content children
int findContentChildrenRecursive(int* g, int gSize, int* s, int sSize, int childIndex, int cookieIndex) {
    // Base case: when we've considered all children or all cookies
    if (childIndex >= gSize || cookieIndex >= sSize) {
        return 0;
    }

    // If the current cookie can satisfy the current child
    if (s[cookieIndex] >= g[childIndex]) {
        // Child is content, move to the next child and next cookie
        return 1 + findContentChildrenRecursive(g, gSize, s, sSize, childIndex + 1, cookieIndex + 1);
    } else {
        // If the current cookie can't satisfy the current child, just try the next cookie
        return findContentChildrenRecursive(g, gSize, s, sSize, childIndex, cookieIndex + 1);
    }
}

int findContentChildren(int* g, int gSize, int* s, int sSize) {
    // Sort the greed factor array and the cookie size array
    qsort(g, gSize, sizeof(int), compare);
    qsort(s, sSize, sizeof(int), compare);

    // Start the recursive process from the first child and first cookie
    return findContentChildrenRecursive(g, gSize, s, sSize, 0, 0);
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
*/