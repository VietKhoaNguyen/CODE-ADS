#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Define NULL explicitly
#ifndef NULL
#define NULL ((void*)0)
#endif

// Definition for a binary tree node.
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Helper function to create a new tree node
struct TreeNode* createNode(int val) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Helper function to compare two trees
bool isSameTree(struct TreeNode* s, struct TreeNode* t) {
    if (s == NULL && t == NULL) {
        return true;
    }
    if (s == NULL || t == NULL) {
        return false;
    }
    return (s->val == t->val) &&
           isSameTree(s->left, t->left) &&
           isSameTree(s->right, t->right);
}

// Main function to check if subRoot is a subtree of root
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot) {
    if (root == NULL) {
        return subRoot == NULL;
    }
    if (isSameTree(root, subRoot)) {
        return true;
    }
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}

// Helper function to free a tree
void freeTree(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

// Example usage
int main() {
    // Constructing the root tree
    struct TreeNode* root = createNode(3);
    root->left = createNode(4);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(2);

    // Constructing the subRoot tree
    struct TreeNode* subRoot = createNode(4);
    subRoot->left = createNode(1);
    subRoot->right = createNode(2);

    // Check if subRoot is a subtree of root
    if (isSubtree(root, subRoot)) {
        printf("subRoot is a subtree of root.\n");
    } else {
        printf("subRoot is NOT a subtree of root.\n");
    }

    // Free allocated memory
    freeTree(root);
    freeTree(subRoot);

    return 0;
}
