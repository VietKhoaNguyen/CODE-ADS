#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Function to calculate the day of the year
int dayOfYear(char* date) {
    // Parse the year, month, and day from the input string
    int year, month, day;
    sscanf(date, "%4d-%2d-%2d", &year, &month, &day);

    // Days in each month for a non-leap year
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // If it's a leap year, update February's days
    if (isLeapYear(year)) {
        daysInMonth[1] = 29; // February has 29 days in a leap year
    }

    // Calculate the day of the year
    int dayOfYear = 0;
    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i];  // Add the days in previous months
    }
    dayOfYear += day;  // Add the days in the current month

    return dayOfYear;
}

// Test the function
int main() {
    char date[] = "2024-03-01";
    int day = dayOfYear(date);
    printf("Day of the year: %d\n", day);  // Expected output: 61 (for "2024-03-01")
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Helper function to check if a year is a leap year
int isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// Recursive function to calculate the day of the year
int dayOfYearRecursive(int year, int month, int day, int* daysInMonth) {
    // Base case: if the month is 1, return the current day
    if (month == 1) {
        return day;
    }
    // Recursive case: calculate days of the previous months and add the current day
    return dayOfYearRecursive(year, month - 1, day, daysInMonth) + daysInMonth[month - 1];
}

// Function to calculate the day of the year
int dayOfYear(char* date) {
    // Parse the year, month, and day from the input string
    int year, month, day;
    sscanf(date, "%4d-%2d-%2d", &year, &month, &day);

    // Days in each month for a non-leap year
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // If it's a leap year, update February's days
    if (isLeapYear(year)) {
        daysInMonth[1] = 29; // February has 29 days in a leap year
    }

    // Call the recursive function
    return dayOfYearRecursive(year, month, day, daysInMonth);
}

// Test the function
int main() {
    char date[] = "2024-03-01";
    int day = dayOfYear(date);
    printf("Day of the year: %d\n", day);  // Expected output: 61 (for "2024-03-01")
    return 0;
}
*/