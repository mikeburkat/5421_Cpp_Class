/*
 * IntList.h
 *
 *  Created on: May 15, 2014
 *      Author: mike
 */

#ifndef INTLIST_H_
#define INTLIST_H_

class IntList {
public:
	IntList();
	virtual ~IntList();

	bool isEmpty() const; // Determine whether the list is empty.
	bool isPresent() const; // Determine whether a given element exists in the list.
	void append(int); // Append an element to the end of the list.
	int getIndex(); // Get an element at a specified position.
	void setIndex(int, int); // Set an element at a specified position.
	int getSize(); // Get size of the list.
	int getCapacity(); // Get capacity of the list.
	IntList* getPtr(); // Get a read-only pointer to the underlying array.

private:
	IntList* ptr;
	int size;
	int capacity;


};

#endif /* INTLIST_H_ */
