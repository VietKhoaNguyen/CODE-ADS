#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to check if two trees are mirrors of each other
bool isMirror(struct TreeNode* t1, struct TreeNode* t2) {
    // If both nodes are NULL, they are mirrors of each other
    if (t1 == NULL && t2 == NULL) {
        return true;
    }
    
    // If one node is NULL and the other is not, they are not mirrors
    if (t1 == NULL || t2 == NULL) {
        return false;
    }
    
    // Check if the values of the current nodes are equal
    // and recursively check the left subtree with the right subtree and vice versa
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

// Main function to check if the tree is symmetric
bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) {
        return true;  // An empty tree is symmetric
    }
    
    // Check if the left and right subtrees of the root are mirrors of each other
    return isMirror(root->left, root->right);
}
