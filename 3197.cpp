#include <bits/stdc++.h>

using namespace std;

int r, c;

const int MAX_SIZE = 1501;

char lake[MAX_SIZE][MAX_SIZE];
int parent[MAX_SIZE * MAX_SIZE];
int Rank[MAX_SIZE * MAX_SIZE];
int dx[4] = { 1,0,-1,0}, dy[4] = { 0,1,0,-1};
int swanCode1 = -1, swanCode2;

bool visited[MAX_SIZE][MAX_SIZE];

struct Node{
	int x, y, d;
}

int find(int u){
	if(u == parent[u])	return u;
	else return parent[u] = find(parent[u]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if (Rank[a] == Rank[b])	Rank[a]++;
	else if (Rank[a] < Rank[b]) {
		temp = a;
		a = b;
		b = temp;
	}
	parent[a] = b;
	return;
}

bool safe(int x, int y) {
	return (0 <= x && x < r) && (0 <= y && y < c);
}



int main(){
	cin >> r >> c;
	for(int i = 0; i < r; i++){
		cin >> lake[i];
	}
	
	queue<Node> Q;
	
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			if(lake[i][j] == 'L'){
				if(swanCode1 == -1){
					swanCode1 = c * i + j;
				}
				else swanCode2 = c * i + j;
			}
		}
	}
	
	for(int i = 0; i < r * c; i++){
		parent[i] = i;
	}
	
	
	return 0;
}