#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct linear{
	ll A, B;
	double start;
	linear(ll slope, ll y):A(slope), B(y), start(0.0){}
};

vector<linear> v;

int n;
ll a, b, c;
ll psum[1000001];
ll dp[1000001];

double cross(linear &f, linear &g){
	return double(g.B - f.B)/(f.A - g.A);
}

int main(){
	ll p;
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	cin >> a >> b >> c;
	for(int i = 1; i <= n; i++){
		cin >> p;
		psum[i] = psum[i - 1] + p;
	}
	
	dp[1] = a * psum[1] * psum[1] + b * psum[1] + c;
	for(int i = 2; i <= n; i++){
		linear f(-2 * a * psum[i - 1], a * psum[i - 1] * psum[i - 1] - b * psum[i - 1] + dp[i - 1]);
		while(v.size() > 0){
			f.start = cross(f, v.back());
			if(f.start <= v.back().start){
				v.pop_back();
			}
			else break;
		}
		
		v.push_back(f);
		
		int s = 0, e = v.size() - 1, pos = 0;
		while(s <= e){
			int mid = (s + e)/2;
			if(v[mid].start <= psum[i]){
				pos = mid;
				s = mid + 1;
			}
			else e = mid - 1;
		}
		
		dp[i] = max(a * psum[i] * psum[i] + b * psum[i] + c, v[pos].A * psum[i] + v[pos].B + a * psum[i] * psum[i] + b * psum[i] + c);
		
	}
	cout << dp[n];
	
}