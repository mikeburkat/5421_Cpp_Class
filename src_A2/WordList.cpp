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
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>
#include <list>
#include <algorithm>


//---------------------------------------------------------

WordList::WordList(std::string x) : fileName(x) {
	this->loadList();
}

//---------------------------------------------------------

const std::string WordList::getFileName() const {
	return this->fileName;
}

//---------------------------------------------------------

const int WordList::getSize() {
	return this->wordList.size();
}

//---------------------------------------------------------

std::ostream& WordList::printAll(std::ostream& co) {
	co << "Word Collection Source File: " << this->getFileName() << std::endl;
	co << std::setw(28) << std::setfill('=') << "=" << std::endl;
	co << std::setfill(' ');

	char header = 'A';
	co << "<" << header << ">" << std::endl;

	int here = 0;
	for (std::list<WordData>::iterator it = this->wordList.begin();
			it != this->wordList.end();) {

		const std::string word = it->getWord();

		if (tolower(word[0]) > tolower(header)) {
			header += 1;
			co << "<" << header << ">" << std::endl;
			here++;
		} else {
			it->printWord(co);
			it++;
		}
	}

	while (header < 'Z') {
		header += 1;
		co << "<" << header << ">" << std::endl;
	}

	co << std::setw(28) << std::setfill('=') << "=" << std::endl;
	co << std::setfill(' ');
	return co;
}

//---------------------------------------------------------

std::ostream& WordList::print(std::ostream& co, std::string prefix) {

	if (prefix.empty()) {
		return this->printAll(co);
	}

	co << "Word Collection Source File: " << this->getFileName() << std::endl;
	co << "Words that begin with \"" << prefix << "\"" << std::endl;
	co << std::setw(28) << std::setfill('=') << "=" << std::endl;
	co << std::setfill(' ');

	for (std::list<WordData>::iterator it = this->wordList.begin();
			it != this->wordList.end(); it++) {
		const std::string word = it->getWord();
		std::string preWord = word.substr(0, prefix.length());
		for (char& c : preWord)
			c = std::tolower(c);
		for (char& c : prefix)
			c = std::tolower(c);

		if (preWord.compare(prefix) == 0) {
			it->printWord(co);
		}
	}
	co << std::setw(28) << std::setfill('=') << "=" << std::endl;
	co << std::setfill(' ');
	return co;
}

//---------------------------------------------------------

void WordList::loadList() {
	std::ifstream fin(this->getFileName());

	if (fin.fail()) {
		std::cout << "File open operation failed." << std::endl;
		return;
	}

	std::string line, word;
	int j = 1;
	while (getline(fin, line)) {
		std::istringstream sin(line);

		while (sin >> word) {

			// find first and last char that are not punctuation.
			int first = 0;
			int last = word.length() - 1;

			int i = first;
			while (i < last && !isalpha(word[i])) {
				i++;
			}
			first = i;

			i = last;
			while (i > first && !isalpha(word[i])) {
				i--;
			}
			last = i;

			if (first == last && !isalpha(word[first])) {
				continue;
			}
			word = word.std::string::substr(first, last - first + 1);
			this->addWord(word, j);
		}
		j++;
	}
	fin.close();
}

//---------------------------------------------------------

void WordList::addWord(std::string newWord, int lineNumber) {
	int comp;

	for (std::list<WordData>::iterator it = this->wordList.begin();
			it != this->wordList.end(); it++) {
		comp = it->compare(newWord);
		if (comp == 0) { // if equal then the word is in the list so append line Number to it.
			it->append(lineNumber);
			return;
		} else if (comp < 0) { // if the word is now smaller than iterator stop and insert before the pointed word.
			this->wordList.insert(it, WordData(newWord, lineNumber));
			return;
		}
	}
	this->wordList.push_back(WordData(newWord, lineNumber));
}

//---------------------------------------------------------

WordList::WordData::WordData(std::string s, int line) : word(s), frequency(0) {
	this->lineNumbers.push_back(line);
	this->frequency++;
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
	this->frequency++;
	// since we read lines sequentially, we just need to check the last
	// number in the list to see if it's on the same line, if it is then return
	// else just add the new line to the back
	if (line == this->lineNumbers.back())
		return;
	this->lineNumbers.push_back(line);
}

//---------------------------------------------------------

int WordList::WordData::compare(const std::string other) const {
	std::string wordLower = this->word;
	std::string otherLower = other;
	for (char& c : wordLower)
		c = std::tolower(c);
	for (char& c : otherLower)
		c = std::tolower(c);

	return otherLower.compare(wordLower);
}

//---------------------------------------------------------

std::ostream& WordList::WordData::printWord(std::ostream& co) const{
	co << std::right << std::setw(15) << this->getWord();
	co << "  (" << this->getFrequency() << ")";
	std::vector<int> lineNums = this->getLinesNumbers();
	for (int i : lineNums)
		co << " " << i;
	co << std::endl << std::endl;

	return co;
}

//---------------------------------------------------------
