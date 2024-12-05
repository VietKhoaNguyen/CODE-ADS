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