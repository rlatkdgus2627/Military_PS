#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<int> graph[802];
int cost[802][802], flow[802][802], capacity[802][802];

//source : 0, sink : 801

bool inQueue[802];
int dist[802], path[802];
int ans, totalCost;
const int INF = 1e9;

void SPFA(){
	queue<int> Q;
	memset(inQueue, false, sizeof(inQueue));
	fill(dist, dist + 802, INF);
	memset(path, -1, sizeof(path));
	dist[0] = 0;
	path[0] = 0;
	inQueue[0] = true;
	Q.push(0);
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		inQueue[cur] = false;
		for(int next : graph[cur]){
			if(capacity[cur][next] - flow[cur][next] > 0 && dist[next] > dist[cur] + cost[cur][next]){
				dist[next] = dist[cur] + cost[cur][next];
				path[next] = cur;
				if(!inQueue[next]){
					Q.push(next);
					inQueue[next] = true;
				}
			}
		}
	}
}

int main(){
	int x, w, c;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		capacity[0][i] = 1;
		graph[0].push_back(i);
		graph[i].push_back(0);
	}
	for(int i = 1; i <= m; i++){
		capacity[n + i][801] = 1;
		graph[n + i].push_back(801);
		graph[801].push_back(n + i);
	}
	for(int i = 1; i <= n; i++){
		cin >> x;
		for(int j = 0; j < x; j++){
			cin >> w >> c;
			graph[i].push_back(n + w);
			graph[n + w].push_back(i);
			cost[i][n + w] = c;
			cost[n + w][i] = -c;
			capacity[i][n + w] = 1;
		}
	}
	while(1){
		SPFA();
		if(path[801] == -1)	break;	
		int cur = 801;
		while(cur){
            totalCost += cost[path[cur]][cur];
            flow[path[cur]][cur] += 1;
            flow[cur][path[cur]] -= 1;
			cur = path[cur];
        }
		ans++;
	}
	cout << ans << "\n";
	cout << totalCost << "\n";
	return 0;
}