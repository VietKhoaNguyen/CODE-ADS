#include <stdio.h>
#include <stdbool.h>

#define MOD 1000000007

// Function to calculate factorial modulo MOD
long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result = (result * i) % MOD;
    }
    return result;
}

// Function to count the number of primes up to n using the Sieve of Eratosthenes
int countPrimes(int n) {
    if (n < 2) return 0;  // No primes less than 2
    
    bool sieve[n + 1];
    for (int i = 0; i <= n; i++) sieve[i] = true;
    sieve[0] = sieve[1] = false;
    
    for (int i = 2; i * i <= n; i++) {
        if (sieve[i]) {
            for (int j = i * i; j <= n; j += i) {
                sieve[j] = false;
            }
        }
    }
    
    int primeCount = 0;
    for (int i = 2; i <= n; i++) {
        if (sieve[i]) primeCount++;
    }
    
    return primeCount;
}

// Function to calculate the number of prime arrangements modulo MOD
int numPrimeArrangements(int n) {
    int p = countPrimes(n);  // Count the number of primes up to n
    int nonPrimes = n - p;   // The number of non-prime numbers
    
    // Calculate the result using factorials of prime count and non-prime count
    long long primeFactorial = factorial(p);
    long long nonPrimeFactorial = factorial(nonPrimes);
    
    // Return the result modulo MOD
    return (primeFactorial * nonPrimeFactorial) % MOD;
}

// Test the function
int main() {
    int n = 5;
    printf("Number of prime arrangements for n = %d: %d\n", n, numPrimeArrangements(n));  // Expected output: 12
    return 0;
}
/*recur O(n* sqrt(n))
#include <stdio.h>
#include <stdbool.h>

#define MOD 1000000007

// Recursive function to calculate factorial modulo MOD
long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;  // Base case: 0! = 1 and 1! = 1
    }
    return (n * factorial(n - 1)) % MOD;
}

// Helper function to check if a number is prime
bool isPrime(int num, int i) {
    if (i * i > num) return true;  // If no divisor found, it's prime
    if (num % i == 0) return false; // If divisible by i, it's not prime
    return isPrime(num, i + 1);  // Recursively check the next divisor
}

// Recursive function to count primes up to n
int countPrimes(int n, int current) {
    if (current > n) return 0;  // Base case: we've checked all numbers up to n
    int isPrimeNumber = (current == 1) ? 0 : (isPrime(current, 2) ? 1 : 0);
    return isPrimeNumber + countPrimes(n, current + 1);  // Recursively count primes
}

// Function to calculate the number of prime arrangements modulo MOD
int numPrimeArrangements(int n) {
    int p = countPrimes(n, 1);  // Count the number of primes up to n
    int nonPrimes = n - p;      // The number of non-prime numbers
    
    // Calculate the result using factorials of prime count and non-prime count
    long long primeFactorial = factorial(p);
    long long nonPrimeFactorial = factorial(nonPrimes);
    
    // Return the result modulo MOD
    return (primeFactorial * nonPrimeFactorial) % MOD;
}

// Test the function
int main() {
    int n = 5;
    printf("Number of prime arrangements for n = %d: %d\n", n, numPrimeArrangements(n));  // Expected output: 12
    return 0;
}
*/