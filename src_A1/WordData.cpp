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

//---------------------------------------------------------

WordData::WordData(std::string word, int lineNumber) {
//	std::cout << "new WordData" << std::endl;
	wordPtr = new char[word.length() + 1];
	std::strcpy(wordPtr, word.c_str());
	setLength();
	frequency = 0;
	lineNumbers = IntList();
	append(lineNumber);
}

//---------------------------------------------------------

WordData::WordData(const WordData& wd) {
  // std::cout<< "Copy Construct: Word Data" <<std::endl;
	copy(wd);
}

//---------------------------------------------------------

void WordData::operator =(const WordData& wd) {
	if (this == &wd) {
//		std::cout<<"Self Assignment Prevented"<<std::endl;
		return;
	}
	copy(wd);
}

//---------------------------------------------------------

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

//---------------------------------------------------------

WordData::~WordData() {
//	std::cout << "delete WordData" << std::endl;
	delete[] wordPtr;
}

//---------------------------------------------------------

std::ostream& operator<<(std::ostream& co, const WordData& wd) {

	const char* const wordPtr = wd.getWord();
	co << std::right << std::setw(15) << wordPtr;
	co << "  (" << wd.getFrequency() << ")" ;
	co << " " << *wd.getLinesNumbers() << std::endl;
	return co;
}

//---------------------------------------------------------

void WordData::append(int lineNumber) {
	frequency++;
	lineNumbers.append(lineNumber);
}

//---------------------------------------------------------

const int WordData::getFrequency() const {
	return frequency;
}

//---------------------------------------------------------

const char* const WordData::getWord() const {
	return wordPtr;
}

//---------------------------------------------------------

const IntList* const WordData::getLinesNumbers() const {
	return &lineNumbers;
}

//---------------------------------------------------------

void WordData::setLength() {
	int i = 0;
	while (wordPtr[i] != '\0') {
		i++;
	}
	length = i;
}

//---------------------------------------------------------

const int WordData::getLength() const {
	return length;
}

//---------------------------------------------------------

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

//---------------------------------------------------------

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

//---------------------------------------------------------

void WordData::wordDataTests() {
	std::cout << "=======WORD DATA TESTS======="<<std::endl;
	std::cout << "test word data creation and append same line number twice"<<std::endl;
	std::string s = "mike";
	WordData wd(s, 0);
	wd.append(1);
	wd.append(1);
	std::cout << wd << std::endl;

	std::cout << "test word data compare function" <<std::endl;
	std::string a = "a";
	WordData aWD(a, 0);
	std::string b = "bas";
	WordData bWD(b, 0);
	std::string b2 = "bas";
	WordData b2WD(b2, 0);
	std::cout << aWD.compare(bWD) << " expecting -1" <<std::endl;
	std::cout << bWD.compare(aWD) << " expecting 1" <<std::endl;
	std::cout << bWD.compare(b2WD) << " expecting 0" << std::endl;
	std::cout << std::endl;

	std::cout << "test word data copy constructor" <<std::endl;
	std::string o = "sameString";
	WordData newWord(o, 1);
	newWord.append(10);
	newWord.append(10);
	WordData copy(newWord);
	std::cout << newWord << copy << std::endl;

	std::cout << "test word data assignment operator" <<std::endl;
	std::string ori = "ori";
	WordData original(ori, 5);
	std::string diff = "different";
	WordData different(diff, 2);
	different.append(3);
	std::cout << original;
	std::cout << different;
	original = different;
	std::cout << original;

}

//---------------------------------------------------------
