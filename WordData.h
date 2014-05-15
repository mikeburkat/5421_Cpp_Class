/*
 * WordData.h
 *
 *  Created on: May 15, 2014
 *      Author: mike
 */

#include "IntList.h"

#ifndef WORDDATA_H_
#define WORDDATA_H_

class WordData {
public:
	WordData();
	virtual ~WordData();

	void append(int);// Append a given number to the list line numbers, incrementing the frequency.
	int getFrequency() const;// Get frequency count.
	char* getWord() const;// Get a read-only pointer to the stored word.
	IntList* getLinesNumbers() const;// Get a read-only reference to the IntList object.
	int equals(WordData) const;// Determine whether the stored word compares equal to, or comes before or after a given word. Use case insensitive alphabetical ordering of strings of characters when comparing two words.
	void print(std::ostream &) const;// Print the word together with its frequency count and list of line numbers to a specified ostream object (like cout).


private:
	char *wordPtr[];
	int frequency;
	IntList linesNumbers;

};


#endif /* WORDDATA_H_ */
