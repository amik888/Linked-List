#include <iostream>
using namespace std;

// Defines a node, which contains data and *next
struct node
{
  string data;
  struct node *next;

// Node constructor
  node(const string& data_item, node* next_ptr = NULL) :
	  data(data_item), next(next_ptr) {}
};


//Displays all the nodes in the list
void display(node* head)
{
	node* currentNode = head;
	while (currentNode -> next != NULL)
	{
		// Prints each node except the tail with a space after
		cout << currentNode -> data << " ";
		currentNode = currentNode -> next;
	}
	// Prints the tail
	cout << currentNode -> data;
}

// Adds a new node before a given node
void addBefore(node* head, node* given, string newData)
{
	node* currentNode = head;
	while(currentNode -> next != given)
	{
		// This moves the currentNode pointer to the node before the given one
		currentNode = currentNode -> next;
	}
	// This inserts the new node into the linked list before the given node
	currentNode -> next = new node(newData, currentNode -> next);
}

// Removes a given node from the linked list
void remove(node* head, node* given)
{
	node* currentNode = head;
	while (currentNode -> next != given)
	{
		// moves the currentNode pointer to the node before the given one
		currentNode = currentNode -> next;
	}
	currentNode -> next = currentNode -> next -> next;
	// removes the node and then deletes data stored at the removed node.
	node* remove = given;
	delete remove;
}

// Inserts a new node to the end from a piece of data
void insert(node* head, string data)
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
			// Finds the tail with currentNode
			currentNode = currentNode -> next;
		}
		// Adds the node to the end
		currentNode -> next = new node(data);
	}
}

// Inserts a new node to the end from a referenced node
void insert(node* head, node* newNode)
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
			// Finds the tail with currentNode
			currentNode = currentNode -> next;
		}
		// Adds the node to the end
		currentNode -> next = newNode;
	}
}

int main()
{
	// Creating the given Linked List
	node* sam = new node ("Sam");
	node* head = new node ("Tom");
	insert(head, "John");
	insert(head, "Harry");
	insert(head, sam);

	cout << "Original List: ";
	display(head);
	cout << endl << endl << "Updated list 1: ";

	head = new node("Bill", head);
	display(head);

	cout << endl << endl << "Updated list 2: ";
	addBefore(head, sam, "Sue");
	display(head);

	cout << endl << endl << "Updated list 3: ";

	node* ptr = head;
	head = head -> next;
	delete ptr;
	display(head);

	cout << endl << endl << "Updated list 4: ";
	remove(head, sam);
	display(head);
}


