#include <bits/stdc++.h>

using namespace std;
vector<int>graph[501];

int n, m, ans, f;
int capacity[501][501], flow[501][501];
int path[501];

const int INF = 1e9;

int main(){
	int a, b, c, source, sink;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		graph[a].push_back(b);
		graph[b].push_back(a);
		capacity[a][b] = capacity[b][a] = c;
	}
	cin >> source >> sink;
	while(1){
		memset(path, 0, sizeof(path));
		queue<int>Q;
		Q.push(source);
		path[source] = source;
		while(!Q.empty()){
			int cur = Q.front();
			Q.pop();
			if(cur == sink)	break;
			for(int next : graph[cur]){
				if(!path[next] && capacity[cur][next] > flow[cur][next]){
					path[next] = cur;
					Q.push(next);
				}
			}
		}
		if(!path[sink])	break;
		f = INF;
		int p = sink;
		while(p != source){
			f = min(f, capacity[path[p]][p] - flow[path[p]][p]);
			p = path[p];
		}
		
		p = sink;
		while(p != source){
			flow[path[p]][p] += f;
			flow[p][path[p]] -= f;
			p = path[p];
		}
		
		ans += f;
	}
	cout << ans;
	return 0;
}