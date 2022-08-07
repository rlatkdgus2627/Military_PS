#include <bits/stdc++.h>

using namespace std;

int n;

int energy[100001];

pair<int, int> table[100001][17];

bool visited[100001];

vector<pair<int, int> >graph[100001];

void dfs(int cur){
	visited[cur] = true;
	for(auto next : graph[cur]){
		if(!visited[next.first]){
			table[next.first][0] = make_pair(cur, next.second);
			visited[next.first] = true;
			dfs(next.first);
			
		}
	}
}

void getTable(){
	for(int j = 1; j <= 16; j++){
		for(int i = 1; i <= n; i++){
			table[i][j] = make_pair(table[table[i][j - 1].first][j - 1].first, table[table[i][j - 1].first][j - 1].second + table[i][j - 1].second);
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	
	for(int i = 1; i <= n; i++){
		cin >> energy[i];
	}
	
	int a, b, c, cur;
	
	for(int i = 0; i < n - 1; i++){
		cin >> a >> b >> c;
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	
	dfs(1);
	getTable();
	
	for(int i = 1; i <= n; i++){
		cur = i;
        for (int j = 16; j >= 0; j--) {
            if (energy[i] - table[cur][j].second >= 0) {
                energy[i] -= table[cur][j].second;
				cur = table[cur][j].first;
            }
        }
		cout << (cur == 0 ? 1 : cur) << "\n";
	}
	
	return 0;
}