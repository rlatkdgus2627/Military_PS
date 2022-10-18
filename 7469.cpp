#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;

ll num[100001];

vector<ll>mergeTree[400001];

void init(int node, int s, int e){
	if(s == e){
		mergeTree[node].push_back(num[s]);
		return;
	}
	
	int mid = (s + e) / 2;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);
	vector<ll> &left = mergeTree[node * 2];
	vector<ll> &right = mergeTree[node * 2 + 1];
	mergeTree[node].resize(left.size() + right.size());
	merge(left.begin(), left.end(), right.begin(), right.end(), mergeTree[node].begin());
	
	return;
}

int query(int node, int s, int e, int l, int r, ll k){
	if(r < s || e < l)	return 0;
	if(l <= s && e <= r)
		return upper_bound(mergeTree[node].begin(), mergeTree[node].end(), k) - mergeTree[node].begin();
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, l, r, k) + query(node * 2 + 1, mid + 1, e, l, r, k);
}

int main(){
	int left, right, k;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	init(1, 1, n);
	
	for(int i = 0; i < m; i++){
		cin >> left >> right >> k;
		ll s = -1e9, e = 1e9;
		while(s <= e){
			//cout << s << " " << e << "\n";
			ll mid = (s + e) / 2;
			//cout << query(1, 1, n, left, right, mid) << "\n";
			if(query(1, 1, n, left, right, mid) < k){
				s = mid + 1;
			}
			else e = mid - 1;
		}
		cout << s << "\n";
	}
	return 0;
}