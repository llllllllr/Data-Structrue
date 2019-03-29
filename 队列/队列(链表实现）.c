#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

typedef struct queueNode
{
	ElementType data;
	queueNode* next;
};

typedef struct queue
{
	queueNode * front, *rear;
};

void InitQueue(queue *&q)
{
	q = (queue*)malloc(sizeof(struct queue));
	q->front = q->rear = NULL;
}

void DestroyQueue(queue *&q)
{
	queueNode* pre = q->front,*temp;
	if (pre)
	{
		temp = pre->next;
		while (temp)
		{
			free(pre);
			pre = temp;
			temp = temp->next;
		}
		free(pre);
	}
	free(q);
}
bool Queue_isEmpty(queue * &q)
{
	return q->rear == NULL;
}

void enQueue(queue* &q, ElementType e)
{
	queueNode* new_rear = (queueNode*)malloc(sizeof(struct queueNode));
	new_rear->data = e;
	new_rear->next = NULL;
	if (q->rear == NULL)//别忘了
		q->rear = q->front = new_rear;
	else
	{
		q->rear->next = new_rear;
		q->rear = new_rear;
	}
}

bool deQueue(queue*&q, ElementType &e)
{
	if (q->rear == NULL)//如果队列是空的
		return false;
	queueNode* temp = q->front;
	if (q->rear == q->front)//如果队列只有一个数据
		q->rear = q->front = NULL;
	else
		q->front= q->front->next;
	e = temp->data;
	free(temp);
	return true;
	
}
int main()
{
	queue*q;
	int e;
	InitQueue(q);
	enQueue(q, 2);
	enQueue(q, 5);
	enQueue(q, 6);
	while (!Queue_isEmpty(q))
	{
		deQueue(q, e);
		printf("%d", e);
	}
	return 0;
}
