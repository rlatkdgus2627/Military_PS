#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using p = pair<ll, ll>;

struct star{
	ll x, y, dx, dy;
};

int n;
ll time_point, ans = 1e18, ansT;

star stars[30001];

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

ll rotating_calipers(ll tp){
	ll answer = 0;
	p v[30001];
	for(int i = 0; i < n; i++){
		v[i] = make_pair(stars[i].x + stars[i].dx * tp, stars[i].y + stars[i].dy * tp);
	}
	swap(v[0], *min_element(v, v + n));
	p start = v[0];
	
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

		if(answer < dist(hull[l], hull[r])){
			answer = dist(hull[l], hull[r]);
		}
	}
	return answer;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	ll X, Y, DX, DY;
	
	cin >> n >> time_point;
	for(int i = 0; i < n; i++){
		cin >> X >> Y >> DX >> DY;
		stars[i] = {X, Y, DX, DY};
	}
	
	ll s = 0, e = time_point;
	
	while(e - s >= 3){
		ll p = (s * 2 + e)/3;
		ll q = (s + e * 2)/3;
		if(rotating_calipers(p) > rotating_calipers(q))	s = p;
		else e = q;
	}
	for(ll i = s; i <= e; i++){
		ll temp = rotating_calipers(i);
		if(ans > temp){
			ansT = i;
			ans = temp;
		}
	}
	
	cout << ansT << "\n" << ans << "\n";
	
	
	return 0;
}