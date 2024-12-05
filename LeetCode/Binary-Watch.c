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
/* recur O(1)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int countBits(int num) {
    int count = 0;
    while (num > 0) {
        count += num & 1;
        num >>= 1;
    }
    return count;
}
void findTimes(int hour, int minute, int turnedOn, int* returnSize, char*** result) {
    // Base case: if we've explored all possible hours (0-11) and minutes (0-59)
    if (hour == 12 && minute == 60) {
        return;
    }

    // Check if the current hour and minute combination has the desired number of LEDs on
    if (countBits(hour) + countBits(minute) == turnedOn) {
        // Allocate memory for the time string and format it
        (*result)[*returnSize] = (char*)malloc(6 * sizeof(char));
        sprintf((*result)[*returnSize], "%d:%02d", hour, minute);
        (*returnSize)++;
    }

    // Recurse for the next minute
    if (minute < 59) {
        findTimes(hour, minute + 1, turnedOn, returnSize, result);
    } else if (hour < 11) { // If we've reached minute 59, increment hour and reset minute to 0
        findTimes(hour + 1, 0, turnedOn, returnSize, result);
    }
}

/**
 * Main function to initiate the recursive process and return possible times.
 */
char** readBinaryWatch(int turnedOn, int* returnSize) {
    // Allocate space for result (maximum number of times can be 300)
    char** result = (char**)malloc(300 * sizeof(char*));
    *returnSize = 0; // Initialize return size

    // Start the recursion from hour 0 and minute 0
    findTimes(0, 0, turnedOn, returnSize, &result);

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
*/