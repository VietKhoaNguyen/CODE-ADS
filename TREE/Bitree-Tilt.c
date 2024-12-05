#include <stdlib.h>
#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to compute the sum of the subtree rooted at the node and calculate tilt.
int calculateSumAndTilt(struct TreeNode* root, int* tilt) {
    if (root == NULL) {
        return 0;  // If the node is null, return a sum of 0.
    }
    
    // Recursively calculate the sum of the left and right subtrees.
    int leftSum = calculateSumAndTilt(root->left, tilt);
    int rightSum = calculateSumAndTilt(root->right, tilt);
    
    // Calculate the tilt for the current node.
    *tilt += abs(leftSum - rightSum);
    
    // Return the sum of values for the current subtree rooted at this node.
    return root->val + leftSum + rightSum;
}

// Main function to find the tilt of the binary tree.
int findTilt(struct TreeNode* root) {
    int tilt = 0;
    calculateSumAndTilt(root, &tilt);
    return tilt;
}

// Example usage
int main() {
    // Example binary tree:
    //       1
    //      / \
    //     2   3
    //    / \
    //   4   5
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->val = 2;
    root->right->val = 3;
    root->left->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->left->val = 4;
    root->left->right->val = 5;
    root->left->left->left = root->left->left->right = NULL;
    root->left->right->left = root->left->right->right = NULL;
    root->right->left = root->right->right = NULL;

    int tilt = findTilt(root);
    printf("Tilt of the binary tree is: %d\n", tilt);  // Expected output: 11

    return 0;
}
