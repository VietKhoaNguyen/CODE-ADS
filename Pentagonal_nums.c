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