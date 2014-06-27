//============================================================================
// Name        : wordListDriver.cpp
// Author      : Michael Burkat
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include "WordList.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main(void) {
	WordList wordlist("Seuss.txt");

	wordlist.print(cout);
	wordlist.print(cout, "Wh");
	wordlist.print(cout, "the");

	ofstream fout("SeussWordList.txt");
	assert(fout.good());
	wordlist.print(fout);
	wordlist.print(fout, "wh");
	wordlist.print(fout, "the");
	fout.close();

	return 0;
}
