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
