//============================================================================
// Name        : RepairExpressWay.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int N, K;
int dp[100][10000], damage[10009];
int idx[100][2], counter;

int f(int i, int last_stamp, int X){
	int result;
	int gap = damage[i]-last_stamp;

	if(i>N-1) return 0;
	if(dp[i][last_stamp]!=0) return dp[i][last_stamp];
	if(last_stamp >= damage[i]) result = f(i+1,last_stamp,K);
	else{
		int res1, res2=99999999;
		res1 = X + f(i+1,damage[i]+(K-1),K);
		if(gap <= K) res2 = gap + f(i+1,damage[i],X);
	result = min(res1,res2);
	}

	dp[i][last_stamp] = result;
	idx[counter][0] = i;
	idx[counter][1] = last_stamp;
	counter++;
	return result;
}

void idxreset(){
	for(int i=0; i<counter; i++){
		int x = idx[i][0];
		int y = idx[i][1];
		dp[x][y] = 0;
	}
}

void merge(int left, int mid, int right){
	int temp[10009];
	int h = left;
	int i = left;
	int j = mid+1;

	while((h<=mid) && (j<=right)){
		if(damage[h] < damage[j]){
			temp[i] = damage[h];
			h++;
		}
		else{
			temp[i] = damage[j];
			j++;
		}
		i++;
	}

	if(h>mid){
		for(int k=j; k<=right; k++){
			temp[i]=damage[k];
			i++;
		}
	}else{
		for(int k=h; k<=right; k++){
			temp[i]=damage[k];
			i++;
		}
	}

	for(int k=left; k<=right; k++){
		damage[k] = temp[k];
	}
}

void merge_sort(int left, int right){
	int mid;
	if(left<right){
		mid = left+(right-left)/2;
		merge_sort(left,mid);
		merge_sort(mid+1,right);
		merge(left, mid, right);
	}
}

int main() {

	int T;
	cin >> T;

	for(int t=1; t<=T; t++){
		counter = 0;
		cin >> N >> K;

		for(int i=0; i<N; i++){
			cin >> damage[i];
		}

		merge_sort(0,N-1);

		for(int i=0; i<N; i++){
			cout << damage[i] << " ";
		}
		cout << endl;
		cout << "#" << t << " " << K + f(1,damage[0]+(K-1),K) << endl;

		idxreset();
	}

	return 0;
}
