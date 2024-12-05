#include <stdio.h>
#include <string.h>

int romanToInt(char* s) {
    // Mapping Roman numeral characters to their integer values
    int romanMap[128] = {0};  // ASCII size to cover all characters
    romanMap['I'] = 1;
    romanMap['V'] = 5;
    romanMap['X'] = 10;
    romanMap['L'] = 50;
    romanMap['C'] = 100;
    romanMap['D'] = 500;
    romanMap['M'] = 1000;

    int result = 0;
    int length = strlen(s);
    
    for (int i = 0; i < length; i++) {
        // If the current value is less than the next value, subtract it
        if (i < length - 1 && romanMap[s[i]] < romanMap[s[i + 1]]) {
            result -= romanMap[s[i]];
        } else {
            result += romanMap[s[i]];
        }
    }

    return result;
}

int main() {
    char roman[] = "MCMXCIV"; // Example Roman numeral
    printf("Integer value: %d\n", romanToInt(roman));  // Should print 1994
    return 0;
}
