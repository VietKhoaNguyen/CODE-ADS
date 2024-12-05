#include <stdbool.h>

bool checkRecord(char* s) {
    int absences = 0;
    int lateCount = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        // Check for absences ('A')
        if (s[i] == 'A') {
            absences++;
            if (absences > 1) {
                return false;  // More than one absence
            }
        }
        
        // Check for consecutive late days ('L')
        if (s[i] == 'L') {
            lateCount++;
            if (lateCount > 2) {
                return false;  // More than two consecutive late days
            }
        } else {
            lateCount = 0;  // Reset late count if current character is not 'L'
        }
    }

    return true;  // If no rule violations, the record is valid
}

int main() {
    char* s = "PPALLP";  // Test case: valid record
    if (checkRecord(s)) {
        printf("Valid record\n");
    } else {
        printf("Invalid record\n");
    }
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdbool.h>

bool checkRecordRecursive(char* s, int index, int absences, int lateCount) {
    // Base case: If we've reached the end of the string
    if (s[index] == '\0') {
        return true;  // No violations found
    }

    // Check for absences ('A')
    if (s[index] == 'A') {
        absences++;
        if (absences > 1) {
            return false;  // More than one absence
        }
    }

    // Check for consecutive late days ('L')
    if (s[index] == 'L') {
        lateCount++;
        if (lateCount > 2) {
            return false;  // More than two consecutive late days
        }
    } else {
        lateCount = 0;  // Reset late count if the current character is not 'L'
    }

    // Recursive call to check the next character
    return checkRecordRecursive(s, index + 1, absences, lateCount);
}

bool checkRecord(char* s) {
    return checkRecordRecursive(s, 0, 0, 0);
}

int main() {
    char* s = "PPALLP";  // Test case: valid record
    if (checkRecord(s)) {
        printf("Valid record\n");
    } else {
        printf("Invalid record\n");
    }
    return 0;
}
*/