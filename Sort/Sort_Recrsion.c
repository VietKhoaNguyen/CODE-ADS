//SORT RECUR
#include <stdio.h>

int minIndex(int arr[], int i, int j) 
{
    if (i == j) 
    {
        return i;
    } 
    else 
    {
        int k = minIndex(arr, i + 1, j);
        if (arr[i] < arr[k]) 
        {
            return i;
        } 
        else 
        {
            return k;
        }
    }
}

void selectionSort(int arr[], int n, int index) 
{
    if (index == n)
    {
        return;
    } 
    else 
    {
        int k = minIndex(arr, index, n - 1);
        if (k != index) 
        {
            int temp = arr[k];
            arr[k] = arr[index];
            arr[index] = temp;
        }
        selectionSort(arr, n, index + 1);
    }
}

void bubbleSort(int arr[], int n) 
{
    if (n == 1) 
    {
        return;
    } 
    else 
    {
        for (int i = 0; i < n - 1; i++) 
        {
            if (arr[i] > arr[i + 1]) 
            {
                int temp = arr[i];
                arr[i] = arr[i + 1];
                arr[i + 1] = temp;
            }
        }
        bubbleSort(arr, n - 1);
    }
}

void insertionSort(int arr[], int n) 
{
    if (n <= 1) 
    {
        return;
    } 
    else 
    {
        insertionSort(arr, n - 1);
        int last = arr[n - 1];
        int j = n - 2;
        while (j >= 0 && arr[j] > last) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = last;
    }
}

int main() {
    int arr1[] = {64, 25, 12, 22, 11};
    int arr2[] = {64, 34, 25, 12, 22, 11, 90};
    int arr3[] = {9, 8, 7, 2, 3, 4};

    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int n3 = sizeof(arr3) / sizeof(arr3[0]);

    selectionSort(arr1, n1, 0);
    bubbleSort(arr2, n2);
    insertionSort(arr3, n3);

    for (int i = 0; i < n1; i++) printf("%d ", arr1[i]);
    printf("\n");

    for (int i = 0; i < n2; i++) printf("%d ", arr2[i]);
    printf("\n");

    for (int i = 0; i < n3; i++) printf("%d ", arr3[i]);
    printf("\n");

    return 0;
}