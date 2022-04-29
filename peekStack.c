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

int peek(struct stack *p, int i)
{
    int a = p->top - i + 1;
    if (a < 0)
    {
        return -1;
    }
    else
    {
        printf("%d\n", p->arr[a]);
        return p->arr[a];
    }
}

void stackTop(struct stack *p)
{
    printf("%d\n", p->arr[p->top]);
}

void stackBotton(struct stack *p)
{
    printf("%d\n", p->arr[0]);
}

int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));

    s->size = 4;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    printf("Stack successfully created :D\n");

    push(s, 6);
    push(s, 16);
    push(s, 26);
    push(s, 77);
    // pop(s);
    // pop(s);
    // peek(s, 1);
    stackBotton(s);
    stackTop(s);

    return 0;
}