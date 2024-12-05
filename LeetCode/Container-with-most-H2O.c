#include <stdio.h>

int maxArea(int* height, int heightSize) {
    int left = 0, right = heightSize - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate the current area
        int width = right - left;
        int current_height = height[left] < height[right] ? height[left] : height[right];
        int current_area = width * current_height;

        // Update the maximum area
        if (current_area > max_area) {
            max_area = current_area;
        }

        // Move the pointer pointing to the smaller height
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int heightSize = sizeof(height) / sizeof(height[0]);
    
    int result = maxArea(height, heightSize);
    printf("Maximum area: %d\n", result);

    return 0;
}
