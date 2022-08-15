#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n;
ll a[100001], b[100001], dp[100001];

struct linear{
	ll a, b;
	double start;
	linear(ll slope, ll y):a(slope), b(y), start(0.0){}
};

vector<linear>v;

double getX(linear &f, linear &g){
	return (double)(g.b - f.b)/(f.a - g.a);
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i];
	}
	for(int i = 2; i <= n; i++){
		linear f(b[i - 1], dp[i - 1]);
		
		while(v.size() > 0){
			f.start = getX(f, v.back());
			if(f.start < v.back().start){
				v.pop_back();
			}
			else break;
		}
		
		v.push_back(f);
		
		int s = 0, e = v.size() - 1, pos = 0;
		while(s <= e){
			int mid = (s + e)/2;
			if(v[mid].start < a[i]){
				pos = mid;
				s = mid + 1;
			}
			else e = mid - 1;
		}
		
		dp[i] = v[pos].a * a[i] + v[pos].b; 
	}
	
	cout << dp[n];
	
	return 0;
}