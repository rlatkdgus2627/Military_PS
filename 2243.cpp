#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;

int segtree[4000001];

int getKth(int node, int s, int e, int k){
	if(s == e)	return s;
	int mid = (s + e)/2;
	if(k <= segtree[node * 2])	return getKth(node * 2, s, mid, k);
	else return getKth(node * 2 + 1, mid + 1, e, k - segtree[node * 2]);
}

void update(int node, int s, int e, int index, int data){
	if(index < s || e < index)	return;
	segtree[node] += data;
	if(s == e)	return;
	int mid = (s + e)/2;
	update(node * 2, s, mid, index, data);
	update(node * 2 + 1, mid + 1, e, index, data);
}	

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	int q, f, c, k;
	while(n--){
		cin >> q;
		if(q == 1){
			cin >> k;
			int remove = getKth(1, 1, 1e6, k);
			cout << remove << "\n";
			update(1, 1, 1e6, remove, -1);
		}
		else{
			cin >> f >> c;
			update(1, 1, 1e6, f, c);
		}
	}
}