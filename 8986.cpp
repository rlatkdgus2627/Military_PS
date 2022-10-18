#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll num[100001], ans = 1e18;

ll dist(ll x){
	ll ret = 0;
	for(int i = 1; i < n; i++){
		ret += labs(num[i] - x * i);
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	
	ll s = 0, e = num[n - 1];
	while(e - s >= 3){
		ll p = (s * 2 + e)/3;
		ll q = (s + e * 2)/3;
		if(dist(p) > dist(q))	s = p;
		else e = q;
	}
	for(ll i = s; i <= e; i++){
		ans = min(ans, dist(i));
	}
	
	cout << ans;
	return 0;
}