#include "queue.h"

cqueue::cqueue()
{
	front = back = -1;
	itemcount = 0;
	for (int i = 0;i < 5;i++)
	{
		arr[i] = 0;
	}
}

bool cqueue::isEmpty()
{
	return (front == -1 && back == -1);
}

bool cqueue::isFull()
{
	return ((back+1)%5 == front);
}
void cqueue::enqueue(int a)
{
	if (isFull())
	{
		std::cout << "Queue overflow:cannot add new element" << std::endl;
		return;
	}
	else if (isEmpty())
	{
		front = back = 0;
		arr[back] = a;
	}
	else
	{
		back = (back + 1) % 5;
		arr[back] = a;
	}
	itemcount++;


}
int cqueue::dequeue()
{
	int val;
	if (isEmpty())
	{
		std::cout << "Stack underflow:No element to dequeue" << std::endl;
		return -1;
	}
	else if (front == back)
	{
		val = arr[front];
		arr[front] = 0;
		front = back = -1;		
	}
	else
	{
		val = arr[front];
		arr[front] = 0;
		front=(front+1)%5;		
	}
	itemcount--;
	return val;
}
int cqueue::count()
{
	return itemcount;
}

void cqueue::display()
{
	for (int i = 0;i < 5;i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

