#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll num[100001], segtree[400004], lazy[400004];

int n, m;

void updateLazy(int s, int e, int node){
    if(!lazy[node]) return;

    segtree[node] = (e - s + 1) - segtree[node];

    if(s != e){
        lazy[node * 2] = !lazy[node * 2];
        lazy[node * 2 + 1] = !lazy[node * 2 + 1];
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

void update(int s, int e, int node, int left, int right){
    updateLazy(s, e, node);

    if(right < s || e < left)  return;
    else if(left <= s && e <= right){
         segtree[node] = (e - s + 1) - segtree[node];
        if(s != e){
            lazy[node * 2] = !lazy[node * 2];
        	lazy[node * 2 + 1] = !lazy[node * 2 + 1];
        }
        return;
    }
    int mid = (s + e) / 2;
    update(s, mid, node * 2, left, right);
    update(mid + 1, e, node * 2 + 1, left, right);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    ll query, s, e;

    cin >> n >> m;

    for(int i = 0; i < m; i++){
        cin >> query;
        if(query == 0){
            cin >> s >> e;
            update(1, n, 1, s, e);
        }
        else{
            cin >> s >> e;
            cout << getSum(1, n, 1, s, e) << "\n";
        }
    }

    return 0;
}