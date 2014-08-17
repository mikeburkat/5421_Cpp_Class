/*
 * WordVector.cpp
 *
 *  Created on: Aug 11, 2014
 *      Author: Mike
 */

#include "WordVector.h"
#include "MyPair.h"
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
using std::find;

/**
 * Constructor initializing the word vector.
 * @param an_input_stream, it's the file that will be analyzed for words and their frequencies.
 */
WordVector::WordVector(std::istream& an_input_stream) : words() {
	istream_iterator<string> start( an_input_stream ), finish;
	*this = for_each( start, finish, *this);
}

/**
 * Insert a word into the vector. If it's already present increment the frequency.
 * @param word to be inserted.
 */
void WordVector::insert(string word) {
	MyPair<string, int> p(word, 1);
	auto vit = find( words.begin(), words.end(), p);
	if (vit != words.end()) ++vit->second;
	else words.push_back(p);
}

/**
 * Remove a word from the vector. If it's removed sucesfully return true.
 * If the word was abscent from the vector return false.
 * @param word, the word to be removed.
 * @return boolean representing the succes or failure of removal.
 */
bool WordVector::remove(string word) {
	MyPair<string, int> p(word, 0);
	auto found = find(words.begin(), words.end(), p);
	if (found == words.end()) return false;
	words.erase(found);
	return true;
}

/**
 * Lookup a word in the vector. If found return the frequency of the word.
 * If missing return 0;
 * @param word, the word to be removed.
 * @return int representing the frequency of the word looked up.
 */
int WordVector::lookup(string word) const {
	MyPair<string, int> p(word, 0);
	auto found = find(words.begin(), words.end(), p);
	if (found == words.end()) return 0;
	return found->second;
}

/**
 * Get the size of the container.
 * @return the size.
 */
int WordVector::size() const {
	return words.size();
}

/*
 * Get the sum of all word frequencies.
 * @return the sum.
 */
int WordVector::sum_frequency_count() const {
	return accumulate(words.begin(), words.end(), 0,
					[](int acc, pair<string, int> word){ return acc + word.second; } );
}

/**
 * the function operator to be used with algorithms, to insert a word.
 * @param word, the word to be inserted.
 */
void WordVector::operator ()(string word) {
	insert(word);
}

/**
 * Prints the constents of the container to the output stream.
 */
void WordVector::print() const {
	for_each(words.begin(), words.end(),
			[](pair<string, int> word){
				stringstream ss;
				ss << setw(3) << word.second << " : " << word.first;
				cout << ss.str() << endl;
			}
	);
}

/**
 * Sort the vector based on a MyPair comparison.
 */
void WordVector::sort() {
	std::sort(words.begin(), words.end(), MyPair<string, int>());
}

