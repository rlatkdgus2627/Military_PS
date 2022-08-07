#include <bits/stdc++.h>

using namespace std;

using ll = long long;

using p = pair<ll, pair<ll, ll> >;

ll n, m, k, s, d, wsum, tax;

const ll INF = 1e12;

vector<pair<ll, ll> >edges[1001];

ll dist[1001][1001];

priority_queue<p, vector<p>, greater<p> > pq;

void dijkstra(){
	ll curNode, visitNode, nextNode, distance;
	pq.push(make_pair(0, make_pair(s, 0)));
	while(!pq.empty()){
		p cur = pq.top();
		pq.pop();
		curNode = cur.second.first;
		visitNode = cur.second.second;
		if(visitNode >= n)	continue;
		if(cur.first > dist[curNode][visitNode])	continue;
		for(auto& next : edges[curNode]){
			nextNode = next.first;
			distance = next.second;
			if(dist[nextNode][visitNode + 1] > cur.first + distance){
				dist[nextNode][visitNode + 1] = cur.first + distance;
				pq.push(make_pair(cur.first + distance, make_pair(nextNode, visitNode + 1)));
			}
		}
	}
}

ll solve(){
	ll ans = INF;
	for(int i = 0; i <= n; i++){
		ans = min(ans, dist[d][i] + wsum * i);
	}
	return ans;
}

int main(){
	ll a, b, w;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m >> k;
	cin >> s >> d;
	for(int i = 1; i <= n; i++){
		fill(dist[i], dist[i] + n + 1, INF);
	}
	for(int i = 0; i < m; i++){
		cin >> a >> b >> w;
		edges[a].push_back(make_pair(b, w));
		edges[b].push_back(make_pair(a, w));
	}
	dijkstra();
	cout << solve() << "\n";
	for(int i = 0; i < k; i++){
		cin >> tax;
		wsum += tax;
		cout << solve() << "\n";
	}
	return 0;
}