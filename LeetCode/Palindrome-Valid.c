#include <ctype.h>  // For isalnum() and tolower()

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    while (left < right) {
        // Move left pointer to the next alphanumeric character
        while (left < right && !isalnum(s[left])) {
            left++;
        }
        
        // Move right pointer to the previous alphanumeric character
        while (left < right && !isalnum(s[right])) {
            right--;
        }
        
        // Compare characters case-insensitively
        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }
        
        // Move both pointers towards the center
        left++;
        right--;
    }
    
    return true;
}
/*recur O(n)
#include <ctype.h>
#include <string.h>  // For strlen()

// Recursive helper function to check palindrome
bool isPalindromeRecursive(char* s, int left, int right) {
    // Base case: If pointers cross, all characters have been checked
    if (left >= right) {
        return true;
    }
    
    // Skip non-alphanumeric characters from the left
    if (!isalnum(s[left])) {
        return isPalindromeRecursive(s, left + 1, right);
    }
    
    // Skip non-alphanumeric characters from the right
    if (!isalnum(s[right])) {
        return isPalindromeRecursive(s, left, right - 1);
    }
    
    // Compare characters case-insensitively
    if (tolower(s[left]) != tolower(s[right])) {
        return false;
    }
    
    // Recur for the next characters
    return isPalindromeRecursive(s, left + 1, right - 1);
}

bool isPalindrome(char* s) {
    int left = 0;
    int right = strlen(s) - 1;
    
    return isPalindromeRecursive(s, left, right);
}

// Example usage
#include <stdio.h>

int main() {
    char s[] = "A man, a plan, a canal: Panama";
    if (isPalindrome(s)) {
        printf("The string is a palindrome.\n");
    } else {
        printf("The string is not a palindrome.\n");
    }
    return 0;
}
*/