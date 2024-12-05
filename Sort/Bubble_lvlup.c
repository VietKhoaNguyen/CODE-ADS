#include <stdio.h>
 void swap(int *x, int *y){      //O(n^2)
    int temp = *x;
    *x = *y;
    *y = temp;
}

void Bubble_lvlup(int arr[], int n, int i ){
    int j;
    int swapped = 0;
    if(i < n-1){
        for(j = 0; j < n-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }        
        }
    }
    if(i < n-1){
        for(j = n -1; j > 0; j--){
            if(arr[j] < arr[j - 1]){
                swap(&arr[j], &arr[j - 1]);
                swapped = 1;
            }        
        }
    }
    if(swapped == 0){
        return;
    }

    Bubble_lvlup(arr, n, ++i)
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    Bubble_lvlup(arr, n, 0);

    printf("Sorted array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
/*
function swap(x, y) {
    temp = x
    x = y
    y = temp
}

function Bubble_lvlup(arr, n, i) {
    j = 0
    swapped = 0
    if i < n-1 {
        while j < n-1 {
            if arr[j] > arr[j+1] {
                swap(arr[j], arr[j+1])
                swapped = 1
            }
            j++
        }
    }
    if i < n-1 {
        j = n - 1
        while j > 0 {
            if arr[j] < arr[j-1] {
                swap(arr[j], arr[j-1])
                swapped = 1
            }
            j--
        }
    }
    if swapped == 0 {
        return
    }

    Bubble_lvlup(arr, n, i+1)
}

arr = [64, 34, 25, 12, 22, 11, 90]
n = size of arr / size of arr[0]

Bubble_lvlup(arr, n, 0)

print "Sorted array: "
for i = 0 to n-1 {
    print arr[i], " "
}
print "\n"
*/