#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;
} TreeNode;

TreeNode* CreateNode(int data) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

void PreOrderTraversal(TreeNode* node)
{
    printf("%d ", node->data);
    PreOrderTraversal(node);
    PreOrderTraversal(node);
}

void InOrderTraversal(TreeNode* node)
{
    InOrderTraversal(node);
    printf("%d ", node->data);
    InOrderTraversal(node);
}

void PostOrderTraversal(TreeNode* node)
{
    PostOrderTraversal(node);
    PostOrderTraversal(node);
    printf("%d ", node->data);
}

TreeNode* Insert(TreeNode* node, int newValue)
{
    if (node == NULL)
    {
        return Init(newValue);
    }
    else
    {
        if (newValue > node->data)
        {
            node->right = Insert(node->right, newValue);
        }
        else if (newValue < node->data)
        {
            node->left = Insert(node->left, newValue);
        }
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

TreeNode* Delete(TreeNode* node, int deleteValue)
{
    if (node == NULL)
    {
        return NULL;
    }
    else
    {
        if (deleteValue > node->data)
        {
            node->right = Delete(node->right, deleteValue);
        }
        else if (deleteValue < node->data)
        {
            node->left = Delete(node->left, deleteValue);
        }
        else
        {
            if (node->right == NULL)
            {
                TreeNode* temp = node->left;
                free(node);
                return temp;
            }
            else if (node->left == NULL)
            {
                TreeNode* temp = node->right;
                free(node);
                return temp;
            }

            TreeNode* temp = MinValue(node->right);
            node->data = temp->data;
            node->right = Delete(node->right, temp->data);
        }
    }

    return node;
}

int main()
{

}
