/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 2 Assignment
 */

#include<iostream>
using namespace std;

class Node {
/*
 * Contains a data storage unit and a pointer to the next
 * element of the linked list.
 */

	public:
		int data;
		Node* next;

		Node() {
			data = 0;
			next = NULL;
		}
};

class SLList {
/*
 * Class for Singly Linked List data structure
 * Pointers to the first and last element of the list
 * identify it. A "size" variable holds the number of
 * elements in the linked list.
 */

	public:
		Node* head;
		Node* tail;
		int size;

	public:
		SLList() {
			head = NULL;
			tail = NULL;
			size = 0;
		}
		
		// Member functions of the SLList class.
		void insert(int d);
		Node* getNode(int i);
		int insertAt(int i, int d);
		void remove();
		int removeAt(int i);
		int countItems();
		void display();
		void rdisplay(Node* p);
		void rrdisplay(Node* p);
};

void SLList::insert(int d) {
/*
 * Inserts the value stored in d at the end of the
 * list.
 */

	Node* new_node = new Node;
	new_node->data = d;
	new_node->next = NULL;

	if (head == NULL) {	
		head = new_node;	// Steps to perform when the list is empty.
		tail = new_node;
	} else {
		tail->next = new_node;	// Steps to perform when list is non-empty.
		tail = new_node;
	}

	++size;
}

Node* SLList::getNode(int i) {
/* 
 * Returns a pointer to the ith element of the list.
 * This function makes the code for insertAt, remove and removeAt
 * functions very readable
 */

	if (i > size || i < 1) {	// Check for validity of i.
		cout << "Invalid element position." << endl;
		return NULL;
	}

	if (i == size) {			// Optimisation. The list entire is not 
		return tail;			// traversed if only the last element is required.
	}

	Node* p = head;				// p is a placeholder variable used to 
	for (int j=1; j<i; ++j) {	// traverse through the list.
		p = p->next;
	}
	return p;
}

int SLList::insertAt(int i, int d) {
/*
 * Inserts a node with data value d at the ith position
 * of the list. Returns -1 for an invalid value of i.
 * Returns 0 for successful insertion of the node at the
 * correct position.
 */

	if (i > size+1 || i < 1) {	// Check for validity of i.
		cout << "Invalid element position." << endl;
		return -1;
	}

	Node* new_node = new Node;
	new_node->data = d;

	if (i == size+1) {			// insert function is called when the
		insert(d);				// element is to be added at the end.
	} else {
		Node* p = getNode(i-1);	// p is a placeholder variable which
								// holds a pointer to the (i-1)th element.
		new_node->next = p->next;
		p->next = new_node;

		++size;
	}

	return 0;
}

void SLList::remove() {
/*
 * Removes the last element of the list
 */

	Node* p = getNode(size-1);
	
	tail = p;
	delete p->next;
	p->next = NULL;
	--size;
}

int SLList::removeAt(int i) {
/*
 * Function to remove the ith element of the list.
 * Returns -1 for an invalid value of i. Returns 0
 * if the element at the given index is successfully removed.
 */

	if (i > size || i < 1) {	// Check for the validity of i
		cout << "Invalid element position." << endl;
		return -1;
	}

	if (i == size) {			// remove() function is called when only
		remove();				// the last element is to be deleted.
	} else {
		Node* p = getNode(i-1);	// p and q are placeholder variables.
		Node* q = p->next;		// p stores a pointer to (i-1)th element.
		p->next = q->next;		// q stores a pointer to the ith element.
		delete q;

		--size;
	}
	return 0;
}

int SLList::countItems() {
/*
 * Returns the number of elements of the linked list.
 */
	return size;
}

void SLList::display() {
/*
 * Prints the value stored in each of the nodes of the list
 */
	
	for (int i=0; i<size; ++i) {
		cout << getNode(i+1)->data << "->";
	}
	cout << "NULL" << endl;
}

void SLList::rdisplay(Node* p) {
	if (p->next == NULL) {
		cout << p->data << endl;
		cout << "End of list." << endl;
		return;
	}

	cout << p->data << endl;
	rdisplay(p->next);
}

void SLList::rrdisplay(Node* p) {
	if (p->next == NULL) {
		cout << p->data << endl;
		return;
	}

	rrdisplay(p->next);
	cout << p->data << endl;
}

int main() {
/* 
 * main() function to test the code.
 */

	SLList l1;

	l1.rdisplay(l1.head);

	return 0;
}
