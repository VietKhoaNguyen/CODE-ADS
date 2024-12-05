#include <string.h>

char* reverseStr(char* s, int k) {
    int len = strlen(s);
    
    // Process the string in chunks of 2k
    for (int i = 0; i < len; i += 2 * k) {
        // Reverse the first k characters of each 2k block
        int left = i;
        int right = (i + k - 1 < len) ? i + k - 1 : len - 1;
        
        while (left < right) {
            // Swap characters at left and right
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
    
    return s;
}

int main() {
    // Example usage
    char str[] = "abcdefg";
    int k = 2;
    printf("Reversed string: %s\n", reverseStr(str, k));  // Output: "bacdfeg"
    
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <string.h>

// Helper function to reverse a section of the string
void reverseSegment(char* s, int left, int right) {
    while (left < right) {
        // Swap characters at left and right
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

// Recursive function to reverse the string in chunks of 2k
char* reverseStr(char* s, int k) {
    int len = strlen(s);
    
    // Base case: if the string length is less than k, reverse the entire string
    if (len < k) {
        reverseSegment(s, 0, len - 1);
        return s;
    }
    
    // Reverse the first k characters
    reverseSegment(s, 0, k - 1);

    // Recursively reverse the remaining part of the string starting from position k
    reverseStr(s + k, k);

    return s;
}

int main() {
    // Example usage
    char str[] = "abcdefg";
    int k = 2;
    printf("Reversed string: %s\n", reverseStr(str, k));  // Output: "bacdfeg"
    
    return 0;
}
*/