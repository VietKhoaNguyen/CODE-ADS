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
/*recur O(logn)
#include <stdio.h>

int BinarySearch(int arr[], int target, int low, int high) {
    if (low > high) {
        return -1;  // Target not found
    }
    
    int mid = (low + high) / 2;
    if (arr[mid] == target) {
        return mid;  // Target found, return index
    } else if (arr[mid] < target) {
        return BinarySearch(arr, target, mid + 1, high);  // Search in the right half
    } else {
        return BinarySearch(arr, target, low, mid - 1);  // Search in the left half
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int target = 3;
    int result = BinarySearch(arr, target, 0, 4);
    printf("%d", result);  // Output: 2 (index of 3)
    return 0;
}
 */