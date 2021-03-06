#include"stdafx.h"
#include<stdio.h>
#include<stdlib.h>

typedef char ElementType;

typedef struct LinkNode
{
	ElementType data;
	LinkNode* next;
}Stack;

Stack* CreateStack()
{
	Stack * preHead = (Stack*)malloc(sizeof(Stack));
	preHead->next = NULL;
	return preHead;
}
void push(Stack *&stk,ElementType e)
{
	LinkNode* preHead = stk;
	LinkNode* nextNode = preHead->next;
	LinkNode * newNode = (LinkNode*)malloc(sizeof(LinkNode));
	newNode->data = e;
	newNode->next =nextNode;
	preHead->next = newNode;
}


ElementType& top(Stack*&stk)
{
	LinkNode* preHead = stk;
	if (!preHead->next)
	{
		printf("stack is empty!");
		exit(0);
	}
	else
	{
		return preHead->next->data;
	}
}

void pop(Stack*& stk)
{
	LinkNode* preHead = stk;
	if (!preHead->next)
	{
		printf("stack is empty!");
		exit(0);
	}
	else
	{
		LinkNode* firstNode = preHead->next;
		LinkNode* newNext = firstNode->next;
		preHead->next = newNext;
		free(firstNode);
	}
}

bool isEmpty(Stack* stk)
{
	LinkNode* preHead = stk;
	return stk->next == NULL;
}
void show(Stack* stk)
{
	LinkNode* p = stk->next;
	while (p)
	{
		printf("%c", p->data);
		p = p->next;
	}
}


void postExp(Stack * stk,char* s)
{
	char ch;
	for (int i = 0; s[i] != '#'; i++)
	{
		ch = s[i];
		switch (ch)
		{
		case'(':push(stk, ch); break;
		case')':
			while (!isEmpty(stk) &&  top(stk)!='(')
			{
				printf("%c", top(stk));
				pop(stk);
			}
			pop(stk);//把左括号弹出来
			break;
		case'+':
		case'-':
			while (!isEmpty(stk) )
			{
				if (top(stk) == '(')
					break;
				else
				{
					printf("%c", top(stk));
					pop(stk);
				}
			}
			push(stk,ch);
			break;
		case'*':
		case'/':
			while (!isEmpty(stk))
			{
				char t = top(stk);
				if (t == '*' || t == '/')
				{
					printf("%c", t);
					pop(stk);
				}
				else
					break;
			}
			push(stk, ch);
			break;
		default:
			printf("%c", ch);
			break;
		}
	}
	while (!isEmpty(stk))
	{
		printf("%c", top(stk));
		pop(stk);
	}
}
int main() {

	char s[30];
	scanf_s("%s", s,30);
	Stack * stk = CreateStack();
	postExp(stk, s);
	
	return 0;
}

//a+(b-c)#  a+b*c+(d*e+f)*g#