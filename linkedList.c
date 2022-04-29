#include <stdio.h>
#include <stdlib.h>

struct linkedList
{
    int data;
    struct linkedList *next;
};

void transversal(struct linkedList *ptr)
{
    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

struct linkedList *insertionAtBeginning(struct linkedList *head, int dataTobeInserted)
{
    struct linkedList *p = (struct linkedList *)malloc(sizeof(struct linkedList));
    p->data = dataTobeInserted;
    p->next = head;
    return p;
}

struct linkedList *insertionInBetween(struct linkedList *head, int dataToBeInserted, int index)
{
    struct linkedList *ptr = (struct linkedList *)malloc(sizeof(struct linkedList));
    struct linkedList *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    p->data = dataToBeInserted;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

struct linkedList *insertionAtEnd(struct linkedList *head, int data)
{
    struct linkedList *ptr = (struct linkedList *)malloc(sizeof(struct linkedList));
    struct linkedList *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

struct linkedList *insertAfterANode(struct linkedList *head, struct linkedList *prevnode, int data)
{
    struct linkedList *ptr = (struct linkedList *)malloc(sizeof(struct linkedList));
    ptr->data = data;
    ptr->next = prevnode->next;
    prevnode->next = ptr;
    return head;
}

int main()
{
    struct linkedList *one;
    struct linkedList *two;
    struct linkedList *three;
    struct linkedList *four;

    one = (struct linkedList *)malloc(sizeof(struct linkedList));
    two = (struct linkedList *)malloc(sizeof(struct linkedList));
    three = (struct linkedList *)malloc(sizeof(struct linkedList));
    four = (struct linkedList *)malloc(sizeof(struct linkedList));

    one->data = 1;
    two->data = 2;
    three->data = 3;
    four->data = 4;
    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    transversal(one);
    // one = insertionAtBeginning(one, 10);
    // transversal(one);

    one = insertAfterANode(one, three, 66);
    transversal(one);

    return 0;
}