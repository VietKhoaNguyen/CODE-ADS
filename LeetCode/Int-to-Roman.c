#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert an integer to a Roman numeral
char* intToRoman(int num) {
    // Arrays for the Roman numerals and their corresponding integer values
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // Allocate memory for the result string, assuming max length 15 (for 3999, the largest number in the range)
    char* result = (char*)malloc(16 * sizeof(char));
    result[0] = '\0';  // Initialize an empty string

    // Iterate through the values array and build the Roman numeral
    for (int i = 0; i < 13; i++) {
        // While num is larger than or equal to the current value, subtract and append the corresponding symbol
        while (num >= values[i]) {
            strcat(result, symbols[i]);
            num -= values[i];
        }
    }

    return result;  // Return the Roman numeral string
}

int main() {
    int num = 1994;  // Example input
    char* roman = intToRoman(num);
    printf("Integer: %d, Roman Numeral: %s\n", num, roman);
    
    free(roman);  // Free the dynamically allocated memory
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to recursively convert an integer to a Roman numeral
void intToRomanRecursive(int num, char* result) {
    // Arrays for the Roman numerals and their corresponding integer values
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    // Base case: when the number is reduced to zero, stop
    if (num == 0) {
        return;
    }

    // Find the largest value less than or equal to num and subtract it
    for (int i = 0; i < 13; i++) {
        if (num >= values[i]) {
            strcat(result, symbols[i]);  // Append the corresponding symbol
            num -= values[i];            // Subtract the value from num
            break;  // Process the largest value and move to the next recursion step
        }
    }

    // Recursive call with the remaining number
    intToRomanRecursive(num, result);
}

// Wrapper function to convert integer to Roman numeral
char* intToRoman(int num) {
    // Allocate memory for the result string, assuming max length 15 (for 3999)
    char* result = (char*)malloc(16 * sizeof(char));
    result[0] = '\0';  // Initialize the result as an empty string

    // Start the recursion
    intToRomanRecursive(num, result);

    return result;
}

int main() {
    int num = 1994;  // Example input
    char* roman = intToRoman(num);
    printf("Integer: %d, Roman Numeral: %s\n", num, roman);
    
    free(roman);  // Free the dynamically allocated memory
    return 0;
}

*/