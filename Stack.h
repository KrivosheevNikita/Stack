#ifndef STACK_H
#define STACK_H 

template <typename T>
class Stack
{

public:

	Stack();

	~Stack();

	int size();

	bool empty();

	void push(T val);

	void pop();

	int last();

private:

	int capacity;
	int top;
	T* storage;

	void resize(int new_capacity);

};
#include "Stack-impl.h"
#endif
