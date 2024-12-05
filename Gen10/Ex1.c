#include <stdio.h>
/*Given an array of 10 elements: 2, 10, 27, 13, 90, 45, 5, 26, 49, 50.
In this problem, we try to find all co-prime numbers. Two integer numbers are co-prime if the
greatest common divisor of these two is 1.
The list of co-prime numbers from the above array is: {(2, 27), (2,13), (2,45), (2,5), (2,49), (10,
27), (10, 13), (10,49), (27,13), (27,5), (27,26), (27,50), (13,90), (13,45), (13,5), (13,49), (13,50),
(90,49), (90,26), (90,49), (45,26), (45,49), (5,26), (5,49), (26,49), (49,50)}. Write a program to find all co-prime numbers with a given array of integer numbers using
Iteration
*/
// Function to calculate the GCD of two numbers using Euclidean algorithm
int gcd(int a, int b) {                 //Complexity:O(n^2)
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find and print all co-prime pairs in the array
void findCoprimePairs(int arr[], int n) {
    printf("Co-prime pairs are: \n");
    // Iterate over all pairs (i, j) where i < j
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // Check if the GCD of arr[i] and arr[j] is 1
            if (gcd(arr[i], arr[j]) == 1) {
                printf("(%d, %d)\n", arr[i], arr[j]);  // Print the co-prime pair
            }
        }
    }
}

int main() {
    // Given array of 10 elements
    int arr[] = {2, 10, 27, 13, 90, 45, 5, 26, 49, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Find and print all co-prime pairs
    findCoprimePairs(arr, n);

    return 0;
}
/*function gcd(a, b):
    while b != 0:
        temp = b
        b = a % b
        a = temp
    return a

function findCoprimePairs(arr, n):
    output "Co-prime pairs are: "
    for i from 0 to n-1:
        for j from i+1 to n-1:
            if gcd(arr[i], arr[j]) == 1:
                output "(", arr[i], ", ", arr[j], ")"
                
function main():
    arr = [2, 10, 27, 13, 90, 45, 5, 26, 49, 50]
    n = length(arr)
    findCoprimePairs(arr, n)

main()*/