#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void displayElements(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *ptr)
{
    if (ptr->next == NULL)
    {
        return 1;
    }
    return 0;
}

int isFull(struct Node *ptr)
{
    struct Node *x = (struct Node *)malloc(sizeof(struct Node));
    if (x == NULL)
    {
        return 1;
    }
    return 0;
}

struct Node *push(struct Node *ptr, int data)
{
    if (isFull(ptr))
    {
        printf("Stack already full\n");
    }
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = ptr;
    ptr = newNode;
    // printf("Successfully added\n");
    return ptr;
}

struct Node *pop(struct Node *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Empty\n");
    }
    struct Node *p = ptr;
    ptr = ptr->next;
    free(p);
    printf("Successfully popped\n");
    return ptr;
}

int main()
{
    struct Node *head = NULL;
    head = push(head, 6);
    head = push(head, 16);
    head = push(head, 26);
    head = push(head, 36);

    displayElements(head);
    head = pop(head);
    displayElements(head);
    return 0;
}