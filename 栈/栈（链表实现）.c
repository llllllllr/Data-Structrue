#include <stdio.h>
#include <stdlib.h>
#define ElementType  char
#define max_size 100
typedef struct stackNode
{
	ElementType data;
	stackNode* next;
}stack;

//初始化栈
void InitStack(stack *& stk)
{
	stk = (stack *)malloc(sizeof(stack));
	stk->next = NULL;
}

//销毁栈
void DestroyStack(stack *& stk)
{
	stackNode * pre = stk->next, *p = pre->next;
	while (p)
	{
		free(pre);
		pre = p;
		p = p->next;
	}
	free(pre);
}


//判断栈是否为空
bool IsEmpty(stack *& stk)
{
	return stk->next == NULL;
}

//入栈

bool push(stack *& stk, ElementType e)
{
	stackNode* p = (stackNode*)malloc(sizeof(stackNode));
	p->data = e;
	p->next = stk->next;
	stk->next = p;
	return true;
}

//出栈并取得栈顶元素（e
bool pop(stack *& stk, ElementType &e)
{
	if (stk->next == NULL)
		return false;
	else
	{
		stackNode * p = stk->next;
		stk->next = p->next;
		e = p->data;
		free(p);
		return true;
	}
} 

//获取栈顶元素

bool top(stack *& stk, ElementType &e)
{
	if (stk->next == NULL)
		return false;
	else
	{
		e = stk->next->data;
		return true;
	}
}

bool Match(char exp[], int n)
{
	bool match = true;
	stack *stk;
	ElementType e;
	int i = 0;
	InitStack(stk);
	while (i < n && match)
	{
		if (exp[i] == '(')
			push(stk, exp[i]);
		else
		{
			if (top(stk, e))
				pop(stk, e);
		}
		i++;
	}
	if (!IsEmpty(stk))
		match = false;
	return match;
}
int main()
{
	char str[7] = "(()";
	bool res = Match(str,3);
	if (res)
		printf("括号对称\n");
	else
		printf("括号不对称\n");
	return 0;
}