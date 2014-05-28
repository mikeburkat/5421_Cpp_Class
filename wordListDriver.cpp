//============================================================================
// Name        : wordListDriver.cpp
// Author      : Michael Burkat
// Version     :
// Copyright   : Your copyright notice
// Description :
//============================================================================

#include "WordList.h"
#include <iostream>
#include <string>
using namespace std;

#include "IntList.h"


void intListTests() {

	cout << "test append and capacity doubling"<<endl;
	IntList intList;
	cout << intList << "capacity: " << intList.getCapacity()<< endl;
	intList.append(1);
	cout << intList << "capacity: " << intList.getCapacity()<< endl;
	intList.append(2);
	cout << intList << "capacity: " << intList.getCapacity()<< endl;
	intList.append(3);
	cout << intList << "capacity: " << intList.getCapacity()<< endl;
	intList.append(4);
	cout << intList << "capacity: " << intList.getCapacity()<< endl;

	cout << "test prevent appending same line again"<<endl;
	intList.append(4);
	cout << intList << "capacity: " << intList.getCapacity()<< endl;
	cout << endl;

	cout << "test copy constructor"<<endl;
	IntList intList2(intList);
	cout << intList << "capacity: " << intList.getCapacity() << endl;
	cout << endl;

	cout << "test assignment operator"<<endl;
	IntList intList3;
	intList3 = intList2;
	cout << intList << "capacity: " << intList.getCapacity() << endl;
	cout << endl;
}

void wordDataTests() {
	cout << "test word data creation and append same line number twice"<<endl;
	string s = "mike";
	WordData wd(s);
	wd.append(1);
	wd.append(1);
	cout << wd << endl;

	cout << "test word data compare function" <<endl;
	string a = "a";
	WordData aWD(a);
	string b = "bas";
	WordData bWD(b);
	string b2 = "bas";
	WordData b2WD(b2);
	cout << aWD.compare(bWD) << " expecting -1" <<endl;
	cout << bWD.compare(aWD) << " expecting 1" <<endl;
	cout << bWD.compare(b2WD) << " expecting 0" << endl;
	cout << endl;

	cout << "test word data copy constructor" <<endl;
	string o = "sameString";
	WordData newWord(o);
	newWord.append(1);
	newWord.append(10);
	newWord.append(10);
	WordData copy(newWord);
	cout << newWord << copy << endl;

	cout << "test word data assignment operator" <<endl;
	string ori = "ori";
	WordData original(ori);
	original.append(5);
	string diff = "different";
	WordData different(diff);
	different.append(2);
	different.append(3);
	cout << original;
	cout << different;
	original = different;
	cout << original;

}



int main(void) {
	WordList wl("test.txt");
	//wl.print(cout);

	//intListTests();
	wordDataTests();

	return 0;
}


