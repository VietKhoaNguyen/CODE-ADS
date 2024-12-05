#include <stdio.h>
#include <stdlib.h>

int CheckCenteredCube(int n)
{
    int i = 1;
    int cube = 9;

    while (n >= cube)
    {
        if (n == cube)
        {
            return 1;
        }

        i++;
        cube = i*i* i + (i+1)* (i+1)* (i+1);
    }

    return 0;
}

void CheckCenteredCubeArray(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (CheckCenteredCube(arr[i]))
        {
            printf("%d ", arr[i]);
        }
    }
}

int main() 
{
    //Iteration
    //Recursion
    int arr[5] = {3,9,23,35,60};

    CheckCenteredCubeArray(arr, 5);
}