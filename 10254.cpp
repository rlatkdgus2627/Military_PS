#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using p = pair<ll, ll>;

int t, n;

p v[200001];

p start;

ll ans;


ll ccw(p &a, p &b, p &c){
    return a.first*b.second + b.first*c.second + c.first*a.second - b.first*a.second - c.first*b.second - a.first*c.second;
}

ll cross(p &a1, p &a2, p &b1, p &b2){
	p a = make_pair(a2.first - a1.first, a2.second - a1.second);
	p b = make_pair(b2.first - b1.first, b2.second - b1.second);
	return a.first * b.second - b.first * a.second;
}

ll dist(p &a, p &b){
	return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second); 
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin >> t;
	while(t--){
		ans = -1;
		cin >> n;
		for(int i = 0; i < n; i++){
			ll x, y;
			cin >> x >> y;
			v[i] = make_pair(x, y);
		}
		
		swap(v[0], *min_element(v, v + n));
		start = v[0];

		sort(v + 1, v + n,[&](p &lhs, p &rhs){
			ll ret = ccw(start, lhs, rhs);
			if(ret == 0){
				if(lhs.first == rhs.first)	return lhs.second < rhs.second;
				else return lhs.first < rhs.first;
			}
			return ret > 0;
		});

		vector<p>hull;
		hull.push_back(v[0]);
		hull.push_back(v[1]);

		int next = 2;

		while(next < n){
			while(hull.size() >= 2){
				p first, second;
				second = hull[hull.size() - 1];
				hull.pop_back();
				first = hull[hull.size() - 1];
				if (ccw(first, second, v[next]) > 0) {
					hull.push_back(second);
					break;
				}
			}
			hull.push_back(v[next++]);
		}

		int l = 0, r = 1;
		int ansL = 0, ansR = 0;

		int size = hull.size();
		
		for(int i = 0; i < size * 2; i++){
			if(cross(hull[l], hull[(l + 1) % size], hull[r], hull[(r + 1) % size]) < 0){
				l = (l + 1) % size;
			}
			else if(cross(hull[l], hull[(l + 1) % size], hull[r], hull[(r + 1) % size]) == 0){
				l = (l + 1) % size;
				r = (r + 1) % size;
			}
			else{
				r = (r + 1) % size;
			}
			
			if(ans < dist(hull[l], hull[r])){
				ansL = l;
				ansR = r;
				ans = dist(hull[l], hull[r]);
			}
		}

		cout << hull[ansL].first << " " << hull[ansL].second << " " << hull[ansR].first << " " << hull[ansR].second << "\n";
	}
    return 0;
}