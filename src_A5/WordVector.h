/*
 * WordVector.h
 *
 *  Created on: Aug 11, 2014
 *      Author: Mike
 */

#ifndef WORDVECTOR_H_
#define WORDVECTOR_H_

#include "MyPair.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class WordVector {
public:
	explicit WordVector( std::istream& );
	void insert( string );  // insert a word into the word vector
	bool remove( string ); // remove a word from the vector, return true if word was removed and false if it was never present.
	int lookup( string ) const; // look for a word, and return it's frequency.
	int size() const; // returns the size of the container.
	int sum_frequency_count() const; // returns the number of words in the file.
	void operator()( string ); // function operator to insert a word into the vector.
	void print() const; // outputs the list of words and of their frequencies.
	void sort(); // sorts the vector into alphabetical order.

private:
	vector< MyPair<string, int> > words;
};

#endif /* WORDVECTOR_H_ */
