#include<iostream>
class queue
{
private:
	int front;
	int back;
	int arr[5];
public:
	queue();
	void enqueue(int);
	int dequeue();
	bool isEmpty();
	bool isFull();
	int count();
	void display();
};

class cqueue
{
private:
	int front;
	int back;
	int arr[5];
	int itemcount;
public:
	cqueue();
	void enqueue(int);
	int dequeue();
	bool isEmpty();
	bool isFull();
	int count();
	void display();
};