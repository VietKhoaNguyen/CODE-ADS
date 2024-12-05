#include <stdio.h>
#include <stdlib.h>
//Ex1: Selection Sort
void selectionSort(int arr[], int n) {          //Complexity: O(n^2)
    int i, j, min_idx;
    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);
 
    selectionSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
/*
procedure selectionSort(arr: array of integers, n: integer)
    i, j, min_idx: integer
    for i = 0 to n - 1
        min_idx = i
        for j = i + 1 to n
            if arr[j] < arr[min_idx]
                min_idx = j
        if min_idx != i
            temp = arr[min_idx]
            arr[min_idx] = arr[i]
            arr[i] = temp

procedure printArray(arr: array of integers, n: integer)
    for i = 0 to n
        print arr[i]
    print newline

procedure main()
    arr = [64, 25, 12, 22, 11]
    n = sizeof(arr) / sizeof(arr[0])
    
    print "Original array:"
    printArray(arr, n)
    
    selectionSort(arr, n)
    
    print "Sorted array:"
    printArray(arr, n)
*/

//Ex2: Improve the Selection Sort by using Binary Recusion
//- Find the minimum and maximum recursively from the unsorted part (two recursive functions).
//- Put the minimum at the end of the sorted part I (which is empty at the beginning)
//- Put the maximum at the front of the sorted part II (which is empty at the beginning)

void Swap(int* a, int* b)                      //Complexity: O(n^2)
{
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Findmin(int a[], int i, int j, int min)
{
    if (i>j)
    {
        return min;
    }

    if (a[min]>a[i])
    {
        min=i;
    }
    Findmin(a, i+1, j, min);
}

int Findmax(int a[], int i, int j,int max)
{
    if (i>j)
    {
        return max;
    }

    if (a[max]<a[i])
    {
        max=i;
    }
    Findmax(a, i+1, j, max);
}

void Select(int a[], int minindex, int maxindex)
{
    if (minindex>=maxindex)
    {
        return;
    }

    int min=Findmin(a, minindex, maxindex, minindex);
    Swap(&a[min], &a[minindex]);
    
    int max=Findmax(a,minindex, maxindex, maxindex);
    Swap(&a[max], &a[maxindex]);

    Select(a,minindex+1, maxindex-1);
}

int main()
{
    int a[5]={1,5,2,8,4};
    Select(a,0,4);
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", a[i]);
    }

}

// function Swap(a, b)
//   temp = a
//    a = b
//    b = temp
//
//function Findmin(a, i, j, min)
//    if i > j
//        return min
//    if a[min] > a[i]
//        min = i
//    Findmin(a, i + 1, j, min)
//
//function Findmax(a, i, j, max)
//    if i > j
//        return max
//    if a[max] < a[i]
//        max = i
//    Findmax(a, i + 1, j, max)

//function Select(a, minindex, maxindex)
//    if minindex >= maxindex
//        return
//    min = Findmin(a, minindex, maxindex, minindex)
//    Swap(a[min], a[minindex])
//    max = Findmax(a, minindex, maxindex, maxindex)
//    Swap(a[max], a[maxindex])
//    Select(a, minindex + 1, maxindex - 1)

//function Main()
//    a = [1, 5, 2, 8, 4]
//    Select(a, 0, 4)
//    for i from 0 to 4
//        print a[i]

//Main()
