//============================================================================
// Name        : Fellowship.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int N;
int orcs[25], cost[25];

int mincost;

int mutate(int level, int total, int g[]){
	int pasukan = g[0] + g[1] + g[2] + g[3];
//	if(total>=mincost) return 0;
	if(level == N){
		mincost = min(mincost,total);
		return 1;
	}
	//hire
	int guard[4] = {g[0]+orcs[level],g[1],g[2],g[3]};
	mutate(level+1, total+(2*cost[level]),guard);

	//pass
	int guard1[4] = {g[0],g[1],g[2],g[3]};
	mutate(level+1, total+cost[level],guard1);

	//battle
	if(pasukan >= orcs[level]){
		int lawan = orcs[level];
		for(int i=3; i>=0; i--){
			if(g[i] != 0){
				if(g[i] >= lawan) {
					g[i] -= lawan;
					break;
				}
				else{
					lawan -= g[i];
					g[i] = 0;
				}
			}
		}
		int guard2[] = {0,g[0],g[1],0};
		mutate(level+1, total, guard2);
	}
	return 0;
}

int main() {

	int T;
	cin >> T;

	while(T--){

		cin >> N;
		mincost = 10000000;

		for(int i=0; i<N; i++){
			cin >> orcs[i] >> cost[i];
		}

		int g[4] = {0,0,0,0};
		mutate(0,0,g);

		cout << mincost << endl;

	}
	return 0;
}

