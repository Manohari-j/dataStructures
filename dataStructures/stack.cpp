#include "stack.h"

stack::stack()
{
	top = -1;
	for (int i = 0;i < 5;i++)
	{
		arr[i] = 0;
	}
}

bool stack::isEmpty()
{
	return (top == -1);
}

bool stack::isFull()
{
	return (top == 4);
}
void stack::push(int a)
{
	if (isFull())
		std::cout << "Stack overflow:cannot add new element"<<std::endl;
	else
	{
		top++;
		arr[top] = a;
	}

}
int stack::pop()
{
	int val;
	if (isEmpty())
	{
		std::cout << "Stack underflow:No element to pop" << std::endl;
		return -1;
	}
	else
	{
		val = arr[top];
		arr[top] = 0;
		top--;
		return val;
	}
}
int stack::count()
{
	return top + 1;
}
int stack::peek(int pos)
{
	if (isEmpty())
	{
		std::cout << "Stack underflow:No element to peek" << std::endl;
		return -1;
	}
	return arr[pos];
}
void stack::change(int index,int val)
{
	arr[index] = val;
}
void stack::display()
{
	for (int i = 0;i < 5;i++)
	{
		std::cout<<arr[i]<<std::endl;
	}
}

