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
public: // Move to private later
	class WordData {
	friend std::ostream& operator<<(std::ostream&, const WordData&); // overloaded stream insertion operator
	friend std::ofstream& operator<<(std::ofstream&, const WordData&); // overloaded stream insertion operator
	public:
		explicit WordData(std::string, int);	//	Constructor
		void append(int); // Append a given number to the list line numbers, incrementing the frequency.
		const int& getFrequency() const;				// Get frequency count.
		const std::string& getWord() const;	// Get a read-only pointer to the stored word.
		const std::vector<int>& getLinesNumbers() const;// Get a read-only reference to the IntList object.
		int compare(const std::string) const;			// Determine whether the stored word compares equal to, or comes before or after a given word. Use case insensitive alphabetical ordering of strings of characters when comparing two words.

	private:
		std::string word;
		int frequency;
		std::vector<int> lineNumbers;
	};

public: // should be made private later
	static int size;					// The size of the list
	std::list<WordData> wordList;
	std::string fileName;
	void setFileName(std::string);
	const std::string getFileName() const;
	void loadList();								// Load this list using the words in the input file
	std::string getWordNodeOf(const std::string) const;	// Get a pointer to the node whose word data object stores a given word
	void addWord(std::string, int);		// Reflect a given word and its corresponding line numbers into this list
public:
	WordList(std::string);				//	Constructor
	std::ostream& print(std::ostream&);	// Print list to cout.
	std::ostream& print(std::ostream&, std::string);		// Print list to cout.
	std::ofstream& print(std::ofstream&); 	// Print the list in the required format.
	std::ofstream& print(std::ofstream&, std::string); 	// Print the list in the required format.
	static int getSize();				// Get the size of the list

};

#endif /* WORDLIST_H_ */

