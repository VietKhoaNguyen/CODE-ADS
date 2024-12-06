#include <stdio.h>
#include <stdlib.h>

// Helper function to find the number of distinct integers using the digits of n
void findDistinctIntegers(int n, int *distinct, int *digits, int count) {
    if (n == 0) {
        // If the number is exhausted, add the current permutation to the distinct set
        int num = 0;
        for (int i = 0; i < count; i++) {
            num = num * 10 + digits[i];
        }
        distinct[num] = 1; // Mark this number as distinct
        return;
    }

    // Extract the last digit
    int digit = n % 10;

    // Explore further by including or excluding the digit
    for (int i = 0; i < count; i++) {
        if (digits[i] == digit) {
            return; // Avoid duplicate digits
        }
    }
    digits[count] = digit; // Add the digit
    findDistinctIntegers(n / 10, distinct, digits, count + 1); // Move to next

}

// Function to count distinct integers
int distinctIntegers(int n) {
    int distinct[1000000] = {0}; // Assuming the maximum possible distinct integers
    int digits[10];
    findDistinctIntegers(n, distinct, digits, 0);
    
    // Count distinct numbers
    int result = 0;
    for (int i = 0; i < 1000000; i++) {
        result += distinct[i]; 
    }
    return result;
}

int main() {
    int n;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate and display the result
    int result = distinctIntegers(n);
    printf("The number of distinct integers is: %d\n", result);

    return 0;
}
/*recur O(d!)
#include <stdio.h>

#define MAX_DIGITS 10

// Helper function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate all distinct permutations of digits
void permute(int* digits, int start, int size, int* distinct) {
    if (start == size) {
        // Convert the current permutation into a number
        int num = 0;
        for (int i = 0; i < size; i++) {
            num = num * 10 + digits[i];
        }
        distinct[num] = 1;  // Mark this number as distinct
        return;
    }
    
    for (int i = start; i < size; i++) {
        // Skip duplicates
        if (i > start && digits[i] == digits[start]) {
            continue;
        }
        
        // Swap the current element with the start
        swap(&digits[start], &digits[i]);
        
        // Recurse with the next position
        permute(digits, start + 1, size, distinct);
        
        // Backtrack (swap back)
        swap(&digits[start], &digits[i]);
    }
}

// Main function to calculate the number of distinct integers
int distinctIntegers(int n) {
    // Convert the number to digits
    int digits[MAX_DIGITS], size = 0;
    
    // Extract digits from the number
    while (n > 0) {
        digits[size++] = n % 10;
        n /= 10;
    }

    // Array to track distinct numbers
    int distinct[1000000] = {0}; // Assuming there are at most 1,000,000 distinct integers
    
    // Generate permutations
    permute(digits, 0, size, distinct);

    // Count distinct numbers
    int count = 0;
    for (int i = 0; i < 1000000; i++) {
        count += distinct[i];
    }
    
    return count;
}

int main() {
    int n;

    // Input number
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculate and display the result
    int result = distinctIntegers(n);
    printf("The number of distinct integers is: %d\n", result);

    return 0;
}
*/