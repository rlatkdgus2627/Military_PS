#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
ll segtree[400001], num[100001], ans[100001];

struct query2{
	int k, left, right, index;
};

bool cmp(query2 lhs, query2 rhs){
	return lhs.k < rhs.k;
}

vector<pair<int, ll> > queries;
vector<query2> offline;

ll init(int node, int s, int e){
	if(s == e)	return segtree[node] = num[s];
	int mid = s + e >> 1;
	return segtree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}


ll getSum(int node, int s, int e, int l, int r){
	if(r < s || e < l)	return 0LL;
	else if(l <= s && e <= r)	return segtree[node];
	int mid = s + e >> 1;
	return getSum(node * 2, s, mid, l, r) + getSum(node * 2 + 1, mid + 1, e, l, r);
}

void update(int node, int s, int e, int index, ll data){
	if(index < s || e < index)	return;
	segtree[node] += data;
	if(s == e)	return;
	int mid = s + e >> 1;
	update(node * 2, s, mid, index, data);
	update(node * 2 + 1, mid + 1, e, index, data);
}

int main(){
	int q, a, b, k, j = 0;
	ll c;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++)	
		cin >> num[i];
	
	init(1, 1, n);
	
	cin >> m;
	for(int i = 0; i < m; i++){
		cin >> q;
		if(q == 1){
			cin >> a >> c;
			queries.push_back({a, c});
		}
		else if(q == 2){
			cin >> k >> a >> b;
			offline.push_back({k, a, b, ++j});
		}
	}
	sort(offline.begin(), offline.end(), cmp);
	j = 0;
	for(auto cur : offline){
		while(j < cur.k){
			update(1, 1, n, queries[j].first, queries[j].second - num[queries[j].first]);
			num[queries[j].first] = queries[j].second;
			j++;
		}
		ans[cur.index] = getSum(1, 1, n, cur.left, cur.right);
	}
	for(int i = 1; i <= offline.size(); i++){
		cout << ans[i] << "\n";
	}
	return 0;
}