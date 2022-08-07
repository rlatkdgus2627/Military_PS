#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int n, k;
int bulb[201];
int dp[201][201];

int solve(int s, int e){
	if(s == e)	return 0;
	int &ret = dp[s][e];
	if(ret != -1)	return ret;
	ret = 201;
	for(int i = s; i < e; i++){
		if(bulb[s] != bulb[i + 1]){
			ret = min(ret, solve(s, i) + solve(i + 1, e) + 1);
		}
		else{
			ret = min(ret, solve(s, i) + solve(i + 1, e));
		}
	}
	return ret;
}

int main(){
	cin.tie(0);
	ios::sync_with_stdio(0);
	
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> bulb[i];
	}
	memset(dp, -1, sizeof(dp));
	
	cout << solve(0, n - 1);
	return 0;
}