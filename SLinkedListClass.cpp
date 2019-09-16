#include "SlinkedListClass.h"

	SLinkedList::SLinkedList(node* head) : head(head) {}
	//Displays all the nodes in the list
	void SLinkedList::display()
	{
		node* currentNode = head;
		while (currentNode -> next != NULL)
		{
			cout << currentNode -> data << " ";
			currentNode = currentNode -> next;
		}
		cout << currentNode -> data;
	}

	// Adds a new node before a given node
	void SLinkedList::addBefore(node* given, string newData)
	{
		node* currentNode = head;
		while(currentNode -> next != given)
		{
			currentNode = currentNode -> next;
		}
		currentNode -> next = new node(newData, currentNode -> next);
	}

	// Removes a given node from the linked list
	void SLinkedList::remove(node* given)
	{
		node* currentNode = head;
		while (currentNode -> next != given)
		{
			currentNode = currentNode -> next;
		}
		currentNode -> next = currentNode -> next -> next;
		node* remove = given;
		delete remove;
	}

	// Inserts a new node to the end from a piece of data
	void SLinkedList::insert(string data)
	{
		if (head == NULL)
		{
			head = new node(data);
		}
		else
		{
			node* currentNode = head;
			while(currentNode -> next != NULL)
			{
				currentNode = currentNode -> next;
			}
			currentNode -> next = new node(data);
		}
	}

	// Inserts a new node to the end from a referenced node
	void SLinkedList::insert(node* newNode)
	{
		if (head == NULL)
		{
			head = newNode;
		}
		else
		{
			node* currentNode = head;
			while(currentNode -> next != NULL)
			{
				currentNode = currentNode -> next;
			}
			currentNode -> next = newNode;
		}
	}
