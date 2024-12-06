#include <stdio.h>
#include <string.h>

char* dayOfTheWeek(int day, int month, int year) {
    // Array of weekday names starting from Saturday to Friday (since Zeller's Congruence starts on Saturday = 0)
    char* daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    // Adjust months and year for January and February
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    // Zeller's Congruence formula
    int q = day;
    int m = month;
    int K = year % 100;
    int J = year / 100;

    int h = (q + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    // Return the day of the week
    return daysOfWeek[h];
}

// Example usage:
int main() {
    int day = 18, month = 7, year = 2023;
    printf("The day of the week is: %s\n", dayOfTheWeek(day, month, year));  // Expected output: "Tuesday"
    return 0;
}
/*recur O(1)
#include <stdio.h>
#include <string.h>

char* daysOfWeek[] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

// Recursive function to calculate the day of the week using Zeller's formula
int calculateDay(int day, int month, int year) {
    // Adjust months and year for January and February
    if (month < 3) {
        month += 12;
        year -= 1;
    }

    // Zeller's Congruence formula
    int q = day;
    int m = month;
    int K = year % 100;
    int J = year / 100;

    // Recursively compute the day of the week
    int h = (q + (13 * (m + 1)) / 5 + K + K / 4 + J / 4 + 5 * J) % 7;

    return h;  // Return the day of the week
}

// Wrapper function to return the actual name of the day
char* dayOfTheWeek(int day, int month, int year) {
    int h = calculateDay(day, month, year);
    return daysOfWeek[h];  // Map the calculated value to the day name
}

// Example usage:
int main() {
    int day = 18, month = 7, year = 2023;
    printf("The day of the week is: %s\n", dayOfTheWeek(day, month, year));  // Expected output: "Tuesday"
    return 0;
}
*/