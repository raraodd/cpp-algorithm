/*
 * Person.cpp
 *
 *  Created on: Feb 6, 2016
 *      Author: wendyp
 */

#include "Person.h"

Person::Person() {
	// TODO Auto-generated constructor stub
	name = "George";

}

string Person::toString(){
	return "Person's name is: " + name;
}

void Person::setName(string newName){
	name = newName;
}

string Person::getName(){
	return name;
}
