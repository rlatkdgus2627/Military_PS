#include <bits/stdc++.h>

using namespace std;
using p = pair<double, double>;

int n;

p v[100001];

p start;

double ans, L;

double ccw(p &a, p &b, p &c){
    return a.first*b.second + b.first*c.second + c.first*a.second - b.first*a.second - c.first*b.second - a.first*c.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	cout << fixed;
	cout.precision(0);
	
    cin >> n >> L;
    for(int i = 0; i < n; i++){
        double x, y;
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    sort(v, v + n, [](p &lhs, p &rhs){
        if(lhs.second == rhs.second)  return lhs.first < rhs.first;
        else return lhs.second < rhs.second;
    });

    start = v[0];

    sort(v + 1, v + n,[](p &lhs, p &rhs){
        double ldx, ldy, rdx, rdy;
        ldx = lhs.first - start.first;
        ldy = lhs.second - start.second; 
        rdx = rhs.first - start.first;
        rdy = rhs.second - start.second; 
        if(ldx * rdy != ldy * rdx)  return ldx * rdy > ldy * rdx;
        if(lhs.second != rhs.second) return lhs.second < rhs.second;
        return lhs.first < rhs.first;
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

	for(int i = 0; i < hull.size() - 1; i++){
		ans += sqrt((hull[i].first - hull[i + 1].first) * (hull[i].first - hull[i + 1].first) + (hull[i].second - hull[i + 1].second) * (hull[i].second - hull[i + 1].second));
	}
	ans += sqrt((hull[0].first - hull[hull.size() - 1].first) * (hull[0].first - hull[hull.size() - 1].first) + (hull[0].second - hull[hull.size() - 1].second) * (hull[0].second - hull[hull.size() - 1].second));
	cout << ans + L * 2 * acos(-1);

    return 0;
}