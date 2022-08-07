#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;
ll u, v;

const ll MIN = -1e12;

struct Node{
	ll s, l, r, m;
	Node() : s(0), l(MIN), r(MIN), m(MIN){}
	Node(ll sum, ll left, ll right, ll Max):s(sum), l(left), r(right), m(Max){}
};

ll num[100001];
Node segtree[400001];

Node init(int node, int s, int e){
	if(s == e){
		return segtree[node] = Node(u * num[s] + v, u * num[s] + v, u * num[s] + v, u * num[s] + v);
	}
	int mid = (s + e)/2;
	Node leftNode = init(node * 2, s, mid);
	Node rightNode = init(node * 2 + 1, mid + 1, e);
	return segtree[node] = Node(leftNode.s + rightNode.s, max(leftNode.l, leftNode.s + rightNode.l), max(rightNode.r, rightNode.s + leftNode.r), max(max(leftNode.m, rightNode.m), leftNode.r + rightNode.l));
}

Node update(int node, int s, int e, int index, ll value){
	if(index < s || e < index)	return segtree[node];
	if(s == e)	return segtree[node] = Node(u * value + v, u * value + v, u * value + v, u * value + v);
	int mid = (s + e)/2;
	Node leftNode = update(node * 2, s, mid, index, value);
	Node rightNode = update(node * 2 + 1, mid + 1, e, index, value);
	return segtree[node] = Node(leftNode.s + rightNode.s, max(leftNode.l, leftNode.s + rightNode.l), max(rightNode.r, rightNode.s + leftNode.r), max(max(leftNode.m, rightNode.m), leftNode.r + rightNode.l));
}

Node query(int node, int s, int e, int left, int right){
	if(right < s || left > e)	return Node();
	if(left <= s && e <= right)	return segtree[node];
	int mid = (s + e)/2;
	Node leftNode = query(node * 2, s, mid, left, right);
	Node rightNode = query(node * 2 + 1, mid + 1, e, left, right);
	return Node(leftNode.s + rightNode.s, max(leftNode.l, leftNode.s + rightNode.l), max(rightNode.r, rightNode.s + leftNode.r), max(max(leftNode.m, rightNode.m), leftNode.r + rightNode.l));
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> q >> u >> v;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	init(1, 0, n - 1);
	
	int start, end;
	int a, b, c;
	for(int i = 0; i < q; i++){
		cin >> c >> a >> b;
		if(c == 0){
			cout << query(1, 0, n - 1, a - 1, b - 1).m - v << "\n";
		}
		else{
			update(1, 0, n - 1, a - 1, (ll)b);
		}
	}
	
	return 0;
}