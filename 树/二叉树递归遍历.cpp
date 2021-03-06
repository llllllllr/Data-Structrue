#include "stdafx.h"
#include<iostream>
#include <iostream>
using namespace std;
#define MaxSize 100
typedef char ElementType;


struct btNode {
	ElementType data;
	btNode* left;
	btNode* right;
	btNode(ElementType da) { data = da; left = right = NULL; }
};


btNode* createTree() {
	btNode* p;
	ElementType d;
	cin >> d;
	if (d == '#')
		p = NULL;
	else {
		p = new btNode(d);
		p->left = createTree();
		p->right = createTree();
	}
	return p;
}             

void preOrder(btNode* p)
{
	if (p == NULL)
		return ;
	cout << p->data << "   ";
	preOrder(p->left);
	preOrder(p->right);
}

void inOrder(btNode * p)
{
	if (p == NULL)
		return;
	else {
		inOrder(p->left);
		cout << p->data << "   ";
		inOrder(p->right);
	}
}

void postOrder(btNode* p){
	if (p == NULL)
		return;
	else
	{
		postOrder(p->left);
		postOrder(p->right);
		cout << p->data << "   ";
	}
}
int main() 
{
	
	btNode* p = createTree();
	cout << "preOrder:" << endl;
	preOrder(p);
	cout << endl;
	cout << "inOrder:" << endl;
	inOrder(p);
	cout << endl;
	cout << "postOrder:" << endl;
	postOrder(p);
	cout << endl;
    return 0;
}

/*
test example :
abcd###e##fg##h#i##
*/

