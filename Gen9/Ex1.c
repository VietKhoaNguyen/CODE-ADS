#include <stdio.h>
/*Write a program to enter a natural number n and find all sphenic numbers from 1 to n using
Recursion*/
// Function to check if a number is prime
int isPrime(int num) {                        //Complexity:O(n^2)
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

// Recursive function to check if a number is sphenic
int isSphenicHelper(int num, int factorCount, int lastFactor) {
    if (num == 1 && factorCount == 3) return 1;  // Found exactly 3 distinct prime factors
    if (factorCount >= 3) return 0;  // More than 3 factors is not sphenic
    for (int i = lastFactor + 1; i <= num; i++) {
        if (isPrime(i) && num % i == 0) {
            // Recursively check the remaining part of the number with updated factor count
            if (isSphenicHelper(num / i, factorCount + 1, i)) {
                return 1;
            }
        }
    }
    return 0;
}

// Wrapper function to check if a number is sphenic
int isSphenic(int num) {
    return isSphenicHelper(num, 0, 1);  // Start with 0 factors and 1 as the last factor
}

// Recursive function to find all sphenic numbers between 1 and n
void findSphenicNumbers(int current, int n) {
    if (current > n) return;  // Base case: stop when current exceeds n
    if (isSphenic(current)) {
        printf("%d ", current);  // Print sphenic number
    }
    findSphenicNumbers(current + 1, n);  // Recursive call for the next number
}

int main() {
    int n;

    // Input: natural number n
    printf("Enter a natural number n: ");
    scanf("%d", &n);

    // Find and print all sphenic numbers between 1 and n
    printf("Sphenic numbers between 1 and %d are: ", n);
    findSphenicNumbers(1, n);  // Start from 1 to n
    printf("\n");

    return 0;
}
/*function isPrime(num) {
    if (num <= 1) return 0;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return 0;
    }
    return 1;
}

function isSphenicHelper(num, factorCount, lastFactor) {
    if (num == 1 && factorCount == 3) return 1;
    if (factorCount >= 3) return 0;
    for (int i = lastFactor + 1; i <= num; i++) {
        if (isPrime(i) && num % i == 0) {
            if (isSphenicHelper(num / i, factorCount + 1, i)) {
                return 1;
            }
        }
    }
    return 0;
}

function isSphenic(num) {
    return isSphenicHelper(num, 0, 1);
}

function findSphenicNumbers(current, n) {
    if (current > n) return;
    if (isSphenic(current)) {
        print(current);
    }
    findSphenicNumbers(current + 1, n);
}

function main() {
    int n;

    print("Enter a natural number n: ");
    n = read();

    print("Sphenic numbers between 1 and ", n, " are: ");
    findSphenicNumbers(1, n);

    return 0;
}*/