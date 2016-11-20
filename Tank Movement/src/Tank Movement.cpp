//============================================================================
// Name        : TankMovement.cpp
// Author      : wendy
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#define MAX 29
#define INVALID 9999999

int N;
int S1x,S1y,S2x,S2y,G1x,G1y,G2x,G2y;
int area[MAX][MAX];
bool visited[MAX][MAX][MAX][MAX];

int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1, 0 };
int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1, 0 };

int absolute(int X){
    return (X < 0) ? -X : X;
}

struct node {
	int X1, Y1, X2, Y2, counter;
	struct node *next;
};

class queue {
private:
	struct node *head;
	struct node *tail;
public:
	queue(){
		head = tail = NULL;
	}

	bool isEmpty(){
		return(head == NULL);
	}

	void push(int X1, int Y1, int X2, int Y2, int counter){
		struct node *data = new struct node;

		data->X1 = X1;
		data->Y1 = Y1;
		data->X2 = X2;
		data->Y2 = Y2;
		data->counter = counter;
		data->next = NULL;

		if(head==NULL){
			head = tail = NULL;
		}else{
			tail -> next = data;
			tail = data;
		}
	}

	struct node pop(){
		struct node *tmp = head;
		struct node ret;

		ret.X1 = tmp->X1;
		ret.Y1 = tmp->Y1;
		ret.X2 = tmp->X2;
		ret.Y2 = tmp->Y2;
		ret.counter = tmp->counter;

		if(head == tail){
			head = tail = NULL;
		} else {
			head = head -> next;
		}

		delete tmp;
		return ret;
	}
};

class queue Queue;
struct node hold;

int doBFS(){

    while(!Queue.isEmpty()) Queue.pop();

    int X1, Y1, X2, Y2;

    Queue.push(S1x, S1y, S2x, S2y, 0);

    while(!Queue.isEmpty()){
    	hold = Queue.pop();

    	X1 = hold.X1;
    	Y1 = hold.Y1;
    	X2 = hold.X2;
    	Y2 = hold.Y2;

    	if (visited[X1][Y1][X2][Y2])
    		continue;

    	visited[X1][Y1][X2][Y2] = true;

    	if (X1 == G1x && Y1 == G1y && X2 == G2x && Y2 == G2y)
    		return hold.counter;

    	if (absolute(X1-X2) < 2 && absolute(Y1-Y2) < 2)
    		continue;

    	if (area[X1][Y1] == 1 || area[X2][Y2] == 1)
    		continue;

    	for(int i=0; i<9; i++){
			for(int j=0; j<9; j++){
				if(i==0 && j==0) continue;

				int X_1 = X1 - dx[i];
				int Y_1 = Y1 - dy[i];
				int X_2 = X2 - dx[j];
				int Y_2 = Y2 - dy[j];

				if(X_1 < 1 || X_1 > N || Y_1 < 1 || Y_1 > N)
					continue;
				if(X_2 < 1 || X_2 > N || Y_2 < 1 || Y_2 > N)
					continue;

				Queue.push(X_1,Y_1,X_2,Y_2,hold.counter+1);
			}
		}
    }
    return INVALID;
}

int main() {

    int T;
    cin >> T;

    for(int test_case=0; test_case<T; test_case++){

        cin >> N;
        cin >> S1x >> S1y >> G1x >> G1y;
        cin >> S2x >> S2y >> G2x >> G2y;

        for(int i=1; i<=N; i++){
        	for(int j=1; j<=N; j++){
        		for(int k=1; k<=N; k++){
        			for(int l=1; l<=N; l++){
        				visited[i][j][k][l] = false;
        			}
        		}
        	}
        }

        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                cin >> area[i][j];
            }
        }

        int minStep = doBFS();
        if(minStep == INVALID) minStep = -1;

        cout << "#" << test_case << " " << minStep << endl;

    }

    return 0;
}
