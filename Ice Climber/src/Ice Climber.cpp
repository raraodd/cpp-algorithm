//============================================================================
// Name        : Ice.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int M, N, A[105][105], visited[105][105];
int start_x, start_y;
int finish_x,finish_y;
int min_height=1000;

bool climbers (int x, int y, int height){
//	cout << x << " " << y << endl;
	if (x < 0 || x > M || y < 0 || y > N) return false;
	if (x == start_x && y == start_y){
		return true;
	}
	if (visited[x][y] == 1) return false;

	visited[x][y] = 1;

	//left
	if(y!=0 && (A[x][y-1] == 1 || A[x][y-1] == 2) && visited[x][y-1]!=1){
		if(climbers(x,y-1,height)) return true;
	}

	//right
	if(y!=N && (A[x][y+1] == 1 || A[x][y+1] == 2) && visited[x][y+1]!=1){
		if(climbers(x,y+1,height)) return true;
	}

	//top
	for(int i=1; i<=height; i++){
//		cout << i << endl;
		if(x-i>=0 && (A[x-i][y] == 1 || A[x-i][y] == 2) && visited[x-1][y]!=1){
			if(climbers(x-i,y,height)) return true;
		}
	}

	//bottom
	for(int i=1; i<=height; i++){
		if(x+i<=M && (A[x+i][y] == 1 || A[x+i][y] == 2) && visited[x+1][y]!=1){
			if(climbers(x+i,y,height)) return true;
		}
	}

	visited[x][y]=0;
	return false;
}

int main() {

	cin >> N >> M;

	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
			cin >> A[i][j];
			if (A[i][j] == 2){
				start_x = i;
				start_y = j;
			}
			if (A[i][j] == 3){
				finish_x = i;
				finish_y = j;
			}
		}
	}

//	cout << start_x << " " << start_y << endl;
//	cout << finish_x << " " << finish_y << endl;

	for(int i=1; i<M; i++){
//		cout << i << endl;
		if(climbers (finish_x,finish_y,i)){
			cout << i;
			break;
		}
//		cout << endl;
	}

	return 0;
}
