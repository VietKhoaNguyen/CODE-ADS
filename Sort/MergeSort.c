#include <stdio.h>
#include <stdlib.h>
void merge(int arr[], int l, int m, int r)                  //Complexity: O(n*log(n))
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, arr_size);

    mergeSort(arr, 0, arr_size - 1);

    printf("\nSorted array is \n");
    printArray(arr, arr_size);
    return 0;
}
/*
function merge(arr, l, m, r)
   declare i, j, k as integers
   n1 = m - l + 1
   n2 = r - m

   declare L[n1], R[n2] as arrays

   for i from 0 to n1
       L[i] = arr[l + i]
   
   for j from 0 to n2
       R[j] = arr[m + 1 + j]

   i = 0
   j = 0
   k = l
   while i < n1 AND j < n2
       if L[i] <= R[j]
           arr[k] = L[i]
           i = i + 1
       else
           arr[k] = R[j]
           j = j + 1
       k = k + 1

   while i < n1
       arr[k] = L[i]
       i = i + 1
       k = k + 1

   while j < n2
       arr[k] = R[j]
       j = j + 1
       k = k + 1

function mergeSort(arr, l, r)
   if l < r
       m = l + (r - l) / 2

       mergeSort(arr, l, m)
       mergeSort(arr, m + 1, r)

       merge(arr, l, m, r)

function printArray(A, size)
   for i from 0 to size
       print A[i]

function main()
   arr = { 12, 11, 13, 5, 6, 7 }
   arr_size = size_of(arr) / size_of(arr[0])

   print "Given array is"
   printArray(arr, arr_size)

   mergeSort(arr, 0, arr_size - 1)

   print "Sorted array is"
   printArray(arr, arr_size)
*/

