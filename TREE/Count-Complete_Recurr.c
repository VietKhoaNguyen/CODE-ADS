#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Recursive function to count the number of nodes
int countNodes(struct TreeNode* root) {
    if (root == NULL) {
        return 0;  // Base case: If the node is NULL, return 0
    }
    
    // Count the current node (1) + count the nodes in the left subtree + count the nodes in the right subtree
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Example usage
int main() {
    // Create a binary tree: 
    //        1
    //       / \
    //      2   3
    //     / \
    //    4   5
    struct TreeNode* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    int nodeCount = countNodes(root);
    printf("Total number of nodes in the tree: %d\n", nodeCount);

    return 0;
}
