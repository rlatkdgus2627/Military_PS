#include <bits/stdc++.h>

using namespace std;

int n, k, d, ans;

vector<int>graph[302];

const int INF = 1e9;
int capacity[302][302], flow[302][302], path[302], f;
//0 : source 301 : sink

int main(){
	int x, z, p;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k >> d;
	for(int i = 1; i <= d; i++){
		cin >> x;
		graph[n + i].push_back(301);
		graph[301].push_back(n + i);
		capacity[n + i][301] = x;
	}
	for(int i = 1; i <= n; i++){
		graph[0].push_back(i);
		graph[i].push_back(0);
		capacity[0][i] = k;
		
		cin >> z;
		for(int j = 0; j < z; j++){
			cin >> x;
			graph[i].push_back(x + n);
			graph[x + n].push_back(i);
			capacity[i][x + n] = 1;
		}
	}
	
	
	while(1){
		memset(path, -1, sizeof(path));
		queue<int>Q;
		Q.push(0);
		path[0] = 0;
		while(!Q.empty()){
			int cur = Q.front();
			Q.pop();
			//cout << cur << "\n";
			if(cur == 301)	break;
			for(int next : graph[cur]){
				if(path[next] == -1 && capacity[cur][next] - flow[cur][next] > 0){
					path[next] = cur;
					Q.push(next);
				}
			}
		}
		
		if(path[301] == -1)	break;
		
		f = INF;
		p = 301;
		while(p != 0){
			f = min(f, capacity[path[p]][p] - flow[path[p]][p]);
			p = path[p];
		}
		
		p = 301;
		while(p != 0){
			flow[path[p]][p] += f;
			flow[p][path[p]] -= f;
			p = path[p];
		}
		
		ans += f;
	}
	
	cout << ans;
	
	return 0;
}