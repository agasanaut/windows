// LLReverse.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/* Link list node */
struct Node {
	int data;
	struct Node* next;
	Node(int data)
	{
		this->data = data;
		next = NULL;
	}
};

struct LinkedList {
	Node* head;
	LinkedList() { head = NULL; }

	/* Function to reverse the linked list */
	Node* reverse1(Node* root)
	{
		if (!root) { return nullptr; }
		if (!(root->next)) { head = root;  return root; }

		Node* temp1 = reverse1(root->next);
		temp1->next = root;
		temp1->next->next = nullptr;
		return root;
	}
	void reverse()
	{
		reverse1(head);
	}
	/* Function to print linked list */
	void print()
	{
		struct Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << " ";
			temp = temp->next;
		}
	}

	void push(int data)
	{
		Node* temp = new Node(data);
		temp->next = head;
		head = temp;
	}
};

/* Driver code*/
int main()
{
	/* Start with the empty list */
	LinkedList ll;
	ll.push(20);
	ll.push(4);
	ll.push(15);
	ll.push(85);

	cout << "Given linked list  : \n";
	ll.print();

	ll.reverse();

	cout << "\nReversed Linked list :  \n";
	ll.print();
	return 0;
}
