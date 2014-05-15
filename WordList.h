/*
 * WordList.h
 *
 *  Created on: May 8, 2014
 *      Author: mike
 */

#include <string>
#include <iostream>
#include "WordNode.h"

#ifndef WORDLIST_H_
#define WORDLIST_H_



class WordList {
public:
	WordList(std::string);
	void readFile();
	void print(std::ostream &) const;
	void loadList();
	void addWord(std::string);
	WordNode* getWordNodeOf();

	static unsigned int getSize() const;

private:
	std::string fileName;
	void setFileName(std::string);
	std::string getFileName();

	static unsigned int size;

};


#endif /* WORDLIST_H_ */
