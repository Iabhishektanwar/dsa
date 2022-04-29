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
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void preOrder(struct node *r)
{
    if (r != NULL)
    {
        printf("%d ", r->data);
        preOrder(r->left);
        preOrder(r->right);
    }
}

void postOrder(struct node *r)
{
    if (r != NULL)
    {

        postOrder(r->left);
        postOrder(r->right);
        printf("%d ", r->data);
    }
}

void inOrder(struct node *r)
{
    if (r != NULL)
    {
        inOrder(r->left);
        printf("%d ", r->data);
        inOrder(r->right);
    }
}

int isBST(struct node *node)
{
    if (node == NULL)
        return 1;

    /* false if left is > than node */
    if (node->left != NULL && node->left->data > node->data)
        return 0;

    /* false if right is < than node */
    if (node->right != NULL && node->right->data < node->data)
        return 0;

    /* false if, recursively, the left or right is not a BST */
    if (!isBST(node->left) || !isBST(node->right))
        return 0;

    /* passing all that, it's a BST */
    return 1;
}

struct node *searchBST(struct node *root, int number)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == number)
    {
        return root;
    }
    else if (root->data > number)
    {
        return (searchBST(root->left, number));
    }
    else
    {
        return (searchBST(root->right, number));
    }
}

struct node *itersearch(struct node *root, int number)
{
    while (root != NULL)
    {
        if (root->data == number)
        {
            return root;
        }
        else if (root->data > number)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    return NULL;
}

int main()
{
    struct node *root = createNode(10);
    struct node *second = createNode(5);
    struct node *third = createNode(50);
    struct node *forth = createNode(3);
    struct node *fifth = createNode(8);
    struct node *sixth = createNode(25);
    struct node *seventh = createNode(70);

    root->left = second;
    root->right = third;
    second->left = forth;
    second->right = fifth;
    third->left = sixth;
    third->right = seventh;

    printf("Bnary tree created successfully :)\n");
    // printf("Pre Order Transversal :)\n");
    // preOrder(root);
    // printf("\nPost Order Transversal :)\n");
    // postOrder(root);
    printf("\nIn Order Transversal :)\n");
    inOrder(root);
    printf("%d\n", isBST(root));

    struct node *a = searchBST(root, 5);
    printf("%d\n", a->data);
    struct node *b = itersearch(root, 5);
    printf("%d\n", b->data);

    return 0;
}