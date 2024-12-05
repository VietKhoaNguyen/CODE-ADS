#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to count the number of nodes in the tree
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Recursive function to perform inorder traversal and store values in an array
void inorderHelper(struct TreeNode* root, int* result, int* index) {
    if (root == NULL) {
        return;
    }
    
    // Traverse left subtree
    inorderHelper(root->left, result, index);
    
    // Visit current node
    result[*index] = root->val;
    (*index)++;
    
    // Traverse right subtree
    inorderHelper(root->right, result, index);
}

// Main function to return the inorder traversal of the binary tree
int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    // Count the number of nodes to allocate the result array
    int totalNodes = countNodes(root);
    
    // Allocate memory for the result array
    int* result = (int*)malloc(totalNodes * sizeof(int));
    if (!result) {
        *returnSize = 0;
        return NULL;  // If memory allocation fails, return NULL
    }

    // Initialize the index for storing values in the result array
    int index = 0;

    // Perform inorder traversal and store values in the result array
    inorderHelper(root, result, &index);

    // Set the return size to the number of elements in the result array
    *returnSize = totalNodes;

    // Return the result array
    return result;
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to print the array (for testing purposes)
void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main function to test the inorderTraversal function
int main() {
    // Constructing a simple binary tree:
    //         1
    //        / \
    //       2   3
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);

    int returnSize = 0;
    int* result = inorderTraversal(root, &returnSize);

    printf("Inorder Traversal: ");
    printArray(result, returnSize);

    // Free the allocated memory for the result array
    free(result);

    return 0;
}
