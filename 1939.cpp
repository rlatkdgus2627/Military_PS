#include <bits/stdc++.h>

using namespace std;


int n, m, ans, s, e;

vector<pair<int, int> >edges[10001];
bool visited[10001];

bool bfs(int weight){
	memset(visited, false, sizeof(visited));
	queue<int> Q;
	Q.push(s);
	visited[s] = true;
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		if(cur == e)	return true;
		for(auto& next : edges[cur]){
			if(!visited[next.first] && next.second >= weight){
				Q.push(next.first);
				visited[next.first] = true;
			}
		}
	}
	return false;
}

int main(){
	int a, b, c;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> c;
		edges[a].push_back(make_pair(b, c));
		edges[b].push_back(make_pair(a, c));
	}
	cin >> s >> e;
	int left = 0, right = 1e9;
	while(left <= right){
		int mid = (left + right)/2;
		if(bfs(mid))	left = mid + 1;
		else right = mid - 1;
	}
	cout << right;
	return 0;
}