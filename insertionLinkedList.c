#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void displayLinkedList(struct node *pointer)
{
    while (pointer != NULL)
    {
        printf("%d\n", pointer->data);
        pointer = pointer->next;
    }
}

struct node *firstElementInsertion(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;

    return head;
}

struct node *inbetweenInsertion(struct node *head, int data, int index)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = head;
    int i = 0;
    while (i < index - 1)
    {
        ptr = ptr->next;
        i++;
    }
    newNode->data = data;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

struct node *insertionAtEnd(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *pointer = head;
    while (pointer->next != NULL)
    {
        pointer = pointer->next;
    }
    newNode->data = data;
    pointer->next = newNode;
    newNode->next = NULL;
    return head;
}

struct node *insertionAfterNode(struct node *head, struct node *Node, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = Node->next;
    Node->next = newNode;
    return head;
}

struct node *firstElementDeletion(struct node *head)
{
    struct node *pointer = head;
    head = head->next;
    free(pointer);
    return head;
}

struct node *deletionInBetween(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = p->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

struct node *lastElementDeletion(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}

struct node *deletionAfterNode(struct node *head, int data)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != data && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == data)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{

    struct node *head;
    struct node *second;
    struct node *third;
    struct node *tail;

    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    third = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->data = 5;
    head->next = second;

    second->data = 10;
    second->next = third;

    third->data = 15;
    third->next = tail;

    tail->data = 20;
    tail->next = NULL;
    printf("List before insertion:\n");
    displayLinkedList(head);
    // printf("List after insertion:\n");
    // head = firstElementInsertion(head, 1);
    // head = inbetweenInsertion(head, 12, 2);
    // head = insertionAtEnd(head, 25);
    // head = insertionAfterNode(head, third, 17);
    printf("List after deletion:\n");
    // head = firstElementDeletion(head);
    // head = deletionInBetween(head, 2);
    // head = lastElementDeletion(head);
    head = deletionAfterNode(head, 15);

    displayLinkedList(head);

    return 0;
}