#include "linkedlist.h"

node::node()
{
	data = 0;
	next = NULL;
}
node::node(int data)
{
	this->data = data;
	next = NULL;
}
llist::llist()
{
	head = NULL;
	size = 0;
}

node* llist::getNode(int data)
{
	node* n = new node();
	n->data = data;
	n->next = NULL;

	return n;

}
void llist::insertfirst(int key)
{
	node* n = getNode(key);
	if (head == NULL)
	{
		head = n;
		size++;
		return;
	}
	node* temp = head;
	head = n;
	n->next = temp;
	size++;
}
void llist::insertpos(int key, int pos)
{
	node* n = getNode(key);
	node* temp = head;
	node* prevnode = NULL;
	
	if ((head == NULL&&pos >1)|| (pos < 1 || pos > size + 1))
	{
		std::cout << "Invalid position\n";
		return;
	}
	while (pos--)
	{
		if (pos == 0)
		{
			if (head == NULL)
			{
				head = n;
				size++;
				return;
			}
			prevnode->next = n;
			n->next = temp;			
		}
		else
		{
			prevnode = temp;
			temp = temp->next;
		}
	}
	size++;
}
void llist::insertlast(int key)
{
	node* n = getNode(key);
	if (head == NULL)
	{
		head = n;
		size++;
		return;
	}
	node* temp = head;
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = n;
	n->next = NULL;
	size++;

}

void llist::deletefirst()
{
	if (head == NULL)
	{
		std::cout << "\nEmpty list\n";
		return;
	}
	node* temp = head;
	head = head->next;
	delete temp;

}
void llist::deletepos(int pos)
{

}
void llist::deletelast()
{
	node* temp = head;
	node* prev=NULL;
	if (head == NULL)
	{
		std::cout << "\nEmpty list\n";
		return;
	}
	if (temp->next == NULL)
	{
		delete temp;
		return;

	}
	while (temp->next->next!= NULL)
	{
		prev = temp;
		temp=temp->next;
	}
	prev->next->next = NULL;
	temp = temp->next; 
	delete temp;

}
void llist::updatenode(int key)
{

}
void llist::traverse()
{
	node* temp = head;
	if (head == NULL)
	{
		std::cout << "Empty list\n";
		return;
	}
	while (temp!=NULL)
	{
		std::cout << temp->data << " ";
		temp = temp->next;
	}
}
