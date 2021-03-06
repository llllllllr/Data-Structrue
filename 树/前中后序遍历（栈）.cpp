#include "stdafx.h"
#include"stack.h"
#include<iostream>
//#include<stack>
using namespace std;
#define MaxSize 100
typedef char ElementType;


struct btNode {
	ElementType data;
	btNode* left;
	btNode* right;
	btNode(ElementType da) { data = da; left = right = NULL; }
};

btNode* createTree()
{
	btNode * p;
	ElementType data;
	cin >> data;
	if (data == '#')
		p = NULL;
	else {
		p = new btNode(data);
		p->left = createTree();
		p->right = createTree();
	}
	
	return p;
}
void preOrderTraversal(btNode* p)
{

	stack<btNode*> stk;
	stk.push(p);
	while (!stk.empty())
	{
		btNode* top = stk.top();
		cout << top->data << "  ";
		stk.pop();
		if (top->right)
			stk.push(top->right);
		if (top->left)
			stk.push(top->left);
	}
	
}

void inorderTraversal(btNode* p)
{
	stack<btNode*> stk;
	btNode* pCurrent = p;
	while (!stk.empty() || pCurrent)
	{
		if (pCurrent)
		{
			stk.push(pCurrent);
			pCurrent = pCurrent->left;
	   }
		else
		{
			btNode * top = stk.top();
			stk.pop();
			cout << top->data << "  ";
			if (top->right)
				pCurrent = top->right;
		}
	}
}

void postOrderTraversal(btNode * p)
{
	stack<btNode*> stk;
	btNode *last = NULL;
	while (!stk.empty() || p)
	{
		if (p)
		{
			stk.push(p);
			p = p->left;
		}
		else
		{
			btNode* top = stk.top();
			if (top->right && top->right != last)
			{
				p = top->right;
			}
			else
			{
				cout << top->data << "  ";
				stk.pop();
				last = top;
			}
		}
	}
}
int main() 
{
	btNode* p = createTree();
	preOrderTraversal(p);
	cout << endl;
	inorderTraversal(p);
	cout << endl;
	postOrderTraversal(p);
	cout << endl;
    return 0;
}

/*
test example :
abcd###e##fg##h#i##
*/

