/*
 * WordMultiSet.h
 *
 *  Created on: Aug 11, 2014
 *      Author: Mike
 */

#ifndef WORDMULTISET_H_
#define WORDMULTISET_H_

#include <iostream>
#include <string>
#include <set>

using std::string;
using std::multiset;

class WordMultiSet {
public:
	explicit WordMultiSet(std::istream&);
	void insert(string);  // insert a word into the word multiset
	bool remove(string); // remove a word from the multiset, return true if word was removed and false if it was never present.
	int lookup(string) const; // look for a word, and return it's frequency.
	int size() const; // returns the size of the container.
	int sum_frequency_count() const; // returns the number of words in the file.
	void operator()(string); // function operator to insert a word into the multiset.
	void print() const; // outputs the list of words and of their frequencies.

	class CompareWords { // inner class used as a funtor for a custom word comparison.
	public:
		bool operator()(string, string) const;
	};

private:
	multiset<string, CompareWords> words;
};

#endif /* WORDMULTISET_H_ */
