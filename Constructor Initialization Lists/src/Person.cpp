/*
 * Person.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: wendyp
 */

#include "Person.h"
#include <sstream>

Person::Person() {
	name = "undefined";
	age = 0;
}

Person::Person(string newName, int newAge) {
	this -> name = newName;
	this -> age = newAge;

	cout << "Memory location of object: " << this << endl;
}

Person::Person(string newName) {
	this -> name = newName;
	this -> age = 0;
}

string Person :: toString(){
	stringstream ss;

	ss << "Name: ";
	ss << name;
	ss << "; age:";
	ss << age;

	return ss.str();
}
