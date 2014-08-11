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

WordVector::WordVector(std::istream& an_input_stream) : words() {
	istream_iterator<string> start( an_input_stream ), finish;
	*this = for_each( start, finish, *this);
}

void WordVector::insert(string word) {
	MyPair<string, int> p(word, 1);
	auto vit = find( words.begin(), words.end(), p);
	if (vit != words.end()) ++vit->second;
	else words.push_back(p);
}

bool WordVector::remove(string word) {
	MyPair<string, int> p(word, 0);
	auto found = find(words.begin(), words.end(), p);
	if (found == words.end()) return false;
	words.erase(found);
	return true;
}

int WordVector::lookup(string word) const {
	MyPair<string, int> p(word, 0);
	auto found = find(words.begin(), words.end(), p);
	if (found == words.end()) return 0;
	return found->second;
}

int WordVector::size() const {
	return words.size();
}

int WordVector::sum_frequency_count() const {
	return accumulate(words.begin(), words.end(), 0,
					[](int acc, pair<string, int> word){ return acc + word.second; } );
}

void WordVector::operator ()(string word) {
	insert(word);
}

void WordVector::print() const {
	for_each(words.begin(), words.end(),
			[](pair<string, int> word){
				stringstream ss;
				ss << setw(3) << word.second << " : " << word.first;
				cout << ss.str() << endl;
			}
	);
}

void WordVector::sort() {
	std::sort(words.begin(), words.end(), MyPair<string, int>());
}

