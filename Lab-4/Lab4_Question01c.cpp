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

int main() {
	ArrayStack foo;
	for (int i=0; i<20; ++i)
		foo.push(i+1);
	foo.empty();
	foo.pop();
	foo.display();
	return 0;
}
