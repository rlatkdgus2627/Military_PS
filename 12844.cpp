#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll num[500001], segtree[2000004], lazy[2000004];

int n, m, k;

ll init(int s, int e,int node){
    if(s == e)  return segtree[node] = num[s];
    int mid = (s + e) / 2;
    return segtree[node] = init(s, mid, node * 2) ^ init(mid + 1, e, node * 2 + 1);
}

void updateLazy(int s, int e, int node){
    if(!lazy[node]) return;

  	if((e - s + 1) % 2) segtree[node] ^= lazy[node];

    if(s != e){
        lazy[node * 2] ^= lazy[node];
        lazy[node * 2 + 1] ^= lazy[node];
    }
    
    lazy[node] = 0LL;
}

ll getXOR(int s, int e, int node, int left, int right){
    updateLazy(s, e, node);
    if(right < s || e < left)   return 0LL;
    else if(left <= s && e <= right)    return segtree[node];
    int mid = (s + e) / 2;
    return getXOR(s, mid, node * 2, left, right) ^ getXOR(mid + 1, e, node * 2 + 1, left, right);
}

void update(int s, int e, int node, int left, int right, ll data){
    updateLazy(s, e, node);

    if(right < s || e < left)  return;
    else if(left <= s && e <= right){
        lazy[node] = data;
        updateLazy(s, e, node);
        return;
    }
    int mid = (s + e) / 2;
    update(s, mid, node * 2, left, right, data);
    update(mid + 1, e, node * 2 + 1, left, right, data);
    segtree[node] = segtree[node * 2] ^ segtree[node * 2 + 1];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll query, s, e, diff;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> num[i];
    }
    init(0, n - 1, 1);
	
	cin >> m;
    for(int i = 0; i < m; i++){
        cin >> query;
        if(query == 1){
            cin >> s >> e >> diff;
            update(0, n - 1, 1, s, e, diff);
        }
        else{
            cin >> s >> e;
            cout << getXOR(0, n - 1, 1, s, e) << "\n";
        }
    }

    return 0;
}