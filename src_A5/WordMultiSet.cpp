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

WordMultiSet::WordMultiSet( istream& an_input_stream ) {
	istream_iterator<string> start( an_input_stream ), finish;
	*this = for_each( start, finish, *this);
}


void WordMultiSet::insert(string word) {
	words.insert(word);
}


bool WordMultiSet::remove(string word) {
	return words.erase( word );
}


int WordMultiSet::lookup(string word) const {
	auto p = words.equal_range(word);
	return std::distance(p.first, p.second);
}


int WordMultiSet::size() const {
	return words.size();
}


int WordMultiSet::sum_frequency_count() const {
	return words.size();
}


void WordMultiSet::operator ()(string word) {
	this->insert( word );
}


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

bool WordMultiSet::CompareWords::operator ()(string s1, string s2) const{
	if (s1.length() == s2.length()) return s1 < s2;
	return s1.length() < s2.length();
}
