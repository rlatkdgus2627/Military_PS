#include <bits/stdc++.h>

using namespace std;

int v, e;

vector<int>graph[10001];
vector<int>ans;
int visited[10001], cnt;
bool isArt[10001];

int dfs(int cur, bool isRoot){
	visited[cur] = ++cnt;
	int ret = visited[cur], early, child = 0;
	for(int next : graph[cur]){
		if(!visited[next]){
			child++;
			early = dfs(next, false);
			ret = min(ret, early);
			if(!isRoot && early >= visited[cur]){
				isArt[cur] = true;
			}
		}
		else{
			ret = min(ret, visited[next]);
		}
	}
	if(isRoot && child >= 2){
		isArt[cur] = true;
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> v >> e;
	int x, y;
	for(int i = 0; i < e; i++){
		cin >> x >> y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	
	for(int i = 1; i <= v; i++) {
		if(!visited[i])	dfs(i, true);
	}
	
	for(int i = 1; i <= v; i++) {
		if(isArt[i])	ans.push_back(i);
	}
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(int p : ans){
		cout << p << " ";
	}
	return 0;
}