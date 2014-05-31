//============================================================================
// Name        : wordListDriver.cpp
// Author      : Michael Burkat
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include "WordList.h"
#include "IntList.h"
#include "WordData.h"
#include <iostream>
#include <string>
using namespace std;


int main(void) {
	WordList wl("input.txt");
	wl.print(cout);

//	// Testing I wrote to verify that I my program met the requirement.
//	WordData wd("tests", 0);
//	wd.wordDataTests();
//
//	IntList il;
//	il.intListTests();

	return 0;
}
