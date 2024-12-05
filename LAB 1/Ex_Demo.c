#include <stdio.h>
#include <stdbool.h>
#include <math.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1){
        return false;
    }
    if (num <= 3){
        return true;
    }
    if(num % 2 == 0 || num % 3 == 0){
        return false;
    }
    for (int i = 5; i * i <= num; i += 6) { // Optimized loop iteration, starting from 5 and skipping even numbers using i += 6
        if (num % i == 0 || num % (i + 2) == 0) // Checking only two possibilities i and i+2
            return false;
    }
    return true;
}

// Function to check if a number is Sphenic
bool Sphenic(int n) {
    int factors = 0;
    if (n < 30) // Replaced 2 * 3 * 5 with 30 for efficiency
        return false;
    for (int p = 2; p <= sqrt(n); p++) { // Optimized loop iteration, checking upto square root of n
        if (n % p == 0) {
            factors++;
            n /= p;
            if (n % p == 0){
                return false;
            }
        }
    }
    if(factors == 2){ // Checking for 3 distinct prime factors
        return true;
    }
    return false;
}

// Function to print the prime factors of a number
void Print(int n) {
    for (int p = 2; p <= n; p++) {
        while (n % p == 0) {
            if (isPrime(p)){
                printf("%d ", p);
            }
            n /= p;
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        if (Sphenic(n)){
            printf("True: ");
            Print(n); // Reused the factorization result from Sphenic function
        }
        else{
            printf("Wrong\n"); // Changed to printf("Wrong\n") for a newline
        }
    }
    return 0;
}