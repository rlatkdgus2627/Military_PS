#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

const ll INF = 1e8;
int n;
vector<p> v;

ll dist(const p &a, const p &b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
}

struct cmp {
	bool operator()(const p &a, const p &b)const{
		if(a.second == b.second)	return a.first < b.first;
		else return a.second < b.second;
	}
};

int main(){
	int del = 0;
	ll x, y, ans;
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> x >> y;
		v.push_back(make_pair(x, y));
	}
	
	sort(v.begin(), v.end(), [](p &lhs, p &rhs){
		return lhs.first < rhs.first;
	});
		
	ans = dist(v[0], v[1]);
	set<p, cmp> S;
	S.insert(v[0]);
	S.insert(v[1]);
	for(int i = 2; i < n; i++){
		p cur = v[i];
		while(del < i){
			ll dx = (cur.first - v[del].first) * (cur.first - v[del].first);
			if(ans < dx){
				S.erase(make_pair(v[del].first, v[del].second));
				del++;
			}
			else break;
		}
		
		ll d = (ll)(sqrt(ans) + 1);
		auto s = S.lower_bound(make_pair(-INF, cur.second - d));
		auto e = S.upper_bound(make_pair(INF, cur.second + d));
		
		for(auto iter = s; iter != e; iter++){
			ans = min(ans, dist(cur, *iter));
		}
		S.insert(cur);
	}
	cout << ans;
	return 0;
}