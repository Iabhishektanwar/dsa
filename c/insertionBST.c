#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int value)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preOrder(struct node *node)
{
    if (node != NULL)
    {
        printf("%d ", node->data);
        preOrder(node->left);
        preOrder(node->right);
    }
}
void postOrder(struct node *node)
{
    if (node != NULL)
    {
        postOrder(node->left);
        postOrder(node->right);
        printf("%d ", node->data);
    }
}
void inOrder(struct node *node)
{
    if (node != NULL)
    {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}
int isBST(struct node *node)
{
    if (node == NULL)
    {
        return 1;
    }
    if (node->left != NULL && node->left->data > node->data)
    {
        return 0;
    }
    if (node->right != NULL && node->right->data < node->data)
    {
        return 0;
    }
    if (!isBST(node->left) || !isBST(node->right))
    {
        return 0;
    }
    return 1;
}
struct node *BSTsearch(struct node *node, int key)
{
    if (node == NULL)
    {
        return NULL;
    }
    if (node->data == key)
    {
        return node;
    }
    else if (key < node->data)
    {
        return (BSTsearch(node->left, key));
    }
    else
    {
        return (BSTsearch(node->right, key));
    }
}
/*
struct node *iterSearch(struct node *node, int key)
{
    while (node != NULL)
    {
        if (node->data == key)
        {
            return node;
        }
        else if (node->data < key)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
}
*/
/*
void insertioninBST(struct node *node, int value)
{
    struct node *pointer = NULL;
    while (node != NULL)
    {
        pointer = node;
        if (value == node->data)
        {
            printf ("Cannot insert %d, already in BST", value);
            return;
        }
        else if (value < node->data)
        {
            node = node->left;
        }
        else
        {
            node = node->right;
        }
    }
    struct node *newnode = createNode(value);
    if (value < pointer->data)
    {
        pointer->left = newnode;
    }
    else
    {
        pointer->right = newnode;
    }
}
*/

void insertBST(struct node *node, int value)
{
    struct node *checkValue = BSTsearch(node, value);
    if (checkValue == NULL)
    {
        struct node *pointer = NULL;
        while (node != NULL)
        {
            pointer = node;
            if (value < node->data)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }

        struct node *newNode = createNode(value);
        if (value < pointer->data)
        {
            pointer->left = newNode;
        }
        else
        {
            pointer->right = newNode;
        }
    }
    else
    {
        printf("Number already present in Binary search tree. Cannot enter.");
    }
}

int main()
{
    struct node *a = createNode(5);
    struct node *b = createNode(3);
    struct node *c = createNode(16);
    struct node *d = createNode(1);
    // struct node *e = createNode();
    struct node *f = createNode(11);
    // struct node *g = createNode();

    a->left = b;
    a->right = c;
    b->left = d;
    // b->right = e;
    c->left = f;
    // c->right = g;
    printf("Tree created successfully :)\n");
    /*
    printf("\nPreOrder Transversal\n");
    preOrder(a);
    printf("\nPostOrder Transversal\n");
    postOrder(a);
    */
    printf("\nInOrder Transversal\n");
    inOrder(a);
    printf("\nIs Binary Search Tree? \n");
    /*int ab = isBST(a);
    if (ab == 1)
    {
        printf("Binary Tree\n");
    }
    else
    {
        printf("Not a binary tree\n");
    }
    struct node *obj = BSTsearch(a, 70);
    if (obj != NULL)
    {
        printf("Element found\n");
    }
    else
    {
        printf("Element not found\n");
    }
    */
    insertBST(a, 67);
    inOrder(a);
    insertBST(a, 3);
    inOrder(a);

    return 0;
}