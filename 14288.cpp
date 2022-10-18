#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m, cnt;
bool direction;

vector<int> graph[100001];

int rangeS[100001], rangeE[100001];

ll segtree[400001], lazy[400001];
ll segtree2[400001], lazy2[400001];

void dfs(int cur){
	rangeS[cur] = ++cnt;
	for(int next : graph[cur]){
		dfs(next);
	}
	rangeE[cur] = cnt;
}

void updateLazy(int node, int s, int e){
	if(!lazy[node])	return;
	segtree[node] += (e - s + 1) * lazy[node];
	if(s != e){
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
	
	return;
}

void update(int node, int s, int e, int left, int right, ll data){
	updateLazy(node, s, e);
	if(right < s || e < left)	return;
	if(left <= s && e <= right){
		segtree[node] += (e - s + 1) * data;
		if(s != e){
			lazy[node * 2] += data;
			lazy[node * 2 + 1] += data;
		}
		return;
	}
	int mid = (s + e)/2;
	update(node * 2, s, mid, left, right, data);
	update(node * 2 + 1, mid + 1, e, left, right, data);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

ll getSum(int node, int s, int e, int left, int right){
	updateLazy(node, s, e);
	if(right < s || e < left)	return 0LL;
	else if(left <= s && e <= right)	return segtree[node];
	int mid = (s + e)/2;
	return getSum(node * 2, s, mid, left, right) + getSum(node * 2 + 1, mid + 1, e, left, right);
}

void updateLazy2(int node, int s, int e){
	if(!lazy2[node])	return;
	segtree2[node] += (e - s + 1) * lazy2[node];
	if(s != e){
		lazy2[node * 2] += lazy2[node];
		lazy2[node * 2 + 1] += lazy2[node];
	}
	lazy2[node] = 0;
	
	return;
}

void update2(int node, int s, int e, int left, int right, ll data){
	updateLazy2(node, s, e);
	if(right < s || e < left)	return;
	if(left <= s && e <= right){
		segtree2[node] += (e - s + 1) * data;
		if(s != e){
			lazy2[node * 2] += data;
			lazy2[node * 2 + 1] += data;
		}
		return;
	}
	int mid = (s + e)/2;
	update2(node * 2, s, mid, left, right, data);
	update2(node * 2 + 1, mid + 1, e, left, right, data);
	segtree2[node] = segtree2[node * 2] + segtree2[node * 2 + 1];
}

ll getSum2(int node, int s, int e, int left, int right){
	updateLazy2(node, s, e);
	if(right < s || e < left)	return 0LL;
	else if(left <= s && e <= right)	return segtree2[node];
	int mid = (s + e)/2;
	return getSum2(node * 2, s, mid, left, right) + getSum2(node * 2 + 1, mid + 1, e, left, right);
}

int main(){
	int x, query, w;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> x;
		if(x == -1)	 continue;
		graph[x].push_back(i);
	}
	dfs(1);
	for(int i = 0; i < m; i++){
		cin >> query;
		if(query == 1){
			cin >> x >> w;
			if(direction){
				update2(1, 1, n, rangeS[x], rangeS[x], w);
			}
			else update(1, 1, n, rangeS[x], rangeE[x], w);
		}
		else if(query == 2){
			cin >> x;
			cout << getSum(1, 1, n, rangeS[x], rangeS[x]) + getSum2(1, 1, n, rangeS[x], rangeE[x]) << "\n";
		}
		else{
			direction ^= true;
		}
	}
	return 0;
}