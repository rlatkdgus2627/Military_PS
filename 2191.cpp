#include <bits/stdc++.h>

using namespace std;

vector<int>graph[101];

int rat[101], hole[101];
bool visited[101];

int n, m, ans;
double s, v;

pair<double, double> ratPos[101];
pair<double, double> holePos[101];

bool dfs(int cur){
	if(visited[cur])	return false;
	visited[cur] = true;
	for(int next : graph[cur]){
		if(!hole[next] || dfs(hole[next])){
			hole[next] = cur;
			rat[cur] = next;
			return true;
		}
	}
	return false;
}

double dist(pair<double, double> &a, pair<double, double> &b){
	return sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> s >> v;
	double x, y;
	for(int i = 1; i <= n; i++){
		cin >> x >> y;
		ratPos[i] = make_pair(x, y);
	}
	for(int i = 1; i <= m; i++){
		cin >> x >> y;
		holePos[i] = make_pair(x, y);
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(dist(ratPos[i], holePos[j]) <= s * v){
				graph[i].push_back(j);
			}
		}
	}
	
	for(int i = 1; i <= n; i++){
		if(!rat[i]){
			memset(visited, false, sizeof(visited));
			if(dfs(i))	ans++;
		}
	}
	cout << n - ans;
	
	
	return 0;
}