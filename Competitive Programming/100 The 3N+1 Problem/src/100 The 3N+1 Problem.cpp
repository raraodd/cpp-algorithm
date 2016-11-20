//============================================================================
// Name        : 100.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int cyclelength(int N){
	int count = 1;
	while(N!=1){
		count++;
		if(N%2==1){
			N = 3*N+1;
		}
		else{
			N = N/2;
		}
	}
	return count;
}

int main() {

	int i, j;
	while ( scanf ("%d %d", &i, &j) != EOF ){
		cout << i << " " << j << " ";
		if(i > j){
			int temp = i;
			i = j;
			j = temp;
		}
		int cycle_length;
		int max_cycle=0;

		for(int k=i; k<=j; k++){
			cycle_length = cyclelength(k);
			max_cycle = max(max_cycle, cycle_length);
		}

		cout << max_cycle;
		cout << endl;
	}

	return 0;
}
