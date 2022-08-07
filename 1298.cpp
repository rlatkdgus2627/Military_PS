#include <bits/stdc++.h>

using namespace std;

int n, m, ans;
int pupil[101], laptop[5001];
bool visited[101];

vector<int> graph[101];

bool dfs(int cur){
	visited[cur] = true;
	for(int next : graph[cur]){
		if(!laptop[next] || (!visited[laptop[next]] && dfs(laptop[next]))){
			pupil[cur] = next;
			laptop[next] = cur;
			return true;
		}
	}
	return false;
}
int main(){
	int a, b;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b;
		graph[a].push_back(b);
	}
	for(int i = 1; i <= n; i++){
		memset(visited, false, sizeof(visited));
		if(dfs(i))	ans++;
	}
	cout << ans;
	return 0;
}