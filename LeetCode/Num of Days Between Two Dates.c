#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int daysBetweenDates(char* date1, char* date2) {
    struct tm tm1 = {0};
    struct tm tm2 = {0};

    // Parse the date1
    sscanf(date1, "%4d-%2d-%2d", &tm1.tm_year, &tm1.tm_mon, &tm1.tm_mday);
    tm1.tm_year -= 1900;  // tm_year is years since 1900
    tm1.tm_mon -= 1;  // tm_mon is 0-based

    // Parse the date2
    sscanf(date2, "%4d-%2d-%2d", &tm2.tm_year, &tm2.tm_mon, &tm2.tm_mday);
    tm2.tm_year -= 1900;  // tm_year is years since 1900
    tm2.tm_mon -= 1;  // tm_mon is 0-based

    // Convert both tm structs to time_t (seconds since epoch)
    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    // Calculate the absolute difference in days
    double difference = difftime(t1, t2) / (60 * 60 * 24);
    return (int)fabs(difference);
}

int main() {
    char date1[] = "2020-01-15";
    char date2[] = "2021-01-15";
    int result = daysBetweenDates(date1, date2);
    printf("Days between %s and %s: %d\n", date1, date2, result);  // Output: 366
    return 0;
}
/*recur O(n)
#include <stdio.h>
#include <stdbool.h>

#define MAX_DAYS_IN_MONTH 31
#define MIN_DAYS_IN_MONTH 28

// Helper function to check if a year is a leap year
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return true;
    }
    return false;
}

// Helper function to get the number of days in a given month
int daysInMonth(int year, int month) {
    if (month == 2) {
        return isLeapYear(year) ? 29 : 28;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    }
    return 31;
}

// Function to parse the date string into year, month, and day
void parseDate(char* date, int* year, int* month, int* day) {
    sscanf(date, "%4d-%2d-%2d", year, month, day);
}

// Recursive function to calculate the number of days between two dates
int calculateDays(int year1, int month1, int day1, int year2, int month2, int day2) {
    // If the dates are the same, no difference
    if (year1 == year2 && month1 == month2 && day1 == day2) {
        return 0;
    }

    // Move date1 forward by one day (recursively)
    if (year1 < year2 || (year1 == year2 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2)) {
        // Increment day1 and recurse
        day1++;
        if (day1 > daysInMonth(year1, month1)) {
            day1 = 1;
            month1++;
            if (month1 > 12) {
                month1 = 1;
                year1++;
            }
        }
        return 1 + calculateDays(year1, month1, day1, year2, month2, day2);  // Add 1 for each recursive step
    }
    // Move date2 forward by one day (recursively)
    else {
        day2++;
        if (day2 > daysInMonth(year2, month2)) {
            day2 = 1;
            month2++;
            if (month2 > 12) {
                month2 = 1;
                year2++;
            }
        }
        return 1 + calculateDays(year1, month1, day1, year2, month2, day2);  // Add 1 for each recursive step
    }
}

int daysBetweenDates(char* date1, char* date2) {
    int year1, month1, day1;
    int year2, month2, day2;

    // Parse the two dates
    parseDate(date1, &year1, &month1, &day1);
    parseDate(date2, &year2, &month2, &day2);

    // Use recursive function to calculate the days difference
    return calculateDays(year1, month1, day1, year2, month2, day2);
}

int main() {
    char date1[] = "2020-01-15";
    char date2[] = "2021-01-15";
    int result = daysBetweenDates(date1, date2);
    printf("Days between %s and %s: %d\n", date1, date2, result);  // Output: 366
    return 0;
}
*/