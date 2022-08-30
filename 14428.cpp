#include <bits/stdc++.h>

using namespace std;

pair<int, int> segtree[400001];
int num[100001];
int n, queryCnt;

const int INF = 1e9 + 1;

pair<int, int> init(int node, int s, int e){
	if(s == e) return segtree[node] = make_pair(num[s], s);
	int mid = (s + e) / 2;
	return segtree[node] = min(init(node * 2, s, mid), init(node * 2 + 1, mid + 1, e));
}

pair<int, int> update(int node, int s, int e, int index, int data){
	if(index < s || e < index)	return segtree[node];
	if(s == e)	return segtree[node] = make_pair(data, s);
	int mid = (s + e) / 2;
	return segtree[node] = min(update(node * 2, s, mid, index, data), update(node * 2 + 1, mid + 1, e, index, data));
}

pair<int, int> getMin(int node, int s, int e, int l, int r){
	if(l > e || r < s)   return make_pair(INF, -1);
	else if(l <= s && e <= r)    return segtree[node];
	int mid = (s + e)/2;
	return min(getMin(node * 2, s, mid, l, r), getMin(node * 2 + 1, mid + 1, e, l, r));
}

int main(){
	int x, query, l, r;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n ;i++){
		cin >> x;
		num[i] = x;
	}
	init(1, 1, n);
	cin >> queryCnt;
	for(int i = 0; i < queryCnt; i++){
		cin >> query >> l >> r;
		if(query == 1){
			update(1, 1, n, l, r);
		}
		else cout << getMin(1, 1, n, l, r).second << "\n";
	}
	return 0;
}
