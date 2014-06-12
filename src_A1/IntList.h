/*
 * IntList.h
 *
 *  Created on: May 15, 2014
 *      Author: mike
 */
#include <iostream>

#ifndef INTLIST_H_
#define INTLIST_H_

class IntList {

	friend std::ostream& operator<<(std::ostream&, const IntList&); // overloaded stream insertion operator

public:
	explicit IntList(int = 1); 		// creates a list of a given size defaults to 1
	IntList(const IntList&); 		// copy constructor
	void operator=(const IntList&); // overloaded assignment operator
	~IntList();						// Destructor

	bool isEmpty() const; 			// Determine whether the list is empty.
	bool isFull() const;			// Determine whether the list is full.
	bool isPresent(int) const; 		// Determine whether a given element exists in the list.
	void append(int); 				// Append an element to the end of the list.
	const int getIndex(int) const; 	// Get an element at a specified position.
	void setIndex(int, int); 		// Set an element at a specified position.
	const int getSize() const; 		// Get size of the list.
	const int getCapacity() const; 	// Get capacity of the list.
	const int* const getPtr(); 		// Get a read-only pointer to the underlying array.
	void intListTests();

private:
	int* intPtr;		// A pointer to a dynamically allocated array of integer elements
	int size;			// The size of the list
	int capacity;		// The current capacity of the list

	void copy(const IntList&);
	void doubleSize();

};

#endif /* INTLIST_H_ */
