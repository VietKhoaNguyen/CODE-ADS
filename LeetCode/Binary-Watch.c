#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Helper function to count the number of 1s in the binary representation of a number.
 */
int countBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** readBinaryWatch(int turnedOn, int* returnSize) {
    char** result = (char**)malloc(300 * sizeof(char*)); // Allocate space for result
    *returnSize = 0; // Initialize return size

    for (int hour = 0; hour < 12; hour++) {     // Hours range from 0 to 11
        for (int minute = 0; minute < 60; minute++) { // Minutes range from 0 to 59
            // Count the total LEDs that are on for the current time
            if (countBits(hour) + countBits(minute) == turnedOn) {
                // Allocate memory for the time string and format it
                result[*returnSize] = (char*)malloc(6 * sizeof(char));
                sprintf(result[*returnSize], "%d:%02d", hour, minute);
                (*returnSize)++;
            }
        }
    }

    return result;
}

int main() {
    int turnedOn = 1;
    int returnSize;
    char** times = readBinaryWatch(turnedOn, &returnSize);

    printf("Possible times with %d LEDs turned on:\n", turnedOn);
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", times[i]);
        free(times[i]); // Free each allocated string
    }
    free(times); // Free the result array

    return 0;
}
