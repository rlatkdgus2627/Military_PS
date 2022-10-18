#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, k;
vector<int> graph[1001];

vector<pair<int, int> > tempEdge, addEdge;
vector<pair<char, int> >query;
bool check[100001];

int dist[1001];
vector<int> ans;

void bfs(int s){
	queue<int>Q;
	Q.push(s);
	while(!Q.empty()){
		int cur = Q.front();
		Q.pop();
		for(int next : graph[cur]){
			if(dist[next] > dist[cur] + 1){
				Q.push(next);
				dist[next] = dist[cur] + 1;
			}
		}
	}
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	int s, e;
	char q;
	cin >> n >> m >> k;
	for(int i = 0; i < m; i++){
		cin >> s >> e;
		tempEdge.push_back(make_pair(s, e));
	}
	
	for(int i = 0; i < k; i++){
		cin >> q >> e;
		query.push_back(make_pair(q, e));
	}
	reverse(query.begin(), query.end());
	
	for(int i = 0; i < k; i++){
		if(query[i].first == 'U'){
			check[query[i].second - 1] = true;
			addEdge.push_back(tempEdge[query[i].second - 1]);
		}
	}
	
	for(int i = 0; i < m; i++){
		if(!check[i]){
			graph[tempEdge[i].first].push_back(tempEdge[i].second);
		}
	}
	
	fill(dist, dist + n + 1, (int)1e9);
	dist[1] = 0;
	bfs(1);
	
	int cnt = 0;
	
	for(int i = 0; i < k; i++){
		if(query[i].first == 'U'){
			graph[addEdge[cnt].first].push_back(addEdge[cnt].second);
			bfs(addEdge[cnt].first);
			cnt++;
		}
		else{
			ans.push_back(dist[query[i].second]);
		}
	}
	
	reverse(ans.begin(), ans.end());
	for(int x : ans){
		if(x >= 1e9){
			cout << "-1" << "\n";
		}
		else cout << x << "\n";
	}
	
	return 0;
}