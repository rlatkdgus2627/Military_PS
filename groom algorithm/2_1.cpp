#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t, n, sum, x, ans;
vector<int> num;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n;
		num.clear();
		sum = ans = 0;
		for(int i = 0; i < n; i++){
			cin >> x;
			num.push_back(x);
			sum += x;
		}
		for(int i = 0; i < n; i++){
			if(num[i] * n >= sum)	ans++;
		}
		cout << ans << "/" << n << "\n";
	}
	
	return 0;
}