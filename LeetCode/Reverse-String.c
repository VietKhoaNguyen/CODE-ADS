#include <stdio.h>

// Function to reverse the string in-place
void reverseString(char* s, int sSize) {
    int left = 0;
    int right = sSize - 1;
    
    // Swap characters from the beginning and end towards the middle
    while (left < right) {
        // Swap characters at left and right positions
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        
        // Move left pointer forward and right pointer backward
        left++;
        right--;
    }
}

// Function to print the string (for testing)
void printString(char* s) {
    printf("%s\n", s);
}

int main() {
    // Test case 1: Reverse a string
    char str1[] = "hello";
    int size1 = sizeof(str1) - 1; // Exclude null terminator
    
    // Reverse the string in-place
    reverseString(str1, size1);
    
    // Print the reversed string
    printString(str1);

    // Test case 2: Reverse another string
    char str2[] = "world";
    int size2 = sizeof(str2) - 1; // Exclude null terminator
    
    // Reverse the string in-place
    reverseString(str2, size2);
    
    // Print the reversed string
    printString(str2);
    
    return 0;
}
/*recur O(n)
#include <stdio.h>

// Recursive function to reverse the string in-place
void reverseString(char* s, int left, int right) {
    // Base case: if left >= right, stop recursion
    if (left >= right) {
        return;
    }

    // Swap characters at left and right positions
    char temp = s[left];
    s[left] = s[right];
    s[right] = temp;

    // Recursive call to move towards the middle
    reverseString(s, left + 1, right - 1);
}

// Function to print the string (for testing)
void printString(char* s) {
    printf("%s\n", s);
}

int main() {
    // Test case 1: Reverse a string
    char str1[] = "hello";
    int size1 = sizeof(str1) - 1; // Exclude null terminator
    
    // Reverse the string in-place
    reverseString(str1, 0, size1 - 1);
    
    // Print the reversed string
    printString(str1);

    // Test case 2: Reverse another string
    char str2[] = "world";
    int size2 = sizeof(str2) - 1; // Exclude null terminator
    
    // Reverse the string in-place
    reverseString(str2, 0, size2 - 1);
    
    // Print the reversed string
    printString(str2);
    
    return 0;
}
*/