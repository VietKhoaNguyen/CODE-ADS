#include <limits.h>  // For INT_MAX

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to calculate the minimum depth of the binary tree
int minDepth(struct TreeNode* root) {
    // Base case: if the tree is empty, return depth 0
    if (root == NULL) {
        return 0;
    }
    
    // If the left child is NULL, recursively calculate the depth of the right subtree
    if (root->left == NULL) {
        return minDepth(root->right) + 1;
    }
    
    // If the right child is NULL, recursively calculate the depth of the left subtree
    if (root->right == NULL) {
        return minDepth(root->left) + 1;
    }
    
    // If both left and right children exist, find the minimum depth of the left and right subtrees
    int leftDepth = minDepth(root->left);
    int rightDepth = minDepth(root->right);
    
    // Return the minimum of the left and right subtree depths, plus 1 for the current node
    return 1 + (leftDepth < rightDepth ? leftDepth : rightDepth);
}
