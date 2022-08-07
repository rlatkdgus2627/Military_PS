#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n, q;
ll segtree[400008], lazy[400008], num[100001];

void updateLazy(int s, int e, int node){
    if(!lazy[node]) return;

    segtree[node] += (e - s + 1) * lazy[node];

    if(s != e){
        lazy[node * 2] += lazy[node];
        lazy[node * 2 + 1] += lazy[node];
    }
    
    lazy[node] = 0;
}

ll getSum(int s, int e, int node, int left, int right){
    updateLazy(s, e, node);

    if(right < s || e < left)   return 0LL;
    else if(left <= s && e <= right)    return segtree[node];
    int mid = (s + e) / 2;
    return getSum(s, mid, node * 2, left, right) + getSum(mid + 1, e, node * 2 + 1, left, right);
}

void update(int s, int e, int node, int left, int right, ll data){
    updateLazy(s, e, node);

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
    update(s, mid, node * 2, left, right, data);
    update(mid + 1, e, node * 2 + 1, left, right, data);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main(){
	cin.tie(0);
    ios::sync_with_stdio(0);
	int query, x, s, e;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	cin >> q;
	for(int i = 0; i < q; i++){
        cin >> query;
        if(query == 1){
            cin >> s >> e;
            update(1, n, 1, s, e, 1LL);
			update(1, n, 1, e + 1, e + 1, -(e - s + 1));
        }
        else{
            cin >> x;
            cout << getSum(1, n, 1, 1, x) + num[x] << "\n";
        }
    }
	return 0;
}