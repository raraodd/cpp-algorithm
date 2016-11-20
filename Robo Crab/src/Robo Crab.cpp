//============================================================================
// Name        : Robo.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int M;
int direction[105], movement[105], pos[105][3];

bool get_around(int A, int B, int C){
	if(B > A && B < C) return true;
	return false;
}

bool intercept(int A0, int A1, int B0, int B1, int C0, int C1, int D0, int D1){
//	cout << A0 << " " << A1 << " " << B0 << " " << B1 << endl;
//	cout << C0 << " " << C1 << " " << D0 << " " << D1 << endl << endl;
	int x, y, count = 0;
	if(A1==B1 && C0==D0){
		x = C0;
		y = A1;
		if(A0 > B0){
			if(get_around(B0,x,A0)) count++;
		}
		else{
			if(get_around(A0,x,B0)) count++;
		}
		if(C1 > D1){
			if(get_around(D1,y,C1)) count++;
		}
		else{
			if(get_around(C1,y,D1)) count++;
		}
		if(count==2){
//			cout << "----" << endl;
			return true;
		}
	}
	return false;
}

bool overlap(int a, int b, int c, int d){
	if(a>b){
		int temp = a;
		a = b;
		b = temp;
	}
	if(c>d){
		int temp = c;
		c = d;
		d = temp;
	}
//	cout << a << " " << b << " " << c << " " << d << endl;
	if(a==c && b==d) return true;
	else if(a<=c && d>=b && c!=b) return true;
	else if(c<=a && b>=d && a!=d) return true;
	else if(a<=c && b>=d) return true;
	else if(c<=a && d>=b) return true;
	return false;
}


int main() {

	cin >> M;
	pos[0][0]=0; //x
	pos[0][1]=0; //y

	for(int i=1; i<M+1; i++){
		cin >> direction[i] >> movement[i];
		if(direction[i] == 1){
			// NORTH - up
			pos[i][0] = pos[i-1][0];
			pos[i][1] = pos[i-1][1]+movement[i];
		}
		else if(direction[i] == 2){
			// SOUTH - down
			pos[i][0] = pos[i-1][0];
			pos[i][1] = pos[i-1][1]-movement[i];
		}
		else if(direction[i] == 3){
			// EAST - right
			pos[i][0] = pos[i-1][0]+movement[i];
			pos[i][1] = pos[i-1][1];
			pos[i][2] = 1;
		}
		else{
			// WEST - left
			pos[i][0] = pos[i-1][0]-movement[i];
			pos[i][1] = pos[i-1][1];
			pos[i][2] = 1;
		}
//		cout << pos[i][0] << " " << pos[i][1] << " " << pos[i][2] << endl;
	}

	bool done = false;

	for(int i=2; i<M+1; i++){
//		cout << i << endl;
		for(int j=i-1; j>0; j--){
//			cout << "j " << j << endl;
			if((pos[i][2] == 1 && pos[j][2] == 0)){
				if(intercept(pos[i][0],pos[i][1],pos[i-1][0],pos[i-1][1],pos[j][0],pos[j][1],pos[j-1][0],pos[j-1][1])){
					done = true;
					break;
				}
			}
			else if((pos[i][2] == 0 && pos[j][2] == 1)){
				if(intercept(pos[j][0],pos[j][1],pos[j-1][0],pos[j-1][1],pos[i][0],pos[i][1],pos[i-1][0],pos[i-1][1])){
					done = true;
					break;
				}
			}
			else if(pos[i][2] == 1 && pos[j][2] == 1){
				if(pos[i][1] == pos[i-1][1] && pos[i][1] == pos[j][1] && pos[j][1] == pos[j-1][1]){
					if(overlap(pos[i][0],pos[i-1][0],pos[j][0],pos[j-1][0])){
						done = true;
						break;
					}
				}
			}
			else if(pos[i][2] == 0 && pos[j][2] == 0){
				if(pos[i][0] == pos[i-1][0] && pos[i][0] == pos[j][0] && pos[j][0] == pos[j-1][0]){
					if(overlap(pos[i][1],pos[i-1][1],pos[j][1],pos[j-1][1])){
						done = true;
						break;
					}
				}
			}
		}
		if(done){
			cout << i;
			break;
		}
	}
	if(!done) cout << -1;


	return 0;
}
