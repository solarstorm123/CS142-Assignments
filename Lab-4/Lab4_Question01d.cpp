/*
 * Ayush Singh (1711037)
 * Programming and Data Structures Laboratory II (2018)
 * Lab 4 Assignment
 */

#include<iostream>
using namespace std;

class Array {
	public:
	int* a;
	int size;

	Array (int s) {
		size = s;
		a = new int[size];
	}

	Array () {
		size = 1;
		a = new int[size];
	}

	int& operator[](int i) {
		return a[i];
	}

	Array& operator=(Array &b) {
		if (a != NULL)
			delete [] a;
		a = b.a;
		b.a = NULL;
		size = b.size;
		return *this;
	}
};

class ArrayQueue {
	Array a;
	int j=0;
	int n=0;

	void resize() {
		Array b (max(2*n, 1));
		for (int i=0; i<n; ++i) {
			b[i] = a[(i+j)%a.size];
		}

		a = b;
		j=0;
	}

	public:
	int size();
	void queue(int x);
	void dequeue();
	void empty();
	void display();
};

int ArrayQueue::size() {
	return n;
}

void ArrayQueue::queue(int x) {
	if (a.size < n+1)
		resize();

	a[(j+n)%a.size] = x;
	++n;
}

void ArrayQueue::dequeue() {
	if (n == 0) {
		cout << "Queue empty. Nothing to do." << endl;
		return;
	}

	j = (j+1) % a.size;
	--n;
	if (a.size >= 3*n)
		resize();
}

void ArrayQueue::empty() {
	if (n == 0)
		cout << "Queue already empty. Nothing to do." << endl;

	while (n > 0)
		dequeue();
}

void ArrayQueue::display() {
	if (n == 0) {
		cout << "Queue empty. Nothing to display." << endl;
		return;
	}

	for (int i=j; i<j+n; ++i) {
		cout << a[i%a.size] << "->";
	}
	cout << "NULL" << endl;
}

int main() {
	ArrayQueue foo;
	for (int i=0; i<10; ++i)
		foo.queue(i+1);

	foo.dequeue();
	foo.queue(15);
	foo.empty();
	foo.display();

	return 0;
}
