/*
 * Cat.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: wendyp
 */
#include <iostream>
#include "Cat.h"

using namespace std;

Cat::Cat(){
	cout << "Cat created." << endl;
	happy = true;
}

Cat::~Cat(){
	cout << "Cat destroyed." << endl;
	happy = false;
}

void Cat::speak(){

	if(happy){
		cout << "Meoow" << endl;
	}
	else
		cout << "Ssst!" << endl;
}

