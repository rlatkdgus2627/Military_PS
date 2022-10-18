#include <bits/stdc++.h>

using namespace std;

int n, m, r;

vector<int> graph[100001];

int visited[100001], cnt;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int u, v;
	cin >> n >> m >> r;
	for(int i = 0; i < m; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	for(int i = 1; i <= n; i++){
		sort(graph[i].begin(), graph[i].end(), greater<int>());
	}
	queue<int>Q;
	visited[r] = ++cnt;
	Q.push(r);
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for(int next : graph[cur]){
			if(!visited[next]){
				visited[next] = ++cnt;
				Q.push(next);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		cout << visited[i] << "\n";
	}
	return 0;
}