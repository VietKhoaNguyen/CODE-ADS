#include <stdio.h>
#include <stdlib.h>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to invert a binary tree
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;  // Base case: If the node is NULL, return NULL
    }
    
    // Swap the left and right children
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    // Recursively invert the left and right subtrees
    invertTree(root->left);
    invertTree(root->right);
    
    return root;  // Return the root of the inverted tree
}

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to print the tree (Pre-order traversal)
void printTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

// Example usage
int main() {
    // Create a binary tree:
    //        4
    //       / \
    //      2   7
    //     / \ / \
    //    1  3 6  9
    struct TreeNode* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    root->right->left = createNode(6);
    root->right->right = createNode(9);

    printf("Original Tree: ");
    printTree(root);
    printf("\n");

    // Invert the binary tree
    root = invertTree(root);

    printf("Inverted Tree: ");
    printTree(root);
    printf("\n");

    return 0;
}
