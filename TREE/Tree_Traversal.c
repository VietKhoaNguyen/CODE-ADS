#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* Init(int data)
{
    TreeNode* newTreeNode = (TreeNode*)malloc(sizeof(TreeNode));
    newTreeNode->data = data;
    newTreeNode->left = NULL;
    newTreeNode->right = NULL;
    return newTreeNode;
}

void InOrderTraversal(TreeNode* treeNode)
{
    if (treeNode == NULL)
    {
        return;
    }
    
    InOrderTraversal(treeNode->left);
    printf("%d ", treeNode->data);
    InOrderTraversal(treeNode->right);
}

void PostOrderTraversal(TreeNode* treeNode)
{
    if (treeNode == NULL)
    {
        return;
    }
    
    PostOrderTraversal(treeNode->left);
    PostOrderTraversal(treeNode->right);
    printf("%d ", treeNode->data);
}

void PreOrderTraversal(TreeNode* treeNode)
{
    if (treeNode == NULL)
    {
        return;
    }
    
    printf("%d ", treeNode->data);
    PreOrderTraversal(treeNode->left);
    PreOrderTraversal(treeNode->right);
}

TreeNode* Insert(TreeNode* node, int newData)
{
    if (node == NULL)
    {
        return Init(newData);
    }
    
    if (newData > node->data)
    {
        node->right = Insert(node->right, newData);
    }
    else if (newData < node->data)
    {
        node->left = Insert(node->left, newData);
    }
    
    return node;
}

TreeNode* MinValue(TreeNode* node)
{
    while (node->left != NULL)
    {
        node = node->left;
    }
    
    return node;
}

TreeNode* Delete(TreeNode* node, int deleteData)
{
    if (deleteData > node->data)
    {
        node->right = Delete(node->right, deleteData);
    }
    else if (deleteData < node->data)
    {
        node->left = Delete(node->left, deleteData);
    }
    else
    {
        if (node->left == NULL) 
        {
            TreeNode* temp = node->right;
            free(node);
            return temp;
        } 
        else if (node->right == NULL) 
        {
            TreeNode* temp = node->left;
            free(node);
            return temp;
        }

        TreeNode* temp = MinValue(node->right);
        node->data = temp->data;
        node->right = Delete(node->right, temp->data);
    }
    
    return node;
}

int main()
{
    TreeNode* root = Init(13);
    root->left = Init(7);
    root->right = Init(15);
    root->left->left = Init(3);
    root->left->right = Init(8);
    root->right->left = Init(14);
    root->right->right = Init(19);
    root->right->right->left = Init(18);

    InOrderTraversal(root);
    printf("\n"); 
    root = Insert(root, 21);
    root = Delete(root, 15);
    InOrderTraversal(root);
    printf("\n");

    return 0;
}
