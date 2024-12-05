#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform DFS and find all paths
void dfs(struct TreeNode* root, char* path, char*** result, int* returnSize) {
    // Base case: if the root is NULL, return
    if (root == NULL) {
        return;
    }

    // Append the current node's value to the path
    int len = strlen(path);
    sprintf(path + len, "%d", root->val); // Append the node value to the path string

    // If it's a leaf node, add the current path to the result
    if (root->left == NULL && root->right == NULL) {
        // Allocate memory for a new string and copy the current path to it
        (*result)[*returnSize] = (char*)malloc(strlen(path) + 1);
        strcpy((*result)[*returnSize], path);
        (*returnSize)++;
    } else {
        // Otherwise, append "->" to the path and explore the left and right subtrees
        strcat(path, "->");

        // Recur for left and right child
        dfs(root->left, path, result, returnSize);
        dfs(root->right, path, result, returnSize);
    }

    // Backtrack: remove the current node's value and "->" from the path
    path[len] = '\0';
}

// Main function to return all root-to-leaf paths
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    // Allocate space for the result array (assuming a maximum of 1000 paths for now)
    char** result = (char**)malloc(1000 * sizeof(char*));
    *returnSize = 0;

    // Allocate a buffer to store the current path (assuming max depth is 1000)
    char path[1000];
    path[0] = '\0'; // Initialize the path as an empty string

    // Call DFS to fill the result array with paths
    dfs(root, path, &result, returnSize);

    return result;
}

// Helper function to create a new node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Test the function
int main() {
    // Create a binary tree
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->right = createNode(5);

    // Call the function
    int returnSize = 0;
    char** paths = binaryTreePaths(root, &returnSize);

    // Print the result paths
    printf("Paths:\n");
    for (int i = 0; i < returnSize; i++) {
        printf("%s\n", paths[i]);
        free(paths[i]);  // Free each string
    }

    free(paths);  // Free the result array

    return 0;
}
