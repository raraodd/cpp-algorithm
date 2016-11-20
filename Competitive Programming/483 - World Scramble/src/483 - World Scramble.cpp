//============================================================================
// Name        : 483.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
using namespace std;

void worldScramble(string word){
}

int main() {

	string String;

	while(getline (cin,String) != EOF){

		int len = String.size();
		int count = 0;
		string subword;

		for(int i=0; i<len; i++){
			cout << String[i];
			if(String[i] == ' '){
				worldScramble(subword);
				cout << subword;
				subword = "";
				count = 0;
			}
			else{
				subword[count] = String[i];
				count++;
			}
		}
	}
	return 0;
}
