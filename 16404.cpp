#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, cnt;

vector<int> graph[100001];

int start[100001], endd[100001];

ll segtree[400001], lazy[400001];

void dfs(int cur){
	start[cur] = ++cnt;
	for(int next: graph[cur]){
		dfs(next);
	}
	endd[cur] = cnt;
}

void updateLazy(int node, int s, int e){
	if(!lazy[node]) return;
	
    segtree[node] += (e - s + 1) * lazy[node];
	
	if(s != e){
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	
	lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, ll data){
	updateLazy(node, s, e);
	if(r < s || e < l)	return;
	else if(l <= s && e <= r){
		segtree[node] += (e - s + 1) * data;
        if(s != e){
            lazy[node * 2] += data;
            lazy[node * 2 + 1] += data;
        }
        return;
	}
	int mid = (s + e)/2;
	update(node * 2, s, mid, l, r, data);
	update(node * 2 + 1, mid + 1, e, l, r, data);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

ll getSum(int node, int s, int e, int l, int r){
	updateLazy(node, s, e);
	if(r < s || e < l)	return 0LL;
	else if(l <= s && e <= r)	return segtree[node];
	int mid = (s + e)/2;
	return getSum(node * 2, s, mid, l, r) + getSum(node * 2 + 1, mid + 1, e, l, r);
}

int main(){
	int x, query, crew;
	ll data;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> x;
		if(x == -1)	continue;
		graph[x].push_back(i);
	}
	dfs(1);
	
	for(int i = 0; i < m; i++){
		cin >> query;
		if(query == 1){
			cin >> crew >> data;
			update(1, 1, n, start[crew], endd[crew], data);
		}
		else{
			cin >> crew;
			cout << getSum(1, 1, n, start[crew], start[crew]) << "\n";
		}
	}
	
	return 0;
}