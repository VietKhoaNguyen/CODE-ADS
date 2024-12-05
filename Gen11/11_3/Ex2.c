#include <stdio.h>
/*Given an array of nautral numbers as following: 4, 15, 45, 9, 40, 27, 3, 5, 10.
In this problem, we try to find all triplets (a, b, c) where a number is the product of two other
numbers in the array i.e. a = b*c; or b = a*c; or c = a*b.
The expect outcome of the above array is: {(15, 3, 5}, (45, 9, 5), (4, 40, 10), (9, 27, 3), (15, 45,
3)}
*/
void find_triplets_recursive(int arr[], int n) {          //Complexity: O(n^3)
    int result[100][3]; // Assuming maximum 100 triplets
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] == arr[j] * arr[k] || arr[j] == arr[i] * arr[k] || arr[k] == arr[i] * arr[j]) {
                    result[count][0] = arr[i];
                    result[count][1] = arr[j];
                    result[count][2] = arr[k];
                    count++;
                }
            }
        }
    }

    // Print the triplets
    for (int i = 0; i < count; i++) {
        printf("(%d, %d, %d)\n", result[i][0], result[i][1], result[i][2]);
    }
}

int main() {
    int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    find_triplets_recursive(arr, n);
    
    return 0;
}
/*
void find_triplets_recursive(int arr[], int n) {
    int result[100][3]; // Assuming maximum 100 triplets
    int count = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (arr[i] == arr[j] * arr[k] || arr[j] == arr[i] * arr[k] || arr[k] == arr[i] * arr[j]) {
                    result[count][0] = arr[i];
                    result[count][1] = arr[j];
                    result[count][2] = arr[k];
                    count++;
                }
            }
        }
    }

    // Print the triplets
    for (int i = 0; i < count; i++) {
        printf("(%d, %d, %d)\n", result[i][0], result[i][1], result[i][2]);
    }
}

int main() {
    int arr[] = {4, 15, 45, 9, 40, 27, 3, 5, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    find_triplets_recursive(arr, n);
    
    return 0;
}*/