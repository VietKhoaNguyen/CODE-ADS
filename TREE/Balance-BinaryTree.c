#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to check the height and balance of the tree
int checkHeight(struct TreeNode* root) {
    // Base case: If the node is NULL, its height is 0 and it's balanced
    if (root == NULL) {
        return 0;
    }
    
    // Recursively check the height of the left subtree
    int leftHeight = checkHeight(root->left);
    if (leftHeight == -1) {
        return -1;  // If the left subtree is unbalanced, propagate the error
    }
    
    // Recursively check the height of the right subtree
    int rightHeight = checkHeight(root->right);
    if (rightHeight == -1) {
        return -1;  // If the right subtree is unbalanced, propagate the error
    }
    
    // If the current node is unbalanced (height difference > 1), return -1
    if (abs(leftHeight - rightHeight) > 1) {
        return -1;
    }
    
    // Return the height of the current node (1 + maximum of left and right heights)
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Main function to check if the tree is balanced
bool isBalanced(struct TreeNode* root) {
    return checkHeight(root) != -1;  // If the height check returns -1, the tree is unbalanced
}
