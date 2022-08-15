#include <bits/stdc++.h>

using namespace std;

int n, m, k;
vector<int>graph[2003];

int flow[2003][2003], capacity[2003][2003];
int path[2003];
//0 : source 2001 : sink 2002 : brigde

const int INF = 1e9;

void dfs(int cur){
	if(path[2001] != -1)	return;
	for(int next : graph[cur]){
		if(path[next] == -1 && capacity[cur][next] - flow[cur][next] > 0){
			path[next] = cur;
			dfs(next);
		}
	}
}


int ford_fulkerson(){
	int ans = 0, f, cur;
	while(1){
		memset(path, -1, sizeof(path));
		path[0] = 0;
		dfs(0);
		if(path[2001] == -1)	break;
		
		f = INF;
		
		cur = 2001;
		while(cur != 0){
			f = min(f, capacity[path[cur]][cur] - flow[path[cur]][cur]);
			cur = path[cur];
		}
		
		cur = 2001;
		while(cur != 0){
			flow[path[cur]][cur] += f;
			flow[cur][path[cur]] -= f;
			//cout << cur << "-";
			cur = path[cur];
		}
		//cout << f << "\n";
		
		ans += f;
	}
	return ans;
}



int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int cnt, x;
	
	cin >> n >> m >> k;
	
	for(int i = 1; i <= n; i++){
		cin >> cnt;
		for(int j = 0; j < cnt; j++){
			cin >> x;
			graph[i].push_back(x + 1000);
			graph[x + 1000].push_back(i);
			
			capacity[i][x + 1000] = 1;
		}
	}
	for(int i = 1; i <= n; i++){
		graph[0].push_back(i);
		graph[i].push_back(0);
		
		graph[2002].push_back(i);
		graph[i].push_back(2002);
		
		capacity[0][i] = 1;
		capacity[2002][i] = k;
	}
	for(int i = 1; i <= m; i++){
		graph[i + 1000].push_back(2001);
		graph[2001].push_back(i + 1000);
		
		capacity[i + 1000][2001] = 1;
	}
	graph[0].push_back(2002);
	graph[2002].push_back(0);
	capacity[0][2002] = k;
	
	cout << ford_fulkerson();
	
	return 0;
}