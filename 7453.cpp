#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int n;
vector<ll> A, B, C, D, AB, CD;
ll ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	int a, b, c, d;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a >> b >> c >> d;
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}
	sort(AB.begin(),AB.end());
	sort(CD.begin(),CD.end());
	for(ll x : AB){
		ans += upper_bound(CD.begin(), CD.end(), -x) - lower_bound(CD.begin(), CD.end(), -x);
	}
	cout << ans;
	
	return 0;
}