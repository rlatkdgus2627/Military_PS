#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using p = pair<ll, ll>;

int t, n;
vector<p> v;
map<p, int> m;

ll ccw(p &a, p &b, p &c){
	 return a.first*b.second + b.first*c.second + c.first*a.second - b.first*a.second - c.first*b.second - a.first*c.second;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		ll x, y;
		v.clear();
		
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> x >> y;
			v.push_back(make_pair(x, y));
			m[make_pair(x, y)] = i;
		}
		
		swap(v[0], *min_element(v.begin(), v.end()));
		sort(v.begin() + 1, v.end(), [&](p &lhs, p &rhs){
			ll ret = ccw(v[0], lhs, rhs);
			if(ret == 0){
				if(lhs.first == rhs.first)	return lhs.second < rhs.second;
				else return lhs.first < rhs.first;
			}
			return ret > 0;
		});
		
		int rev = v.size()-1;
		while(ccw(v[0], v[rev - 1], v[rev]) == 0){
			rev--;
		}
		reverse(v.begin() + rev, v.end());
		
		for(auto cur : v){
			cout << m[cur] << " ";
		}
		cout << "\n";
	}
	return 0;
}