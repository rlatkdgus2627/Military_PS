#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
int n, m;

ll segtree[4000001];

void update(int node, int s, int e, int index, ll data){
	if(index < s || index > e)	return;
	else if(s <= index && index <= e)	segtree[node] += data;
	if(s == e)	return;
	int mid = (s + e)/2;
	update(node * 2, s, mid, index, data);
	update(node * 2 + 1, mid + 1, e, index, data);
}

ll getSum(int node, int s, int e, int l, int r){
	if(r < s || e < l)	return 0LL;
	else if(l <= s && e <= r)	return segtree[node];
	int mid = (s + e)/2;
	return getSum(node * 2, s, mid, l, r) + getSum(node * 2 + 1, mid + 1, e, l, r);
}
void init(){
	memset(segtree, 0, sizeof(segtree));
}

int main(){
	int query;
	int left, right;
	ll data;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> query;
		if(query == 0){
			cin >> left >> right;
			if(left > right)	swap(left, right);
			cout << getSum(1, 1, n, left, right) << "\n";
		}
		else{
			cin >> left >> data;
			update(1, 1, n, left, data - getSum(1, 1, n, left, left));
		}
	}
	return 0;
}