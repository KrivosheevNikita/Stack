#ifndef STACK_IMPL_H
#define STACK_IMPL_H
#include <iostream>

//конструктор по умолчанию
template <typename T>
Stack<T>::Stack()
{
	capacity = 1;
	top = 0;
	storage = new T[capacity];
}

//конструктор копирования
template <typename T>
Stack<T>::Stack(Stack<T>& s)
{
	capacity = s.capacity;
	top = s.top;
	storage = new T[capacity];
	for (int i = top - 1; i != -1; --i)
	{
		storage[i] = s.storage[i];
	}
}

//деструктор
template <typename T>
Stack<T>::~Stack()
{
	delete[] storage;
}

//возврат размера стека
template <typename T>
int Stack<T>::size()
{
	return top;
}

//проверка стека на отсутствие элементов
template <typename T>
bool Stack<T>::empty()
{
	return top == 0;
}

//добавление одного элемента в стек
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

//удаление элемента из вершины стека
template <typename T>
void Stack<T>::pop()
{
	if (!empty() && top == capacity / 4)
	{
		resize(capacity / 2);
	}
	if (top != 0) --top;
}

//получение последнего элемента из стека
template <typename T>
int Stack<T>::last()
{
	try
	{
		if (top == 0) throw std::out_of_range("Stack is empty. Accessing a non-existent element using last()");
		return storage[top - 1];
	}
	catch (const std::out_of_range& ex)
	{
		std::cout << std::endl << "Error: " << ex.what() << std::endl;
		std::abort();
	}
}

//вывод содержимого стека на экран, начиная с последнего добавленного элемента
template <typename T>
void Stack<T>::print()
{
	for (int i = top - 1; i != -1; --i)
	{
		std::cout << storage[i] << " ";
	}
}

//оператор сравнения двух стеков
template <typename T>
template<typename U>
bool Stack<T>::operator==(const Stack<U>& right)
{
	if (this->top != right.top)
	{
		return false;
	}
	for (int i = top - 1; i != -1; --i)
	{
		if (this->storage[i] != right.storage[i])
		{
			return false;
		}
	}
	return true;
}

template <typename T>
template<typename U>
bool Stack<T>::operator!=(const Stack<U>& right)
{
	return !(*this == right);
}

//изменение емкости стека
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

#endif
