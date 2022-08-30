#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using p = pair<ll, ll>;

int t;
int n;
vector<p> v;

const double INF = 1e9;
double ans, temp;

double dist(const p &a, const p &b, const p &c){
	double s = fabs((a.first * b.second + b.first * c.second + c.first * a.second) - (b.first * a.second + c.first * b.second + a.first * c.second));
	double d = sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
	return s/d;
}

ll ccw(p &a, p &b, p &c){
	ll temp = a.first*b.second + b.first*c.second + c.first*a.second - b.first*a.second - c.first*b.second - a.first*c.second;
    if(temp > 0LL)	return 1LL;
	else if(temp < 0LL)	return -1LL;
	else return 0;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cout << fixed;
	cout.precision(2);
	while(1){
		t++;
		cin >> n;
		if(n == 0)	break;
		v.clear();
		for(int i = 0; i < n; i++){
			ll x, y;
			cin >> x >> y;
			v.push_back(make_pair(x, y));
		}
		
		swap(v[0], *min_element(v.begin(), v.end()));

		sort(v.begin() + 1, v.end(),[&](p &lhs, p &rhs){
			ll ret = ccw(v[0], lhs, rhs);
			if(ret == 0){
				if(lhs.first == rhs.first)	return lhs.second < rhs.second;
				else return lhs.first < rhs.first;
			}
			return ret > 0;
		});
		
		vector<p>hull;
		hull.push_back(v[0]);

		int next = 1;

		while(next < n){
			while(hull.size() >= 2){
				p first, second;
				second = hull.back();
				hull.pop_back();
				first = hull.back();
				if (ccw(first, second, v[next]) > 0) {
					hull.push_back(second);
					break;
				}
			}
			hull.push_back(v[next++]);
		}
		
		ans = INF;
		for(int i = 0; i < hull.size(); i++){
			temp = 0;
			for(int j = 0; j < hull.size(); j++){
				temp = max(temp, dist(hull[i], hull[(i + 1) % hull.size()], hull[j]));
			}
			ans = min(ans, temp);
		}
		cout << "Case " << t << ": " << ans +  0.00499999<< "\n";
	}
	return 0;
}