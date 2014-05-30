/*
 * WordData.cpp
 *
 *  Created on: May 15, 2014
 *      Author: mike
 */

#include "WordData.h"
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>

WordData::WordData(std::string word) {
//	std::cout << "new WordData" << std::endl;
	wordPtr = new char[word.length() + 1];
	std::strcpy(wordPtr, word.c_str());
	setLength();
	frequency = 0;
	lineNumbers = IntList();
}

WordData::WordData(const WordData& wd) {
  // std::cout<< "Copy Construct: Word Data" <<std::endl;
	copy(wd);
}

void WordData::operator =(const WordData& wd) {
	if (this == &wd) {
//		std::cout<<"Self Assignment Prevented"<<std::endl;
		return;
	}
	copy(wd);
}



void WordData::copy(const WordData& wd) {
	frequency = wd.getFrequency();
	lineNumbers = *wd.getLinesNumbers();
	length = wd.getLength();

	wordPtr = new char[length+1];
	const char* const tempPtr = wd.getWord();
	for (int i = 0; i < length + 1; i++){
		wordPtr[i] = tempPtr[i];
	}
}

WordData::~WordData() {
//	std::cout << "delete WordData" << std::endl;
	delete[] wordPtr;
}

std::ostream& operator<<(std::ostream& co, const WordData& wd) {

	const char* const wordPtr = wd.getWord();
	co << std::right << std::setw(15) << wordPtr;
	co << "  (" << wd.getFrequency() << ")" ;
	co << " " << *wd.getLinesNumbers() << std::endl;
	return co;
}
void WordData::append(int lineNumber) {
	frequency++;
	lineNumbers.append(lineNumber);
}

const int WordData::getFrequency() const {
	return frequency;
}

const char* const WordData::getWord() const {
	return wordPtr;
}

const IntList* const WordData::getLinesNumbers() const {
	return &lineNumbers;
}

void WordData::setLength() {
	int i = 0;
	while (wordPtr[i] != '\0') {
		i++;
	}
	length = i;
}

const int WordData::getLength() const {
	return length;
}

int WordData::compare(const WordData& other) const {
	const char* const thisWord = getWord();
	const char* const otherWord = other.getWord();

	int i = 0;
	while (thisWord[i] != '\0' || otherWord[i] != '\0') {
		int comp = compareChars(thisWord[i], otherWord[i]);
		if (comp != 0) return comp;
		i++;
	}
	return 0;
}

int WordData::compareChars(char one, char two) const {
//	std::cout << one << " " << two << std::endl;

	one = tolower(one);
	two = tolower(two);

	if (one == two) {
		return 0;
	} else if (one == '\0') {
		return -1;
	} else if (two == '\0') {
		return 1;
	} else if (one < two) {
		return -1;
	} else {
		return 1;
	}
}
