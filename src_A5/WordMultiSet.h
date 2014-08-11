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
	explicit WordMultiSet( std::istream& );
	void insert( string );
	bool remove( string );
	int lookup( string ) const;
	int size() const;
	int sum_frequency_count() const;
	void operator()( string );
	void print() const;

	class CompareWords {
	public:
		bool operator()(string, string) const;
	};

private:
	multiset<string, CompareWords> words;
};


#endif /* WORDMULTISET_H_ */
