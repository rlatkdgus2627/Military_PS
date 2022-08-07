#include <bits/stdc++.h>

using namespace std;

int n;
int q;

int num[100001];
int segtree[400001];

const int INF = 1e9 + 7;

int init(int node, int s, int e){
	if(s == e)	return segtree[node] = num[s];
	int mid = (s + e) / 2;
	return segtree[node] = min(init(node * 2, s, mid), init(node * 2 + 1, mid + 1, e));
}

int update(int node, int s, int e, int index, int value){
	if(index < s || index > e)  return segtree[node];
	if(s == e)  return segtree[node] = value;
	int mid = (s + e)/2;
    return segtree[node] = min(update(node * 2, s, mid, index, value), update(node * 2 + 1, mid + 1, e, index, value));
}

int getMin(int node, int s, int e, int l, int r){
	if(r < s || l > e)	return INF;
	if(l <= s && e <= r)	return segtree[node];
	int mid = (s + e) / 2;
	return min(getMin(node * 2, s, mid, l, r), getMin(node * 2 + 1, mid + 1, e, l, r));
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	init(1, 0, n - 1);
	cin >> q;
	for(int i = 0; i < q; i++){
		int x, a, b;
		cin >> x >> a >> b;
		if(x == 1){
			update(1, 0, n - 1, a - 1, b);
		}
		else{
			cout << getMin(1, 0, n - 1, a - 1, b - 1) << "\n";
		}
	}
	
	return 0;
}