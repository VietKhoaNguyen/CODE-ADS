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
