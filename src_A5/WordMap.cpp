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


WordMap::WordMap( istream& an_input_stream ) {
	istream_iterator<string> start( an_input_stream ), finish;
	*this = for_each( start, finish, *this);

}

void WordMap::insert( string word ) {
	words[word]++;
}


bool WordMap::remove( string word ) {
	return words.erase( word );

}


int WordMap::lookup( string word ) const {
	auto it = words.find( word );
	if ( it == std::end(words) ) return 0;
	return it->second;
}

int WordMap::sum_frequency_count() const {
	return accumulate(words.begin(), words.end(), 0,
				[](int acc, pair<string, int> word){ return acc + word.second; } );
}

int WordMap::size() const {
	return words.size();
}

void WordMap::operator ()( string word ) {
	this->insert( word );
}

void WordMap::print() const {
	for_each(words.begin(), words.end(),
			[](pair<string, int> word){
				stringstream ss;
				ss << setw(3) << word.second << " : " << word.first;
				cout << ss.str() << endl;
			}
	);
}
