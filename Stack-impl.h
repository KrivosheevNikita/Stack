#ifndef STACK_IMPL_H
#define STACK_IMPL_H
template <typename T>
Stack<T>::Stack()
{
	capacity = 1;
	top = 0;
	storage = new T[capacity];
}

template <typename T>
Stack<T>::~Stack()
{
	delete[] storage;
}

template <typename T>
int Stack<T>::size()
{
	return top;
}

template <typename T>
bool Stack<T>::empty()
{
	return top == 0;
}

template <typename T>
void Stack<T>::push(T val)
{
	if (top == capacity)
	{
		resize(2 * capacity);
	}
	storage[top] = val;
	++top;
}

template <typename T>
void Stack<T>::pop()
{
	if (!empty() && top == capacity / 4)
	{
		resize(capacity / 2);
	}
	--top;
}

template <typename T>
void Stack<T>::resize(int new_capacity)
{
	T* temp = new T[new_capacity];
	for (int i = 0; i != top; ++i)
	{
		temp[i] = storage[i];
	}
	delete[] storage;
	storage = temp;
	capacity = new_capacity;
}

template <typename T>
int Stack<T>::last()
{
	return storage[top - 1];
}
#endif