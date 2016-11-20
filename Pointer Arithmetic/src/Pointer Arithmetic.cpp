//============================================================================
// Name        : Pointer.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {

	const int N = 5;
	string texts[N] = {"one", "two", "three", "four", "five"};

	string *pTexts = texts;

	pTexts += 3;
	cout << *pTexts << endl;

	pTexts -= 2;
	cout << *pTexts << endl;

	string *pEnd = &texts[N];
	pTexts = &texts[0];

	while(pTexts != pEnd){
		cout << *pTexts << "\t" << pTexts << endl;
		pTexts++;
	}

	//Set pTexts back to start
	pTexts = &texts[0];

	long elements = (long)(pEnd - pTexts);

	cout << elements << endl;
	return 0;
}
