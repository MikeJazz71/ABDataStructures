#pragma once
#include <cstddef>
#include <iostream>

using namespace std; 

class Node 
{
public:

	int data;
	Node* next;
	
	
	
};

class LinkedList
{

private:
	Node* head;
	Node* tail;
	Node* previous = NULL;
	Node* Pos = head; 
	 
	
	



public:
	int length = 0;


	LinkedList()
	{
		//head = NULL;
		//tail = head;
		
		
		
	}

	LinkedList(int A[], int n);
	~LinkedList(); 
	void Display();
	void Append(int data);
	void MakeEmpty();
	int Sum();
	int Max();
	int Min();
	bool Search(int key);
	bool MoveToFront(int key);
	void Insert(int Position, int data);
	void Delete(int index);
	int GetLength();
	void SortedList(int key);
	
	
	
	
	

	
};



inline LinkedList::LinkedList(int A[], int n)
{

	int i;
	Node* temp;
	head = new Node;
	head->data = A[0];
	head->next = NULL;
	tail = head;
	length = 1; 
	

	for (i=1; i < n; i++) // Start from one as the first Node has been created above
	{
		temp = new Node;
		temp->data = A[i];
		temp->next = NULL;
		tail->next = temp;
		tail = temp;
		length++; 
		
	}
	
}

inline LinkedList::~LinkedList()
{

	Node* p = head;

	while (p != NULL)
	{
		head = head->next;
		delete p;
		p = head;
		length--; 
	}
	
}

inline void LinkedList::Display()
{
	Node *p = head;

	while (p != NULL)
	{
		cout << p->data << " ";
		p = p -> next;
		

		
	}

	cout << endl; 
}

inline void LinkedList::Append(int data)
{
	Node* temp; 
	temp = new Node;
	temp->data = data;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
	length++;
}

inline void LinkedList::MakeEmpty()
{

	Node* temp;


	while (head != NULL)
	{

		temp = head;
		head = head->next;
		delete temp; 
		
		length--; 
	}
	
}

inline int LinkedList::Sum()
{
	int sum = 0;
	Node* p = head;

	while (p != NULL)
	{

		sum += p->data;
		p = p->next; 
		
	}
	
	return sum;
}

inline int LinkedList::Max()
{
	Node* p = head;
	int max = p->data;
	if (length == 0)
	{
		return 0;
	}
	else
	{
		while (p != NULL)
		{

			if (p->data > max)
			{
				max = p->data;
				p = p->next;
			}
			else
			{
				p = p->next;
			}
		}

		return max;
	}

	
}

inline int LinkedList::Min()
{
	Node* p = head;
	int min = p->data;
	if (length == 0)
	{
		return 0;
	}
	else
	{
		while (p != NULL)
		{

			if (p->data < min)
			{
				min = p->data;
				p = p->next;
			}
			else
			{
				p = p->next;
			}
		}

		return min;
	}

}

inline bool LinkedList::Search(int key)
{
	Node* p = head;

	if (length == 0)
	{
		return false;
	}
	else
	{

		while (p != NULL)
		{
			if (p->data == key)
			{
				cout << "Found" << endl; 
				return true;
				
			} else
			{
				p = p->next;
			}
		}
		
		return false; 
	}

	

	

	

	
}

inline bool LinkedList::MoveToFront(int key)
{
	Node* p = head;
	Node* q = tail; 

	if (length == 0)
	{
		return false;
	}
	else
	{

		while (p != NULL)
		{
			if (p->data == key)
			{
				cout << "Found" << endl;
				q->next = p->next;
				p->next = head;
				head = p;
				break;

			}
			else
			{
				q = p; 
				p = p->next;
			}
		}

		return false;
	}

}

inline void LinkedList::Insert(int Position, int data)
{

	if (Position == 0)
	{
		Node* temp = new Node;
		temp->data = data;
		temp->next = head;
		head = temp;
		length++; 
		
		
	} else
	{
		Node* temp = new Node;
		Node* Pos = head; 
		temp->data = data;
		temp->next = NULL; 
		for (int i = 0; i < Position-1; i++)
		{
			Pos = Pos->next; 
		}

		temp->next = Pos->next;
		Pos->next = temp;
		length++; 
		
	}
}

inline void LinkedList::Delete(int index)
{

	Node* Pos = head;

	if (index == 0)
	{
		head = head->next;
		int x = Pos->data; 
		delete Pos;
		length--;
		cout << x << " was deleted." << endl;
		
		
		
	} else
	{
		
		
		for (int i = 0; i < index; i++)
		{
			 
			previous = Pos;
			
			Pos = Pos->next; 
			
			
		}
		previous->next = Pos->next;
		int x = Pos->data; 
		delete Pos;
		
		length--;
		cout << x << " was deleted." << endl; 
	}
}

inline int LinkedList::GetLength()
{
	return length;
}

inline void LinkedList::SortedList(int key)
{

	Node* temp = new Node;
	
	
	if (length == 0)
	{
		
		head = temp;
		temp->data = key;
		temp->next = NULL; 
		
	} else
	{

		Node* p = head;
		Node* q = NULL;
		while (p && p->data < key)
		{
			q = p;
			p = p->next; 

			
		}
		if (p == head)
		{
			temp->next = head;
			head = temp; 
			
		}
		else 
		{


			temp->data = key;
			temp->next = q->next; 
			
			q->next = temp;

			/*
			 * Node* temp = new Node;
Node* Pos = head;
temp->data = data;
temp->next = NULL;
for (int i = 0; i < Position - 1; i++)
{
	Pos = Pos->next;
}

temp->next = Pos->next;
Pos->next = temp;
length++;
			 */
		}
		
		
	}
}




