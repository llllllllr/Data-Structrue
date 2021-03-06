#include "stdafx.h"
#include<stack>
#include<iostream>
#include <iostream>
using namespace std;
#define MaxSize 100

template <class T>
struct chainNode {
	T element;
	chainNode<T> * next;
	chainNode(T& element) { this->element = element; }
	chainNode(T& element, chainNode<T>* next) { this->element = element; this->next = next; }
};
template<class T>
class queue {
public:
	queue() {}
	virtual bool empty() = 0;
	virtual int size() = 0;
	virtual T& front() = 0;
	virtual T& back() = 0;
	virtual void pop() = 0;
	virtual void push(T& element) = 0;
};

template<class T>
class arrayQueue :public queue<T> {
public:
	arrayQueue() {
		arrayLength = MaxSize;
		theBack = theFront = 0;
		que = new T[arrayLength];
	}
	~arrayQueue() {
		delete[]que;
	}
	bool empty() {
		return theBack == theFront;
	}

	int size() { return (theBack - theFront + arrayLength) % arrayLength; }

	T& front() {
		if (theBack == theFront)
		{
			cout << "the queue is empty! " << endl;
			exit(0);
		}
		else
			return que[(theFront + 1) % arrayLength];
	}

	T& back() {
		if (theBack == theFront)
		{
			cout << "the queue is empty! " << endl;
			exit(0);
		}
		else
			return que[(theBack + 1) % arrayLength];
	}

	void push(T& element) {
		if ((theBack +1) % arrayLength == theFront)
		{
			cout << "the queue is full" << endl;
			exit(0);
		}
		else
		{
			theBack = (theBack + 1) % arrayLength;
			que[theBack] = element;
		}
	}

	void pop() {
		if (theFront == theBack)
		{
			cout << "the queue is empty" << endl;
			exit(0);
		}
		else {
			theFront = (theFront + 1) % arrayLength;
			que[theFront].~T();
		}
	}
private:
	int arrayLength;
	int theBack;
	int theFront;
	T * que;
};

template<class T>
class linkQueue /*:public queue<T>*/
{
public:
	linkQueue() {
		queueFront = queueBack = NULL;
	}
	bool empty() {
		return linkSize == 0;
	}
	int size() { return linkSize; }
	T& front()
	{

		if (linkSize == 0)
		{
			cout << "the queue is empty" << endl;
			exit(0);
		}
		else
			return queueFront->element;
	}
		T& back() {
		if (linkSize == 0)
		{
			cout << "the queue is empty" << endl;
			exit(0);
		}
		else {
			return queueBack->element;
		}
	}
	void pop() {
		if (linkSize==0)
		{
			cout << "the queue is empty" << endl;
			exit(0);
		}
		else
		{
			chainNode<T>* nextNode = queueFront->next;
			delete queueFront;
			queueFront = nextNode;
			linkSize--;
		}
	}
	void push(T & element)
	{
		chainNode<T> *newNode = new chainNode<T>(element, NULL);
		if (linkSize == 0)
			queueFront = newNode;
		else
			queueBack->next = newNode;
		queueBack = newNode;
		linkSize++;
	}
	void test() {
		if (queueFront == queueBack == NULL)
			cout << queueFront->element << "     " << queueBack->element << "    "<<linkSize<<endl;
		else
			return;
	}
private:
	chainNode<T> * queueFront;
	chainNode<T> * queueBack;
	int linkSize;
};
int main() 
{
	linkQueue<int> q;
	for (int i = 0; i < 10; i++)
		q.push(i);
	//q.test();
	while (!q.empty())
	{
		cout << q.front() << endl;
		q.pop();
	}
	//int mg[10][10] = {
	//{ 1,1,1,1,1,1,1,1,1,1 },{ 1,0,0,1,0,0,0,1,0,1 },
	//{ 1,0,0,1,0,0,0,1,0,1 },{ 1,0,0,0,0,1,1,0,0,1 },
	//{ 1,0,1,1,1,0,0,0,0,1 },{ 1,0,0,0,1,0,0,0,0,1 },
	//{ 1,0,1,0,0,0,1,0,0,1 },{ 1,0,1,1,1,0,1,1,0,1 },
	//{ 1,1,0,0,0,0,0,0,0,1 },{ 1,1,1,1,1,1,1,1,1,1 }
	//};
	//findPath(1, 1, 8, 8, mg);
    return 0;
}

