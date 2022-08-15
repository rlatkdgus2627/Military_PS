#include <bits/stdc++.h>

using namespace std;

vector<int>graph[401];

int n, p, ans;

int capacity[401][401], flow[401][401], path[401];

const int INF = 1e9;


int main(){
	int x, y;
	int cur, f;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> p;
	for(int i = 0; i < p; i++){
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
		capacity[x][y] = 1;
	}
	
	while(1){
		memset(path, 0, sizeof(path));
		queue<int>Q;
		Q.push(1);
		while(!Q.empty()){
			cur = Q.front();
			Q.pop();
			if(cur == 2)	break;
			for(int next : graph[cur]){
				if(capacity[cur][next] - flow[cur][next] > 0 && !path[next]){
					path[next] = cur;
					Q.push(next);
				}
			}
		}
		
		if(!path[2])	break;
		
		f = INF;
		cur = 2;
		while(cur != 1){
			f = min(f, capacity[path[cur]][cur] - flow[path[cur]][cur]);
			cur = path[cur];
		}
		
		cur = 2;
		while(cur != 1){
			flow[path[cur]][cur] += f;
			flow[cur][path[cur]] -= f;
			cur = path[cur];
		}
		
		ans += f;
	}
	cout << ans;
	return 0;
}