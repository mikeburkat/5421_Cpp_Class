/*
 * WordMap.h
 *
 *  Created on: Aug 11, 2014
 *      Author: Mike
 */

#ifndef WORDMAP_H_
#define WORDMAP_H_

#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;

class WordMap {
public:
	explicit WordMap( std::istream& );
	void insert( string );  // insert a word into the word map.
		bool remove( string ); // remove a word from the map, return true if word was removed and false if it was never present.
		int lookup( string ) const; // look for a word, and return it's frequency.
		int size() const; // returns the size of the container.
		int sum_frequency_count() const; // returns the number of words in the file.
		void operator()( string ); // function operator to insert a word into the map.
		void print() const; // outputs the list of words and of their frequencies.

private:
	map<string, int> words;
};

#endif /* WORDMAP_H_ */
