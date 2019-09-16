#include <string>
#include <iostream>
using namespace std;

struct node
{
  string data;
  struct node *next;

  node(const string& data_item, node* next_ptr = NULL) :
	  data(data_item), next(next_ptr) {}
};

class SLinkedList
{
private:
	node* head;

public:

	SLinkedList(node* head = NULL);
	//Displays all the nodes in the list
	void display();

	// Adds a new node before a given node
	void addBefore(node* given, string newData);

	// Removes a given node from the linked list
	void remove(node* given);

	// Inserts a new node to the end from a piece of data
	void insert(string data);

	// Inserts a new node to the end from a referenced node
	void insert(node* newNode);

};
