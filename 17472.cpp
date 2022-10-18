#include <bits/stdc++.h>

using namespace std;

int parent[7];
int board[11][11];

int n, m, ans;
int island;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

struct edge{
	int s, e, distance;
};

bool cmp(edge &lhs, edge &rhs){
	return lhs.distance < rhs.distance;
}

vector<edge> edges;

int find(int u){
	return parent[u] == u ? u : parent[u] = find(parent[u]);
}

void findpath(int x, int y, int dist, int group, int d){
	if(dist >= 3 && board[x][y] && board[x][y] != group){
		edges.push_back({group, board[x][y], dist - 1});
		return;
	}
	
	if(dist < 3 && board[x][y] && board[x][y] != group){
		return;
	}
	
	int nextX, nextY;
	nextX = x + dx[d];
	nextY = y + dy[d];
	if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)	return;
	if(board[nextX][nextY] == group)	return;
	findpath(nextX, nextY, dist + 1, group, d);
}

void dfs(int x, int y, int mark){
	board[x][y] = mark;
	int nextX, nextY;
	for(int i = 0; i < 4; i++){
		nextX = x + dx[i];
		nextY = y + dy[i];
		if(nextX < 0 || nextX >= n || nextY < 0 || nextY >= m)	continue;
		if(board[nextX][nextY] == 7){
			dfs(nextX, nextY, mark);
		}
	}
}


int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> board[i][j];
			board[i][j] = board[i][j] ? 7 : 0;
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 7)	dfs(i, j, ++island);
		}
	}
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			for(int k = 0; k < 4; k++){
				if(board[i][j])	findpath(i, j, 0, board[i][j], k);
			}
		}
	}
	
	sort(edges.begin(), edges.end(), cmp);
	
	/*
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
	for(auto cur : edges){
		cout << cur.s << " " << cur.e << " " << cur.distance << "\n";
	}
	*/
	
	
	for(int i = 1; i <= island; i++){
		parent[i] = i;
	}
	
	
	for(auto cur : edges){
		int u = find(cur.s);
		int v = find(cur.e);
		
		if(u != v){
			parent[u] = v;
			ans += cur.distance;
			island--;
			if(island == 1)	break;
		}
		
	}
	
	if(island > 1)	cout << "-1";
	else cout << ans;
	
	return 0;
}