#pragma once
#include <iostream>
using namespace std;
template<class T>
class stack {
public:
 
	stack(int capacity=10 ) {
		if (capacity < 0)
			cout << "capacity must be bigger than 0" << endl;
		arrayLength = capacity;
		stk = new T[arrayLength];
		stackTop = -1;

	}
	~stack() { delete[]stk; }
	bool empty() { return stackTop == -1; }
	int size() const { return stackTop + 1; }
	T& top() {
		if (stackTop == -1)
		     cout << "stack is empty!" << endl;  
		else
			return stk[stackTop];
	}
	void pop() {
		if (stackTop == -1)
			cout << "stack is empty!cannot pop an element!" << endl;
		else
			stk[stackTop--].~T();
	}

	void push(const T& element) {
		if (stackTop == arrayLength - 1)
			cout << "Õ»ÒÑÂú" << endl;
		else
		 stk[++stackTop] = element;
	}
private:
	int stackTop;
	int arrayLength;
	T* stk;
};


