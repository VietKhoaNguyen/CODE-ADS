#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to perform in-order traversal and count frequencies
void inorderTraversal(struct TreeNode* root, int* count, int* prev, int* maxCount, int* modes, int* modeSize) {
    if (root == NULL) {
        return;
    }
    
    // Traverse the left subtree
    inorderTraversal(root->left, count, prev, maxCount, modes, modeSize);

    // Count the current node's value
    if (*prev == root->val) {
        (*count)++;
    } else {
        *prev = root->val;
        *count = 1;
    }

    // Check if this count is a new maximum
    if (*count > *maxCount) {
        *maxCount = *count;
        *modeSize = 0; // Reset the modes array
        modes[*modeSize] = root->val;
        (*modeSize)++;
    } else if (*count == *maxCount) {
        modes[*modeSize] = root->val;
        (*modeSize)++;
    }

    // Traverse the right subtree
    inorderTraversal(root->right, count, prev, maxCount, modes, modeSize);
}

int* findMode(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    
    if (root == NULL) {
        return NULL;
    }

    int* modes = (int*)malloc(1000 * sizeof(int)); // Allocate a large enough array for storing modes
    int count = 0; // Current count of a number
    int prev = INT_MIN; // Previous value for comparison
    int maxCount = 0; // Maximum frequency
    int modeSize = 0; // Size of the modes array

    inorderTraversal(root, &count, &prev, &maxCount, modes, &modeSize);

    *returnSize = modeSize; // Set the size of the result
    return modes;
}
struct TreeNode* newTreeNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

int main() {
    // Example: Create a binary search tree
    struct TreeNode* root = newTreeNode(1);
    root->right = newTreeNode(2);
    root->right->left = newTreeNode(2);
    
    int returnSize;
    int* result = findMode(root, &returnSize);
    
    // Print the result (modes)
    printf("Modes: ");
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    
    free(result); // Free allocated memory
    return 0;
}