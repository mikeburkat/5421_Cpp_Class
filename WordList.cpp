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
#include <string>

unsigned int size;

unsigned int getSize() {
	return size;
}

WordList::WordList(std::string x) {
	setFileName(x);
}

void WordList::readFile() {

}

void WordList::print(std::ostream & co) {
	co << getFileName() << std::endl;
}

void WordList::setFileName(std::string f) {
	fileName = f;
}

std::string WordList::getFileName() {
	return fileName;
}

