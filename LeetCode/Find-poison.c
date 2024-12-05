#include <stdio.h>

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (timeSeriesSize == 0) {
        return 0; // No attacks, no poison duration
    }

    int totalDuration = 0;

    for (int i = 0; i < timeSeriesSize - 1; i++) {
        // Add the smaller of the duration or the gap between consecutive attacks
        totalDuration += (timeSeries[i + 1] - timeSeries[i] < duration) 
                         ? (timeSeries[i + 1] - timeSeries[i]) 
                         : duration;
    }

    // Add the full duration for the last attack
    totalDuration += duration;

    return totalDuration;
}
int main() {
    int timeSeries[] = {1, 4};
    int timeSeriesSize = 2;
    int duration = 2;

    int result = findPoisonedDuration(timeSeries, timeSeriesSize, duration);
    printf("Total Poisoned Duration: %d\n", result); // Output: 4

    return 0;
}
/* recur O(n)
#include <stdio.h>

// Helper function to recursively calculate the poisoned duration
int calculatePoisonedDuration(int* timeSeries, int timeSeriesSize, int duration, int index) {
    // Base case: when index reaches the second-to-last element or beyond
    if (index >= timeSeriesSize - 1) {
        return duration; // The last attack always adds the full duration
    }

    // Calculate the gap between consecutive attacks
    int gap = timeSeries[index + 1] - timeSeries[index];

    // Add the smaller of the gap or the duration to the total
    int currentPoisonDuration = (gap < duration) ? gap : duration;

    // Recursively calculate the rest of the poisoned duration
    return currentPoisonDuration + calculatePoisonedDuration(timeSeries, timeSeriesSize, duration, index + 1);
}

int findPoisonedDuration(int* timeSeries, int timeSeriesSize, int duration) {
    if (timeSeriesSize == 0) {
        return 0; // No attacks, no poison duration
    }

    // Start the recursive calculation from index 0
    return calculatePoisonedDuration(timeSeries, timeSeriesSize, duration, 0) + duration;
}

int main() {
    int timeSeries[] = {1, 4};
    int timeSeriesSize = 2;
    int duration = 2;

    int result = findPoisonedDuration(timeSeries, timeSeriesSize, duration);
    printf("Total Poisoned Duration: %d\n", result); // Output: 4

    return 0;
}
*/