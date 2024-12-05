#include <stdio.h>
#include <stdlib.h>

int CheckCubeNumber(int n, int i)
{
    int cube = i*i*i + (i+1)*(i+1)*(i+1);
    if (n == cube) return 1;
    if (n < cube) return 0;
    CheckCubeNumber(n, ++i);
}

void CheckCubeNumberArray(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (CheckCubeNumber(arr[i], 1))
        {
            printf("%d is cube number\n", arr[i]);
        }
        else
        {
            printf("%d is not cube number\n", arr[i]);
        }
    }
}

int main()
{
    int arr[5] = {0, 7, 9, 35, 100};
    CheckCubeNumberArray(arr, 5);
}