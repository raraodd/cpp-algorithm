#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct City {
	int to[10];
	int length = 0;
	void add(int dest) {
		to[length] = dest;
		length++;
	}
};

int N, M;
City cities[10];
int visited[10];

int mutate(int node, int parent) {
	if (visited[node] == 1) {
		return 1;
	}
	visited[node] = 1;
	for(int i = 0; i < cities[node].length; i++) {
		int toCity = cities[node].to[i];
		int curr = mutate(toCity, node);
		if (curr == 1) return 1;
	}
	visited[node] = 0;
	return 0;
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int from, to;
		cin >> from;
		cin >> to;
		cities[from].add(to);
	}

	int state = 0;
	for(int i = 0; i < N; i++) {
		state = mutate(i + 1, -1);
		if(state == 1) break;
	}
	if(state == 1) cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}

