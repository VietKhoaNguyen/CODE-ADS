#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Initialize random number generator
    srand(time(NULL));

    // Generate a random number (0 or 1) to simulate coin flip
    int flip = rand() % 2;

    // Display the result of the coin flip
    if (flip == 0) {
        printf("Heads\n");
    } else {
        printf("Tails\n");
    }

    return 0;
}