//============================================================================
// Name        : Merge.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int a[1000];

void merge(int,int,int);

void merge(int left,int mid,int right){
	int temp[10000];
	int h=left; // leftIndex
	int i=left; // auxIndex
	int j=mid+1; // rightIndex

	while((h<=mid)&&(j<=right)){
		if(a[h]<=a[j]){
			temp[i]=a[h];
			h++;
		}
		else{
			temp[i]=a[j];
			j++;
		}
			i++;
	}

	while(h<=mid){
		int idx = h++;
		temp[i]=a[idx];
		i++;
	}

	while(j<=right){
		int idx = j++;
		temp[i]=a[idx];
	}

	for(int k=left;k<=right;k++){
		a[k]=temp[k];
	}
}

void merge_sort(int left,int right){
	int mid;
	if(left<right){
		mid = left + (right-left)/2;//This avoids overfleft when left, right are too large
		// cout << "mid: " << mid << endl;
		merge_sort(left,mid);
		merge_sort(mid+1,right);
		merge(left,mid,right);
	}
}

int main() {

	int n;

	cin >> n;

	for(int i=0; i<n; i++){
		cin >> a[i];
	}

	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}

	cout << endl;

	merge_sort(0,n-1);

	for(int i=0; i<n; i++){
		cout << a[i] << " ";
	}

	return 0;
}

