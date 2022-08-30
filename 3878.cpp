#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using p = pair<ll, ll>;

int t, n, m;

p v[101], u[101];

p start;

ll ans;


ll ccw(p &a, p &b, p &c){
	ll temp = a.first*b.second + b.first*c.second + c.first*a.second - b.first*a.second - c.first*b.second - a.first*c.second;
    if(temp > 0LL)	return 1LL;
	else if(temp < 0LL)	return -1LL;
	else return 0;
}

ll cross(p &a1, p &a2, p &b1, p &b2){
	p a = make_pair(a2.first - a1.first, a2.second - a1.second);
	p b = make_pair(b2.first - b1.first, b2.second - b1.second);
	return a.first * b.second - b.first * a.second;
}

bool isInside(vector<p>& hull, p &point){
	if(hull.size() <= 2)	return false;
	ll check = ccw(point, hull[0], hull[1]);
	for(int i = 1; i < hull.size(); i++){
		if(check != ccw(point, hull[i], hull[(i + 1) % hull.size()]))	return false;
	}
	return true;
}

bool isCross(p a, p b, p c, p d){
	ll ab = ccw(a, c, b) * ccw(a, d, b);
	ll cd = ccw(c, a, d) * ccw(c, b, d);
	if(ab == 0 && cd == 0){
		if(a > b){
			swap(a, b);
		}
		if(c > d){
			swap(c, d);
		}
		return c <= b && a <= d;
	}
	else return ab <= 0 && cd <= 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			ll x, y;
			cin >> x >> y;
			v[i] = make_pair(x, y);
		}
		
		for(int i = 0; i < m; i++){
			ll x, y;
			cin >> x >> y;
			u[i] = make_pair(x, y);
		}
		
		swap(v[0], *min_element(v, v + n));

		sort(v + 1, v + n,[&](p &lhs, p &rhs){
			ll ret = ccw(v[0], lhs, rhs);
			if(ret == 0){
				if(lhs.first == rhs.first)	return lhs.second < rhs.second;
				else return lhs.first < rhs.first;
			}
			return ret > 0;
		});
		
		swap(u[0], *min_element(u, u + m));

		sort(u + 1, u + m,[&](p &lhs, p &rhs){
			ll ret = ccw(u[0], lhs, rhs);
			if(ret == 0){
				if(lhs.first == rhs.first)	return lhs.second < rhs.second;
				else return lhs.first < rhs.first;
			}
			return ret > 0;
		});

		vector<p>blackHull;
		blackHull.push_back(v[0]);

		int next = 1;

		while(next < n){
			while(blackHull.size() >= 2){
				p first, second;
				second = blackHull[blackHull.size() - 1];
				blackHull.pop_back();
				first = blackHull[blackHull.size() - 1];
				if (ccw(first, second, v[next]) > 0) {
					blackHull.push_back(second);
					break;
				}
			}
			blackHull.push_back(v[next++]);
		}
		
		vector<p>whiteHull;
		whiteHull.push_back(u[0]);

		next = 1;

		while(next < m){
			while(whiteHull.size() >= 2){
				p first, second;
				second = whiteHull[whiteHull.size() - 1];
				whiteHull.pop_back();
				first = whiteHull[whiteHull.size() - 1];
				if (ccw(first, second, u[next]) > 0) {
					whiteHull.push_back(second);
					break;
				}
			}
			whiteHull.push_back(u[next++]);
		}
		
		bool ans = false;
		if(isInside(blackHull, whiteHull[0]) || isInside(whiteHull, blackHull[0]))
			ans = true;
		for(int i = 0; i < blackHull.size(); i++){
			for(int j = 0; j < whiteHull.size(); j++){
				int iNext = (i + 1) % blackHull.size();
				int jNext = (j + 1) % whiteHull.size();
				if(isCross(blackHull[i], blackHull[iNext], whiteHull[j], whiteHull[jNext])){
					ans = true;
				}
			}
		}
		
		if(ans)	cout << "NO\n";
		else cout << "YES\n";
		
	}
    return 0;
}