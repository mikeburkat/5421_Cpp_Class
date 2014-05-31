/*
 * WordData.h
 *
 *  Created on: May 15, 2014
 *      Author: mike
 */

#include "IntList.h"
#include <iostream>

#ifndef WORDDATA_H_
#define WORDDATA_H_

class WordData {

	friend std::ostream& operator<<(std::ostream&, const WordData&); // overloaded stream insertion operator

public:
	explicit WordData(std::string, int);	//	Constructor
	WordData(const WordData&);				//	Copy Constructor
	void operator=(const WordData&);		//	Assignment operator
	virtual ~WordData();					//	Destructor

	void append(int);							// Append a given number to the list line numbers, incrementing the frequency.
	const int getFrequency() const;				// Get frequency count.
	const char* const getWord() const;			// Get a read-only pointer to the stored word.
	const IntList* const getLinesNumbers() const;// Get a read-only reference to the IntList object.
	int compare(const WordData&) const;			// Determine whether the stored word compares equal to, or comes before or after a given word. Use case insensitive alphabetical ordering of strings of characters when comparing two words.
	std::ostream& print(std::ostream&) const;	// Print the word together with its frequency count and list of line numbers to a specified ostream object (like cout).
	void wordDataTests(); // You can run my automated test to see that my program meets the requirements.

private:
	char* wordPtr;		// A pointer to a dynamically allocated array of char that stores a word
	int frequency;		// The frequency count of the word
	int length;
	IntList lineNumbers;// An IntList object storing a list of line numbers associated with the word
	int compareChars(const char, const char) const;
	void copy(const WordData&);
	void setLength();
	const int getLength() const;
};

#endif /* WORDDATA_H_ */
