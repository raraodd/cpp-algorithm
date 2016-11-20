/*
 * Person.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: wendyp
 */

#include "Person.h"
#include <sstream>



string Person :: toString(){
	stringstream ss;

	ss << "Name: ";
	ss << name;
	ss << "; age:";
	ss << age;

	return ss.str();
}
