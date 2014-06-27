/*
 * WordList.h
 *
 *  Created on: May 8, 2014
 *      Author: mike
 */

#include <string>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <assert.h>

#ifndef WORDLIST_H_
#define WORDLIST_H_

class WordList {

public:
	explicit WordList(std::string);
	std::ostream& print(std::ostream&, std::string = std::string());	// Print list to cout or fout
	const int getSize();

private:
	// helper class to store details of a word
	class WordData {
	public:
		WordData(std::string, int);
		void append(int); 								// Append a given number to the list line numbers, incrementing the frequency.
		const int& getFrequency() const;				// Get frequency count.
		const std::string& getWord() const;				// Get a read-only pointer to the stored word.
		const std::vector<int>& getLinesNumbers() const;// Get a read-only reference to the IntList object.
		int compare(const std::string) const;			// Determine whether the stored word compares equal to, or comes before or after a given word. Use case insensitive alphabetical ordering of strings of characters when comparing two words.
		std::ostream& printWord(std::ostream&) const; 	// Print the word to cout or fout
	private:
		std::string word;
		int frequency;
		std::vector<int> lineNumbers;
	};

	std::list<WordData> wordList;
	std::string fileName;
	const std::string getFileName() const;
	void loadList();				// Load this list using the words in the input file
	void addWord(std::string, int);	// Reflect a given word and its corresponding line numbers into this list
	std::ostream& printAll(std::ostream&);	// Print list to cout or fout
};

#endif /* WORDLIST_H_ */
