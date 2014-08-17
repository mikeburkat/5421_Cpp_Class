/*
 * WordMap.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: Mike
 */

#include "WordMap.h"
#include <string>
#include <map>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <iterator>
#include <numeric>
#include <algorithm>


using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::istream;
using std::istream_iterator;
using std::ostream_iterator;
using std::accumulate;
using std::for_each;
using std::pair;
using std::setw;

/**
 * Constructor initializing the word map.
 * @param an_input_stream, it's the file that will be analyzed for words and their frequencies.
 */
WordMap::WordMap( istream& an_input_stream ) {
	istream_iterator<string> start( an_input_stream ), finish;
	*this = for_each( start, finish, *this);
}

/**
 * Insert a word into the map. If it's already present increment the frequency.
 * @param word to be inserted.
 */
void WordMap::insert( string word ) {
	words[word]++;
}

/**
 * Remove a word from the map. If it's removed sucesfully return true.
 * If the word was abscent from the vector return false.
 * @param word, the word to be removed.
 * @return boolean representing the succes or failure of removal.
 */
bool WordMap::remove( string word ) {
	return words.erase( word );

}

/**
 * Lookup a word in the map. If found return the frequency of the word.
 * If missing return 0;
 * @param word, the word to be removed.
 * @return int representing the frequency of the word looked up.
 */
int WordMap::lookup( string word ) const {
	auto it = words.find( word );
	if ( it == std::end(words) ) return 0;
	return it->second;
}

/*
 * Get the sum of all word frequencies.
 * @return the sum.
 */
int WordMap::sum_frequency_count() const {
	return accumulate(words.begin(), words.end(), 0,
				[](int acc, pair<string, int> word){ return acc + word.second; } );
}

/**
 * Get the size of the container.
 * @return the size.
 */
int WordMap::size() const {
	return words.size();
}

/**
 * the function operator to be used with algorithms, to insert a word.
 * @param word, the word to be inserted.
 */
void WordMap::operator ()( string word ) {
	this->insert( word );
}

/**
 * Prints the constents of the container to the output stream.
 */
void WordMap::print() const {
	for_each(words.begin(), words.end(),
			[](pair<string, int> word){
				stringstream ss;
				ss << setw(3) << word.second << " : " << word.first;
				cout << ss.str() << endl;
			}
	);
}
