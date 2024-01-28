#include "queue.h"

queue::queue()
{
	front = back =  -1;
	for (int i = 0;i < 5;i++)
	{
		arr[i] = 0;
	}
}

bool queue::isEmpty()
{
	return (front == -1 && back == -1);
}

bool queue::isFull()
{
	return (back == 5);
}
void queue::enqueue(int a)
{
	if (isFull())
	{
		std::cout << "Queue overflow:cannot add new element" << std::endl;
	}		
	else if(isEmpty())
	{
		front = back = 0;
		arr[back] = a;
	}
	else
	{
		back++;
		arr[back] = a;
	}
	

}
int queue::dequeue()
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
		return val;
	}
	else
	{
		val = arr[front];
		arr[front] = 0;
		front++;
		return val;
	}
}
int queue::count()
{
	return (back-front) + 1;
}

void queue::display()
{
	for (int i = 0;i < 5;i++)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

