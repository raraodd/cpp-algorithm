//============================================================================
// Name        : Snakes.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int board[10][10], snakes[15][15], ladders[15][15], max;
int n, m;
int moves = 10000;

int isLadders(int position, int target){
	for(int i=0; i<m; i++){
		if(position == ladders[i][0]){
			if(target > ladders[i][0])
				return position;
			else
				return ladders[i][1];
		}
	}
	return position;
}

bool isSnakes(int position){
	for(int i=0; i<n; i++){
		if(position == snakes[i][0])
			return true;
	}
	return false;
}

void solution (int move, int position, int target, int target_pos){
//	cout << "--" <<  position << endl;
	if(!isSnakes(position) && position <= 100 && move != moves){
		if(position <= target && position > 0){
			position = isLadders(position,target);
			move++;
//			cout << position << " " << move << endl;
			for(int i=6; i>=1; i--){
//				cout << i << endl;
				solution(move,position+i,target,target_pos);
			}
		}
		if(position >= target_pos && position < 100){
			position = isLadders(position,target);
			move++;
//			cout << position << " " << move << endl;
			for(int i=6; i>=1; i--){
//				cout << i << endl;
				solution(move,position+i,target,target_pos);
			}
		}
		if(position == 100){
			if (move < moves)
				moves = move;
//			cout << "##" << position << " " << moves << endl;
		}
	}
}

int main() {

	int T;
	cin >> T;

	while(T--){
		cin >> n;
		int max = 0, target, target_pos;

		for (int i=0; i<n; i++){
			cin >> ladders[i][0] >> ladders[i][1];
			int range = ladders[i][1] - ladders[i][0];
			if (range > max){
				max = range;
				target = ladders[i][0];
				target_pos = ladders[i][1];
			}
		}

		//cout << max << " " << target << endl;

		cin >> m;

		for (int i=0; i<m; i++){
			cin >>	snakes[i][0] >> snakes[i][1];
		}

//		for (int i=0; i<n; i++){
//			cout << ladders[i][0] << " " << ladders[i][1] << endl;
//		}
//		cout << endl;
//		for (int i=0; i<m; i++){
//			cout << snakes[i][0] << " " << snakes[i][1] << endl;
//		}
		solution(0, 1, target, target_pos);
		cout << moves << endl;
	}


	return 0;
}

