#ifndef STACK_H
#define STACK_H 

template <typename T>
class Stack
{

public:

	Stack();

	Stack(Stack<T>& right);

	~Stack();

	int size();

	bool empty();

	void push(T val);

	void pop();

	int last();

	void print();

	bool operator==(const Stack<T>& right);

	bool operator!=(const Stack<T>& right);

private:

	int capacity;
	int top;
	T* storage;

	void resize(int new_capacity);
};
#include "Stack-impl.h"
#endif
