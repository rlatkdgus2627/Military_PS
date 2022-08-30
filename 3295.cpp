#include <bits/stdc++.h>

using namespace std;

int t;
int n, m, ans;
vector<int>graph[1000];
int out[1000], in[1000];
bool visited[1000];

void init(){
	for(int i = 0; i < n; i++){
		graph[i].clear();
		in[i] = out[i] = -1;
	}
	ans = 0;
}

bool dfs(int cur){
	if(visited[cur])	return false;
	visited[cur] = true;
	for(int next : graph[cur]){
		if(in[next] == -1 || dfs(in[next])){
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
	cin >> t;
	while(t--){
		cin >> n >> m;
		init();
		for(int i = 0; i < m; i++){
			cin >> u >> v;
			graph[u].push_back(v);
		}
		for(int i = 0; i < n; i++){
			if(out[i] == -1){
				memset(visited, false, sizeof(visited));
				if(dfs(i))	ans++;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}