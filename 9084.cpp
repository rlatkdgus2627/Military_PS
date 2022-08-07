#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int t;
int n;

ll dp[21][10001];
int coin[21], m;

ll solve(int i, int cur){
	if(i >= n || cur < 0)	return 0;
	if(cur == 0)	return 1;
	
	ll &ret = dp[i][cur];
	if(ret != 0LL)	return ret;
	
	ret += solve(i + 1, cur);
	ret += solve(i, cur - coin[i]);
	
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	cin >> t;
	while(t--){
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++){
			cin >> coin[i];
		}
		cin >> m;
		cout << solve(0, m) << "\n";
	}
	return 0;
}