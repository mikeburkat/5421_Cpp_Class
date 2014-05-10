/*
 * WordList.h
 *
 *  Created on: May 8, 2014
 *      Author: mike
 */

#include <string>
#include <iostream>

#ifndef WORDLIST_H_
#define WORDLIST_H_


class WordList {
public:
	WordList(std::string);
	void readFile();
	void print(std::ostream & co);

private:
	std::string fileName;
	void setFileName(std::string f);
	std::string getFileName();

};


#endif /* WORDLIST_H_ */
