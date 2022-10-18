#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll n, x;
ll ans;
ll cnt;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	stack<pair<ll, ll> > S;
	for(int i = 0; i < n; i++){
		cin >> x;
		while(!S.empty() && S.top().first < x){
			ans += S.top().second;
			S.pop();
		}
		cnt = 1;
		if(!S.empty() && S.top().first == x){
			ans += S.top().second;
			cnt = S.top().second + 1;
			if(S.size() > 1)	ans++;
			S.pop();
		}
		else if(!S.empty()){
			ans++;
		}
		S.push(make_pair(x, cnt));
	}
	cout << ans;
	return 0;
}