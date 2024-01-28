#include<iostream>
class stack
{
private:
	int top;
	int arr[5];
public:
	stack();
	void push(int);
	int pop();
	int peek(int);
	void change(int,int);
	bool isEmpty();
	bool isFull();
	int count();
	void display();
};