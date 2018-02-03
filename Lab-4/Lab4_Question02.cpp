/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 4 Assignment
 */

#include<iostream>
using namespace std;

class Array {
/*
 * User defined Array class. Keeps track of number of elements.
 * Possible to resize the array.
 * Also is very cool.
 */
	public:
	int* a;
	int size;		// Keeps track of number of elements in the array.

	Array (int s) {
		size = s;
		a = new int[size];
	}

	Array () {
		size = 1;
		a = new int[size];
	}

	int& operator[](int i) {	// Overloaded [] to index elements of Array
		return a[i];			// like normal arrays.
	}

	Array& operator=(Array &b) {	// = needs to be overloaded
		if (a != NULL)				// because the class contains a pointer.
			delete [] a;
		a = b.a;
		b.a = NULL;
		size = b.size;
		return *this;
	}
};

class ArrayStack {
/*
 * Implementation of the ArrayStack interface.
 * Contains an Array (backing array) and an integer, n to keep track of 
 * the number of elements of the Stack.
 */
	Array a; 						// backing array
	int n=0;						// track the number of elements

	friend class DoubleArrayQueue;	// Allows access of variables from within
									// DoubleArrayQueue

	void resize() {
		/*
		 * Function to resize the backing array.
		 * It is made sure that the backing array is at most twice
		 * the size of the stack.
		 */
		Array b (max(2*n, 1));
		for (int i=0; i<n; ++i) {
			b[i] = a[i];
		}

		a = b;
	}

	public:
	int size();
	int get(int k);
	void push(int x);
	void pop();
	void empty();
	void display();
};

int ArrayStack::size() {
/*
 * Returns the number of elements in the stack.
 */
	return n;
}

int ArrayStack::get(int k) {
/*
 * Returns the kth element of the stack
 * Returns zero if the index is invalid.
 */
	if (k < 0 || k > size() - 1) {		// Enforces bounds of k
		cout << "Invalid index." << endl;
		return 0;
	}

	return a[k];
}

void ArrayStack::push(int x) {
/*
 * Adds an element to the top of the stack.
 */
	if (a.size < n+1) {
		resize();
	}

	a[n] = x;
	++n; 				// Increment to keep up with the number of elements.
}

void ArrayStack::pop() {
/*
 * Deletes the element at the top of the stack.
 * Done by decrementing n; decreasing n by 1 ends the list
 * one place before than it did earlier.
 */
	if (n == 0) {		// Check for empty list.
		cout << "List empty. Nothing to do." << endl;
		return;
	}

	a[n] = a[n+1];
	--n;				

	if (a.size >= 3*n)
		resize();
}

void ArrayStack::empty() {
/*
 * Deletes all elements of the stack.
 */
	if (n == 0) {		// Check for empty list.
		cout << "List empty. Nothing to do." << endl;
		return;
	}

	while (n > 0) {
		pop();
	}
}

void ArrayStack::display() {
/* 
 * Displays all the elements of the stack.
 * Starts from the bottom, goes to the top.
 */
	if (n == 0) {		// Check for empty list.
		cout << "List empty. Nothing to do." << endl;
		return;
	}

	for (int i=0; i<n; ++i) {
		cout << a[i] << "->";
	}
	cout << "NULL" << endl;
}

class DoubleArrayQueue {
/* 
 * Implementation of Queue interface using two Stacks.
 * Consists of two stacks: one for the first half of the queue,
 * the other for the last half of the queue.
 * Both queue() and dequeue() operations take linear time.
 *
 */

	ArrayStack front;		// dequeue() operation happens here.
	ArrayStack back;		// queue() operation happens here.

	public:
	int size() {			// Returns the total number of elements in the queue
		return front.size() + back.size();
	}
	
	int get(int i);
	void balance();
	void queue(int x);
	void dequeue();
	void empty();
	void display();
};

int DoubleArrayQueue::get(int i) {
/*
 * Returns the ith element of the queue
 */

	if (i < front.size()) {
		return front.get(front.size() - i - 1);
	} else {
		return back.get(i - front.size());
	}
}

void DoubleArrayQueue::balance() {
/*
 * Ensures that the number of elements in front/back are not less
 * than a third of the elements in back/front.
 * Calling balance() after every add, delete operation keeps the
 * list balanced.
 */
	if (3*front.size() < back.size() ||
			3*back.size() < front.size()) {

		int n = size();			// total number of elements in queue.
		int nf = n/2;		// number of elements desired in front.
		Array af (max(2*nf, 1));	// dummy array for front.
		for (int k=0; k<nf; ++k) {
			af[nf-k-1] = get(k);
		}

		int nb = n - nf;	// number of elements desired in back.
		Array ab (max(2*nb, 1));	// dummy array for back.
		for (int k=0; k<nb; ++k) {
			ab[k] = get(nf+k);
		}

		front.a = af;
		front.n = nf;
		back.a = ab;
		back.n = nb;
	}
}

void DoubleArrayQueue::queue(int x) {
/*
 * Adds an element to the end of the queue.
 */
	back.push(x);
	balance(); 
}

void DoubleArrayQueue::dequeue() {
/*
 * Removes an element from the front of the queue.
 */
	if (size() == 0) {		// Check for empty queue.
		cout << "Empty queue. Nothing to do." << endl;
		return;
	}

	front.pop();
	balance();
}

void DoubleArrayQueue::empty() {
/*
 * Deletes all elements of the queue.
 */
	if (size() == 0) {		// Check for empty queue.
		cout << "Queue already empty. Nothing to do." << endl;
		return;
	}

	front.empty();
	back.empty();
}

void DoubleArrayQueue::display() {
/* 
 * Displays all the elements of the queue,
 * from front to back.
 */
	if (size() == 0) {		// Check for empty queue.
		cout << "Empty queue. Nothing to display." << endl;
		return;
	}

	for (int i=0; i<size(); ++i) {
		cout << get(i) << "->";
	}
	cout << "NULL" << endl;
}

int main() {
	DoubleArrayQueue foo;
	for (int i=0; i<20; ++i) {
		foo.queue(i+1);
	}

	foo.display();

	return 0;
}
