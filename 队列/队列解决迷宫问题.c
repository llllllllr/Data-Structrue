#include <stdio.h>
#include <stdlib.h>
#define   maxSize 1000
typedef struct
{
	int x, y;
	int pre;
}Box;

typedef struct BoxQueue
{
	Box data[maxSize];
	int front, rear;
	int length;
};

void InitiBoxQueue(BoxQueue*&q)
{
	q = (BoxQueue*)malloc(sizeof(struct BoxQueue));
	q->front = q->rear = 0;
	q->length = 0;
}

void DestroyQueue(BoxQueue *&q)
{
	free(q);
}
void enQueue(BoxQueue *&q, Box e)
{
	if ((q->rear + 1) % maxSize == q->front)
	{
		printf("%s", "队列已满，无法进队");
		return;
	}
	else
	{
		q->rear = (q->rear + 1) % maxSize;
		q->data[q->rear] = e;
		q->length += 1;
	}
}

bool  deQueue(BoxQueue *&q, Box &e)
{
	if (q->rear == q->front)
	{
		printf("%s", "队列是空的！");
		return false;
	 }
	q->front = (q->front + 1) % maxSize;
	e = q->data[q->front];
	
	return true;
}

bool isEmpety(BoxQueue *&q)
{
	return q->front == q->rear;
}

void disp_path(BoxQueue *q, int front)
{
	int k = front, ns = 0;
	int j;
	do
	{
		j = k;
		k = q->data[j].pre;
		q->data[j].pre = -1;
	} while (k != 1);
		printf("迷宫最短路径如下:\n");
		k = 0;
		while (k < q->length)
		{
			if (q->data[k].pre == -1)
			{
				ns++;
				printf("\t(%d,%d)", q->data[k].x, q->data[k].y);
				if (ns % 5 == 0) printf("\n");
			}
			k++;
		}
		printf("\n");
}
bool mgPath(int beginx, int  beginy, int endx, int endy,int mg[10][10])
{
	Box e;
	int x, y, direc, tempx, tempy;
	BoxQueue *q;
	InitiBoxQueue(q);
	e.x = beginx, e.y = beginy, e.pre = -1;
	enQueue(q, e);
	mg[beginx][beginy] = -1;
	while(!isEmpety(q))
	 {
		 deQueue(q, e);
		x = e.x, y = e.y;
		if (x == endx && y == endy)
		{
			disp_path(q, q->front);
			DestroyQueue(q);
			return true;
		}
		for (direc = 0; direc < 4; direc++)
		{
			switch (direc)
			{
			case 0: tempx = x , tempy = y-1; break;
			case 1: tempx = x+1, tempy = y ; break;
			case 2:tempx = x , tempy = y+1; break;
			case 3:tempx = x-1, tempy = y; break;
			}
			if (mg[tempx][tempy] == 0)
			{
				/*printf("%d   %d", tempx, tempy);*/
				e.x = tempx;
				e.y = tempy;
				e.pre = q->front;
				enQueue(q, e);
				mg[tempx][tempy] = -1;
			}
		}
	}
	
	DestroyQueue(q);
	return false;
}
int main()
{
	int mg[10][10] = {
	{ 1,1,1,1,1,1,1,1,1,1 },{ 1,0,0,1,0,0,0,1,0,1 },
	{ 1,0,0,1,0,0,0,1,0,1 },{ 1,0,0,0,0,1,1,0,0,1 },
	{ 1,0,1,1,1,0,0,0,0,1 },{ 1,0,0,0,1,0,0,0,0,1 },
	{ 1,0,1,0,0,0,1,0,0,1 },{ 1,0,1,1,1,0,1,1,0,1 },
	{ 1,1,0,0,0,0,0,0,0,1 },{ 1,1,1,1,1,1,1,1,1,1 }
	};
	mgPath(1, 1, 8, 8,mg);
	return 0;
}