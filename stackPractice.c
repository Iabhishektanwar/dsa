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

void push(struct stack *p, int data)
{
    if (isFull(p))
    {
        printf("Stack full, cannot push :(\n");
    }
    else
    {
        p->top += 1;
        p->arr[p->top] = data;
        printf("Successfully pushed :)\n");
    }
}

void pop(struct stack *p)
{
    if (isEmpty(p))
    {
        printf("Already empty, cannot pop :(\n");
    }
    else
    {
        p->top -= 1;
        printf("Successfully poped :)\n");
    }
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 2;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    printf("Stack successfully created :D\n");

    push(s, 6);
    push(s, 6);
    push(s, 6);
    pop(s);
    pop(s);
    pop(s);

    return 0;
}