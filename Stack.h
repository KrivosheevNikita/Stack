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

	template<typename U>
	bool operator==(const Stack<U>& right);

	template<typename U>
	bool operator!=(const Stack<U>& right);

private:

	int capacity;
	int top;
	T* storage;

	void resize(int new_capacity);
};
#include "Stack-impl.h"
#endif
