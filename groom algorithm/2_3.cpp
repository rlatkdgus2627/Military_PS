#include <bits/stdc++.h>

using namespace std;

int n, k;
vector<pair<string, double> > v;
string s;
double x;
int main() {
	cout << fixed;
	cout.precision(2);
	
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> s >> x;
		v.push_back(make_pair(s, x));
	}
	sort(v.begin(), v.end(), [](pair<string, double> &a, pair<string, double> &b){
		if(a.first == b.first)	return a.second < b.second;
		else return a.first < b.first;
	});
	
	cout << v[k - 1].first << " " << v[k - 1].second;
	return 0;
}