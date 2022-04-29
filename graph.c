#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int r;
    int f;
    int *arr;
};

void displayQueue(struct queue *q)
{
    int pointer = q->r + 1;
    while (pointer != q->size)
    {
        printf("%d ",q->arr[pointer]);
        pointer = pointer + 1;
    }
}

int isEmpty(struct queue *q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct queue *q)
{
    if (q->f == q->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct queue *q, int data)
{
    if (isFull(q))
    {
        printf("Queue already full, cannot enqueue\n");
    }
    else
    {
        q->f = q->f + 1;
        q->arr[q->f] = data;
        printf("Successfully enqueued\n");
    }
}

void dequeue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue already empty, cannot dequeue\n");
    }
    else
    {
        q->r = q->r + 1;
        printf("Successfully dequeued\n");
    }
}

int main()
{
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 10;
    q->r = q->f = -1;
    q->arr = (int *)malloc(sizeof(int) * q->size);


    return 0;
}