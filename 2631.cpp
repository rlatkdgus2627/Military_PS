#include <bits/stdc++.h>

using namespace std;

int n;

vector<int> child, v;

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		child.push_back(x);
	}
	
	v.push_back(-1e9);
	
	for (int i = 0; i < n; i++) {
		if (child[i] > v.back()) {
			v.push_back(child[i]);
		}
		else {
			auto t = lower_bound(v.begin(), v.end(), child[i]);
			*t = child[i];
		}
	}
	
	cout << n - v.size() + 1 << "\n";
	
	
	return 0;
}