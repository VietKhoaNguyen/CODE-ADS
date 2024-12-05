#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct TreeNode
{
    int value;
    struct TreeNode *parent, *tLeft, *tRight;
} * Tree;

void randomArr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand() % 100;
}

void init(Tree *t, int height)
{
    *t = (Tree)malloc(sizeof(struct TreeNode));

    (*t)->value = 0;
    (*t)->parent = NULL;
    (*t)->tLeft = NULL;
    (*t)->tRight = NULL;
    if (height > 1)
    {
        init(&((*t)->tLeft), height - 1);
        (*t)->tLeft->parent = *t;
        init(&((*t)->tRight), height - 1);
        (*t)->tRight->parent = *t;
    }
}

int isLeaf(Tree t)
{
    return (t->tLeft == NULL && t->tRight == NULL);
}

void printIndentation(int depth)
{
    for (int i = 0; i < depth - 1; i++)
    {
        printf("|  ");
    }
}

void printTree(Tree t, int depth, int last)
{
    if (depth > 0)
    {
        printIndentation(depth);
        printf(last ? "\\- " : "|- ");
    }

    if (t->parent == NULL)
        printf("ROOT: ");
    else if (t->parent->tLeft == t)
        printf("L: ");
    else
        printf("R: ");

    printf("%d\n", t->value);

    if (t->tLeft != NULL)
        printTree(t->tLeft, depth + 1, t->tRight == NULL);
    if (t->tRight != NULL)
        printTree(t->tRight, depth + 1, 1);
}

int fillArray(int *arr, int arr_length, int target_length)
{
    int E = arr[0];
    for (int i = 1; i < arr_length; i++)
    {
        if (arr[i] > E)
            E = arr[i];
    }
    E++;
    while (arr_length < pow(2, target_length - 1))
    {
        arr[arr_length] = E;
        arr_length++;
    }
    return arr_length;
}

int FILL_LEAF_INDEX = 0;
void fillLeaf(Tree *t, int data[])
{
    if (*t == NULL)
        return;
    fillLeaf(&((*t)->tLeft), data);
    if (isLeaf(*t))
    {
        (*t)->value = data[FILL_LEAF_INDEX];
        FILL_LEAF_INDEX++;
    }
    fillLeaf(&((*t)->tRight), data);
}

void fillNode(Tree *t)
{
    if (*t == NULL)
        return;
    fillNode(&((*t)->tLeft));
    fillNode(&((*t)->tRight));
    if (!isLeaf(*t))
    {
        if ((*t)->tLeft->value < (*t)->tRight->value)
            (*t)->value = (*t)->tLeft->value;
        else
            (*t)->value = (*t)->tRight->value;
    }
}

int findNode(Tree t, int value)
{
    if (t == NULL)
        return -1;
    if (t->value == value)
    {
        printf("Found node with value %d\n", value);
        printTree(t, 0, 1);
        return 1;
    }
    int left = findNode(t->tLeft, value);
    int right = findNode(t->tRight, value);
    if (left == -1 && right == -1)
        return -1;
    return 1;
}

void insertNode(Tree *t, int value)
{
    if (*t == NULL)
    {
        *t = (Tree)malloc(sizeof(struct TreeNode));
        (*t)->value = value;
        (*t)->parent = NULL;
        (*t)->tLeft = NULL;
        (*t)->tRight = NULL;
        return;
    }
    if (value < (*t)->value)
    {
        if ((*t)->tLeft == NULL)
        {
            (*t)->tLeft = (Tree)malloc(sizeof(struct TreeNode));
            (*t)->tLeft->value = value;
            (*t)->tLeft->parent = *t;
            (*t)->tLeft->tLeft = NULL;
            (*t)->tLeft->tRight = NULL;
        }
        else
            insertNode(&((*t)->tLeft), value);
    }
    else
    {
        if ((*t)->tRight == NULL)
        {
            (*t)->tRight = (Tree)malloc(sizeof(struct TreeNode));
            (*t)->tRight->value = value;
            (*t)->tRight->parent = *t;
            (*t)->tRight->tLeft = NULL;
            (*t)->tRight->tRight = NULL;
        }
        else
            insertNode(&((*t)->tRight), value);
    }
}

void removeNode(Tree *t, int value)
{
    if (*t == NULL)
        return;
    if ((*t)->value == value)
    {
        if ((*t)->tLeft == NULL && (*t)->tRight == NULL)
        {
            if ((*t)->parent->tLeft == *t)
                (*t)->parent->tLeft = NULL;
            else
                (*t)->parent->tRight = NULL;
            free(*t);
            *t = NULL;
        }
        else if ((*t)->tLeft == NULL)
        {
            if ((*t)->parent->tLeft == *t)
                (*t)->parent->tLeft = (*t)->tRight;
            else
                (*t)->parent->tRight = (*t)->tRight;
            (*t)->tRight->parent = (*t)->parent;
            free(*t);
            *t = NULL;
        }
        else if ((*t)->tRight == NULL)
        {
            if ((*t)->parent->tLeft == *t)
                (*t)->parent->tLeft = (*t)->tLeft;
            else
                (*t)->parent->tRight = (*t)->tLeft;
            (*t)->tLeft->parent = (*t)->parent;
            free(*t);
            *t = NULL;
        }
        else
        {
            Tree temp = (*t)->tRight;
            while (temp->tLeft != NULL)
                temp = temp->tLeft;
            (*t)->value = temp->value;
            removeNode(&((*t)->tRight), temp->value);
        }
    }
    else if (value < (*t)->value)
        removeNode(&((*t)->tLeft), value);
    else
        removeNode(&((*t)->tRight), value);
}

int main()
{
    int arr[] = {8, 20, 41, 7, 2, 5, 2, 6, 8, 92, 2};
    int arr_length = sizeof(arr) / sizeof(arr[0]);
    int height = ceil(log2(arr_length)) + 1;
    printf("%d\n", height);
    arr_length = fillArray(arr, arr_length, height);
    Tree main_tree;
    init(&main_tree, height);
    fillLeaf(&main_tree, arr);
    fillNode(&main_tree);
    printTree(main_tree, 0, 1);

    printf("Enter a number to search: ");
    int search_value;
    scanf("%d", &search_value);

    if (findNode(main_tree, search_value) == -1)
    {
        printf("Not found\n");
    }

    printf("Enter a number to insert: ");
    int insert_value;
    scanf("%d", &insert_value);
    insertNode(&main_tree, insert_value);
    printTree(main_tree, 0, 1);

    printf("Enter a number to remove: ");
    int remove_value;
    scanf("%d", &remove_value);
    removeNode(&main_tree, remove_value);
    printTree(main_tree, 0, 1);

    return 0;
}
