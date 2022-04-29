#include <stdio.h>
#include <stdlib.h>
#define N 6
struct edge
{
    int source, destination;
};
struct node
{
    int destination;
    struct node *next;
};
struct edge *createEdge(struct edge *e[], int noOfEdges)
{
    for (int i = 0; i < noOfEdges; i++)
    {
        struct edge *newEdge = (struct edge *)malloc(sizeof(struct edge));
        newEdge->source = e[i]->source;
        newEdge->destination = e[i]->destination;
        return newEdge;
    }
}
int main()
{
    struct edge *edges[] = {{0, 1}, {1, 2}, {2, 1}, {2, 0}, {3, 2}, {4, 5}, {5, 4}};
    int n = sizeof(edges) / sizeof(struct edge);

    return 0;
}