#include <bits/stdc++.h>

using namespace std;

int n, ans;

int fenwick_tree[100002];

void update(int i, int value){
	while(i <= 100001){
		fenwick_tree[i] += value;
		i += (i & -i);
	}
}

int getValue(int i){
	int ret = 0;
	while(i > 0){
		ret += fenwick_tree[i];
		i -= (i & -i);
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	int s, e;
	for(int i = 0; i < n; i++){
		cin >> s >> e;
		int left = getValue(s);
		int right = getValue(e);
		cout << left + right << "\n";
		update(s, -left);
		update(s + 1, left);
		update(e, -right);
		update(e + 1, right);
		update(s + 1, 1);
		update(e, -1);
	}
	return 0;
}