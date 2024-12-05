#include <stdbool.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to check if two binary trees are the same
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    // If both nodes are NULL, they are the same (both trees are empty)
    if (p == NULL && q == NULL) {
        return true;
    }
    
    // If one node is NULL and the other is not, they are not the same
    if (p == NULL || q == NULL) {
        return false;
    }
    
    // If both nodes are non-NULL, compare their values
    if (p->val != q->val) {
        return false;
    }
    
    // Recursively compare the left and right subtrees
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
