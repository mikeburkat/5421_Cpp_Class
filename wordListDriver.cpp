//============================================================================
// Name        : wordListDriver.cpp
// Author      : Michael Burkat
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include "WordList.h"
#include <iostream>
using namespace std;

int main(void) {
	WordList wl("input.txt");
	wl.print(cout);
	return 0;
}
