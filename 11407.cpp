#include <bits/stdc++.h>

using namespace std;

vector<int> graph[203];
int n, m;

int cost[203][203], capacity[203][203], flow[203][203];
int maxFlow, totalCost;

int path[203], dist[203], ans;
bool inQueue[203];


const int source = 201;
const int sink = 202;

const int INF = 1e9;

void SPFA(){
	queue<int>Q;
	fill(dist, dist + 203, INF);
	memset(inQueue, false, sizeof(inQueue));
	memset(path, 0, sizeof(path));
	
	Q.push(source);
	inQueue[source] = true;
	dist[source] = 0;
	
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
	int x;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> x;
		graph[201].push_back(i);
		graph[i].push_back(201);
		capacity[201][i] = x;
	}
	for(int i = 1; i <= m; i++){
		cin >> x;
		graph[i + n].push_back(202);
		graph[202].push_back(i + n);
		capacity[i + n][202] = x;
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> x;
			graph[j].push_back(i + n);
			graph[i + n].push_back(j);
			capacity[j][i + n] = x; 
		}
	}
	
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= n; j++){
			cin >> x;
			cost[j][i + n] = x; 
			cost[i + n][j] = -x; 
		}
	}
	
	while(1){
		SPFA();
		if(!path[sink])	break;
		maxFlow = INF;
		int cur = sink;
		while(cur != source){
			maxFlow = min(maxFlow, capacity[path[cur]][cur] - flow[path[cur]][cur]);
			cur = path[cur];
		}
		
		cur = sink;
		while(cur != source){
			totalCost += cost[path[cur]][cur] * maxFlow;
			flow[path[cur]][cur] += maxFlow;
			flow[cur][path[cur]] -= maxFlow;
			cur = path[cur];
		}
		ans += maxFlow;
	}
	cout << ans << "\n" << totalCost << "\n";
	return 0;
}