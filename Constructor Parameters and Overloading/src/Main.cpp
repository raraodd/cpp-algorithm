//============================================================================
// Name        : Constructor.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Person.h"
using namespace std;

int main() {

	Person person;
	Person person1("Bob",20);
	Person person2("Barbie", 30);

	cout << person1.toString() << "; Memory location: " << &person1 << endl;
	cout << person2.toString() << "; Memory location: " << &person2 << endl;
	return 0;
}
