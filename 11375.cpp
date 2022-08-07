#include <bits/stdc++.h>

using namespace std;

int n, m;
int crew[1001], work[1001], ans;

vector<int> graph[1001];
bool visited[1001];

bool dfs(int cur){
	visited[cur] = true;
	for(int next : graph[cur]){
		if(!work[next] || (!visited[work[next]] && dfs(work[next]))){
			crew[cur] = next;
			work[next] = cur;
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
		if(!crew[i]){
			memset(visited, false, sizeof(visited));
			if(dfs(i))	ans++;
		}
	}
	cout << ans;
	return 0;
}