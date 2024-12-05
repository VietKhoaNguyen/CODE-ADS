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