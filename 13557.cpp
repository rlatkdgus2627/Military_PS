#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, q;

const ll MIN = -1e13;

struct Node{
	ll s, l, r, m;
	Node() : s(0), l(MIN), r(MIN), m(MIN){}
	Node(ll sum, ll left, ll right, ll Max):s(sum), l(left), r(right), m(Max){}
};

ll num[100001];
Node segtree[400001];

Node init(int node, int s, int e){
	if(s == e){
		return segtree[node] = Node(num[s], num[s], num[s], num[s]);
	}
	int mid = (s + e)/2;
	Node leftNode = init(node * 2, s, mid);
	Node rightNode = init(node * 2 + 1, mid + 1, e);
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
	
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> num[i];
	}
	init(1, 1, n);
	
	int x1, y1, x2, y2;
	cin >> q;
	for(int i = 0; i < q; i++){
		cin >> x1 >> y1 >> x2 >> y2;
		if(y1 < x2){
			Node leftPart = query(1, 1, n, x1, y1);
			Node midPart = query(1, 1, n, y1 + 1, x2 - 1);
			Node rightPart = query(1, 1, n, x2, y2);
			cout << leftPart.r + midPart.s + rightPart.l << "\n";
		}
		else{
			Node leftPart = query(1, 1, n, x1, x2 -1);
			Node midPart = query(1, 1, n, x2, y1);
			Node rightPart = query(1, 1, n, y1 + 1, y2);
			cout << max(midPart.m, max(leftPart.r + midPart.l, max(midPart.r + rightPart.l, leftPart.r + midPart.s + rightPart.l))) << "\n";
		}
		
	}
	
	return 0;
}