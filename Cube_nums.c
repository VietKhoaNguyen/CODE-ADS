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
/*recursive O(n)
#include <stdio.h>
#include <stdlib.h>

// Recursive function to check if n is a cube number
int CheckCubeNumber(int n, int i)
{
    // Calculate the sum of cubes of i and i+1
    int cube = i * i * i + (i + 1) * (i + 1) * (i + 1);
    
    // If we find the exact match, return 1
    if (n == cube)
        return 1;

    // If n is less than the current cube, no need to check further
    if (n < cube)
        return 0;

    // Recursively check the next value of i
    return CheckCubeNumber(n, i + 1);
}

// Function to check each element in the array and print if it is a cube number
void CheckCubeNumberArray(int* arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        if (CheckCubeNumber(arr[i], 1))
        {
            printf("%d is a cube number\n", arr[i]);
        }
        else
        {
            printf("%d is not a cube number\n", arr[i]);
        }
    }
}

int main()
{
    int arr[5] = {0, 7, 9, 35, 100};
    CheckCubeNumberArray(arr, 5);  // Check the numbers in the array
    return 0;
}

*/
