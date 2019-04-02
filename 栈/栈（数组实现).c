#include <stdio.h>
#include <stdlib.h>
#define ElementType  char
#define max_size 100
typedef struct
{
	ElementType data[max_size];
	int top;
}stack;

void InitStack(stack *& stk)
{
	stk = (stack *)malloc(sizeof(stack));
	stk->top = -1;
}

void DestroyStack(stack *& stk)
{
	free(stk);
}

bool IsEmpty(stack *& stk)
{
	return stk->top == -1;
}

bool push(stack *& stk, ElementType e)
{
	if (stk->top == max_size - 1)
		return false;
	else
	{
		stk->top++;
		stk->data[stk->top] = e;
		return true;
	}
}

bool pop(stack *& stk,ElementType & e)
{
	if (stk->top == -1)
		return false;
	else
	{
		e = stk->data[stk->top];
		stk->top--;
		return true;
	}
}

bool symStr(char str[])
{
	stack *stk;
	InitStack(stk);
	for (int i = 0; str[i] != '\0'; i++)
		push(stk, str[i]);
	for (int i = 0; str[i] != '\0'; i++)
	{
		char top;
		pop(stk, top);
		if (top != str[i])
			return false;
	}
	return true;
}
int main()
{
	char str[7] = "abccba";
	bool res = symStr(str);
	if (res)
		printf("字符串对称\n");
	else
		printf("字符串不对称\n");
	return 0;
}