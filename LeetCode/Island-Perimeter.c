#include <stdio.h>

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;

    // Directions: up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    // Iterate through each cell in the grid
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) { // If it's a land cell
                // Check all four directions
                for (int d = 0; d < 4; d++) {
                    int newRow = i + directions[d][0];
                    int newCol = j + directions[d][1];

                    // Check if it's out of bounds or water
                    if (newRow < 0 || newRow >= gridSize || newCol < 0 || newCol >= gridColSize[i] || grid[newRow][newCol] == 0) {
                        perimeter++; // Add 1 to perimeter for each water or boundary side
                    }
                }
            }
        }
    }

    return perimeter;
}

int main() {
    int grid[4][4] = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };

    int gridSize = 4;
    int gridColSize[4] = {4, 4, 4, 4};

    // Convert grid to a pointer-to-pointer for use in function
    int* gridPtrs[4];
    for (int i = 0; i < 4; i++) {
        gridPtrs[i] = grid[i];
    }

    printf("Island Perimeter: %d\n", islandPerimeter(gridPtrs, gridSize, gridColSize));

    return 0;
}
/*recur O(m*n)
#include <stdio.h>

int calculatePerimeter(int** grid, int gridSize, int* gridColSize, int row, int col) {
    // Directions: up, down, left, right
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int perimeter = 0;

    // Check all four directions
    for (int d = 0; d < 4; d++) {
        int newRow = row + directions[d][0];
        int newCol = col + directions[d][1];

        // Check if it's out of bounds or water
        if (newRow < 0 || newRow >= gridSize || newCol < 0 || newCol >= gridColSize[row] || grid[newRow][newCol] == 0) {
            perimeter++; // Add 1 to perimeter for each water or boundary side
        }
    }

    return perimeter;
}

void dfs(int** grid, int gridSize, int* gridColSize, int row, int col, int* perimeter) {
    // If the cell is out of bounds or already visited, return
    if (row < 0 || row >= gridSize || col < 0 || col >= gridColSize[row] || grid[row][col] == 0) {
        return;
    }

    // Mark the cell as visited
    grid[row][col] = 0; // Set the cell to 0 to avoid revisiting it

    // Add the perimeter of the current cell
    *perimeter += calculatePerimeter(grid, gridSize, gridColSize, row, col);

    // Visit all four directions recursively
    dfs(grid, gridSize, gridColSize, row - 1, col, perimeter); // Up
    dfs(grid, gridSize, gridColSize, row + 1, col, perimeter); // Down
    dfs(grid, gridSize, gridColSize, row, col - 1, perimeter); // Left
    dfs(grid, gridSize, gridColSize, row, col + 1, perimeter); // Right
}

int islandPerimeter(int** grid, int gridSize, int* gridColSize) {
    int perimeter = 0;

    // Start DFS from the first land cell
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridColSize[i]; j++) {
            if (grid[i][j] == 1) { // Start DFS from the first land cell
                dfs(grid, gridSize, gridColSize, i, j, &perimeter);
                return perimeter; // Return the perimeter once the island is fully explored
            }
        }
    }

    return perimeter; // If no land cell is found, return 0
}

int main() {
    int grid[4][4] = {
        {1, 1, 0, 0},
        {1, 1, 0, 0},
        {0, 0, 1, 1},
        {0, 0, 1, 1}
    };

    int gridSize = 4;
    int gridColSize[4] = {4, 4, 4, 4};

    // Convert grid to a pointer-to-pointer for use in function
    int* gridPtrs[4];
    for (int i = 0; i < 4; i++) {
        gridPtrs[i] = grid[i];
    }

    printf("Island Perimeter: %d\n", islandPerimeter(gridPtrs, gridSize, gridColSize));

    return 0;
}
*/