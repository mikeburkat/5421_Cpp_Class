/*
 * MyPair.h
 *
 *  Created on: Aug 11, 2014
 *      Author: Mike
 */

#ifndef MYPAIR_H_
#define MYPAIR_H_

#include <string>
#include <utility>

/**
 * This class is used in combination with the WordVector to compare words when sorting.
 */
template<class K, class V>
class MyPair : public std::pair<K, V> {
public:
	MyPair(){};
	/**
	 * Constucts a pair object of the requires template classes.
	 */
	MyPair(const K& x, const V& y) : std::pair<K, V>(x, y) {};

	/**
	 * Compares two MyPair object for equality of their word.
	 * @param p1, is the first MyPair object
	 * @param p2, is the second MyPair object
	 * @return is the equality as boolean
	 */
	friend bool operator==(const MyPair& p1, const MyPair& p2) {
		return p1.first == p2.first;
	}

	/**
	 * Compares if first word is smaller than the second.
	 * @param p1, is the first MyPair object
	 * @param p2, is the second MyPair object
	 * @return is the comparison as boolean
	 */
	bool operator()(const MyPair& p1, const MyPair& p2) {
		return (p1.first < p2.first);
	}
};



#endif /* MYPAIR_H_ */
