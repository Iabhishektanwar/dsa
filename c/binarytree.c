#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int dataValue)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = dataValue;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void preOrderTransversal(struct node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preOrderTransversal(r->left);
        preOrderTransversal(r->right);
    }
}
void postOrderTransversal(struct node *r)
{
    if (r != NULL)
    {
        postOrderTransversal(r->left);
        postOrderTransversal(r->right);
        printf("%d ", r->data);
    }
}
void inOrderTransversal(struct node *r)
{
    if (r != NULL)
    {
        inOrderTransversal(r->left);
        printf("%d ", r->data);
        inOrderTransversal(r->right);
    }
}
int isBST(struct node *r)
{
    if (r == NULL)
    {
        return 1;
    }
    if (r->left != NULL && r->left->data > r->data)
    {
        return 0;
    }
    if (r->right != NULL && r->right->data < r->data)
    {
        return 0;
    }
    if (!isBST(r->left) || !isBST(r->right))
    {
        return 0;
    }
    return 1;
}
struct node *BSTsearch(struct node *r, int valueToBeSearched)
{
    if (r == NULL)
    {
        return NULL;
    }
    if (r->data == valueToBeSearched)
    {
        return r;
    }
    else if (valueToBeSearched < r->data)
    {
        return (BSTsearch(r->left, valueToBeSearched));
    }
    else
    {
        return (BSTsearch(r->right, valueToBeSearched));
    }
}
void insertionBST(struct node *r, int data)
{
    struct node *pointer = NULL;
    while (r != NULL)
    {
        pointer = r;
        if (data == r->data)
        {
            printf("Cannot enter %d, already present", data);
            return;
        }
        else if (data < r->data)
        {
            r = r->left;
        }
        else
        {
            r = r->right;
        }
    }
    struct node *newNode = createNode(data);
    if (data < pointer->data)
    {
        pointer->left = newNode;
    }
    else
    {
        pointer->right = newNode;
    }
}
struct node *iPre(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *inOrderPredecessor;
    if (root == NULL)
    {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL)
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        inOrderPredecessor = iPre(root);
        root->data = inOrderPredecessor->data;
        root->left = deleteNode(root->left, inOrderPredecessor->data);
    }
    return root;
}

int main()
{
    struct node *root = createNode(50);
    struct node *second = createNode(40);
    struct node *third = createNode(60);
    // struct node *forth = createNode(20);
    // struct node *fifth = createNode(45);
    // struct node *sixth = createNode(59);
    // struct node *seventh = createNode(65);
    // struct node *eighth = createNode(44);
    // struct node *ninth = createNode(49);
    // struct node *tenth = createNode(64);

    root->left = second;
    root->right = third;
    // second->left = forth;
    // second->right = fifth;
    // third->left = sixth;
    // third->right = seventh;
    // fifth->left = eighth;
    // fifth->right = ninth;
    // seventh->left = tenth;

    // printf("\nPre Order Transversal \n");
    // preOrderTransversal(root);
    // printf("\nPost Order Transversal \n");
    // postOrderTransversal(root);
    printf("\nIn Order Transversal \n");
    inOrderTransversal(root);

    // if (isBST(root))
    // {
    //     printf("\nBinary Search Tree !!!\n");
    // }
    // else
    // {
    //     printf("\nNot a Binary Search Tree !!!\n");
    // }

    // BSTsearch(root, 45);
    insertionBST(root, 20);
    inOrderTransversal(root);
    insertionBST(root, 45);
    inOrderTransversal(root);

    deleteNode(root, 40);
    inOrderTransversal(root);

    return 0;
}