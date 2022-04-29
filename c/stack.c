#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *arr;
};

int isEmpty(struct stack *p)
{
    if (p->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *p)
{
    if (p->top == p->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *p, int value)
{
    if (isFull(p))
    {
        printf("Stack akready full, cannot push\n");
    }
    else
    {
        p->top++;
        p->arr[p->top] = value;
        printf("Successfully added\n");
    }
}

int pop(struct stack *p)
{
    if (isEmpty(p))
    {
        printf("Stack already empty, cannot pop\n");
        return -1;
    }
    else
    {
        int val = p->arr[p->top];
        p->top--;
        printf("Removed\n");
        return val;
    }
}

int main()
{
    struct stack *s;
    s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 2;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));

    // int a = isEmpty(s);
    // printf("%d\n", a);
    // int b = isFull(s);
    // printf("%d\n", b);
    push(s, 7);
    // printf("%d\n",s->top);
    push(s, 6);
    push(s, 6);
    push(s, 5);
    pop(s);
    pop(s);
    pop(s);
    // printf("%d\n", isEmpty(s));

    return 0;
}