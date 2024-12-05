#include <stdio.h>
void BubbleSort(int* arr, int length)
{
    for (int i = 0; i < length-1; i++)
    {
        for (int j = 0; j < length-1-i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void SelectionSort(int* arr, int length)
{
    for (int i = 0; i < length-1; i++)
    {
        int minIndex = i;
        for (int j = i+1; j < length; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void InsertionSort(int* arr, int length)
{
    for (int i = 1; i < length; i++)
    {
        int temp = arr[i];
        int count = 0;
        for (int j = i-1; j >= 0; j--)
        {
            if (arr[j] > temp)
            {
                arr[j+1] = arr[j];
                count++;
            }
            else break;
        }

        arr[i-count] = temp;
    }
}

int main()
{
    int arr[7] = {3,1,8,5,9,0,3};

    InsertionSort(arr, 7);

    for (int i = 0; i < 7; i++)
    {
        printf("%d ", arr[i]);
    }
}