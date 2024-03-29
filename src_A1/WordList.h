///*
// * WordList.h
// *
// *  Created on: May 8, 2014
// *      Author: mike
// */
//
//#include <string>
//#include <iostream>
//#include "WordData.h"
//
//#ifndef WORDLIST_H_
//#define WORDLIST_H_
//
//
//
//class WordList {
//private:
//	struct WordNode {
//		WordData wordData; 						// A WordData object
//		WordNode* next; 						// A pointer to a WordNode object
//		WordNode(WordData, WordNode* = nullptr);// A constructor that initializes the data members of the struct
//	};
//
//	WordNode* first;					// A pointer to the first node of the list;
//	WordNode* last;						// A pointer to the last node of the list;
//	static int size;					// The size of the list
//	std::string fileName;
//	void setFileName(std::string);
//	const std::string getFileName() const;
//	void copy(const WordList&);
//	void loadList();								// Load this list using the words in the input file
//	WordNode* getWordNodeOf(const WordData&) const;	// Get a pointer to the node whose word data object stores a given word
//	void addWord(std::string, int);		// Reflect a given word and its corresponding line numbers into this list
//
//
//public:
//	WordList(std::string);				//	Constructor
//	WordList(const WordList&);			//	Copy Constructor
//	void operator=(const WordList&);	//	Assignment operator
//	~WordList();						//	Destructor
//	std::ostream& print(std::ostream&); // Print the list in the required format after first loading it.
//	static int getSize();				// Get the size of the list
//
//};
//
//#endif /* WORDLIST_H_ */
//
