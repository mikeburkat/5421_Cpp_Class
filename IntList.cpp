/*
 * IntList.cpp
 *
 *  Created on: May 15, 2014
 *      Author: mike
 */

#include "IntList.h"
#include <iostream>

//---------------------------------------------------------

IntList::IntList(int sizeParam) {
//	std::cout<< "Construct: IntList" <<std::endl;

	capacity = sizeParam;
	intPtr = new int[sizeParam];
	size = 0;
}

//---------------------------------------------------------

IntList::IntList(const IntList& iL) {
	copy(iL);
}

//---------------------------------------------------------

void IntList::operator=(const IntList& iL) {
//	std::cout<<"assignment operator"<<std::endl;
	if (this == &iL) {
//		std::cout<<"Self Assignment Prevented"<<std::endl;
		return;
	}
	copy(iL);
}

//---------------------------------------------------------

IntList::~IntList() {
//	std::cout<< "Destroy: IntList" <<std::endl;
	delete [] intPtr;
}

//---------------------------------------------------------

std::ostream& operator<<(std::ostream& co, const IntList& iL) {

	//co << "(" << iL.getSize() << ") " ;
	//co << "(" << iL.getCapacity() << ") " ;

	for (int i = 0; i < iL.size; i++) {
		co << " " << iL.getIndex(i);
	}
	return co;
}

//---------------------------------------------------------

void IntList::copy(const IntList& iL) {
//	std::cout<<"copy function"<<std::endl;
	capacity = iL.getCapacity();
	size = iL.getSize();
	intPtr = new int[getCapacity()];

	for (int i = 0; i < iL.getSize(); i++) {
			setIndex(i, iL.getIndex(i));
	}
}

//---------------------------------------------------------

void IntList::append(int lineNumber) {
	if (isPresent(lineNumber)) return;

	setIndex(size++, lineNumber);

	if (isFull()) {
		doubleSize();
	}
}

//---------------------------------------------------------

void IntList::doubleSize() {

	capacity *= 2;
	const int* temp = getPtr();
	intPtr = new int[getCapacity()];
	for (int i = 0; i <= getSize(); i++) {
		setIndex(i, temp[i]);
	}
	delete[] temp;
}

//---------------------------------------------------------

const int IntList::getCapacity() const {
	return capacity;
}

//---------------------------------------------------------

const int IntList::getSize() const {
	return size;
}

//---------------------------------------------------------

const int* const  IntList::getPtr() {
	return intPtr;
}

//---------------------------------------------------------

void IntList::setIndex(int index, int input) {
	if (index < capacity) {
		intPtr[index] = input;
	} else {
		std::cout << "Out of Bounds" << std::endl;
	}
}

//---------------------------------------------------------

const int IntList::getIndex(int index) const {
	if (index < size) {
		return intPtr[index];
	} else {
		std::cout << "Out of Bounds" << std::endl;
		return -1;
	}
}

//---------------------------------------------------------

bool IntList::isPresent(int x) const{
	for (int i = 0; i < size; i++) {
		if (getIndex(i) == x) {
			return true;
		}
	}
	return false;
}

//---------------------------------------------------------

bool IntList::isEmpty() const {
	return (size == 0) ? true : false;
}

//---------------------------------------------------------

bool IntList::isFull() const {
	return (size == capacity) ? true : false;
}

//---------------------------------------------------------
