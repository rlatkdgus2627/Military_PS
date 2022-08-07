#include <bits/stdc++.h>

using namespace std;

int n, m;

int num[100001];

vector<int> mergeTree[400001];

void init(int node, int s, int e){
	if(s == e){
		mergeTree[node].push_back(num[s]);
		return;
	}
	int mid = (s + e)/2;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);
	vector<int>& left = mergeTree[node * 2];
	vector<int>& right = mergeTree[node * 2 + 1];
	mergeTree[node].resize(left.size() + right.size());
	merge(left.begin(), left.end(), right.begin(), right.end(), mergeTree[node].begin());
	return;
}

int query(int node, int s, int e, int l, int r, int k){
	if(r < s || e < l)	return 0;
	if(l <= s && e <= r)
		return mergeTree[node].end() - upper_bound(mergeTree[node].begin(), mergeTree[node].end(), k);
	int mid = (s + e)/2;
	return query(node * 2, s, mid, l, r, k) + query(node * 2 + 1, mid + 1, e, l, r, k);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	init(1, 1, n);
	cin >> m;
	int l, r, k;
	for(int i = 0; i < m; i++){
		cin >> l >> r >> k;
		cout << query(1, 1, n, l, r, k) << "\n";
	}
}
	