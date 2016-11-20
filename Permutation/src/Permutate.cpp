/*
 * Permutate.cpp
 *
 *  Created on: Feb 9, 2016
 *      Author: wendyp
 */

#include "Permutate.h"

void Permutate :: input(int N){
	for(int i=0; i<N; i++){
		cout << "items[" << i+1 << "]: ";
		cin >> items[i];
	}
}
