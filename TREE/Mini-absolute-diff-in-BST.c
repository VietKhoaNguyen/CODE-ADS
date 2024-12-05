#include <stdio.h>
#include <limits.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function for in-order traversal
void inOrderTraversal(struct TreeNode* root, int* prev, int* minDiff) {
    if (root == NULL) {
        return;
    }

    // Traverse the left subtree
    inOrderTraversal(root->left, prev, minDiff);

    // Process the current node
    if (*prev != -1) {
        int diff = root->val - *prev;
        if (diff < *minDiff) {
            *minDiff = diff;
        }
    }
    *prev = root->val;

    // Traverse the right subtree
    inOrderTraversal(root->right, prev, minDiff);
}

// Main function to find the minimum difference
int getMinimumDifference(struct TreeNode* root) {
    int prev = -1;  // Previous node value (initialize to -1, meaning no node visited yet)
    int minDiff = INT_MAX;  // Initialize minDiff to the largest possible integer
    inOrderTraversal(root, &prev, &minDiff);
    return minDiff;
}

int main() {
    // Example Usage
    // Construct a simple BST
    struct TreeNode node1 = {1, NULL, NULL};
    struct TreeNode node3 = {3, NULL, NULL};
    struct TreeNode node2 = {2, &node1, &node3};
    
    // Find the minimum difference
    int result = getMinimumDifference(&node2);
    printf("Minimum absolute difference: %d\n", result);  // Output should be 1
    
    return 0;
}
