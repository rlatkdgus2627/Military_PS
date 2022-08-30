#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
int q1, q2;

ll segtree[4000001], lazy[4000001], num[1000001];

ll init(int node, int s, int e){
    if(s == e)  return segtree[node] = num[s];
    int mid = (s + e) / 2;
    return segtree[node] = init(node * 2, s, mid) + init(node * 2 + 1, mid + 1, e);
}

void updateLazy(int node, int s, int e){
	if(!lazy[node])	return;
	segtree[node] += (e - s + 1) * lazy[node];
	if(s != e){
		lazy[node * 2] += lazy[node];
		lazy[node * 2 + 1] += lazy[node];
	}
	lazy[node] = 0;
}
ll getSum(int node, int s, int e, int left, int right){
	updateLazy(node, s, e);
	if(right < s || e < left)   return 0LL;
    else if(left <= s && e <= right)    return segtree[node];
    int mid = (s + e) / 2;
	return getSum(node * 2, s, mid, left, right) + getSum(node * 2 + 1, mid + 1, e, left, right);
}

void update(int node, int s, int e, int left, int right, ll data){
	updateLazy(node, s, e);
	if(right < s || e < left)  return;
    else if(left <= s && e <= right){
        segtree[node] += (e - s + 1) * data;
        if(s != e){
            lazy[node * 2] += data;
            lazy[node * 2 + 1] += data;
        }
        return;
    }
	int mid = (s + e) / 2;
	update(node * 2, s, mid, left, right, data);
    update(node * 2 + 1, mid + 1, e, left, right, data);
	segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main(){
	int query;
	int s, e;
	ll data;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> q1 >> q2;
	
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	init(1, 1, n);
	for(int i = 0; i < q1 + q2; i++){
		cin >> query;
		if(query == 1){
			cin >> s >> e;
			cout << getSum(1, 1, n, s, e) << "\n";
		}
		else{
			cin >> s >> e >> data;
			update(1, 1, n, s, e, data);
		}
	}
	
	return 0;
}