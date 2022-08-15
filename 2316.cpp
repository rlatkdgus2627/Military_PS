#include <bits/stdc++.h>

using namespace std;

int n, p, ans;

vector<int>graph[802];
int capacity[802][802], flow[802][802], path[802];
//i : in, i + n : out

const int INF = 1e9;

int main(){
	int s, e, f, cur;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> p;
	for(int i = 1; i <= n; i++){
		graph[i].push_back(i + n);
		graph[i + n].push_back(i);
		capacity[i][i + n] = (i == 1 || i == 2 ? INF : 1);
	
	}
	for(int i = 0; i < p; i++){
		cin >> s >> e;
		graph[s + n].push_back(e);
		graph[e].push_back(s + n);
		
		graph[e + n].push_back(s);
		graph[s].push_back(e + n);
		capacity[s + n][e] = 1;
		capacity[e + n][s] = 1;
	}
	
	while(1){
		memset(path, 0, sizeof(path));
		queue<int>Q;
		Q.push(1);
		while(!Q.empty()){
			cur = Q.front();
			Q.pop();
			if(cur == 2 + n)	break;
			for(int next : graph[cur]){
				if(capacity[cur][next] - flow[cur][next] > 0 && !path[next]){
					path[next] = cur;
					Q.push(next);
				}
			}
		}
		
		if(!path[2 + n])	break;
		
		f = INF;
		cur = 2 + n;
		while(cur != 1){
			f = min(f, capacity[path[cur]][cur] - flow[path[cur]][cur]);
			cur = path[cur];
		}
		
		cur = 2 + n;
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