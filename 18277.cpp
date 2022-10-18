#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, c, q;
vector<int> graph[200004];
int rBegin[200004], rEnd[200004], cnt;
ll depth[200004];

ll segtree[800004];

void dfs(int cur){
	rBegin[cur] = ++cnt;
	for(int next : graph[cur]){
		if(!rBegin[next]){
			depth[next] = depth[cur] + 1;
			dfs(next);
		}
	}
	rEnd[cur] = cnt;
}

void update(int node, int s, int e, int index, ll value){
	if(index < s || e < index)	return;
	segtree[node] += value;
	if(s == e)	return;
	int mid = (s + e)/2;
	update(node * 2, s, mid, index, value);
	update(node * 2 + 1, mid + 1, e, index, value);
}

ll getSum(int node, int s, int e, int l, int r){
    if(r < s || e < l)   return 0LL;
    else if(l <= s && e <= r)    return segtree[node];
    int mid = (s + e) / 2;
    return getSum(node * 2, s, mid, l, r) + getSum(node * 2 + 1, mid + 1, e, l, r);
}

int main(){
	int u, v;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> c;
	for(int i = 0; i < n - 1; i++){
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	depth[c] = 1;
	dfs(c);
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> u >> v;
		if(u == 1){
			update(1, 1, n, rBegin[v], 1);
		}
		else{
			cout << getSum(1, 1, n, rBegin[v], rEnd[v]) * depth[v] << "\n";
		}
	}
	return 0;
}