#include <iostream>
#include <cmath>
using namespace std;

int pos[1000][10], board[1000][1000], N;
int dist = 10000000;

int interstellar(int level, int state, int sum){
	cout << level << " " << state << " " << sum << endl;
//	if(level!=0 && (board[level][state]==-1 || board[level][state]==0)) return 0;
	if(state==N*2+2){
		dist = min(dist,sum);
		cout << "dist= " << dist << endl;
		return 1;
	}
	for(int i=state+1; i<N*2+2; i++){
		if(board[level][i]!=0){
			cout << "i= " << i << " " << board[level][i] << endl;
			if(i%2==1) interstellar(i+1,i+1,sum+board[level][i]);
			else interstellar(i-1,i-1,sum+board[level][i]);
		}
	}
	return 1;
}

int main() {

	cin >> pos[0][0] >> pos[0][1];
	int finish[2];
	cin >> finish[0] >> finish[1];
	cin >> N; // wormholes

	for(int i=1; i<=N*2; i+=2){
		cin >> pos[i][0] >> pos[i][1];
		cin >> pos[i+1][0] >> pos[i+1][1];
	}

	pos[N*2+1][0] = finish[0];
	pos[N*2+1][1] = finish[1];

	for(int i=0; i<=N*2+1; i++){
		cout << pos[i][0] << " " << pos[i][1] << endl;
	}

	for(int i=0; i<=N*2+1; i++){
		for(int j=0; j<=N*2+1; j++){
			if(i==j){
				board[i][j]=-1;
				continue;
			}
			if(i!=0 && j!=0 && i!=N*2+1 && j!=N*2+1 && j%2==1 && j==i-1){
				board[i][j]=0;
				continue;
			}
			if(i!=0 && j!=0 && i!=N*2+1 && j!=N*2+1 && j%2==0 && j==i+1){
				board[i][j]=0;
				continue;
			}
			board[i][j]=(abs(pos[j][0]-pos[i][0])+abs(pos[j][1]-pos[i][1]));
		}
	}

	for(int i=0; i<=N*2+1; i++){
		for(int j=0; j<=N*2+1; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	interstellar(0,0,0);
	cout << dist << endl;
	return 0;
}

