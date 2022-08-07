#include <bits/stdc++.h>

using namespace std;

int v, e;

vector<int>graph[100001];
vector<pair<int, int> > ans;
int visited[100001], cnt;

int dfs(int cur, int prev){
	visited[cur] = ++cnt;
	int ret = visited[cur], early;
	for(int next : graph[cur]){
		if(next == prev)	continue;
		if(!visited[next]){
			early = dfs(next, cur);
			ret = min(ret, early);
			if(early > visited[cur]){
				ans.push_back(make_pair(min(cur,next), max(cur,next)));
			}
		}
		else{
			ret = min(ret, visited[next]);
		}
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
		if(!visited[i])	dfs(i, i);
	}
	
	
	
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for(auto p : ans){
		cout << p.first << " " << p.second << "\n";
	}
	return 0;
}