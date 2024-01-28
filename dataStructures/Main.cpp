#include <iostream>
/*#include "stack.h"
#include "queue.h"
#include "linkedlist.h"
#include "binarysearch.cpp"
#include "selectionSort.cpp"
#include "bubbleSort.cpp"
#include "factorial.cpp"
#include "mergeSort.cpp"
#include "QuickSort.cpp"*/
#include "Expression.cpp"
#include<stack>
using namespace std;

//Infix, postfix, prefix
int precedence(char c)
{
	if (c == '^')
		return 3;
	else if (c == '*' || c == '/')
		return 2;
	else if (c == '+' || c == '-')
		return 1;
	else
		return -1;

}
string infixToPostfix(stack<char> s, string infix)
{
	string postfix;
	for (int i = 0;i < infix.length();i++)
	{
		if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			postfix += infix[i];
		}
		else if (infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while ((s.top() != '(')&& (!s.empty()))
			{
				char temp = s.top();
				postfix += temp;
				s.pop();
			}
			if (s.top() == '(')
				s.pop();
		}
		else if(infix[i] == '^'||infix[i] == '+' || infix[i] == '-'|| infix[i] == '*'|| infix[i] == '/')
		{
			if (s.empty())
			{
				s.push(infix[i]);
			}
			else
			{
				if (precedence(infix[i])>precedence(s.top()))
				{
					s.push(infix[i]);
				}
				else if ((precedence(infix[i]) == precedence(s.top())&&(infix[i]=='^')))
				{
					s.push(infix[i]);
				}
				else
				{
					while (!s.empty()&&(precedence(infix[i]) <= precedence(s.top())))
					{
						char temp = s.top();
						postfix += temp;
						s.pop();
					}
					s.push(infix[i]);
				}
			}

		}

	}
	while (!s.empty())
	{	 
		postfix += s.top();
		s.pop();
	}

	return postfix;
}
int main()
{
	string infix, postfix;
	cout << "Enter infix expression: ";
	cin >> infix;
	stack <char> s;
	cout << "Infix Expression: " << infix << endl;
	postfix = infixToPostfix(s, infix);
	cout << "Postfix Expression: " << postfix << endl;


}
/*
//Quick Sort
int main()
{
	int arr[] = { 4,2,9,5,34,87,12,98,38,17 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "\nUnsorted array elements: ";
	for (int k : arr)
	{
		cout << k << " ";
	}
	cout << "\nSorted array elements: ";
	quicksort(arr, 0, size - 1);
	for (int k : arr)
	{
		cout << k << " ";
	}
	return 0;
}*/
//MergeSort

/*int main()
{
	int arr[10] = { 4,2,9,5,34,87,12,98,38,17 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "\nUnsorted array elements: ";
	for (int k : arr)
	{
		cout << k << " ";
	}
	cout << "\nSorted array elements: ";
	mergesort(arr,0, size-1);
	for (int k : arr)
	{
		cout << k << " ";
	}
	return 0;
}*/
/*
//Factorial
int main()
{
	//int f = fact(5);
	int f = recurfact(5);
	cout << f << endl;
}
*/
/*
//Bubble Sort
int main()
{
	int arr[] = { 32,5,25,11,19,4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << "\nUnsorted array elements: ";
	for (int k : arr)
	{
		cout << k << " ";
	}
	cout << "\nSorted array elements: ";
	bubblesort(arr, size);
	for (int k : arr)
	{
		cout << k << " ";
	}

}*/

/*Selection Sort
int main()
{
	int arr[] = { 32,5,25,11,19,4 };
	int size=sizeof(arr)/sizeof(arr[0]);
	cout << "\nUnsorted array elements: ";
	for (int k : arr)
	{
		cout << k << " ";
	}
	cout << "\nSorted array elements: ";
	Selectionsort(arr, size);
	for (int k : arr)
	{
		cout << k << " ";
	}

}*/

/*
//Binary Search
int main()
{
	int arr[5] = {9,24,54,73,96};
	int val;
	cout << "Enter an element to search:";
	cin >> val;

	int result=binarysearch(arr,0,4,val);
	(result == -1)? cout << "Value not found" :cout << val << " is found at position " << result + 1;
	
}
*/

/* Linked List

int main()
{
	llist l;
	int choice, pos, val;
	do
	{
		cout << "\nMenu: select 0 to exit" << endl;
		cout << "1.Insert at first" << endl;
		cout << "2.Insert at position" << endl;
		cout << "3.Insert at last" << endl;
		cout << "4.Delete at first" << endl;
		cout << "5.Delete at position" << endl;
		cout << "6.Delete at last" << endl;
		cout << "7.Update the node" << endl;
		cout << "8.Traverse list" << endl;
		cout << "9.ClearScreen" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			cout << "Enter a value to Insert at first : ";
			cin >> val;
			l.insertfirst(val);
			break;
		case 2:
			cout << "Enter pos : ";
			cin >> pos;
			cout << "Enter a value to Insert at pos : ";
			cin >> val;
			l.insertpos(val,pos);
			break;
		case 3:
			cout << "Enter a value to Insert at last : ";
			cin >> val;
			l.insertlast(val);
			break;
		case 4:
			l.deletefirst();			
			break;
		case 5:
			cout << "Enter pos of the element to be deleted : ";
			cin >> pos;
			l.deletepos(pos);
			break;
		case 6:
			l.deletelast();
			break;
		case 7:

			break;

		case 8:
			cout << "Linked list values : " << endl;
			l.traverse();
			break;
		case 9:
			system("cls");
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}

	} while (choice != 0);
	return 0;
	


}*/

/* Queue and Circular Queue
int main()
{
	//queue s;// use it when its normal queue
	cqueue s;
	int choice, pos, val;
	bool v;
	do
	{
		cout << "\nMenu: select 0 to exit" << endl;
		cout << "1.Enqueue" << endl;
		cout << "2.Dequeue" << endl;
		cout << "3.isEmpty" << endl;
		cout << "4.isFull" << endl;
		cout << "5.Count" << endl;
		cout << "6.display" << endl;
		cout << "7.ClearScreen" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			cout << "Enter a value to enqueue in the queue : ";
			cin >> val;
			s.enqueue(val);
			break;
		case 2:
			s.dequeue();
			break;
		case 3:
			v = s.isEmpty();
			cout << ((v == true) ? "Queue is Empty\n" : "Queue is not Empty\n");
			break;
		case 4:
			v = s.isFull();
			cout << ((v == true) ? "Queue is Full\n" : "Queue is not Full\n");
			break;
		
		case 5:
			cout << "No. of elements in the stack " << s.count();
			break;
		
		case 6:
			cout << "Stack values : " << endl;
			s.display();
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}

	} while (choice != 0);
	return 0;
}*/

/*
//Stack
int main()
{
	stack s;
	int choice, pos, val;
	bool v;
	do
	{
		cout << "\nMenu: select 0 to exit" << endl;
		cout << "1.Push" << endl;
		cout << "2.Pop" << endl;
		cout << "3.isEmpty" << endl;
		cout << "4.isFull" << endl;
		cout << "5.Peek" << endl;
		cout << "6.Count" << endl;
		cout << "7.Change" << endl;
		cout << "8.display" << endl;
		cout << "9.ClearScreen" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
			break;
		case 1:
			cout << "Enter a value to push in the stack : ";
			cin >> val;
			s.push(val);
			break;
		case 2:
			s.pop();
			break;
		case 3:
			 v=s.isEmpty();
			cout << (v == true) ? "Stack is Empty\n" : "Stack is not Empty\n";
			break;
		case 4:
			 v = s.isFull();
			cout << (v == true) ? "Stack is Full\n" : "Stack is not Full\n";
			break;
		case 5:
			cout << "Enter a position to peek : ";
			cin >> pos;
			cout<<"\nElement at position"<<pos<<":"<<s.peek(pos)<<endl;
			break;
		case 6:
			cout << "No. of elements in the stack "<<s.count();
			break;
		case 7:
			cout << "Enter a position at which the value to be changed : ";
			cin >> pos;
			cout << "\nEnter a value to be inserted : ";
			cin >> val;
			s.change(pos,val);
		case 8:
			cout << "Stack values : "<<endl;
			s.display();
			break;
		case 9:
			system("cls");
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}

	} while (choice != 0);
	return 0;
}*/