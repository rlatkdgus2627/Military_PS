#include <bits/stdc++.h>

using namespace std;

int n;

int predator[101], prey[51], ans;
bool visited[101];
bool ties[51][51];
vector<int> edges[101];

struct info{
	int size, speed, iq;
};

info shark[51];

bool check(int a, int b){
	return (shark[a].size >= shark[b].size) && (shark[a].speed >= shark[b].speed) && (shark[a].iq >= shark[b].iq);
}

bool check2(int a, int b){
	return (shark[a].size == shark[b].size) && (shark[a].speed == shark[b].speed) && (shark[a].iq == shark[b].iq);
}

bool dfs(int cur){
	if(visited[cur])	return false;
	visited[cur] = true;
	for(int next : edges[cur]){
		if(!prey[next] || dfs(prey[next])){
			predator[cur] = next;
			prey[next] = cur;
			return true;
		}
	}
	return false;
}

int main(){
	int size, speed, iq;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> size >> speed >> iq;
		shark[i] = {size, speed, iq};
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j)	continue;
			if(check(i, j) && !ties[i][j] && !ties[j][i]){
				if(check2(i, j)){
					ties[i][j] = true;
					ties[j][i] = true;
				}
				edges[2 * i - 1].push_back(j);
				edges[2 * i].push_back(j);
			}
		}
	}
	for(int i = 1; i <= 2 * n; i++){
		if(!predator[i]){
			memset(visited, false, sizeof(visited));
			if(dfs(i))	ans++;
		}
	}
	cout << n - ans;
	return 0;
}