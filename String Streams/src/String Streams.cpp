//============================================================================
// Name        : String.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>

using namespace std;

int main() {

	string name = "Bob";
	int age = 32;

	stringstream ss;

	ss << "Name is: ";
	ss << name;
	ss << endl;
	ss << "Age is: ";
	ss << age;

	string info = ss.str();

	cout << info << endl;

	return 0;
}
