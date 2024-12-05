#include <stdio.h>
#include <stdbool.h>

// Function to check if a^2 + b^2 == result^2 (Pythagorean triplet condition)
bool condition(int a, int b, int result) {          // O(n^3)
    return (a * a + b * b == result * result);
}

// Recursive loop to find and print Pythagorean triplets in the array
void loop(int *array, int ind_a, int ind_b, int ind_c, int length) {
    int a = array[ind_a];
    int b = array[ind_b];
    int c = array[ind_c];

    // Check for Pythagorean triplets and print them
    if (condition(a, b, c) || condition(b, c, a) || condition(c, a, b)) {
        printf("%d %d %d\n", a, b, c);
    }

    // Recursive calls to cover all combinations
    if (ind_c < length - 1) {
        loop(array, ind_a, ind_b, ind_c + 1, length);
    } else if (ind_b < length - 2) {
        loop(array, ind_a, ind_b + 1, ind_b + 2, length);
    } else if (ind_a < length - 3) {
        loop(array, ind_a + 1, ind_a + 2, ind_a + 3, length);
    }
}

int main() {
    // Example array
    int arr[] = {4, 15, 28, 45, 40, 9, 53, 41, 8, 17, 3, 5};
    int arr_length = sizeof(arr) / sizeof(arr[0]);

    // Call the loop function to find and print Pythagorean triplets
    loop(arr, 0, 1, 2, arr_length);

    return 0;
}


// Not using bool function:
#include <stdio.h>

// Function to check if a^2 + b^2 == result^2 (Pythagorean triplet condition)
int condition(int a, int b, int result) {     // O(n^3)
    if (a * a + b * b == result * result) {
        return 1; // Return 1 if the condition is true
    }
    return 0; // Return 0 otherwise
}

// Recursive loop to find and print Pythagorean triplets in the array
void loop(int *array, int ind_a, int ind_b, int ind_c, int length) {
    int a = array[ind_a];
    int b = array[ind_b];
    int c = array[ind_c];

    // Check for Pythagorean triplets and print them
    if (condition(a, b, c) || condition(b, c, a) || condition(c, a, b)) {
        printf("%d %d %d\n", a, b, c);
    }

    // Recursive calls to cover all combinations
    if (ind_c < length - 1) {
        loop(array, ind_a, ind_b, ind_c + 1, length);
    } else if (ind_b < length - 2) {
        loop(array, ind_a, ind_b + 1, ind_b + 2, length);
    } else if (ind_a < length - 3) {
        loop(array, ind_a + 1, ind_a + 2, ind_a + 3, length);
    }
}

int main() {
    // Example array
    int arr[] = {4, 15, 28, 45, 40, 9, 53, 41, 8, 17, 3, 5};
    int arr_length = sizeof(arr) / sizeof(arr[0]);

    // Call the loop function to find and print Pythagorean triplets
    loop(arr, 0, 1, 2, arr_length);

    return 0;
}
/*// Function to check if a^2 + b^2 == result^2 (Pythagorean triplet condition)
function condition(a, b, result) {
    if (a * a + b * b == result * result) {
        return 1; // Return 1 if the condition is true
    }
    return 0; // Return 0 otherwise
}

// Recursive loop to find and print Pythagorean triplets in the array
function loop(array, ind_a, ind_b, ind_c, length) {
    a <- array[ind_a]
    b <- array[ind_b]
    c <- array[ind_c]

    // Check for Pythagorean triplets and print them
    if (condition(a, b, c) || condition(b, c, a) || condition(c, a, b)) {
        print a, b, c
    }

    // Recursive calls to cover all combinations
    if (ind_c < length - 1) {
        loop(array, ind_a, ind_b, ind_c + 1, length)
    } else if (ind_b < length - 2) {
        loop(array, ind_a, ind_b + 1, ind_b + 2, length)
    } else if (ind_a < length - 3) {
        loop(array, ind_a + 1, ind_a + 2, ind_a + 3, length)
    }
}

// Example array
arr <- {4, 15, 28, 45, 40, 9, 53, 41, 8, 17, 3, 5}
arr_length <- length(arr)

// Call the loop function to find and print Pythagorean triplets
loop(arr, 0, 1, 2, arr_length)*/