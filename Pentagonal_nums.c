#include<stdio.h>
#include<math.h>
/* Create a random array
Create a for loops with i-> Array Length
Check whether Arr[i] = (3n^2-n)/2 with n=1
else n++ */
void pentagonite(int arr[],int l)
{
    for(int i=0;i<=l;i++)
    {
        for(int n=1;n<=arr[i];n++)
        {
            int pentagon=(3*pow(n,2)-n)/2;
            if(arr[i] == pentagon){
                printf("%d is a pentagonal number\n",arr[i]);
            }
        }
    }
}

void pentagonrec(int* arr, int l, int i, int n)
{
    if (i <= l)
    {
        if (n <= arr[i])
        {
            int pentagon=(3*pow(n,2)-n)/2;
            if(arr[i] == pentagon){
                printf("%d is a pentagonal number\n",arr[i]);
            }

            pentagonrec(arr, l, i, ++n);
        }

        pentagonrec(arr, l, ++i, 1);
    }
}

int main ()
{
    int arr[5]={1,5,12,2,3};
    //pentagonite(arr, 5);
    pentagonrec(arr, 5, 0, 1);

}
/*recur O(n)
#include<stdio.h>
#include<math.h>

// Recursive function to check if a number is a pentagonal number
int isPentagonal(int n) {
    int i = 1;
    while (1) {
        int pentagon = (3 * pow(i, 2) - i) / 2;
        if (pentagon == n) {
            return 1;  // It's a pentagonal number
        } else if (pentagon > n) {
            return 0;  // It's not a pentagonal number
        }
        i++;
    }
}

// Recursive function to check each element in the array
void pentagonrec(int* arr, int l, int i) {
    // Base case: when we have checked all elements
    if (i >= l) {
        return;
    }

    // Check if the current element is a pentagonal number
    if (isPentagonal(arr[i])) {
        printf("%d is a pentagonal number\n", arr[i]);
    }

    // Recur for the next element
    pentagonrec(arr, l, i + 1);
}

int main() {
    int arr[5] = {1, 5, 12, 2, 3};
    pentagonrec(arr, 5, 0);  // Start recursion with index 0
    return 0;
}
*/
