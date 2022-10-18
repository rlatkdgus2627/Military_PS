#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const ll MOD = 1e9;

int n;

ll dp[100][10][1 << 11], ans;

ll solve(int cur, int num, int state){
	if(cur == n - 1 && state == (1 << 10) - 1){
		return 1;
	}
	
	if(cur >= n - 1){
		return 0;
	}
	
	ll &ret = dp[cur][num][state];
	
	if(ret)	return ret;
	
	if(num == 0){
		ret = solve(cur + 1, 1, state | (1 << 1)) % MOD;
	}
	else if(num == 9){
		ret = solve(cur + 1, 8, state | (1 << 8)) % MOD;
	}
	else{
		ret += solve(cur + 1, num + 1, state | (1 << num + 1)) % MOD;
		ret += solve(cur + 1, num - 1, state | (1 << num - 1)) % MOD;
	}
	
	ret %= MOD;
	
	return ret;
	
}

int main(){
	cin >> n;
	for(int i = 1; i <= 9; i++){
		ans += solve(0, i, (1 << i)) % MOD;
	}
	cout << ans % MOD;
	return 0;
}