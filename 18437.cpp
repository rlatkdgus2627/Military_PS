#include <bits/stdc++.h>

using namespace std;

int n, m;

int rangeS[100001], rangeE[100001], cnt;
vector<int> graph[100001];

int segtree[400001], lazy[400001];

void dfs(int cur){
	rangeS[cur] = ++cnt;
	for(int next : graph[cur]){
		dfs(next);
	}
	rangeE[cur] = cnt;
}

void updateLazy(int node, int s, int e){
	if(lazy[node] == -1)	return;
	segtree[node] = (e - s + 1) * lazy[node];
	
	if(s != e){
		lazy[node * 2] = lazy[node * 2 + 1] = lazy[node]; 
	}
	lazy[node] = -1;
	return;
}

void update(int node, int s, int e, int l, int r, int data){
	updateLazy(node, s, e);
	if(r < s || e < l)	return;
	else if(l <= s && e <= r){
		lazy[node] = data;
		updateLazy(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
    update(node * 2, s, mid, l, r, data);
    update(node * 2 + 1, mid + 1, e, l, r, data);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int getSum(int node, int s, int e, int l, int r){
	updateLazy(node, s, e);
	if(r < s || e < l)	return 0;
	else if(l <= s && e <= r)	return segtree[node];
	int mid = (s + e) / 2;
	return getSum(node * 2, s, mid, l, r) + getSum(node * 2 + 1, mid + 1, e, l, r);
}

int main(){
	int x, query;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> x;
		if(x != 0)	graph[x].push_back(i);
	}
	
	cin >> m;
	dfs(1);
	memset(lazy, -1, sizeof(lazy));
	update(1, 1, n, rangeS[1], rangeE[1], 1);
	
	for(int i = 0; i < m; i++){
		cin >> query >> x;
		switch(query){
			case 1:
				update(1, 1, n, rangeS[x] + 1, rangeE[x], 1);
				break;
			case 2:
				update(1, 1, n, rangeS[x] + 1, rangeE[x], 0);
				break;
			default:
				cout << getSum(1, 1, n, rangeS[x] + 1, rangeE[x]) << "\n";
				break;
		}
	}
		
	return 0;
}