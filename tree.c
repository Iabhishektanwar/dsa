#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrderTransversal(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrderTransversal(root->left);
        preOrderTransversal(root->right);
    }
}

void postOrderTransversal(struct node *root)
{
    if (root != NULL)
    {
        postOrderTransversal(root->left);
        postOrderTransversal(root->right);
        printf("%d ", root->data);
    }
}

void inOrderTransversal(struct node *root)
{
    if (root != NULL)
    {
        inOrderTransversal(root->left);
        printf("%d ", root->data);
        inOrderTransversal(root->right);
    }
}

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node *searchBST(struct node *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return searchBST(root->left, key);
    }
    else
    {
        return searchBST(root->right, key);
    }
}

int main()
{

    struct node *root = createNode(5);
    struct node *second = createNode(3);
    struct node *third = createNode(6);
    struct node *forth = createNode(1);
    struct node *fifth = createNode(4);

    root->left = second;
    root->right = third;
    second->left = forth;
    second->right = fifth;
    printf("Tree successfully created :)\n");
    // printf("Pre-order transversal\n");
    // preOrderTransversal(root);
    // printf("\nPost-order transversal\n");
    // postOrderTransversal(root);
    printf("\nIn-order transversal\n");
    inOrderTransversal(root);
    if (isBST(root))
    {
        printf("BST\n");
    }
    else
    {
        printf("Not BST\n");
    }

    struct node *r = searchBST(root, 1);
    if (r == NULL)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found\n");
    }

    return 0;
}