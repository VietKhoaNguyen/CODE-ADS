#include <stdio.h>
#include <math.h>
                            //Complexity: O(sqrt(n))
// Function to check if a number is prime
int isPrime(int n) {
    if (n <= 1) return 0; // 0 and 1 are not prime
    if (n == 2 || n == 3) return 1; // 2 and 3 are prime
    if (n % 2 == 0 || n % 3 == 0) return 0; // Multiples of 2 or 3 are not prime
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return 0; // Check for divisibility
    }
    return 1;
}

// Function to find the largest divisor of n
int largestDivisor(int n) {
    for (int i = n / 2; i > 1; i--) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

// Recursive function to fully factorize the number
void factorize(int n) {
    if (n <= 1) return; // Stop recursion if n is 1 or less

    if (isPrime(n)) {
        printf("%d ", n); // If n is prime, just print it
        return;
    }

    // Find the largest divisor of n
    int d1 = largestDivisor(n);
    int d2 = n / d1;

    // Factorize the divisor recursively
    if (isPrime(d1)) {
        printf("%d ", d1);
    } else {
        factorize(d1); // Recursively factorize d1
    }

    // Factorize the second divisor
    if (isPrime(d2)) {
        printf("%d ", d2);
    } else {
        factorize(d2); // Recursively factorize d2
    }
}

// Main function
int main() {
    int n;
    
    printf("Enter a number to factorize: ");
    scanf("%d", &n);
    
    printf("Prime factorization of %d: ", n);
    factorize(n); // Factorize the number recursively
    printf("\n");

    return 0;
}

/*
function isPrime(n) {
    if (n <= 1) 
        return 0;
    if (n == 2 || n == 3) 
        return 1;
    if (n % 2 == 0 || n % 3 == 0) 
        return 0;

    i = 5
    while i * i <= n {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
        i += 6
    }
    return 1;
}

function largestDivisor(n) {
    i = n / 2
    while i > 1 {
        if (n % i == 0) {
            return i;
        }
        i--
    }
    return 1;
}

function factorize(n) {
    if (n <= 1) 
        return;
    
    if (isPrime(n)) {
        print n
        return;
    }

    d1 = largestDivisor(n);
    d2 = n / d1;

    if (isPrime(d1) == 0) {
        factorize(d1);
    } else {
        print d1
    }

    if (isPrime(d2) == 0) {
        factorize(d2);
    } else {
        print d2
    }
}

function main() {
    input n
    print "Enter a number to factorize: ", n
    print "Prime factorization of ", n, ": "
    factorize(n)
    print newline
}*/