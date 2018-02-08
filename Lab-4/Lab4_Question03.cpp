/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 4 Assignment
 */

#include<iostream>
#include<string>
using namespace std;

class StackLL {
	class Node {
		public:
			char data;
			Node* next;
	};

	Node* top;
	int size;

	public:
		StackLL() {
			top = NULL;
			size = 0;
		}

		void push(char d);
		void pop();
		char get(int i);
		bool isPalindrome();
};

void StackLL::push(char d) {
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

char StackLL::get(int i) {
	if (i < 0 || i > size-1) {
		cout << "Invalid index." << endl;
		return '\0';
	}

	Node* p = top;
	for (int j=0; j<i; ++j) {
		p = p->next;
	}

	return p->data;
}

bool isPalindrome(string f0) {
	StackLL f1;
	for (int i=0; i<f0.length(); ++i) {
		f1.push(f0[i]);
	}

	for (int i=0; i<f0.length(); ++i) {
		if (f0[i] != f1.get(0)) {
			return false;
		}
		f1.pop();
	}

	return true;
}

class Node {
	public:
	string name;
	string phone_number;
	string issue;

	Node* next;

	void print() {
		cout << "Name: " << name << endl;
		cout << "Phone Number: " << phone_number << endl;
		cout << "Issue: " << issue << endl;
	}
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

		void queue(string n, string p_n, string i);
		void addToFront(string n, string p_n, string i);
		void dequeue();
		void empty();
		void display();
};

void QueueLL::queue(string n, string p_n, string i) {
/*
 * Creates a new node and adds it to the end of the queue.
 */

	if (isPalindrome(n)) {
		addToFront(n, p_n, i);
		return;
	}

	Node* new_node = new Node;
	new_node->name = n;
	new_node->phone_number = p_n;
	new_node->issue = i;

	if (size == 0) {
		new_node->next = NULL;
		front = new_node;
	} else {
		new_node->next = back;
	}
	back = new_node;
	++size;
}

void QueueLL::addToFront(string n, string p_n, string i) {
	Node* new_node = new Node;
	new_node->name = n;
	new_node->phone_number = p_n;
	new_node->issue = i;
	new_node->next = NULL;

	if (size == 0) {
		front = new_node;
		back = new_node;
	} else {
		front->next = new_node;
		front = new_node;
	}

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
		(*p).print();
		cout << endl;
		p=p->next;
	}
}

int main() {
	QueueLL issueList;
	string dummyName = "aaaaaa";
	for (int i=0; i<12; ++i) {
		string foo = dummyName;
		foo[5] += i;
		issueList.queue(foo, "99999", "screen doesn't work :(");
	}

	issueList.queue("ayush", "9999", "foo");
	issueList.queue("Ayush", "666", "flu");
	issueList.queue("Sing", "555", "cold");

	issueList.queue("LookAkooL", "0000", "Look I am a palindrome");
	issueList.queue("WooW", "0000", "I am not very imaginative");

	issueList.display();

	return 0;
}
