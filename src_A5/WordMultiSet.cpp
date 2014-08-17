/*
 * WordMultiSet.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: Mike
 */

#include "WordMultiSet.h"
#include <string>
#include <set>
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
 * Constructor initializing the word multi set.
 * @param an_input_stream, it's the file that will be analyzed for words and their frequencies.
 */
WordMultiSet::WordMultiSet( istream& an_input_stream ) {
	istream_iterator<string> start( an_input_stream ), finish;
	*this = for_each( start, finish, *this);
}

/**
 * Insert a word into the multiset. If it's already present increment the frequency.
 * @param word to be inserted.
 */
void WordMultiSet::insert(string word) {
	words.insert(word);
}

/**
 * Remove a word from the multiset. If it's removed sucesfully return true.
 * If the word was abscent from the vector return false.
 * @param word, the word to be removed.
 * @return boolean representing the succes or failure of removal.
 */
bool WordMultiSet::remove(string word) {
	return words.erase( word );
}

/**
 * Lookup a word in the multiset. If found return the frequency of the word.
 * If missing return 0;
 * @param word, the word to be removed.
 * @return int representing the frequency of the word looked up.
 */
int WordMultiSet::lookup(string word) const {
	auto p = words.equal_range(word);
	return std::distance(p.first, p.second);
}

/**
 * Get the size of the container.
 * @return the size.
 */
int WordMultiSet::size() const {
	return words.size();
}

/*
 * Get the sum of all word frequencies.
 * @return the sum.
 */
int WordMultiSet::sum_frequency_count() const {
	return words.size();
}

/**
 * the function operator to be used with algorithms, to insert a word.
 * @param word, the word to be inserted.
 */
void WordMultiSet::operator ()(string word) {
	this->insert( word );
}

/**
 * Prints the constents of the container to the output stream.
 */
void WordMultiSet::print() const {
	string previous("");
	for_each(words.begin(), words.end(),
				[&previous, this](string word){
					if (previous == word) return;
					stringstream ss;
					ss << setw(3) << this->lookup(word) << " : " << word;
					cout << ss.str() << endl;
					previous = word;
				}
		);
}

/**
 * The compare words functor to keep the words in sorted order.
 * @param s1, first word to compare
 * @param s2, second word to compare
 * @return the result of the comparison.
 */
bool WordMultiSet::CompareWords::operator ()(string s1, string s2) const{
	if (s1.length() == s2.length()) return s1 < s2;
	return s1.length() < s2.length();
}
