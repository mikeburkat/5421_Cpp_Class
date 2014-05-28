/*
 * WordList.cpp
 *
 *  Created on: May 8, 2014
 *      Author: mike
 *
 *
 *
 */

#include "WordList.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>

unsigned int size;

unsigned int getSize() {
	return size;
}

WordList::WordList(std::string x) {
	setFileName(x);
	//loadList();
}

void WordList::setFileName(std::string f) {
	fileName = f;
}

const std::string WordList::getFileName() const{
	return fileName;
}

std::ostream& WordList::print(std::ostream& co) const{
	co << "Word Collection Source File: " << getFileName() << std::endl;
	co << std::setw(28) << std::setfill('=') << "=" << std::endl;

	return co;
}

void WordList::loadList() {
	std::ifstream fin(getFileName());

	if(fin.fail()) {
		std::cout << "File open operation failed." << std::endl;
		return;
	}

	std::string line, word;
	int i = 1;
	while ( getline(fin, line) ) {
		std::istringstream sin(line);

		while ( sin >> word ) {
			std::cout << word << std::endl;
			addWord(word, i);
		}
		i++;
	}
	fin.close();
}

void WordList::addWord(std::string word, unsigned int lineNumber) {

	WordData wd(word);
	WordList::WordNode* node = new WordList::WordNode(wd);


}

WordList::WordNode::WordNode(WordData wd, WordNode* ptrWd) : wordData(wd), next(ptrWd) {
}
