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

int WordList::size = 0;

//---------------------------------------------------------

WordList::WordList(std::string x) {
	setFileName(x);

	// the list is loaded in the print function, since requirement
	// is to create an empty list.
}

//---------------------------------------------------------

void WordList::setFileName(std::string f) {
	fileName = f;
}

//---------------------------------------------------------

const std::string WordList::getFileName() const {
	return fileName;
}

//---------------------------------------------------------

int WordList::getSize() {
	return size;
}

//---------------------------------------------------------

std::ostream& WordList::print(std::ostream& co) {

	return co;
}

//---------------------------------------------------------

std::ostream& WordList::print(std::ostream& co, std::string s) {
//	// The list has to be loaded
//	loadList();
//
//	co << "Word Collection Source File: " << getFileName() << std::endl;
//	co << std::setw(28) << std::setfill('=') << "=" << std::endl;
//	co << std::setfill(' ');
//
//	WordList::WordNode* current = first;
//	char header = 'A';
//	co << "<" << header << ">" << std::endl;
//
//	for (int i = 0; i < size;) {
//		const char* const word = current->wordData.getWord();
//
//		if (tolower(word[0]) > tolower(header)) {
//			header += 1;
//			co << "<" << header << ">" << std::endl;
//		} else {
//			co << current->wordData;
//			current = current->next;
//			i++;
//		}
//	}
//
//	while (header < 'Z') {
//		header += 1;
//		co << "<" << header << ">" << std::endl;
//	}
//
	return co;
}

//---------------------------------------------------------

std::ofstream& WordList::print(std::ofstream& co) {

	return co;
}

//---------------------------------------------------------

std::ofstream& WordList::print(std::ofstream& co, std::string s) {

	return co;
}

//---------------------------------------------------------

void WordList::loadList() {
	std::ifstream fin(getFileName());

	if (fin.fail()) {
		std::cout << "File open operation failed." << std::endl;
		return;
	}

	std::string line, word;
	int j = 1;
	while (getline(fin, line)) {
		std::istringstream sin(line);

		while (sin >> word) {
//			std::cout << word << std::endl;

			// find first and last char that are not punctuation.
			int first = 0;
			int last = word.length() - 1;

			int i = first;
			while (i < last) {
				if (!ispunct(word[i])) {
					first = i;
					break;
				} else {
					i++;
				}
			}

			i = last;
			while (i > first) {
				if (ispunct(word[i])) {
					i--;
					last = i;
				} else {
					break;
				}
			}

//      std::cout << "f: " <<first << " l: " <<last<< std::endl;
			word = word.std::string::substr(first, last - first + 1);
//      std::cout << word << std::endl;

			addWord(word, j);
		}
		j++;
	}
	fin.close();
}

//---------------------------------------------------------

void WordList::addWord(std::string word, int lineNumber) {

	// check if equal
	// if larger insert here and return

	std::list<WordData>::iterator it;



}

//---------------------------------------------------------

std::string WordList::getWordNodeOf(const std::string) const {

//	WordList::WordNode* current = first;
//	while (current != nullptr) {
//		if (wd.compare(current->wordData) == 0) {
//			return current;
//		} else {
//			current = current->next;
//		}
//	}
	return "";
}

//---------------------------------------------------------

WordList::WordData::WordData(std::string s, int line) {
	word = s;
	lineNumbers.push_back(line);
	frequency = 0;
	frequency++;
}

//---------------------------------------------------------

const int& WordList::WordData::getFrequency() const {
	return frequency;
}

//---------------------------------------------------------

const std::string& WordList::WordData::getWord() const {
	return word;
}

//---------------------------------------------------------

const std::vector<int>& WordList::WordData::getLinesNumbers() const {
	return lineNumbers;
}

//---------------------------------------------------------

void WordList::WordData::append(int line) {
	frequency++;
	// since we read lines sequentially, we just need to check the last
	// number in the list to see if it's on the same line, if it is then return
	// else just add the new line to the back
	if (line == lineNumbers.back()) return;
	lineNumbers.push_back(line);
}

//---------------------------------------------------------

int WordList::WordData::compare(const std::string other) const {
	std::string wordLower = word;
	std::string otherLower = other;
	for (char& c : wordLower) c = std::tolower(c);
	for (char& c : otherLower) c = std::tolower(c);

	return otherLower.compare(wordLower);
}

//---------------------------------------------------------

std::ostream& operator<<(std::ostream& co, const WordList::WordData& wd) {
	co << std::right << std::setw(15) << wd.getWord();
	co << "  (" << wd.getFrequency() << ")";
	std::vector<int> lineNums = wd.getLinesNumbers();
	for (int i : lineNums ) co << " " << i;
	co << std::endl;

	return co;
}

