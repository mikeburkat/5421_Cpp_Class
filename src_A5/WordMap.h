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
	void insert( string );
	bool remove( string );
	int lookup( string ) const;
	int size() const;
	int sum_frequency_count() const;
	void operator()( string );
	void print() const;

private:
	map<string, int> words;
};




#endif /* WORDMAP_H_ */
