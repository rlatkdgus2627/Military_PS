#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll n, m;
ll oil[2501];
vector<pair<ll, ll> >graph[2501];
ll dp[2501][2501];


struct Node{
	ll cur, minoil;
	ll sum;
};

struct cmp{
	bool operator()(Node& lhs, Node& rhs){
		return lhs.sum > rhs.sum;
	}
};

ll dijkstra(){
	ll next, next_oil;
	ll dist;
	priority_queue<Node, vector<Node>, cmp> pq;
	pq.push({1, oil[1], 0});
	while(!pq.empty()){
		Node u = pq.top();
		pq.pop();
		
		if(dp[u.cur][u.minoil] != -1)	continue;
		dp[u.cur][u.minoil] = u.sum;
		
		if(u.cur == n){
			return u.sum;
		}
		
	
		for (int i = 0; i < graph[u.cur].size(); i++) {
			next = graph[u.cur][i].first;
			dist = graph[u.cur][i].second;
			next_oil = min(u.minoil, oil[next]);
			
			if (dp[next][next_oil] != -1){
				continue;
			}	
	
			pq.push({next, next_oil, u.sum + u.minoil * dist});
			
		}
	}
	
	return -1;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	ll s, e, w;
	for(int i = 1; i <= n; i++){
		cin >> oil[i];
	}
	memset(dp, -1, sizeof(dp));
	
	for(int i = 0; i < m; i++){
		cin >> s >> e >> w;
		graph[s].push_back(make_pair(e, w));
		graph[e].push_back(make_pair(s, w));
	}
	cout << dijkstra();
	return 0;
}