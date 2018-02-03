/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 4 Assignment
 */

#include<iostream>
using namespace std;

class Node {
	public:
		int data;
		Node* next;
};

class QueueLL {
	Node* front;
	Node* back;
	int size;

	public:
		QueueLL() {
			front = NULL;
			back = NULL;
			size = 0;
		}

		void queue(int d);
		void dequeue();
		void empty();
		void display();
};

void QueueLL::queue(int d) {
/*
 * Creates a new node and adds it to the end of the queue.
 */
	Node* new_node = new Node;
	new_node->data = d;

	if (size == 0) {
		new_node->next = NULL;
		front = new_node;
	} else {
		new_node->next = back;
	}
	back = new_node;
	++size;
}

void QueueLL::dequeue() {
/*
 * Removes the node at the front of the queue
 */
	if (size == 0) {
		cout << "List empty. Nothing to do." << endl;
		return;
	} else if (size == 1) {
		Node* temp = front;
		front = NULL;
		back = NULL;
		delete temp;
	} else {
		Node* p = back;
		while (p->next != front) {
			p = p->next;
		}

		Node* temp = front;
		p->next = NULL;
		front = p;
		delete temp;
	}
	--size;
}

void QueueLL::empty() {
/*
 * Empties the queue. Deletes all elements, sets size to zero
 */
	while (size > 0) {
		dequeue();
	}
}

void QueueLL::display() {
/*
 * Displays all the elements of the queue from front to back
 */
	if (size == 0) {
		cout << "List empty. Nothing to do." << endl;
		return;
	}

	Node* p = back;
	while (p != NULL) {
		cout << p->data << "->";
		p = p->next;
	}
	cout << "NULL" << endl;
}

int main() {
	QueueLL l1;
	for (int i=0; i<10; ++i) {
		l1.queue(i+1);
	}

	l1.empty();
	l1.display();
	return 0;
}
