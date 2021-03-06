//============================================================================
// Name        : Knapsack.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

float weight[2001], value[2001];
float density[2001], UB[2001];

void merge(int left,int mid,int right){
	int temp[2001], tempVal[2001], tempWeight[2001];
	int h=left; // leftIndex
	int i=left; // auxIndex
	int j=mid+1; // rightIndex

	while((h<=mid)&&(j<=right)){
		if(density[h]>=density[j]){
			temp[i]=density[h];
			tempVal[i]=value[h];
			tempWeight[i]=weight[h];
			h++;
		}
		else{
			temp[i]=density[j];
			tempVal[i]=value[j];
			tempWeight[i]=weight[j];
			j++;
		}
		i++;
	}

	while(h<=mid){
		int idx = h++;
		temp[i]=density[idx];
		tempVal[i]=value[idx];
		tempWeight[i]=weight[idx];
		i++;
	}
	while(j<=right){
		int idx = j++;
		temp[i]=density[idx];
		tempVal[i]=value[idx];
		tempWeight[i]=weight[idx];
	}
	for(int k=left;k<=right;k++){
		density[k]=temp[k];
		value[k]=tempVal[k];
		weight[k]=tempWeight[k];
//		cout << "dens[" << k << "]: " << density[k] << endl;
	}
//	cout << endl;
}

void merge_sort(int left,int right){
	int mid;
	if(left<right){
		mid = left + (right-left)/2;//This avoids overfleft when left, right are too large
//		cout << "mid: " << mid << endl;
		merge_sort(left,mid);
		merge_sort(mid+1,right);
		merge(left,mid,right);
	}
}

float get_UB(int S, int N){
	int val = 0, w = 0, i = 0;
	while ( i < N && w < S){
		w += weight[i];
		if(w > S){
			val += (S-(w-weight[i]))*value[i]/weight[i];
		}
		else
			val += value[i];
		cout << w << " " << val << endl;
		i++;
	}
	return val;
}

void knapsack(int i, int v, int w, int S){
	if(w <= S && UB[i] >= UB[i-1]){
		v += value[i];
		w += weight[i];
	}
}

int main() {

	int T, S, N;

	cin >> T;

	while(T--){
		cin >> S >> N;
		cout << endl;

		for(int i=0; i<N; i++){
			cin >> weight[i] >> value[i];
			density[i] = value[i] / weight[i];
//			cout << density[i] << "  ";
		}

//		cout << endl;
		merge_sort(0,N-1);

		for(int i=0;i<N;i++)
			cout << density[i] << "  " << value[i] << " " << weight[i] << endl;

		UB[0] = get_UB(S,N);
		cout << UB[0];

		knapsack(1,0,0,S);

	}

	return 0;
}

//int main(){
//	int value = 2000000;
//	cout << value;
//}
