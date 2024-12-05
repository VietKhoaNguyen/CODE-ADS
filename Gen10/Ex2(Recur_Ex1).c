#include <stdio.h>

// Recursive function to calculate the GCD of two numbers
int gcd(int a, int b) {                 //Complexity:O(n^2)
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// Recursive function to find and print co-prime pairs
void findCoprimePairsRecursive(int arr[], int n, int i, int j) {
    // Base case: If all pairs are checked
    if (i >= n - 1) {
        return;
    }

    // Base case for inner loop (j)
    if (j >= n) {
        findCoprimePairsRecursive(arr, n, i + 1, i + 2); // Move to the next i and reset j
        return;
    }

    // Check if the pair (arr[i], arr[j]) is co-prime
    if (gcd(arr[i], arr[j]) == 1) {
        printf("(%d, %d)\n", arr[i], arr[j]);
    }

    // Recursive call to check the next pair (arr[i], arr[j+1])
    findCoprimePairsRecursive(arr, n, i, j + 1);
}

int main() {
    // Given array of 10 elements
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Output message
    printf("Co-prime pairs are:\n");

    // Start finding co-prime pairs using recursion
    findCoprimePairsRecursive(arr, n, 0, 1); // Start with first pair (arr[0], arr[1])

    return 0;
}
/*
FUNCTION gcd(a, b)
    IF b == 0 THEN
        RETURN a
    ELSE
        RETURN gcd(b, a % b)

FUNCTION findCoprimePairsRecursive(arr, n, i, j)
    IF i >= n - 1 THEN
        RETURN
    END IF
    
    IF j >= n THEN
        findCoprimePairsRecursive(arr, n, i + 1, i + 2)
        RETURN
    END IF
    
    IF gcd(arr[i], arr[j]) == 1 THEN
        OUTPUT "(%d, %d)\n", arr[i], arr[j]
    END IF
    
    findCoprimePairsRecursive(arr, n, i, j + 1)

FUNCTION main()
    arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50}
    n = LENGTH(arr)
    
    OUTPUT "Co-prime pairs are:\n"
    
    findCoprimePairsRecursive(arr, n, 0, 1)    

main()
*/