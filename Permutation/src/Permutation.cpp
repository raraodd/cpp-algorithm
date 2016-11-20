//============================================================================
// Name        : Permutation.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

using namespace std;

#include "Permutate.h"

bool except (int ResIdx, char result[], char item){
	for(int i=0; i<ResIdx; i++){
		if(result[i] == item)
			return true;
	}
	return false;
}

void permutation (int j, char result[], int x, char items[], int N){
	if(j < x){
		for(int i=0; i<N; i++){
			if(!except(j, result, items[i])){
				result[j] = items[i];
				if(j==x-1){
					for(int k=0; k<x; k++){
						cout << result[k] << " ";
					}
					cout << endl;
				}
				permutation(j+1,result,x,items,N);
			}
		}
	}
}

int main() {

	int N, x;

	cout << "PERMUTATION" << endl;
	cout << "Input N: " << flush;
	cin >> N;
	cout << "Input x: " << flush;
	cin >> x;

	cout << endl;
	cout << "Input the N items" << endl;
	cout << "=================" << endl;
	Permutate input;
	input.input(N);

//	Permutate
//	permutation(0,result,x,items,N);
	return 0;
}
