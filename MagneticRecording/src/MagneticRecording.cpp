//============================================================================
// Name        : MagneticRecording.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include <iostream>
using namespace std;

char data[109];
int dp[309][3];
int N, L, LC, K;
int counter, dpIdx[309][2];
int totalCost, minCost;

int colorToInt(char color){
	int j;
	if(color == 'S') j=0;
	if(color == 'M') j=1;
	if(color == 'N') j=2;
	return j;
}

bool is_valid(int start, int end, char color){
	for(int i=start; i<end; i++){
		if(data[i]!='*' && data[i]!=color) return false;
	}
	return true;
}

void resetDpTable(){
	for(int i=0; i<counter; i++){
		int x = dpIdx[i][0];
		int y = dpIdx[i][1];
		dp[x][y] = 0;
	}

}

int f(int idx, char color){

//	cout << idx << " " << color << endl;
	int j = colorToInt(color);
	if(dp[idx][j]!=0) {
//		cout << "return "<< "dp["<<idx<<"]["<<j<<"]= " << dp[idx][j] << endl;
		return dp[idx][j];
	}

	int minResult = 999, result;

	if(idx+L >= N) minResult = 1;



	for(int i=idx+1; i<idx+L; i++){
		if(i+L>N) break;
		if(is_valid(i,i+L,color)){
			result = f(i,color);
			if(result!=-1)
				minResult=min(minResult,result+1);
		}
	}

	if(idx+2*L-1 < N){
		if(is_valid(idx+L,idx+2*L,'S')){
			result = f(idx+L,'S');
			if(result!=-1)
				minResult=min(minResult,result+1);
		}
		if(is_valid(idx+L,idx+2*L,'N')){
			result = f(idx+L,'N');
			if(result!=-1)
				minResult=min(minResult,result+1);
		}
		if(is_valid(idx+L,idx+2*L,'M')){
			result = f(idx+L,'M');
			if(result!=-1)
				minResult=min(minResult,result+1);
		}

	}

	if(minResult == 999) minResult = -1;
	dp[idx][j]=minResult;
//	cout << "dp["<<idx<<"]["<<j<<"]= " <<minResult<<endl;
	dpIdx[counter][0] = idx;
	dpIdx[counter][1] = j;
	counter++;
//	cout << "backtrack" << endl << endl;
	return minResult;
}

int main() {

	int T;
	cin >> T;

	for(int test_case=1; test_case<=T; test_case++){
		cin >> N >> LC >> K;

		minCost = LC+(K*N);

		int record;
		for(int i=0; i<N; i++){
			cin >> data[i];
		}

		for(L=2; L<=N; L++){
			int minRecord = 999;

//			cout << "L= " << L << endl;
			if(is_valid(0,L,'S')){
				counter = 0;
//				cout << "S valid" << endl;
				record = f(0,'S');
				if(record!=-1) minRecord=min(minRecord,record);
//				cout << record << " " << minRecord << endl << endl;
			}
			resetDpTable();
			if(is_valid(0,L,'M')){
				counter = 0;
//				cout << "M valid" << endl;
				record = f(0,'M');
				if(record!=-1) minRecord=min(minRecord,record);
//				cout << record << " " << minRecord << endl << endl;
			}
			resetDpTable();
			if(is_valid(0,L,'N')){
				counter = 0;
//				cout << "N valid" << endl;
				record = f(0,'N');
				if(record!=-1) minRecord=min(minRecord,record);
//				cout << record << " " << minRecord << endl << endl;
			}
			resetDpTable();

			if(minRecord!=999){
				totalCost = (LC*L)+(K*minRecord);
				minCost = min(minCost,totalCost);
//				cout << "- "<<minRecord << " " << totalCost << endl << endl;
			}
		}

		cout << "#" << test_case << " " << minCost << endl;
	}

	return 0;
}
