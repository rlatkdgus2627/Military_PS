#include <bits/stdc++.h>

using namespace std;

int n, m, r;

vector<int>graph[100001];

int visited[100001];

int cnt;

void dfs(int cur){
	visited[cur] = ++cnt;
	for(int next : graph[cur]){
		if(!visited[next])	dfs(next);
	}
}

int main(){
	int u, v;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> r;
	
	
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end());
	}
	
	dfs(r);
	
	for(int i = 1; i <= n; i++){
		cout << visited[i] << "\n";
	}
	return 0;
}