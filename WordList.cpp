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
#include <cstring>

int WordList::size = 0;

int WordList::getSize() {
	return size;
}

WordList::WordList(std::string x) {
	setFileName(x);
	first = nullptr;
	last = nullptr;
	loadList();
}

WordList::~WordList() {
//	std::cout << "WordList Destructor." << std::endl;
	WordNode* previous = first;
	WordNode* current = first->next;
	for (int i = 0; i < size; i++) {
		delete previous;
		previous = current;
		current = current->next;
	}
}

void WordList::setFileName(std::string f) {
	fileName = f;
}

const std::string WordList::getFileName() const {
	return fileName;
}

std::ostream& WordList::print(std::ostream& co) const {
	co << "Word Collection Source File: " << getFileName() << std::endl;
	co << std::setw(28) << std::setfill('=') << "=" << std::endl;
	co << std::setfill(' ');

	WordList::WordNode* current = first;
	co << "size: " << size << std::endl;
	char header = 'A';
	co << "<" << header << ">" << std::endl;

	for (int i = 0; header < 'Z';) {
		const char* const word = current->wordData.getWord();

		if ( tolower(word[0]) > tolower(header) || i >= size) {
			header += 1;
			co << "<" << header << ">" << std::endl;
			co << i << std::endl;
		} else {
			co << current->wordData;
			current = current->next;
			i++;
			co << i << std::endl;
		}
	}
	return co;
}

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

void WordList::addWord(std::string word, int lineNumber) {
	WordData wd(word);

	// Check if it's already in the list, then just append the line number.
	WordList::WordNode* found = getWordNodeOf(wd);
	if (found != nullptr) {
//		std::cout << found->wordData << std::endl;
		found->wordData.append(lineNumber);
//		std::cout << found->wordData << std::endl;
		return;
	}
//	std::cout << "not found in word list" << std::endl;

// Createa a new node, and append the line number.
	WordList::WordNode* node = new WordList::WordNode(wd);
	node->wordData.append(lineNumber);

	// Check if the list is empty, then add.
	if (getSize() == 0) {
		first = node;
		last = node;
		size++;
//			std::cout << "inserted in null list" << std::endl;
		return;
	}

	// Check if it comes before the first node, then add.
	if (node->wordData.compare(first->wordData) < 0) {
		node->next = first;
		first = node;
		size++;
//		std::cout << "was smaller than first" << std::endl;
		return;
	}

	// Check if it comes before the last node, then add.
	if (node->wordData.compare(last->wordData) > 0) {
		last->next = node;
		last = node;
		size++;
//		std::cout << "was larger than last" << std::endl;
		return;
	}

	//Find where the the node fits, after the previous and before the current.
	WordList::WordNode* previous = first;
	WordList::WordNode* current = first->next;
	while (current != nullptr && current->wordData.compare(node->wordData) < 0) {
		previous = current;
		current = current->next;
	}

	// Add then node at the right position.
	previous->next = node;
	node->next = current;
	size++;

//	std::cout << "after: " << previous->wordData;
//	std::cout << "inserted: " << node->wordData;
//	std::cout << "before: " << current->wordData;
}

WordList::WordNode* WordList::getWordNodeOf(
		const WordList::WordNode& wd) const {

	WordList::WordNode* current = first;
	while (current != nullptr) {
		if (wd.wordData.compare(current->wordData) == 0) {
			return current;
		} else {
			current = current->next;
		}
	}
	return nullptr;
}

WordList::WordNode::WordNode(WordData wd, WordNode* ptrWd) :
		wordData(wd), next(ptrWd) {
}
