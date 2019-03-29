#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
#define maxSize 10000
typedef struct {
    ElementType data[maxSize];
    int front, rear;
    int length;
}queue;

void InitiQueue(queue * &q)
{
    q = (queue*)malloc(sizeof( queue));
    q->front = q->rear = 0;
    q->length = 0;
}

void DestroyQueue(queue*&q)
{
    free(q);
}

bool Queue_isEmpty(queue *&q)
{
    return q->rear == q->front;
}

bool enQueue(queue*&q, ElementType e)
{
    if (((q->rear + 1) % maxSize) == q->front)
        return false;
    else
    {
        q->rear = (q->rear + 1) % maxSize;
        q->data[q->rear] = e;
        q->length++;
        return true;
    }
}

bool deQueue(queue *&q, ElementType &e)
{
    if (q->front == q->rear)
        return false;
    else
    {
        q->front = (q->front + 1) % maxSize;
        e = q->data[q->front];
        return true;
    }
}