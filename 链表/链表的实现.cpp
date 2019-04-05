#include<iostream>
using namespace std;
#define  ElementType int
//链表的结点
typedef struct ListNode
{
	ElementType data;
	ListNode* next;
};

//建表-->头插法
ListNode* CreateListH(int n)
{
	
	ListNode* preHead = (ListNode*)malloc(sizeof(ListNode));
	preHead->next = NULL;
	ListNode * ph = preHead;
	for (int i = 0; i < n; i++)
	{
		ListNode * s = (ListNode*)malloc(sizeof(ListNode));
		cin >> s->data;
		s->next = ph->next;
		ph->next = s;
	}
	return preHead;
}
//建表-->尾插法
ListNode* CreateListT(int n)
{
	ListNode* preHead = (ListNode*)malloc(sizeof(ListNode));
	preHead->next = NULL;
	ListNode* ph = preHead;
	for (int i = 0; i < n; i++)
	{
		ListNode* s = (ListNode*)malloc(sizeof(ListNode));
		cin >> s->data;
		s->next = NULL;
		ph->next = s;
		ph = s;
	}
	return preHead;
}

//销毁链表
void DestroyList(ListNode* preHead)
{
	while (preHead)
	{
		ListNode*temp = preHead;
		preHead = preHead->next;
		free(temp);
	}
}

//按元素值查找
int search(ElementType e, ListNode* preHead)
{
	int index = 1;
	ListNode* p = preHead->next;
	while (p  && p->data != e)
	{
		p = p->next;
		index++;
	}
	if (!p)
		return 0;
	else
		return index;
}

//按下标查找
ElementType search2(ListNode *preHead, int index)
{
	ListNode* p = preHead;
	for (int i = 0; i < index-1 ; i++)
		p = p->next;
	return p->next->data;
}

//删除结点
bool ListDelete(ListNode* preHead, int i)
{
	int k = 1;
	ListNode* p = preHead->next;
	while (k < i - 1)
	{
		p = p->next;
		k++;
	}
	if (!p)
		return false;
	else
	{
		ListNode* pNext = p->next->next;
		ListNode* temp = p->next;
		p->next = pNext;
		free(temp);
	}
	return true;
}

void show(ListNode* preHead)
{
	ListNode* head = preHead->next;
	while (head)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
int main() 
{
	ListNode* preHead = CreateListT(5);
	cout << ListDelete(preHead, 3) << endl;
	show(preHead);
    return 0;
}

