#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using p = pair<ll, ll>;

int t, n;

p v[100001];

p start;

ll ccw(p &a, p &b, p &c){
    return a.first*b.second + b.first*c.second + c.first*a.second - b.first*a.second - c.first*b.second - a.first*c.second;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++){
        ll x, y;
        cin >> x >> y;
        v[i] = make_pair(x, y);
    }
    sort(v, v + n, [](p &lhs, p &rhs){
        if(lhs.second == rhs.second)  return lhs.first < rhs.first;
        else return lhs.second < rhs.second;
    });

    start = v[0];

    sort(v + 1, v + n,[](p &lhs, p &rhs){
        ll ldx, ldy, rdx, rdy;
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

    return 0;
}