//============================================================================
// Name        : Trade-In.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int A[2000][2000], B[2000][2000], C[2000][2000], S[10], pos[2000][2000];
int x=0;

void save(int i){
	C[i][1] += 1;
}

void save_pos(int value, int i, int j){
	if(A[i][j]==0){
		pos[x][0] = B[i][j];
		pos[x][1] = i;
		pos[x][2] = j;
		x++;
	}
}

int coloring(int M, int N){
	int state;
	for(int i=0; i<M; i++){
		for(int j=0; j<N; j++){
//			cout <<endl<< i << " " << j << " " << A[i][j] << endl;
			if(i!=0 || j!=0){
				// LEFT
				if(j!=0 && A[i][j] == A[i][j-1]){
					B[i][j] = B[i][j-1];
					save(B[i][j]);
					save_pos(B[i][j],i,j);
//					cout << B[i][j] << endl;
					continue;
				}
				// TOP
				else if(i!=0 && A[i][j] == A[i-1][j]){
					B[i][j] = B[i-1][j];
					save(B[i][j]);
					save_pos(B[i][j],i,j);
//					cout << B[i][j] << endl;
					continue;
				}
				// RIGHT
				else if(j!=N-1 && A[i][j] == A[i][j+1]){
					if(A[i][j] == A[i-1][j+1]){
						B[i][j] = B[i-1][j+1];
						save(B[i][j]);
						save_pos(B[i][j],i,j);
//						cout << B[i][j] << endl;
						continue;
					}
				}
				if(j == 0){
					B[i][j] = state + 1;
					C[B[i][j]][0] = B[i][j];
					C[B[i][j]][1] = 1;
					save_pos(B[i][j],i,j);
					state = B[i][j];
//					cout << B[i][j] << endl;
				}
				else{
					B[i][j] = state + 1;
					C[B[i][j]][0] = B[i][j];
					C[B[i][j]][1] = 1;
					save_pos(B[i][j],i,j);
					state = B[i][j];
//					cout << B[i][j] << endl;
				}
			}
			else{
				B[i][j] = 1;
				C[B[i][j]][0] = B[i][j];
				C[B[i][j]][1] = 1;
				state = B[i][j];
//				cout << B[i][j] << endl;
			}
		}
	}
	return state;
}

int main() {

	int T;
	cin >> T;
	while(T--){

		int M, N;

		cin >> M >> N;

		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				cin >> A[i][j];
				B[i][j] = 0;
			}
		}

		int idx = coloring(M,N);

		for(int i=0; i<M; i++){
			for(int j=0; j<N; j++){
				cout << B[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		for(int i=1; i<=idx; i++){
			cout << C[i][0] << " " << C[i][1] << endl;
		}

		cout << endl;
		for(int i = 0; i<x; i++){
			cout << pos[i][0] << " " << pos[i][1] << " " << pos[i][2] << endl;
		}
		cout << endl;
	}

	return 0;
}

