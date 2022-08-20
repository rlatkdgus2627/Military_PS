#include <bits/stdc++.h>

using namespace std;

int n, m;

char board[101][101];
int capacity[101][101][4], flow[101][101][4], ans;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

pair<int, int> source, sink;

int path[101][101];

bool safe(int cx, int cy){
	return 0 <= cx && cx < n && 0 <= cy && cy < m; 
}

int main(){
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> board[i];
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 'K')	source = make_pair(i, j);
			if(board[i][j] == 'H')	sink = make_pair(i, j);
			if(board[i][j] == '#')	continue;
			
		}
	}
	while(1){
		
	}
	return 0;
}