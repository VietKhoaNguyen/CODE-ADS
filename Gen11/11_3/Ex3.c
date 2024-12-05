#include <stdio.h>
#include <stdlib.h>
/*Propose a method to improve the proposed algorithm in Question 1, with the aims of
reducing the complexity of proposed algorithm (time complexity or memory complexity)
*/
void find_triplets_optimized(int arr[], int n) {         // //Complexity: O(n^3)
    int result[3];
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int b = arr[i];
            int c = arr[j];

            if (b * c != 0 && arr[b * c] != 0) {
                result[0] = b * c;
                result[1] = b;
                result[2] = c;
                qsort(result, 3, sizeof(int), compare);
                printf("(%d, %d, %d)\n", result[0], result[1], result[2]);
            }

            if (b != 0 && c % b == 0 && arr[c / b] != 0) {
                result[0] = c;
                result[1] = b;
                result[2] = c / b;
                qsort(result, 3, sizeof(int), compare);
                printf("(%d, %d, %d)\n", result[0], result[1], result[2]);
            }

            if (c != 0 && b % c == 0 && arr[b / c] != 0) {
                result[0] = b;
                result[1] = b / c;
                result[2] = c;
                qsort(result, 3, sizeof(int), compare);
                printf("(%d, %d, %d)\n", result[0], result[1], result[2]);
            }
        }
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    find_triplets_optimized(arr, n);
    
    return 0;
}
/*function find_triplets_optimized(arr, n)
    result = array of size 3
    
    for i from 0 to n-1
        for j from i+1 to n-1
            b = arr[i]
            c = arr[j]
            
            if b * c != 0 and arr[b * c] != 0
                result[0] = b * c
                result[1] = b
                result[2] = c
                sort(result)
                print("(result[0], result[1], result[2])")

            if b != 0 and c mod b == 0 and arr[c / b] != 0
                result[0] = c
                result[1] = b
                result[2] = c / b
                sort(result)
                print("(result[0], result[1], result[2])")

            if c != 0 and b mod c == 0 and arr[b / c] != 0
                result[0] = b
                result[1] = b / c
                result[2] = c
                sort(result)
                print("(result[0], result[1], result[2])")

function compare(a, b)
    return a - b

function main()
    arr = [4, 15, 45, 9, 40, 27, 3, 5, 10]
    n = size of arr
    
    find_triplets_optimized(arr, n)

main()*/