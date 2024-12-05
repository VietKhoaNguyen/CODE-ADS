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
