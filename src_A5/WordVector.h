/*
 * WordVector.h
 *
 *  Created on: Aug 11, 2014
 *      Author: Mike
 */

#ifndef WORDVECTOR_H_
#define WORDVECTOR_H_

#include "MyPair.h"
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;

class WordVector {
public:
	explicit WordVector( std::istream& );
	void insert( string );
	bool remove( string );
	int lookup( string ) const;
	int size() const;
	int sum_frequency_count() const;
	void operator()( string );
	void print() const;
	void sort();

private:
	vector< MyPair<string, int> > words;
};



#endif /* WORDVECTOR_H_ */
