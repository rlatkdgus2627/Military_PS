#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int num[1000001], temp[1000001];
ll ans;
ll segtree[4000001];

ll getSum(int s, int e, int node, int left, int right) {
	if (left > e || right < s) return 0;
	if (left <= s && e <= right) return segtree[node];
	ll mid = (s + e) / 2;
	return getSum(s, mid, node * 2, left, right) + getSum(mid + 1, e, node * 2 + 1, left, right);
}

void update(int s, int e, int node, int index, ll data) {
	if (index < s || e < index ) return;
	segtree[node] += data;
	if (s == e) return;
	ll mid = (s + e) / 2;
	update(s, mid, node * 2, index, data);
	update(mid + 1, e, node * 2 + 1, index, data);
	
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	int x;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		temp[x] = i;
	}
	for (int i = 1; i <= n; i++) {
		cin >> x;
		num[i] = temp[x];
	}
	for (int i = 1; i <= n; i++) {
		ans += getSum(1, n, 1, num[i] + 1, n);
		update(1, n, 1, num[i], 1);
	}
	
	cout << ans;
	
	return 0;
}