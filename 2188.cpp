#include <bits/stdc++.h>

using namespace std;

int n, m;
int cow[201], barn[201], ans;

vector<int> graph[201];
bool visited[201];

bool dfs(int cur){
	visited[cur] = true;
	for(int next : graph[cur]){
		if(!barn[next] || (!visited[barn[next]] && dfs(barn[next]))){
			cow[cur] = next;
			barn[next] = cur;
			return true;
		}
	}
	return false;
}
		   
int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	int cnt, x;
	for(int i = 1; i <= n; i++){
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			cin >> x;
			graph[i].push_back(x);
		}
	}
	for(int i = 1; i <= n; i++){
		if(!cow[i]){
			memset(visited, false, sizeof(visited));
			if(dfs(i))	ans++;
		}
	}
	cout << ans;
	return 0;
}