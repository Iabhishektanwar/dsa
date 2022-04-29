#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
};

void doublyLinkedListTransversal(struct node *head, struct node *tail)
{
    struct node *pointer = head;
    struct node *pointer_ = tail;
    while (pointer != NULL)
    {
        printf("%d\n", pointer->data);
        pointer = pointer->next;
    }
    while (pointer_ != NULL)
    {
        printf("%d\n", pointer_->data);
        pointer_ = pointer_->previous;
    }
    
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
    one->previous = NULL;
    one->next = two;

    two->data = 15;
    two->previous = one;
    two->next = three;

    three->data = 25;
    three->previous = two;
    three->next = four;

    four->data = 35;
    four->previous = three;
    four->next = NULL;
    doublyLinkedListTransversal(one, four);

    return 0;
}