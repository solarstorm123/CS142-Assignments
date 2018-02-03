/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 4 Assignment
 */

#include<iostream>
using namespace std;

class StackLL {
	class Node {
		public:
			int data;
			Node* next;
	};

	Node* top;
	int size;

	public:
		StackLL() {
			top = NULL;
			size = 0;
		}

		void push(int d);
		void pop();
		void empty();
		void display();
};

void StackLL::push(int d) {
/*
 * Pushes a node with data d at the top of the stack
 */
	Node* new_node = new Node;
	new_node->data = d;
	
	if (size == 0) {		// Checks if stack is empty.
		new_node->next = NULL;
	} else {
		new_node->next = top;
	}

	top = new_node;
	++size;
}

void StackLL::pop() {
/*
 * Pops the node at the top of the stack.
 */
	if (size == 0) {	// Checks if stack is empty.
		cout << "List empty. Nothing to do." << endl;
		return;
	}

	Node* temp = top;
	top = top->next;
	delete temp;
	--size;
}

void StackLL::empty() {
/*
 * Empties the list. Deletes all nodes. Sets size to zero.
 */
	while (size > 0) {
		pop();
	}
}

void StackLL::display() {
/*
 * Displays all elements stored in the stack
 */
	Node* p = top;
	if (size == 0) {		// Checks if stack is empty.
		cout << "List empty. No elements to display." << endl;
		return;
	}

	while (p != NULL) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

int main() {

	StackLL l1;
	for (int i=0; i<10; ++i) {
		l1.push(i+1);
	}

	l1.pop();
	l1.display();
	return 0;
}
