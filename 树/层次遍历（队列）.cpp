#include "stdafx.h"
#include"queue.h"

#include<iostream>
//#include<queue>
using namespace std;
typedef char ElementType;
#define MaxSize 100

struct btNode
{
	ElementType data;
	btNode* left;
	btNode* right;
	btNode(ElementType &e) :data(e), left(NULL),right(NULL){}
};

btNode* createTree()
{
	btNode* p;
	ElementType d;
	cin >> d;
	if (d == '#')
		p = NULL;
	else
	{
		p = new btNode(d);
		p->left = createTree();
		p->right = createTree();
	}
	return p;
}

void leverOrderTraversal(btNode* p)
{
	int count = 0;
	queue<btNode*> q;
	ElementType data[MaxSize];
	q.push(p);
	q.push(NULL);
	while (!q.empty())
	{
		btNode* t = q.front();
		q.pop();
		if (t == NULL)
		{
			for (int i = 0; i < count; i++)
				cout << data[i] << "  ";
			cout << endl;
			count = 0;
			if (q.size() > 0)
				q.push(NULL);
		}
		else
		{
			data[count++] = t->data;
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
		}
	}
}
int main() 
{
	btNode* p = createTree();
	leverOrderTraversal(p);
    return 0;
}

/*
test example :
abcd###e##fg##h#i##
*/

