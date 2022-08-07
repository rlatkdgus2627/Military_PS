#include <bits/stdc++.h>

using namespace std;

int n;

int dp[50][250001];

int block[50];

const int INF = -1e8;

int solve(int cur, int diff){
	if(diff > 250000){
		return INF;
	}
	if(cur == n && diff != 0){
		return INF;
	}
	
	if(cur == n && diff == 0){
		return 0;
	}
	
	int& ret = dp[cur][diff];
	if(ret != -1)	return ret;
	
	ret = solve(cur + 1, diff);
	
	ret = max(ret, solve(cur + 1, diff + block[cur]));
	
	if(diff < block[cur]){
		ret = max(ret, diff + solve(cur + 1, block[cur] - diff));
	}
	else{
		ret = max(ret, block[cur] + solve(cur + 1, diff - block[cur]));
	}
	return ret;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> block[i];
	}
	memset(dp, -1, sizeof(dp));
	int ans = solve(0, 0);
	if(ans <= 0){
		cout << "-1";
	}
	else cout << ans;
	
	return 0;
}