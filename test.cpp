#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, m;
ll modcnt[1001], psum, ans;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		ll x;
		cin >> x;
		psum += x;
		modcnt[psum % x]++;
	}
	for(int i = 0; i <= m; i++){
		ans += modcnt[i] * (modcnt[i] - 1) / 2;
	}
	cout << ans + modcnt[0];
}