#include <bits/stdc++.h>

using namespace std;

int segtree[2000001], n;
int num[500001];

vector<int> xCompress;

int getSum(int node, int s, int e, int left, int right){
	if(left > e || right < s)	return 0;
	else if(left <= s && e <= right)	return segtree[node];
	int mid = (s + e)/2;
	return getSum(node * 2, s, mid, left, right) + getSum(node * 2 + 1, mid + 1, e, left, right);
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
	for(int i = 1; i <= n; i++){
		cin >> num[i];
		xCompress.push_back(num[i]);
	}
	sort(xCompress.begin(), xCompress.end());
	
	for(int i = 1; i <= n; i++){
		num[i] = lower_bound(xCompress.begin(), xCompress.end(), num[i]) - xCompress.begin() + 1;
		cout << i - getSum(1, 1, n, 1, num[i]) << "\n";
		update(1, 1, n, num[i], 1);
	}
	
	
	
	return 0;
}