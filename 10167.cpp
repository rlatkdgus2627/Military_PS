#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
vector<pair<ll, ll> > AB;

ll ans;

priority_queue<ll> pq;

int main(){
	ll x;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x;
		AB.push_back(make_pair(0, x));
	}
	for(int i = 0; i < n; i++){
		cin >> x;
		AB[i].first = x;
	}
	sort(AB.begin(), AB.end());
	ans += AB[0].second;
	for(int i = 1; i <= (n - 1)/2; i++){
		pq.push(AB[2 * i - 1].second);
		pq.push(AB[2 * i].second);
		ans += pq.top();
		pq.pop();
	}
	cout << ans;
	return 0;
}