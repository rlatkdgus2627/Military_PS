#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
vector<int>graph[10001];
int out[10001], in[10001];
bool visited[10001];

bool dfs(int cur){
	if(visited[cur])	return false;
	visited[cur] = true;
	for(int next : graph[cur]){
		if(!in[next] || dfs(in[next])){
			in[next] = cur;
			out[cur] = next;
			return true;
		}
	}
	return false;
}

int main(){
	int u, v;
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph[u].push_back(v);
	}
	for(int i = 1; i <= n; i++){
		if(!out[i]){
			memset(visited, false, sizeof(visited));
			if(dfs(i))	ans++;
		}
	}
	cout << n - ans << "\n";
	
	return 0;
}