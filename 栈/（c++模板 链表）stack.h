#pragma once
#include <iostream>
using namespace std;

template<class T>
struct chainNode
{
	T element;
	chainNode<T> * next;
	chainNode(){}
	chainNode(const T& element)
	{
		this->element = element;
	}
	chainNode(const T& element, chainNode<T> *next)
	{
		this->element = element;
		this->next = next;
	}
};

template<class T>
class stack {
public:
	stack() {
		cout << "aaaa" << endl;
		stackSize = 0;
		stackTop = new chainNode<T>(-1,NULL);
	}
	~stack() {
		while (!stackTop != NULL)
		{
			chainNode<T> * next = stackTop->next;
			delete stackTop;
			stackTop = next;
		}
	}
		bool empty(){return stackSize == 0;}
		int size() { return stackSize; }
		T& top() {
			if (stackSize == 0) {
				cout << "栈是空的，无法弹出元素" << endl;
			}
			else
				return stackTop->element;
		}
		void push(T & element)
		{
			stackTop = new chainNode<T>(element, stackTop);
			stackSize++; 

		}
		void pop() {
			if (stackSize == 0)
			{
				cout << "栈是空的" << endl;
			}
			else {
				chainNode<T>* nextNode = stackTop->next;
				delete stackTop;
				stackTop = nextNode;
				stackSize--;
			}
		}
private:
	int stackSize;
	chainNode<T> * stackTop;
};
