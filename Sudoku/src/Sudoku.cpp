//============================================================================
// Name        : Sudoku.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <math.h>
using namespace std;

void print(int N, int matrix[][100]);

bool row(int RowIdx, int N, int A[][100], int result[][100], int item){
	for(int i=0; i<N; i++){
		if(A[RowIdx][i] == item || result[RowIdx][i] == item)
			return true;
	}
	return false;
}

bool column(int ColIdx, int N, int A[][100], int result[][100], int item){
	for(int i=0; i<N; i++){
		if(A[i][ColIdx] == item || result[i][ColIdx] == item)
			return true;
	}
	return false;
}

bool square(int RowIdx, int ColIdx, int N, int A[][100], int result[][100], int item){
	int sqrtN = sqrt(N);
//	cout << "sqrt: " << sqrtN << endl;
	int RowUpperLimit, RowLowerLimit, ColUpperLimit, ColLowerLimit;
	for (int i=0; i<sqrtN; i++){
		if(RowIdx>=i*sqrtN && RowIdx<(i+1)*sqrtN){
			RowUpperLimit = (i+1)*sqrtN;
			RowLowerLimit = i*sqrtN;
			break;
		}
	}
	for (int i=0; i<sqrtN; i++){
		if(ColIdx>=i*sqrtN && ColIdx<(i+1)*sqrtN){
			ColUpperLimit = (i+1)*sqrtN;
			ColLowerLimit = i*sqrtN;
			break;
		}
	}
//	cout << RowLowerLimit << " " << RowUpperLimit << " " << ColLowerLimit << " " << ColUpperLimit << endl;
	for(int i=RowLowerLimit; i<RowUpperLimit; i++){
		for(int j=ColLowerLimit; j<ColUpperLimit; j++){
			if(A[i][j] == item || result[i][j] == item)
				return true;
		}
	}
	return false;
}

void print(int N, int matrix[][100]){
	for(int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
}

void printRes(int N, int result[][100], int A[][100]){
	for(int i=0; i<N; i++){
		for (int j=0; j<N; j++){
			if(A[i][j] != 0)
				cout << A[i][j] << " ";
			else
				cout << result[i][j]+A[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void sudoku (int level, int i, int j, int N, int A[][100], int result[][100], int items[100]){
	if(level <= pow(N,2) && i < N && j < N){
		cout << level << " " << i+1 << " " << j+1 << endl;
 		if(A[i][j]==0){
			for(int k=0; k<N; k++){
				if(!row(i,N,A,result,items[k])){
					if(!column(j,N,A,result,items[k])){
						if(!square(i,j,N,A,result,items[k])){
							result[i][j] = items[k];
//							cout << endl << endl;
							printRes(N,result,A);
//							cout << endl;
							if(j+1 == N){
								sudoku(level+1,i+1,0,N,A,result,items);
							}
							else
								sudoku(level+1,i,j+1,N,A,result,items);
							result[i][j]=-1;
						}
					}
				}
			}
		}
 		else{
			if(j+1 == N){
				sudoku(level+1,i+1,0,N,A,result,items);
			}
			else
				sudoku(level+1,i,j+1,N,A,result,items);
		}
	}
}

int main() {
	int N, n, row, col;
//	cout << "Enter the size of matrix (N): ";
	cin >> N;
	int A[100][100], items[100], result[100][100];

	for(int i=0; i<N; i++){
		items[i] = i+1;
		for(int j=0; j<N; j++){
			A[i][j]=0;
			result[i][j]=-1;
		}
	}

//	cout << "n: ";
	cin >> n;
	for(int i=0; i<n; i++){
//		cout << "n= " << i+1 << endl;
//		cout << "Enter row position: ";
		cin >> row;
//		cout << "Enter column position: ";
		cin >> col;
//		cout << "Enter the number of A[" << row << "][" << col << "]: ";
		cin >> A[row-1][col-1];
		result[row-1][col-1] = 0;
	}
	cout << endl;

	print(N,A);
	cout << endl;
	print(N,result);
	cout << endl;
	sudoku(1,0,0,N,A,result,items);
	return 0;
}


