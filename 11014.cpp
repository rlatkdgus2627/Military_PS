#include <bits/stdc++.h>

using namespace std;

vector<int>graph[8080];

bool visited[8080];

int my[8080], opp[8080], ans, n, m, total;
char board[81][81];

int dx[6] = {-1, -1, 0, 0, 1, 1};
int dy[6] = {-1, 1, -1, 1, -1, 1};

bool safe(int x, int y){
	return (0 <= x && x < n) && (0 <= y && y < m);
}
void getGraph(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(board[i][j] == 'x')	continue;
			total++;
			for(int k = 0; k < 6; k++){
				int cx = i + dx[k];
				int cy = j + dy[k];
				if(safe(cx, cy) && board[cx][cy] == '.'){
					graph[i * 80 + j].push_back(cx * 80 + cy);
				}
			}
		}
	}
}

bool dfs(int cur){
	if(visited[cur])	return false;
	visited[cur] = true;
	for(int next : graph[cur]){
		if(!opp[next] || dfs(opp[next])){
			my[cur] = next;
			opp[next] = cur;
			return true;
		}
	}
	return false;
}

int main(){
	int t;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		total = ans = 0;
		for(int i = 0; i < n; i++){
			cin >> board[i];
		}
		
		for(int i = 0; i < 8080; i++){
			opp[i] = my[i] = 0;
			graph[i].clear();
		}
		
		getGraph();
		
		for(int i = 0; i < n; i++){
			for(int j = 1; j < m; j += 2)
				if(!my[i * 80 + j]){
					memset(visited, false, sizeof(visited));
					if(dfs(i * 80 + j))	ans++;
				}
		}
		cout << total - ans << "\n";
	}
	return 0;
}