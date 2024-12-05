#include <stdio.h>
#include <math.h>
int isPrime(int n) {                                //Complexity: O(sqrt(n))
    if (n <= 1) return 0;
    if (n == 2 || n == 3) return 1;
    if (n % 2 == 0 || n % 3 == 0) return 0;
    
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return 0;
    }
    return 1;
}

int largestDivisor(int n) {
    for (int i = n / 2; i > 1; i--) {
        if (n % i == 0) {
            return i;
        }
    }
    return 1;
}

void factorize(int n) {
    if (n <= 1) return;

    if (isPrime(n)) {
        printf("%d ", n);
        return;
    }

    int d1 = largestDivisor(n);
    int d2 = n / d1;

    if (isPrime(d1) == 0) { 
        factorize(d1);
    } else {
        printf("%d ", d1);
    }

    if (isPrime(d2) == 0) {
        factorize(d2);
    } else {
        printf("%d ", d2);
    }
}

int main() {
    int n;

    printf("Enter a number to factorize: ");
    scanf("%d", &n);
    
    printf("Prime factorization of %d: ", n);
    factorize(n);
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