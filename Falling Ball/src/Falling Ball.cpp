//============================================================================
// Name        : Falling.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int L, N, earliest=0, latest, minim;
int A[1009];
int dist = 0;
int y1, y2;

void late(){
	latest = max(L-y1,y2);
}

int main() {

	cin >> L >> N;

	int mid;
	mid = L/2;
	float mid1;
	if(L%2 == 0) mid1=mid+0.5;
	else mid1=mid+1;

//	cout << float(mid1) << endl;

	int x = 0;
	for(int i=1; i<=N; i++){
		cin >> A[i];
		if(i!=1){
			if(dist < A[i]-A[i-1]){
				dist = A[i]-A[i-1];
				y1 = A[i-1];
				y2 = A[i];
			}
		}
		if(mid1==A[i]){
			x = 1;
			earliest = mid1;
		}
		if(x!=1){
			if(A[i] <= mid1) minim = mid1 - A[i];
			else minim = L - A[i];
			if(earliest < minim) earliest = minim;
		}
	}

	late();
	cout << earliest << " " << latest;
	return 0;
}
