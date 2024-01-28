#include<iostream>
class node
{
public:
	int data;
	node* next;
	node();
	node(int);
};

class llist
{
public:
	node* head;
	int size;
	llist();
	node* getNode(int);
	void insertfirst(int);
	void insertpos(int, int);
	void insertlast(int);
	void deletefirst();
	void deletepos(int);
	void deletelast();
	void updatenode(int);
	void traverse();
	
};
