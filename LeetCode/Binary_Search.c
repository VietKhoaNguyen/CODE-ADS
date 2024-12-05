#include <stdio.h>
int BinarySearch(int arr[], int target, int low, int high)
{
    int mid= (low+high)/2;
    if (arr[mid]==target)
    {
        return mid;
    }
    else if (arr[mid]<target)
    {
        BinarySearch(arr, target, mid, high);
    }
    else
    {
        BinarySearch(arr, target, low, mid);
    }
}

int main()
{
    int arr[]={1,2,3,4,5};
    printf("%d",BinarySearch(arr, 3, 0, 4));
}
/*
binary_search(arr, target, low, high)
    mid = (low + high) / 2
    if arr[mid] == target
        return mid
    else if arr[mid] < target
        return binary_search(arr, target, mid, high)
    else
        return binary_search(arr, target, low, mid)

main()
    arr = [1, 2, 3, 4, 5]
    print(binary_search(arr, 3, 0, 4))
*/