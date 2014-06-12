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

void wordDataTests() {

	WordList::WordData w1("first", 2);
	w1.append(3);
	w1.append(3);
	cout << w1 << endl;

	cout << w1.compare("second") << endl;
	cout << w1.compare("first") << endl;
	cout << w1.compare("another") << endl;

}


int main(void) {
	WordList wordlist("src_A2/Seuss.txt");

	wordDataTests();

//	ofstream fout("SeussWordList.txt");
//	assert(fout.good());
//	wordlist.print(fout);
//	wordlist.print(fout, "wh");
//	wordlist.print(fout, "the");
//	fout.close();

	return 0;
}
