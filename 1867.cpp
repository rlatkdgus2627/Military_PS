#include <bits/stdc++.h>

using namespace std;

vector<int>graph[501];

int row[501], col[501];
bool visited[501];

int n, k, ans;

bool dfs(int cur){
	if(visited[cur])	return false;
	visited[cur] = true;
	for(int next : graph[cur]){
		if(!col[next] || dfs(col[next])){
			row[cur] = next;
			col[next] = cur;
			return true;
		}
	}
	return false;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	int r, c;
	for(int i = 0; i < k; i++){
		cin >> r >> c;
		graph[r].push_back(c);
	}
	for(int i = 1; i <= n; i++){
		if(!row[i]){
			memset(visited, false, sizeof(visited));
			if(dfs(i))	ans++;
		}
	}
	cout << ans;
	return 0;
}