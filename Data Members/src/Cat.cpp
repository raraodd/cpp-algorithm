/*
 * Cat.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: wendyp
 */
#include <iostream>
#include "Cat.h"

using namespace std;

void Cat::speak() {

	if (happy) {
		cout << "Meouw!" << endl;
	}
	else {
		cout << "Ssstt!" << endl;
	}
}

void Cat::makeHappy(){
	happy = true;
}

void Cat::makeSad(){
	happy = false;
}
