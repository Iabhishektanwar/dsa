#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};

void displayCircularLinkedList(struct node *head)
{
    struct node *pointer = head;
    do
    {
        printf("%d\n", pointer->data);
        pointer = pointer->next;
    } while (pointer!=head);
}

struct node *elementInsertion(struct node *head, int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    do
    {
        p = p->next;
    } while (p->next!=head);
    p->next = newNode;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    return head;
    
}

int main()
{
    struct node *one;
    struct node *two;
    struct node *three;
    struct node *four;

    one = (struct node *)malloc(sizeof(struct node));
    two = (struct node *)malloc(sizeof(struct node));
    three = (struct node *)malloc(sizeof(struct node));
    four = (struct node *)malloc(sizeof(struct node));

    one->data = 5;
    one->next = two;

    two->data = 10;
    two->next = three;

    three->data = 15;
    three->next = four;

    four->data = 20;
    four->next = one;
    printf("List before insertion\n");
    displayCircularLinkedList(one);
    printf("List after insertion\n");
    one = elementInsertion(one, 100);
    displayCircularLinkedList(one);

    return 0;
}