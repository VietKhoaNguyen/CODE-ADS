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

    int arr[5] = {3,9,23,35,60};

    CheckCenteredCubeArray(arr, 5);
}
/*recur O(n)
#include <stdio.h>
#include <stdlib.h>

// Recursive function to check if n is a centered cube
int CheckCenteredCubeRecursive(int n, int i, int cube)
{
    // Base case: If the cube exceeds n, n is not a centered cube
    if (n < cube)
    {
        return 0;
    }

    // If the cube matches n, n is a centered cube
    if (n == cube)
    {
        return 1;
    }

    // Recursive case: Compute the next centered cube and continue checking
    return CheckCenteredCubeRecursive(n, i + 1, (i + 1) * (i + 1) * (i + 1) + (i + 2) * (i + 2) * (i + 2));
}

// Wrapper function for checking centered cube
int CheckCenteredCube(int n)
{
    return CheckCenteredCubeRecursive(n, 1, 9); // Start from the first cube (i = 1, cube = 9)
}

// Recursive function to check an array of numbers for centered cubes
void CheckCenteredCubeArrayRecursive(int* arr, int length, int index)
{
    // Base case: If we have checked all elements, return
    if (index >= length)
    {
        return;
    }

    // If the current number is a centered cube, print it
    if (CheckCenteredCube(arr[index]))
    {
        printf("%d ", arr[index]);
    }

    // Recurse to check the next element
    CheckCenteredCubeArrayRecursive(arr, length, index + 1);
}

int main()
{
    int arr[5] = {3, 9, 23, 35, 60};

    // Call the recursive function to check the array
    CheckCenteredCubeArrayRecursive(arr, 5, 0);  // Start from index 0

    return 0;
}
<<<<<<< HEAD
*/
=======
*/
>>>>>>> 5527a31819c76f85ec241af65a5c546360320eae
