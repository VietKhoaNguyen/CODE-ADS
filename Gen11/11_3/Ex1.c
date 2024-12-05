#include <stdio.h>
#include <stdlib.h>
/*Given an array of nautral numbers as following: 4, 15, 45, 9, 40, 27, 3, 5, 10.
In this problem, we try to find all triplets (a, b, c) where a number is the product of two other
numbers in the array i.e. a = b*c; or b = a*c; or c = a*b.
The expect outcome of the above array is: {(15, 3, 5}, (45, 9, 5), (4, 40, 10), (9, 27, 3), (15, 45,
3)}
*/
void find_triplets_iterative(int arr[], int size) {      //Complexity: O(n^3)
    int result[3];
    
    // Iterate through the array
    for (int i = 0; i < size; i++) {
        int a = arr[i];
        int remaining[size - 1];
        int index = 0;
        
        for (int j = 0; j < size; j++) {
            if (j != i) {
                remaining[index] = arr[j];
                index++;
            }
        }
        
        // Check all pairs in the remaining elements
        for (int j = 0; j < size - 1; j++) {
            for (int k = j + 1; k < size - 1; k++) {
                int b = remaining[j];
                int c = remaining[k];
                
                if (a == b * c || b == a * c || c == a * b) {
                    result[0] = a;
                    result[1] = b;
                    result[2] = c;
                    printf("{%d, %d, %d}\n", result[0], result[1], result[2]);
                }
            }
        }
    }
}

int main() {
    int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int size = sizeof(arr) / sizeof(int);
    
    find_triplets_iterative(arr, size);
    
    return 0;
}/*
function find_triplets_iterative(arr) {
    result = new Set()

    for i = 0 to length of arr - 1 do
        a = arr[i]
        remaining = arr[0:i] + arr[i+1:]

        for j = 0 to length of remaining - 1 do
            for k = j + 1 to length of remaining do
                b = remaining[j]
                c = remaining[k]
                if a = b * c OR b = a * c OR c = a * b then
                    result.add(sorted([a, b, c]))

    return result
}

arr = [4, 15, 45, 9, 40, 27, 3, 5, 10]
triplets_iterative = find_triplets_iterative(arr)
print(triplets_iterative)
*/